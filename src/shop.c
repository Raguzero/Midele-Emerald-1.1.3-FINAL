#include "global.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "money.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon_icon.h"
#include "scanline_effect.h"
#include "script.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "text_window.h"
#include "tv.h"
#include "constants/decorations.h"
#include "constants/items.h"
#include "constants/metatile_behaviors.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/tv.h"
#include "event_data.h"

EWRAM_DATA struct MartInfo gMartInfo = {0};
EWRAM_DATA struct ShopData *gShopDataPtr = NULL;
EWRAM_DATA struct ListMenuItem *gUnknown_02039F74 = NULL;
EWRAM_DATA u8 (*gUnknown_02039F78)[16] = {0};
EWRAM_DATA u8 gMartPurchaseHistoryId = 0;
EWRAM_DATA struct ItemSlot gMartPurchaseHistory[3] = {0};

static void Task_ShopMenu(u8 taskId);
static void Task_HandleShopMenuQuit(u8 taskId);
static void Task_HandleEVShopMenuChooseAnotherMon(u8 taskId);
static void CB2_InitBuyEVMenu(void);
static void CB2_InitBuyMenu(void);
static void Task_GoToBuyOrSellMenu(u8 taskId);
static void MapPostLoadHook_ReturnToEVShopMenu(void);
static void MapPostLoadHook_ReturnToShopMenu(void);
static void Task_ReturnToEVShopMenu(u8 taskId);
static void Task_ReturnToShopMenu(u8 taskId);
static void ShowEVShopMenuAfterExitingBuyOrSellMenu(u8 taskId);
static void ShowShopMenuAfterExitingBuyOrSellMenu(u8 taskId);
static void BuyEVMenuDrawGraphics(void);
static void BuyMenuDrawGraphics(void);
static void BuyMenuAddScrollIndicatorArrows(void);
static void Task_BuyEVMenu(u8 taskId);
static void Task_BuyMenu(u8 taskId);
static void BuyEVMenuBuildListMenuTemplate(void);
static void BuyMenuBuildListMenuTemplate(void);
static void BuyEVMenuInitBgs(void);
static void BuyMenuInitBgs(void);
static void BuyMenuInitWindows(void);
static void BuyEVMenuDecompressBgGraphics(void);
static void BuyMenuDecompressBgGraphics(void);
static void BuyEVMenuSetListEntry(struct ListMenuItem *menuItem, u16 item, u8 *name);
static void BuyMenuSetListEntry(struct ListMenuItem*, u16, u8*);
static void BuyEVMenuAddMonIcon();
static void BuyMenuAddItemIcon(u16, u8);
static void BuyMenuRemoveItemIcon(u16, u8);
static void BuyMenuPrint(u8 windowId, const u8 *text, u8 x, u8 y, s8 speed, u8 colorSet);
static void BuyMenuDrawMapGraphics(void);
static void BuyMenuCopyMenuBgToBg1TilemapBuffer(void);
static void BuyMenuCollectEventObjectData(void);
static void BuyMenuDrawEventObjects(void);
static void BuyMenuDrawMapBg(void);
static bool8 BuyMenuCheckForOverlapWithMenuBg(int, int);
static void BuyMenuDrawMapMetatile(s16, s16, const u16*, u8);
static void BuyMenuDrawMapMetatileLayer(u16 *dest, s16 offset1, s16 offset2, const u16 *src);
static bool8 BuyMenuCheckIfEventObjectOverlapsMenuBg(s16 *);
static void ExitEVBuyMenu(u8 taskId);
static void ExitBuyMenu(u8 taskId);
static void Task_ExitBuyMenu(u8 taskId);
static void BuyEVMenuTryMakePurchase(u8 taskId);
static void BuyMenuTryMakePurchase(u8 taskId);
static void BuyEVMenuReturnToItemList(u8 taskId);
static void BuyMenuReturnToItemList(u8 taskId);
static void Task_BuyHowManyEVDialogueInit(u8 taskId);
static void Task_BuyHowManyDialogueInit(u8 taskId);
static void BuyEVMenuConfirmPurchase(u8 taskId);
static void BuyEVMenuConfirmSuboptimalEVs(u8 taskId);
static void BuyMenuConfirmPurchase(u8 taskId);
static void BuyEVMenuPrintItemQuantityAndPrice(u8 taskId);
static void BuyMenuPrintItemQuantityAndPrice(u8 taskId);
static void Task_BuyHowManyEVDialogueHandleInput(u8 taskId);
static void Task_BuyHowManyDialogueHandleInput(u8 taskId);
static void BuyMenuSubtractMoney(u8 taskId);
static void BuyEVMenuWaitForABAfterConfirming(u8 taskId);
static void RecordItemPurchase(u8 taskId);
static void Task_ReturnToItemListAfterItemPurchase(u8 taskId);
static void Task_ReturnToItemListAfterTMShopPurchase(u8 taskId);
static void Task_ReturnToItemListAfterDecorationPurchase(u8 taskId);
static void Task_ReturnToItemListAfterEVPurchase(u8 taskId);
static void Task_HandleShopMenuBuyEV(u8 taskId);
static void Task_HandleShopMenuBuy(u8 taskId);
static void Task_HandleShopMenuSell(u8 taskId);
static void BuyEVMenuPrintItemDescription(s32 item, bool8 onInit, struct ListMenu *list);
static void BuyMenuPrintItemDescriptionAndShowItemIcon(s32 item, bool8 onInit, struct ListMenu *list);
static void BuyEVMenuPrintEVsInList(u8 windowId, s32 item, u8 y, u8 itemPos);
static void BuyMenuPrintPriceInList(u8 windowId, s32 item, u8 y, u8 itemPos);

static const struct EVYesNoFuncTable sShopPurchaseEVYesNoFuncs =
{
    BuyEVMenuTryMakePurchase,
    BuyEVMenuReturnToItemList
};

static const struct EVYesNoFuncTable sShopConfirmSuboptimalEVYesNoFuncs =
{
    ExitEVBuyMenu,
    BuyEVMenuReturnToItemList
};

static const struct YesNoFuncTable sShopPurchaseYesNoFuncs =
{
    BuyMenuTryMakePurchase,
    BuyMenuReturnToItemList
};

static const struct MenuAction sShopMenuActions_BuyEVQuit[] =
{
    { gText_Yes, {.void_u8=Task_HandleEVShopMenuChooseAnotherMon} },
    { gText_No, {.void_u8=Task_HandleShopMenuQuit} }
};

static const struct MenuAction sShopMenuActions_BuySellQuit[] =
{
    { gText_ShopBuy, {.void_u8=Task_HandleShopMenuBuy} },
    { gText_ShopSell, {.void_u8=Task_HandleShopMenuSell} },
    { gText_ShopQuit, {.void_u8=Task_HandleShopMenuQuit} }
};

static const struct MenuAction sShopMenuActions_BuyQuit[] =
{
    { gText_ShopBuy, {.void_u8=Task_HandleShopMenuBuy} },
    { gText_ShopQuit, {.void_u8=Task_HandleShopMenuQuit} }
};

static const struct WindowTemplate sShopMenuWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 9,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x0008,
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 9,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x0008,
    }
};

static const struct ListMenuTemplate sEVShopBuyMenuListTemplate =
{
    .items = NULL,
    .moveCursorFunc = BuyEVMenuPrintItemDescription,
    .itemPrintFunc = BuyEVMenuPrintEVsInList,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 1,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 0,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 7,
    .cursorKind = 0
};

static const struct ListMenuTemplate sShopBuyMenuListTemplate =
{
    .items = NULL,
    .moveCursorFunc = BuyMenuPrintItemDescriptionAndShowItemIcon,
    .itemPrintFunc = BuyMenuPrintPriceInList,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 1,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 0,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 7,
    .cursorKind = 0
};

static const struct BgTemplate sEVShopBuyMenuBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct BgTemplate sShopBuyMenuBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate sShopBuyMenuWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x001E,
    },
    {
        .bg = 0,
        .tilemapLeft = 14,
        .tilemapTop = 2,
        .width = 15,
        .height = 16,
        .paletteNum = 15,
        .baseBlock = 0x0032,
    },
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 13,
        .width = 14,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x0122,
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 11,
        .width = 12,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x0176,
    },
    {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 11,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x018E,
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x01A2,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sShopBuyMenuYesNoWindowTemplates =
{
    .bg = 0,
    .tilemapLeft = 21,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x020E,
};

static const u8 sShopBuyMenuTextColors[][3] =
{
    {1, 2, 3},
    {0, 2, 3},
    {0, 3, 2}
};

static u8 CreateEVShopMenu(bool8 first_time)
{

    ScriptContext2_Enable();
    gMartInfo.martType = MART_TYPE_NORMAL;

    if (!first_time) {
        int numMenuItems;
        struct WindowTemplate winTemplate;
 
        winTemplate = sShopMenuWindowTemplates[1];
        winTemplate.width = GetMaxWidthInMenuTable(sShopMenuActions_BuyEVQuit, ARRAY_COUNT(sShopMenuActions_BuyEVQuit));
        gMartInfo.windowId = AddWindow(&winTemplate);
        gMartInfo.menuActions = sShopMenuActions_BuyEVQuit;
        numMenuItems = ARRAY_COUNT(sShopMenuActions_BuyEVQuit);

        SetStandardWindowBorderStyle(gMartInfo.windowId, 0);
        PrintMenuTable(gMartInfo.windowId, numMenuItems, gMartInfo.menuActions);
        InitMenuInUpperLeftCornerPlaySoundWhenAPressed(gMartInfo.windowId, numMenuItems, 0);
        PutWindowTilemap(gMartInfo.windowId);
        CopyWindowToVram(gMartInfo.windowId, 1);

        return CreateTask(Task_ShopMenu, 8);
    } else
        return CreateTask(Task_HandleShopMenuBuyEV, 8);
}

static u8 CreateShopMenu(u8 martType)
{
    int numMenuItems;

    ScriptContext2_Enable();
    gMartInfo.martType = martType;

   if (martType == MART_TYPE_NORMAL || martType == MART_TYPE_TM)
    {
        struct WindowTemplate winTemplate;
        winTemplate = sShopMenuWindowTemplates[0];
        winTemplate.width = GetMaxWidthInMenuTable(sShopMenuActions_BuySellQuit, ARRAY_COUNT(sShopMenuActions_BuySellQuit));
        gMartInfo.windowId = AddWindow(&winTemplate);
        gMartInfo.menuActions = sShopMenuActions_BuySellQuit;
        numMenuItems = ARRAY_COUNT(sShopMenuActions_BuySellQuit);
    }
    else
    {
        struct WindowTemplate winTemplate;
        winTemplate = sShopMenuWindowTemplates[1];
        winTemplate.width = GetMaxWidthInMenuTable(sShopMenuActions_BuyQuit, ARRAY_COUNT(sShopMenuActions_BuyQuit));
        gMartInfo.windowId = AddWindow(&winTemplate);
        gMartInfo.menuActions = sShopMenuActions_BuyQuit;
        numMenuItems = ARRAY_COUNT(sShopMenuActions_BuyQuit);
    }

    SetStandardWindowBorderStyle(gMartInfo.windowId, 0);
    PrintMenuTable(gMartInfo.windowId, numMenuItems, gMartInfo.menuActions);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(gMartInfo.windowId, numMenuItems, 0);
    PutWindowTilemap(gMartInfo.windowId);
    CopyWindowToVram(gMartInfo.windowId, 1);

    return CreateTask(Task_ShopMenu, 8);
}

static void SetShopMenuCallback(void (* callback)(void))
{
    gMartInfo.callback = callback;
}

static void SetShopItemsForSale(const u16 *items)
{
    u16 i = 0;

    gMartInfo.itemList = items;
    gMartInfo.itemCount = 0;

    while (gMartInfo.itemList[i])
    {
        gMartInfo.itemCount++;
        i++;
    }
}


static void SetTMShopItemsForSale(const u16 *items)
{
    u16 i = 0;

    gMartInfo.itemList = items;
    gMartInfo.itemCount = 0;

    while (i < TMSHOP_ITEMS_COUNT && gMartInfo.itemList[i])
    {
        gMartInfo.itemCount++;
        i++;
    }
}

static void SetShopId(u8 shopId)
{
    gMartInfo.shopId = shopId;
}

static void SetEVShopItemsForSale(const u16 *items)
{
    u16 i = 0;

    gMartInfo.itemList = items;
    gMartInfo.itemCount = 0;

    while (gMartInfo.itemList[i])
    {
        gMartInfo.itemCount++;
        i++;
    }
}

static void Task_ShopMenu(u8 taskId)
{
    s8 inputCode = Menu_ProcessInputNoWrap();
    switch (inputCode)
    {
    case MENU_NOTHING_CHOSEN:
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        Task_HandleShopMenuQuit(taskId);
        break;
    default:
        gMartInfo.menuActions[inputCode].func.void_u8(taskId);
        break;
    }
}

static void Task_HandleShopMenuBuyEV(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[8] = (u32)CB2_InitBuyEVMenu >> 16;
    data[9] = (u32)CB2_InitBuyEVMenu;
    gTasks[taskId].func = Task_GoToBuyOrSellMenu;
    FadeScreen(FADE_TO_BLACK, 0);
}

static void Task_HandleShopMenuBuy(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[8] = (u32)CB2_InitBuyMenu >> 16;
    data[9] = (u32)CB2_InitBuyMenu;
    gTasks[taskId].func = Task_GoToBuyOrSellMenu;
    FadeScreen(FADE_TO_BLACK, 0);
}

static void Task_HandleShopMenuSell(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[8] = (u32)CB2_GoToSellMenu >> 16;
    data[9] = (u32)CB2_GoToSellMenu;
    gTasks[taskId].func = Task_GoToBuyOrSellMenu;
    FadeScreen(FADE_TO_BLACK, 0);
}

void CB2_ExitSellMenu(void)
{
    gFieldCallback = MapPostLoadHook_ReturnToShopMenu;
    SetMainCallback2(CB2_ReturnToField);
}

static void Task_HandleShopMenuQuit(u8 taskId)
{
    ClearStdWindowAndFrameToTransparent(gMartInfo.windowId, 2);
    RemoveWindow(gMartInfo.windowId);
    SaveRecordedItemPurchasesForTVShow();
    ScriptContext2_Disable();
    DestroyTask(taskId);

    if (gMartInfo.callback)
        gMartInfo.callback();
}

static void Task_HandleEVShopMenuChooseAnotherMon(u8 taskId)
{
    gSpecialVar_0x8004 = 200; // Esto le indica al script que quiere elegir otro mon
    Task_HandleShopMenuQuit(taskId);
}

static void Task_GoToBuyOrSellMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        SetMainCallback2((void *)((u16)data[8] << 16 | (u16)data[9]));
    }
}

static void MapPostLoadHook_ReturnToEVShopMenu(void)
{
    FadeInFromBlack();
    CreateTask(Task_ReturnToEVShopMenu, 8);
}

static void MapPostLoadHook_ReturnToShopMenu(void)
{
    FadeInFromBlack();
    CreateTask(Task_ReturnToShopMenu, 8);
}

static void Task_ReturnToEVShopMenu(u8 taskId)
{
    if (IsWeatherNotFadingIn() == TRUE)
    {
        if (gMartInfo.martType == MART_TYPE_DECOR2)
            DisplayItemMessageOnField(taskId, gText_CanIHelpWithAnythingElse, ShowEVShopMenuAfterExitingBuyOrSellMenu);
        else
            DisplayItemMessageOnField(taskId, gText_DoYouWantToSetEVsOfAnotherMon, ShowEVShopMenuAfterExitingBuyOrSellMenu);
    }
}

static void Task_ReturnToShopMenu(u8 taskId)
{
    if (IsWeatherNotFadingIn() == TRUE)
    {
        if (gMartInfo.martType == MART_TYPE_DECOR2)
            DisplayItemMessageOnField(taskId, gText_CanIHelpWithAnythingElse, ShowShopMenuAfterExitingBuyOrSellMenu);
        else
            DisplayItemMessageOnField(taskId, gText_AnythingElseICanHelp, ShowShopMenuAfterExitingBuyOrSellMenu);
    }
}

static void ShowEVShopMenuAfterExitingBuyOrSellMenu(u8 taskId)
{
    CreateEVShopMenu(FALSE);
    DestroyTask(taskId);
}

static void ShowShopMenuAfterExitingBuyOrSellMenu(u8 taskId)
{
    CreateShopMenu(gMartInfo.martType);
    DestroyTask(taskId);
}

static void CB2_BuyMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

static void VBlankCB_BuyMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

#define tItemCount data[1]
#define tItemId data[5]
#define tListTaskId data[7]

static void CB2_InitBuyEVMenu(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        CpuFastFill(0, (void *)OAM, OAM_SIZE);
        ScanlineEffect_Stop();
        reset_temp_tile_data_buffers();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        clear_scheduled_bg_copies_to_vram();
        gShopDataPtr = AllocZeroed(sizeof(struct ShopData));
        gShopDataPtr->scrollIndicatorsTaskId = 0xFF;
        gShopDataPtr->itemSpriteIds[0] = 0xFF;
        gShopDataPtr->itemSpriteIds[1] = 0xFF;
        BuyEVMenuBuildListMenuTemplate();
        BuyEVMenuInitBgs();
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 0x20, 0x20);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 0x20, 0x20);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 0x20, 0x20);
        BuyMenuInitWindows();
        BuyEVMenuDecompressBgGraphics();
        BuyEVMenuAddMonIcon();
        gMain.state++;
        break;
    case 1:
        if (!free_temp_tile_data_buffers_if_possible())
            gMain.state++;
        break;
    default:
        BuyEVMenuDrawGraphics();
        BuyMenuAddScrollIndicatorArrows();
        taskId = CreateTask(Task_BuyEVMenu, 8);
        gTasks[taskId].tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
        BlendPalettes(0xFFFFFFFF, 0x10, RGB_BLACK);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB_BuyMenu);
        SetMainCallback2(CB2_BuyMenu);
        break;
    }
}

static void CB2_InitBuyMenu(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        CpuFastFill(0, (void *)OAM, OAM_SIZE);
        ScanlineEffect_Stop();
        reset_temp_tile_data_buffers();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        clear_scheduled_bg_copies_to_vram();
        gShopDataPtr = AllocZeroed(sizeof(struct ShopData));
        gShopDataPtr->scrollIndicatorsTaskId = 0xFF;
        gShopDataPtr->itemSpriteIds[0] = 0xFF;
        gShopDataPtr->itemSpriteIds[1] = 0xFF;
        BuyMenuBuildListMenuTemplate();
        BuyMenuInitBgs();
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 0x20, 0x20);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 0x20, 0x20);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 0x20, 0x20);
        BuyMenuInitWindows();
        BuyMenuDecompressBgGraphics();
        gMain.state++;
        break;
    case 1:
        if (!free_temp_tile_data_buffers_if_possible())
            gMain.state++;
        break;
    default:
        BuyMenuDrawGraphics();
        BuyMenuAddScrollIndicatorArrows();
        taskId = CreateTask(Task_BuyMenu, 8);
        gTasks[taskId].tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
        BlendPalettes(0xFFFFFFFF, 0x10, RGB_BLACK);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB_BuyMenu);
        SetMainCallback2(CB2_BuyMenu);
        break;
    }
}

static void BuyMenuFreeMemory(void)
{
    Free(gShopDataPtr);
    Free(gUnknown_02039F74);
    Free(gUnknown_02039F78);
    FreeAllWindowBuffers();
}

static void BuyEVMenuBuildListMenuTemplate(void)
{
    u16 i;
    u16 itemCount;

    gUnknown_02039F74 = Alloc((gMartInfo.itemCount + 1) * sizeof(*gUnknown_02039F74));
    gUnknown_02039F78 = Alloc((gMartInfo.itemCount + 1) * sizeof(*gUnknown_02039F78));
    for (i = 0; i < gMartInfo.itemCount; i++)
        BuyEVMenuSetListEntry(&gUnknown_02039F74[i], gMartInfo.itemList[i], gUnknown_02039F78[i]);

    StringCopy(gUnknown_02039F78[i], gText_Confirm3);
    gUnknown_02039F74[i].name = gUnknown_02039F78[i];
    gUnknown_02039F74[i].id = -2;

    gMultiuseListMenuTemplate = sEVShopBuyMenuListTemplate;
    gMultiuseListMenuTemplate.items = gUnknown_02039F74;
    gMultiuseListMenuTemplate.totalItems = gMartInfo.itemCount + 1;
    if (gMultiuseListMenuTemplate.totalItems > 8)
        gMultiuseListMenuTemplate.maxShowed = 8;
    else
        gMultiuseListMenuTemplate.maxShowed = gMultiuseListMenuTemplate.totalItems;

    gShopDataPtr->itemsShowed = gMultiuseListMenuTemplate.maxShowed;
}

static void BuyMenuBuildListMenuTemplate(void)
{
    u16 i;
    u16 itemCount;

    gUnknown_02039F74 = Alloc((gMartInfo.itemCount + 1) * sizeof(*gUnknown_02039F74));
    gUnknown_02039F78 = Alloc((gMartInfo.itemCount + 1) * sizeof(*gUnknown_02039F78));
    for (i = 0; i < gMartInfo.itemCount; i++)
        BuyMenuSetListEntry(&gUnknown_02039F74[i], gMartInfo.itemList[i], gUnknown_02039F78[i]);

    StringCopy(gUnknown_02039F78[i], gText_Cancel2);
    gUnknown_02039F74[i].name = gUnknown_02039F78[i];
    gUnknown_02039F74[i].id = -2;

    gMultiuseListMenuTemplate = sShopBuyMenuListTemplate;
    gMultiuseListMenuTemplate.items = gUnknown_02039F74;
    gMultiuseListMenuTemplate.totalItems = gMartInfo.itemCount + 1;
    if (gMultiuseListMenuTemplate.totalItems > 8)
        gMultiuseListMenuTemplate.maxShowed = 8;
    else
        gMultiuseListMenuTemplate.maxShowed = gMultiuseListMenuTemplate.totalItems;

    gShopDataPtr->itemsShowed = gMultiuseListMenuTemplate.maxShowed;
}

static const u8* const sEVShopItems[] =
{
    gText_HP3,
	gText_Attack,
	gText_Defense,
	gText_Speed,
	gText_SpAtk,
	gText_SpDef
};

static void BuyEVMenuSetListEntry(struct ListMenuItem *menuItem, u16 item, u8 *name)
{
	u8 itemNo;
	if (itemNo > 5) itemNo = 0;
	if (gMartInfo.martType == MART_TYPE_NORMAL)
		CopyItemName(item, name);
	else
		StringCopy(name, gDecorations[item].name);

	menuItem->name = sEVShopItems[itemNo];
	itemNo++;
	menuItem->id = item;
}

static void BuyMenuSetListEntry(struct ListMenuItem *menuItem, u16 item, u8 *name)
{
    if (gMartInfo.martType == MART_TYPE_NORMAL || gMartInfo.martType == MART_TYPE_TM)
        CopyItemName(item, name);
    else
        StringCopy(name, gDecorations[item].name);

    menuItem->name = name;
    menuItem->id = item;
}

static void BuyEVMenuPrintItemDescription(s32 item, bool8 onInit, struct ListMenu *list)
{
    const u8 *description;

    u8 pos = gSpecialVar_0x8004;
    u8  hp = GetMonData(&gPlayerParty[pos], MON_DATA_HP_EV, NULL);
    u8 atk = GetMonData(&gPlayerParty[pos], MON_DATA_ATK_EV, NULL);
    u8 def = GetMonData(&gPlayerParty[pos], MON_DATA_DEF_EV, NULL);
    u8 spe = GetMonData(&gPlayerParty[pos], MON_DATA_SPEED_EV, NULL);
    u8 spa = GetMonData(&gPlayerParty[pos], MON_DATA_SPATK_EV, NULL);
    u8 spd = GetMonData(&gPlayerParty[pos], MON_DATA_SPDEF_EV, NULL);
    s16 remaining = 510 - hp - atk - def - spe - spa - spd;
    if (remaining < 0) remaining = 0;

    if (onInit != TRUE)
        PlaySE(SE_SELECT);


    ConvertIntToDecimalStringN(gStringVar1, remaining, STR_CONV_MODE_RIGHT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_UnassignedEVsVar1);
    description = gStringVar4;

    FillWindowPixelBuffer(2, PIXEL_FILL(0));
    BuyMenuPrint(2, description, 3, 1, 0, 0);

    if (list->selectedRow < 6 && ((hp % 4) + (atk % 4) + (def % 4) + (spe % 4) + (spa % 4) + (spd % 4)) > 2)
    {
        u8 evs_wasted_in_current_stat = (GetMonData(&gPlayerParty[pos], MON_DATA_HP_EV + list->selectedRow, NULL) % 4);
        if (evs_wasted_in_current_stat)
        {
            ConvertIntToDecimalStringN(gStringVar1, evs_wasted_in_current_stat, STR_CONV_MODE_LEFT_ALIGN, 1);
            StringExpandPlaceholders(gStringVar4, gText_WastedEVsInThisStatVar1);
            BuyMenuPrint(2, gStringVar4, 3, 17, 0, 0);
        }
    }
}

static void BuyMenuPrintItemDescriptionAndShowItemIcon(s32 item, bool8 onInit, struct ListMenu *list)
{
    const u8 *description;
    if (onInit != TRUE)
        PlaySE(SE_SELECT);

    if (item != -2)
        BuyMenuAddItemIcon(item, gShopDataPtr->iconSlot);
    else
        BuyMenuAddItemIcon(-1, gShopDataPtr->iconSlot);

    BuyMenuRemoveItemIcon(item, gShopDataPtr->iconSlot ^ 1);
    gShopDataPtr->iconSlot ^= 1;
    if (item != -2)
    {
       if (gMartInfo.martType == MART_TYPE_NORMAL || gMartInfo.martType == MART_TYPE_TM)
            description = ItemId_GetDescription(item);
        else
            description = gDecorations[item].description;
    }
    else
    {
        description = gText_QuitShopping;
    }

    FillWindowPixelBuffer(2, PIXEL_FILL(0));
    BuyMenuPrint(2, description, 3, 1, 0, 0);
}

// TM Shop
bool8 GetSetItemBought(u8 storeId, u16 itemPos, u8 caseId)
{
    u16 mask;

    mask = 1 << itemPos;
    switch (caseId)
    {
    case FLAG_GET_BOUGHT:
        return (gSaveBlock2Ptr->tmShopFlags[storeId] & mask) != 0;
    case FLAG_SET_BOUGHT:
        gSaveBlock2Ptr->tmShopFlags[storeId] |= mask;
        return TRUE;
    }

    return FALSE;
}

static void BuyEVMenuPrintEVsInList(u8 windowId, s32 item, u8 y, u8 itemPos)
{
    u8 x;
    u8 pos = gSpecialVar_0x8004;
    u16 currentstat = GetMonData(&gPlayerParty[pos], MON_DATA_HP_EV + itemPos, NULL);

    if (item != -2)
    {
        ConvertIntToDecimalStringN(gStringVar1, currentstat, STR_CONV_MODE_RIGHT_ALIGN, 3);
        x = GetStringRightAlignXOffset(7, gStringVar1, 0x58);
        AddTextPrinterParameterized4(windowId, 7, x, y, 0, 0, sShopBuyMenuTextColors[1], -1, gStringVar1);
        
        currentstat = GetMonData(&gPlayerParty[pos], MON_DATA_MAX_HP + itemPos, NULL);
        ConvertIntToDecimalStringN(gStringVar1, currentstat, STR_CONV_MODE_RIGHT_ALIGN, 3);
        x = GetStringRightAlignXOffset(7, gStringVar1, 0x78);
        AddTextPrinterParameterized4(windowId, 7, x, y, 0, 0, sShopBuyMenuTextColors[1], -1, gStringVar1);
    }
}

static void BuyMenuPrintPriceInList(u8 windowId, s32 item, u8 y, u8 itemPos)
{
    u8 x;

    if (item != -2)
    {
        if (gMartInfo.martType == MART_TYPE_NORMAL)
        {
            ConvertIntToDecimalStringN(
                gStringVar1,
                ItemId_GetPrice(item) >> GetPriceReduction(POKENEWS_SLATEPORT),
                STR_CONV_MODE_LEFT_ALIGN,
                5);
            StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
        }
        else if (gMartInfo.martType == MART_TYPE_TM)
        {
            if (GetSetItemBought(gMartInfo.shopId, itemPos, FLAG_GET_BOUGHT))
            {
                StringCopy(gStringVar1, gText_SoldOut);
                StringExpandPlaceholders(gStringVar4, gText_StrVar1);
            }
            else
            {
                ConvertIntToDecimalStringN(
                    gStringVar1,
                    ItemId_GetPrice(item) >> GetPriceReduction(POKENEWS_SLATEPORT),
                    STR_CONV_MODE_LEFT_ALIGN,
                    5);
                StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
            }	
        }
        else
        {
            ConvertIntToDecimalStringN(
                gStringVar1,
                gDecorations[item].price,
                STR_CONV_MODE_LEFT_ALIGN,
                5);
		 StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
        }

        x = GetStringRightAlignXOffset(7, gStringVar4, 0x78);
        AddTextPrinterParameterized4(windowId, 7, x, y, 0, 0, sShopBuyMenuTextColors[1], -1, gStringVar4);
    }
}

static void BuyMenuAddScrollIndicatorArrows(void)
{
    if (gShopDataPtr->scrollIndicatorsTaskId == 0xFF && gMartInfo.itemCount + 1 > 8)
    {
        gShopDataPtr->scrollIndicatorsTaskId = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP,
            0xAC,
            0xC,
            0x94,
            gMartInfo.itemCount - 7,
            2100,
            2100,
            &gShopDataPtr->scrollOffset);
    }
}

static void BuyMenuRemoveScrollIndicatorArrows(void)
{
    if (gShopDataPtr->scrollIndicatorsTaskId != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(gShopDataPtr->scrollIndicatorsTaskId);
        gShopDataPtr->scrollIndicatorsTaskId = 0xFF;
    }
}

static void BuyMenuPrintCursor(u8 scrollIndicatorsTaskId, u8 colorSet)
{
    u8 y = ListMenuGetYCoordForPrintingArrowCursor(scrollIndicatorsTaskId);
    BuyMenuPrint(1, gText_SelectorArrow2, 0, y, 0, colorSet);
}

static void BuyEVMenuAddMonIcon()
{
    u8 spriteId;
    u8 *spriteIdPtr = &gShopDataPtr->itemSpriteIds[0];
    u8 pos = gSpecialVar_0x8004;
    u16 species = GetMonData(&gPlayerParty[pos], MON_DATA_SPECIES2);
    
    if (*spriteIdPtr != 0xFF)
        return;

    LoadMonIconPalette(species);
    spriteId = CreateMonIcon(species, SpriteCB_MonIcon, 20, 81, 4, GetMonData(&gPlayerParty[pos], MON_DATA_PERSONALITY), FALSE);
    if (spriteId != MAX_SPRITES)
    {
        *spriteIdPtr = spriteId;
        gSprites[spriteId].oam.priority = 1;
    }
}

static void BuyMenuAddItemIcon(u16 item, u8 iconSlot)
{
    u8 spriteId;
    u8 *spriteIdPtr = &gShopDataPtr->itemSpriteIds[iconSlot];
    if (*spriteIdPtr != 0xFF)
        return;

    if (gMartInfo.martType == MART_TYPE_NORMAL || gMartInfo.martType == MART_TYPE_TM || item == 0xFFFF)
    {
        spriteId = AddItemIconSprite(iconSlot + 2110, iconSlot + 2110, item);
        if (spriteId != MAX_SPRITES)
        {
            *spriteIdPtr = spriteId;
            gSprites[spriteId].pos2.x = 24;
            gSprites[spriteId].pos2.y = 88;
        }
    }
    else
    {
        spriteId = AddDecorationIconObject(item, 20, 84, 1, iconSlot + 2110, iconSlot + 2110);
        if (spriteId != MAX_SPRITES)
            *spriteIdPtr = spriteId;
    }
}

static void BuyMenuRemoveItemIcon(u16 item, u8 iconSlot)
{
    u8 *spriteIdPtr = &gShopDataPtr->itemSpriteIds[iconSlot];
    if (*spriteIdPtr == 0xFF)
        return;

    FreeSpriteTilesByTag(iconSlot + 2110);
    FreeSpritePaletteByTag(iconSlot + 2110);
    DestroySprite(&gSprites[*spriteIdPtr]);
    *spriteIdPtr = 0xFF;
}

static void BuyEVMenuInitBgs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sEVShopBuyMenuBgTemplates, ARRAY_COUNT(sEVShopBuyMenuBgTemplates));
    SetBgTilemapBuffer(1, gShopDataPtr->tilemapBuffers[1]);
    SetBgTilemapBuffer(2, gShopDataPtr->tilemapBuffers[3]);
    SetBgTilemapBuffer(3, gShopDataPtr->tilemapBuffers[2]);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

static void BuyMenuInitBgs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sShopBuyMenuBgTemplates, ARRAY_COUNT(sShopBuyMenuBgTemplates));
    SetBgTilemapBuffer(1, gShopDataPtr->tilemapBuffers[1]);
    SetBgTilemapBuffer(2, gShopDataPtr->tilemapBuffers[3]);
    SetBgTilemapBuffer(3, gShopDataPtr->tilemapBuffers[2]);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

static void BuyEVMenuDecompressBgGraphics(void)
{
    decompress_and_copy_tile_data_to_vram(1, gBuyEVMenuFrame_Gfx, 0x3A0, 0x3E3, 0);
    LZDecompressWram(gBuyMenuFrame_Tilemap, gShopDataPtr->tilemapBuffers[0]);
    LoadCompressedPalette(gMenuMoneyPal, 0xC0, 0x20);
}

static void BuyMenuDecompressBgGraphics(void)
{
    decompress_and_copy_tile_data_to_vram(1, gBuyMenuFrame_Gfx, 0x3A0, 0x3E3, 0);
    LZDecompressWram(gBuyMenuFrame_Tilemap, gShopDataPtr->tilemapBuffers[0]);
    LoadCompressedPalette(gMenuMoneyPal, 0xC0, 0x20);
}

static void BuyMenuInitWindows(void)
{
    InitWindows(sShopBuyMenuWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 1, 0xD0);
    LoadMessageBoxGfx(0, 0xA, 0xE0);
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    PutWindowTilemap(2);
}

static void BuyMenuPrint(u8 windowId, const u8 *text, u8 x, u8 y, s8 speed, u8 colorSet)
{
    AddTextPrinterParameterized4(windowId, 1, x, y, 0, 0, sShopBuyMenuTextColors[colorSet], speed, text);
}

static void BuyMenuDisplayMessage(u8 taskId, const u8 *text, TaskFunc callback)
{
    DisplayMessageAndContinueTask(taskId, 5, 10, 14, 1, GetPlayerTextSpeedDelay(), text, callback);
    schedule_bg_copy_tilemap_to_vram(0);
}

static void BuyEVMenuDrawGraphics(void)
{
    BuyMenuDrawMapGraphics();
    BuyMenuCopyMenuBgToBg1TilemapBuffer();
    schedule_bg_copy_tilemap_to_vram(0);
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
    schedule_bg_copy_tilemap_to_vram(3);
}

static void BuyMenuDrawGraphics(void)
{
    BuyMenuDrawMapGraphics();
    BuyMenuCopyMenuBgToBg1TilemapBuffer();
    AddMoneyLabelObject(19, 11);
    PrintMoneyAmountInMoneyBoxWithBorder(0, 1, 13, GetMoney(&gSaveBlock1Ptr->money));
    schedule_bg_copy_tilemap_to_vram(0);
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
    schedule_bg_copy_tilemap_to_vram(3);
}

static void BuyMenuDrawMapGraphics(void)
{
    BuyMenuCollectEventObjectData();
    BuyMenuDrawEventObjects();
    BuyMenuDrawMapBg();
}

static void BuyMenuDrawMapBg(void)
{
    s16 i;
    s16 j;
    s16 x;
    s16 y;
    const struct MapLayout *mapLayout;
    u16 metatile;
    u8 metatileLayerType;

    mapLayout = gMapHeader.mapLayout;
    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    x -= 4;
    y -= 4;

    for (j = 0; j < 10; j++)
    {
        for (i = 0; i < 15; i++)
        {
            metatile = MapGridGetMetatileIdAt(x + i, y + j);
            if (BuyMenuCheckForOverlapWithMenuBg(i, j) == TRUE)
                metatileLayerType = MapGridGetMetatileLayerTypeAt(x + i, y + j);
            else
                metatileLayerType = 1;

            if (metatile < NUM_METATILES_IN_PRIMARY)
            {
                BuyMenuDrawMapMetatile(i, j, (u16*)mapLayout->primaryTileset->metatiles + metatile * 8, metatileLayerType);
            }
            else
            {
                BuyMenuDrawMapMetatile(i, j, (u16*)mapLayout->secondaryTileset->metatiles + ((metatile - NUM_METATILES_IN_PRIMARY) * 8), metatileLayerType);
            }
        }
    }
}

static void BuyMenuDrawMapMetatile(s16 x, s16 y, const u16 *src, u8 metatileLayerType)
{
    u16 offset1 = x * 2;
    u16 offset2 = y * 64;

    switch (metatileLayerType)
    {
    case 0:
        BuyMenuDrawMapMetatileLayer(gShopDataPtr->tilemapBuffers[3], offset1, offset2, src);
        BuyMenuDrawMapMetatileLayer(gShopDataPtr->tilemapBuffers[1], offset1, offset2, src + 4);
        break;
    case 1:
        BuyMenuDrawMapMetatileLayer(gShopDataPtr->tilemapBuffers[2], offset1, offset2, src);
        BuyMenuDrawMapMetatileLayer(gShopDataPtr->tilemapBuffers[3], offset1, offset2, src + 4);
        break;
    case 2:
        BuyMenuDrawMapMetatileLayer(gShopDataPtr->tilemapBuffers[2], offset1, offset2, src);
        BuyMenuDrawMapMetatileLayer(gShopDataPtr->tilemapBuffers[1], offset1, offset2, src + 4);
        break;
    }
}

static void BuyMenuDrawMapMetatileLayer(u16 *dest, s16 offset1, s16 offset2, const u16 *src)
{
    // This function draws a whole 2x2 metatile.
    dest[offset1 + offset2] = src[0]; // top left
    dest[offset1 + offset2 + 1] = src[1]; // top right
    dest[offset1 + offset2 + 32] = src[2]; // bottom left
    dest[offset1 + offset2 + 33] = src[3]; // bottom right
}

static void BuyMenuCollectEventObjectData(void)
{
    s16 facingX;
    s16 facingY;
    u8 y;
    u8 x;
    u8 r8 = 0;

    GetXYCoordsOneStepInFrontOfPlayer(&facingX, &facingY);
    for (y = 0; y < 16; y++)
        gShopDataPtr->viewportObjects[y][EVENT_OBJ_ID] = 16;
    for (y = 0; y < 5; y++)
    {
        for (x = 0; x < 7; x++)
        {
            u8 eventObjId = GetEventObjectIdByXY(facingX - 4 + x, facingY - 2 + y);

            if (eventObjId != 16)
            {
                gShopDataPtr->viewportObjects[r8][EVENT_OBJ_ID] = eventObjId;
                gShopDataPtr->viewportObjects[r8][X_COORD] = x;
                gShopDataPtr->viewportObjects[r8][Y_COORD] = y;
                gShopDataPtr->viewportObjects[r8][LAYER_TYPE] = MapGridGetMetatileLayerTypeAt(facingX - 4 + x, facingY - 2 + y);

                switch (gEventObjects[eventObjId].facingDirection)
                {
                    case DIR_SOUTH:
                        gShopDataPtr->viewportObjects[r8][ANIM_NUM] = 0;
                        break;
                    case DIR_NORTH:
                        gShopDataPtr->viewportObjects[r8][ANIM_NUM] = 1;
                        break;
                    case DIR_WEST:
                        gShopDataPtr->viewportObjects[r8][ANIM_NUM] = 2;
                        break;
                    case DIR_EAST:
                    default:
                        gShopDataPtr->viewportObjects[r8][ANIM_NUM] = 3;
                        break;
                }
                r8++;
            }
        }
    }
}

static void BuyMenuDrawEventObjects(void)
{
    u8 i;
    u8 spriteId;
    const struct EventObjectGraphicsInfo *graphicsInfo;

    for (i = 0; i < 16; i++) // max objects?
    {
        if (gShopDataPtr->viewportObjects[i][EVENT_OBJ_ID] == 16)
            continue;

        graphicsInfo = GetEventObjectGraphicsInfo(gEventObjects[gShopDataPtr->viewportObjects[i][EVENT_OBJ_ID]].graphicsId);

        spriteId = AddPseudoEventObject(
            gEventObjects[gShopDataPtr->viewportObjects[i][EVENT_OBJ_ID]].graphicsId,
            SpriteCallbackDummy,
            (u16)gShopDataPtr->viewportObjects[i][X_COORD] * 16 + 8,
            (u16)gShopDataPtr->viewportObjects[i][Y_COORD] * 16 + 48 - graphicsInfo->height / 2,
            2);

        if (BuyMenuCheckIfEventObjectOverlapsMenuBg(gShopDataPtr->viewportObjects[i]) == TRUE)
        {
            gSprites[spriteId].subspriteTableNum = 4;
            gSprites[spriteId].subspriteMode = SUBSPRITES_ON;
        }

        StartSpriteAnim(&gSprites[spriteId], gShopDataPtr->viewportObjects[i][ANIM_NUM]);
    }
}

static bool8 BuyMenuCheckIfEventObjectOverlapsMenuBg(s16 *object)
{
    if (!BuyMenuCheckForOverlapWithMenuBg(object[X_COORD], object[Y_COORD] + 2) && object[LAYER_TYPE] != MB_SECRET_BASE_WALL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void BuyMenuCopyMenuBgToBg1TilemapBuffer(void)
{
    s16 i;
    u16 *dest = gShopDataPtr->tilemapBuffers[1];
    const u16 *src = gShopDataPtr->tilemapBuffers[0];

    for (i = 0; i < 1024; i++)
    {
        if (src[i] != 0)
        {
            dest[i] = src[i] + 0xC3E3;
        }
    }
}

static bool8 BuyMenuCheckForOverlapWithMenuBg(int x, int y)
{
    const u16 *metatile = gShopDataPtr->tilemapBuffers[0];
    int offset1 = x * 2;
    int offset2 = y * 64;

    if (metatile[offset2 + offset1] == 0 &&
        metatile[offset2 + offset1 + 32] == 0 &&
        metatile[offset2 + offset1 + 1] == 0 &&
        metatile[offset2 + offset1 + 33] == 0)
    {
        return TRUE;
    }

    return FALSE;
}

static void Task_BuyEVMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        s32 itemId = ListMenu_ProcessInput(tListTaskId);
        ListMenuGetScrollAndRow(tListTaskId, &gShopDataPtr->scrollOffset, &gShopDataPtr->selectedRow);

        switch (itemId)
        {
        case LIST_NOTHING_CHOSEN:
            break;
        case LIST_CANCEL:
            PlaySE(SE_SELECT);
            
            {
                u8 pos = gSpecialVar_0x8004;
                u8  hp = GetMonData(&gPlayerParty[pos], MON_DATA_HP_EV, NULL);
                u8 atk = GetMonData(&gPlayerParty[pos], MON_DATA_ATK_EV, NULL);
                u8 def = GetMonData(&gPlayerParty[pos], MON_DATA_DEF_EV, NULL);
                u8 spe = GetMonData(&gPlayerParty[pos], MON_DATA_SPEED_EV, NULL);
                u8 spa = GetMonData(&gPlayerParty[pos], MON_DATA_SPATK_EV, NULL);
                u8 spd = GetMonData(&gPlayerParty[pos], MON_DATA_SPDEF_EV, NULL);
                
                u8 wasted_evs = (hp % 4) + (atk % 4) + (def % 4) + (spe % 4) + (spa % 4) + (spd % 4);
                
                if (wasted_evs > 2)
                {
                    ClearWindowTilemap(2);
                    ConvertIntToDecimalStringN(gStringVar1, wasted_evs, STR_CONV_MODE_LEFT_ALIGN, 2);
                    BuyMenuDisplayMessage(taskId, gText_Var1EVsAreWastedDoYouWantToConfirmThisEVSpread, BuyEVMenuConfirmSuboptimalEVs);
                }
                else
                    ExitEVBuyMenu(taskId);
            }
            break;
        default:
            PlaySE(SE_SELECT);
            tItemId = itemId;
            ClearWindowTilemap(2);
            BuyMenuRemoveScrollIndicatorArrows();
            BuyMenuPrintCursor(tListTaskId, 2);

            if (gMartInfo.martType == MART_TYPE_NORMAL)
            {
                gShopDataPtr->totalCost = (ItemId_GetPrice(itemId) >> GetPriceReduction(POKENEWS_SLATEPORT));
            }
            else
            {
                gShopDataPtr->totalCost = gDecorations[itemId].price;
            }

            if (!IsEnoughMoney(&gSaveBlock1Ptr->money, gShopDataPtr->totalCost))
            {
                BuyMenuDisplayMessage(taskId, gText_YouDontHaveMoney, BuyEVMenuReturnToItemList);
            }
            else
            {
                if (gMartInfo.martType == MART_TYPE_NORMAL)
                {
                    StringCopy(gStringVar1, sEVShopItems[gShopDataPtr->selectedRow]);
                    if (ItemId_GetPocket(itemId) == POCKET_TM_HM)
                    {
                        StringCopy(gStringVar2, gMoveNames[ItemIdToBattleMoveId(itemId)]);
                        BuyMenuDisplayMessage(taskId, gText_Var1CertainlyHowMany2, Task_BuyHowManyEVDialogueInit);
                    }
                    else
                    {
                        BuyMenuDisplayMessage(taskId, gText_Var1CertainlyHowMany, Task_BuyHowManyEVDialogueInit);
                    }
                }
                else
                {
                    StringCopy(gStringVar1, gDecorations[itemId].name);
                    ConvertIntToDecimalStringN(gStringVar2, gShopDataPtr->totalCost, STR_CONV_MODE_LEFT_ALIGN, 6);

                    if (gMartInfo.martType == MART_TYPE_DECOR)
                        StringExpandPlaceholders(gStringVar4, gText_Var1IsItThatllBeVar2);
                    else
                        StringExpandPlaceholders(gStringVar4, gText_YouWantedVar1);
                    BuyMenuDisplayMessage(taskId, gStringVar4, BuyEVMenuConfirmPurchase);
                }
            }
            break;
        }
    }
}

static void Task_BuyMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        s32 itemId = ListMenu_ProcessInput(tListTaskId);
        ListMenuGetScrollAndRow(tListTaskId, &gShopDataPtr->scrollOffset, &gShopDataPtr->selectedRow);

        switch (itemId)
        {
        case LIST_NOTHING_CHOSEN:
            break;
        case LIST_CANCEL:
            PlaySE(SE_SELECT);
            ExitBuyMenu(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            tItemId = itemId;
            ClearWindowTilemap(2);
            BuyMenuRemoveScrollIndicatorArrows();
            BuyMenuPrintCursor(tListTaskId, 2);

            if (gMartInfo.martType == MART_TYPE_NORMAL || gMartInfo.martType == MART_TYPE_TM)
            {
                gShopDataPtr->totalCost = (ItemId_GetPrice(itemId) >> GetPriceReduction(POKENEWS_SLATEPORT));
            }
            else
            {
                gShopDataPtr->totalCost = gDecorations[itemId].price;
            }

            if (!IsEnoughMoney(&gSaveBlock1Ptr->money, gShopDataPtr->totalCost))
            {
                BuyMenuDisplayMessage(taskId, gText_YouDontHaveMoney, BuyMenuReturnToItemList);
            }
	        else if (ItemId_GetPocket(itemId) == POCKET_TM_HM && CheckBagHasItem(itemId, 1))
            {
                BuyMenuDisplayMessage(taskId, gText_YouAlreadyHaveThis, BuyMenuReturnToItemList);
            }
            else
            {
                if (gMartInfo.martType == MART_TYPE_NORMAL)
                {
                    CopyItemName(itemId, gStringVar1);
                    if (ItemId_GetPocket(itemId) == POCKET_TM_HM)
                    {
                        StringCopy(gStringVar2, gMoveNames[ItemIdToBattleMoveId(itemId)]);
                        BuyMenuDisplayMessage(taskId, gText_Var1CertainlyHowMany2, Task_BuyHowManyDialogueInit);
                    }
                    else
                    {
                        BuyMenuDisplayMessage(taskId, gText_Var1CertainlyHowMany, Task_BuyHowManyDialogueInit);
                    }
                }
                else if (gMartInfo.martType == MART_TYPE_TM)
                {
                    CopyItemName(itemId, gStringVar1);

                    ConvertIntToDecimalStringN(gStringVar2, gShopDataPtr->totalCost, STR_CONV_MODE_LEFT_ALIGN, 6);

                    if (ItemId_GetPocket(itemId) == POCKET_TM_HM)
                    {
                        StringCopy(gStringVar4, gMoveNames[ItemIdToBattleMoveId(itemId)]);
                    }

                    StringExpandPlaceholders(gStringVar4, gText_YouWantedVar1ThatllBeVar2);

                    if (!GetSetItemBought(gMartInfo.shopId, gShopDataPtr->selectedRow + gShopDataPtr->scrollOffset, FLAG_GET_BOUGHT))
                    {
                        tItemCount = 1;
                        BuyMenuDisplayMessage(taskId, gStringVar4, BuyMenuConfirmPurchase);
                    }
                    else
                    {
                        BuyMenuDisplayMessage(taskId, gText_SorryWereOutOfThis, BuyMenuReturnToItemList);
                    }
                }
                else
                {
                    StringCopy(gStringVar1, gDecorations[itemId].name);
                    ConvertIntToDecimalStringN(gStringVar2, gShopDataPtr->totalCost, STR_CONV_MODE_LEFT_ALIGN, 6);

                    if (gMartInfo.martType == MART_TYPE_DECOR)
                        StringExpandPlaceholders(gStringVar4, gText_Var1IsItThatllBeVar2);
                    else
                        StringExpandPlaceholders(gStringVar4, gText_YouWantedVar1ThatllBeVar2);
                    BuyMenuDisplayMessage(taskId, gStringVar4, BuyMenuConfirmPurchase);
                }
            }
            break;
        }
    }
}

static void Task_BuyHowManyEVDialogueInit(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 pos = gSpecialVar_0x8004;
    u8  hp = GetMonData(&gPlayerParty[pos], MON_DATA_HP_EV, NULL);
    u8 atk = GetMonData(&gPlayerParty[pos], MON_DATA_ATK_EV, NULL);
    u8 def = GetMonData(&gPlayerParty[pos], MON_DATA_DEF_EV, NULL);
    u8 spe = GetMonData(&gPlayerParty[pos], MON_DATA_SPEED_EV, NULL);
    u8 spa = GetMonData(&gPlayerParty[pos], MON_DATA_SPATK_EV, NULL);
    u8 spd = GetMonData(&gPlayerParty[pos], MON_DATA_SPDEF_EV, NULL);

    u16 quantityInBag = CountTotalItemQuantityInBag(tItemId);
    u16 maxQuantity;
    s16 remaining;

    // DrawStdFrameWithCustomTileAndPalette(3, FALSE, 1, 13);
    // ConvertIntToDecimalStringN(gStringVar1, quantityInBag, STR_CONV_MODE_RIGHT_ALIGN, 4);
    // StringExpandPlaceholders(gStringVar4, gText_InBagVar1);
    // BuyMenuPrint(3, gStringVar4, 0, 1, 0, 0);
    tItemCount = GetMonData(&gPlayerParty[pos], MON_DATA_HP_EV + gShopDataPtr->selectedRow);
    DrawStdFrameWithCustomTileAndPalette(4, FALSE, 1, 13);
    BuyEVMenuPrintItemQuantityAndPrice(taskId);
    schedule_bg_copy_tilemap_to_vram(0);

    remaining = 508 - hp - atk - def - spe - spa - spd + tItemCount;

    if (remaining < 0) remaining = 0;
    if (remaining > 252) remaining = 252;
    maxQuantity = remaining;

    gShopDataPtr->maxQuantity = maxQuantity;

    gTasks[taskId].func = Task_BuyHowManyEVDialogueHandleInput;
}

static void Task_BuyHowManyDialogueInit(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u16 quantityInBag = CountTotalItemQuantityInBag(tItemId);
    u16 maxQuantity;

    DrawStdFrameWithCustomTileAndPalette(3, FALSE, 1, 13);
    ConvertIntToDecimalStringN(gStringVar1, quantityInBag, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_InBagVar1);
    BuyMenuPrint(3, gStringVar4, 0, 1, 0, 0);
    tItemCount = 1;
    DrawStdFrameWithCustomTileAndPalette(4, FALSE, 1, 13);
    BuyMenuPrintItemQuantityAndPrice(taskId);
    schedule_bg_copy_tilemap_to_vram(0);

    maxQuantity = GetMoney(&gSaveBlock1Ptr->money) / gShopDataPtr->totalCost;

    if (maxQuantity > MAX_BAG_ITEM_CAPACITY)
    {
        gShopDataPtr->maxQuantity = MAX_BAG_ITEM_CAPACITY;
    }
    else
    {
        gShopDataPtr->maxQuantity = maxQuantity;
    }

    gTasks[taskId].func = Task_BuyHowManyDialogueHandleInput;
}

static void Task_BuyHowManyEVDialogueHandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (AdjustEVQuantityAccordingToDPadInput(&tItemCount, gShopDataPtr->maxQuantity) == TRUE)
    {
        gShopDataPtr->totalCost = (ItemId_GetPrice(tItemId) >> GetPriceReduction(POKENEWS_SLATEPORT)) * tItemCount;
        BuyEVMenuPrintItemQuantityAndPrice(taskId);
    }
    else
    {
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            ClearStdWindowAndFrameToTransparent(4, 0);
            ClearStdWindowAndFrameToTransparent(3, 0);
            ClearWindowTilemap(4);
            ClearWindowTilemap(3);
            PutWindowTilemap(1);
            StringCopy(gStringVar1, sEVShopItems[gShopDataPtr->selectedRow]);
            ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, 3);
            ConvertIntToDecimalStringN(gStringVar3, gShopDataPtr->totalCost, STR_CONV_MODE_LEFT_ALIGN, 6);
            BuyMenuDisplayMessage(taskId, gText_DoYouWantToSetVar1EVToVar2, BuyEVMenuConfirmPurchase);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            ClearStdWindowAndFrameToTransparent(4, 0);
            ClearStdWindowAndFrameToTransparent(3, 0);
            ClearWindowTilemap(4);
            ClearWindowTilemap(3);
            BuyEVMenuReturnToItemList(taskId);
        }
    }
}

static void Task_BuyHowManyDialogueHandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, gShopDataPtr->maxQuantity) == TRUE)
    {
        gShopDataPtr->totalCost = (ItemId_GetPrice(tItemId) >> GetPriceReduction(POKENEWS_SLATEPORT)) * tItemCount;
        BuyMenuPrintItemQuantityAndPrice(taskId);
    }
    else
    {
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            ClearStdWindowAndFrameToTransparent(4, 0);
            ClearStdWindowAndFrameToTransparent(3, 0);
            ClearWindowTilemap(4);
            ClearWindowTilemap(3);
            PutWindowTilemap(1);
            CopyItemName(tItemId, gStringVar1);
            ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, 2);
            ConvertIntToDecimalStringN(gStringVar3, gShopDataPtr->totalCost, STR_CONV_MODE_LEFT_ALIGN, 6);
            BuyMenuDisplayMessage(taskId, gText_Var1AndYouWantedVar2, BuyMenuConfirmPurchase);
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            ClearStdWindowAndFrameToTransparent(4, 0);
            ClearStdWindowAndFrameToTransparent(3, 0);
            ClearWindowTilemap(4);
            ClearWindowTilemap(3);
            BuyMenuReturnToItemList(taskId);
        }
    }
}

static void BuyEVMenuConfirmPurchase(u8 taskId)
{
    CreateEVYesNoMenuWithCallbacks(taskId, &sShopBuyMenuYesNoWindowTemplates, 1, 0, 0, 1, 13, &sShopPurchaseEVYesNoFuncs);
}

static void BuyEVMenuConfirmSuboptimalEVs(u8 taskId)
{
    CreateEVYesNoMenuWithCallbacks(taskId, &sShopBuyMenuYesNoWindowTemplates, 1, 0, 0, 1, 13, &sShopConfirmSuboptimalEVYesNoFuncs);
}

static void BuyMenuConfirmPurchase(u8 taskId)
{
    CreateYesNoMenuWithCallbacks(taskId, &sShopBuyMenuYesNoWindowTemplates, 1, 0, 0, 1, 13, &sShopPurchaseYesNoFuncs);
}

static void BuyEVMenuTryMakePurchase(u8 taskId)
{
	s16 *data = gTasks[taskId].data;
	u8 pos = gSpecialVar_0x8004;


	SetMonData(&gPlayerParty[pos], MON_DATA_HP_EV + gShopDataPtr->selectedRow, &tItemCount);
	CalculateMonStats(&gPlayerParty[pos]);
	RedrawListMenu(tListTaskId); // actualiza los EVs mostrados
	PutWindowTilemap(1);
	BuyMenuDisplayMessage(taskId, gText_HereYouGoThankYou, BuyEVMenuWaitForABAfterConfirming);
}

static void BuyMenuTryMakePurchase(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    PutWindowTilemap(1);

    if (gMartInfo.martType == MART_TYPE_NORMAL)
    {
        if (AddBagItem(tItemId, tItemCount) == TRUE)
        {
            BuyMenuDisplayMessage(taskId, gText_HereYouGoThankYou, BuyMenuSubtractMoney);
            RecordItemPurchase(taskId);
        }
        else
        {
            BuyMenuDisplayMessage(taskId, gText_NoMoreRoomForThis, BuyMenuReturnToItemList);
        }
    }
    else if (gMartInfo.martType == MART_TYPE_TM)
    {
        if (AddBagItem(tItemId, tItemCount) == TRUE)
        {
            GetSetItemBought(gMartInfo.shopId, gShopDataPtr->selectedRow + gShopDataPtr->scrollOffset, FLAG_SET_BOUGHT);
            BuyMenuDisplayMessage(taskId, gText_HereYouGoThankYou, BuyMenuSubtractMoney);
            RecordItemPurchase(taskId);
        }
        else
        {
            BuyMenuDisplayMessage(taskId, gText_NoMoreRoomForThis, BuyMenuReturnToItemList);
        }
    }
    else
    {
        if (DecorationAdd(tItemId))
        {
            if (gMartInfo.martType == MART_TYPE_DECOR)
            {
                BuyMenuDisplayMessage(taskId, gText_ThankYouIllSendItHome, BuyMenuSubtractMoney);
            }
            else
            {
                BuyMenuDisplayMessage(taskId, gText_ThanksIllSendItHome, BuyMenuSubtractMoney);
            }
        }
        else
        {
            BuyMenuDisplayMessage(taskId, gText_SpaceForVar1Full, BuyMenuReturnToItemList);
        }
    }
}

static void BuyEVMenuWaitForABAfterConfirming(u8 taskId)
{
    gTasks[taskId].func = Task_ReturnToItemListAfterEVPurchase;
}

static void BuyMenuSubtractMoney(u8 taskId)
{
    IncrementGameStat(GAME_STAT_SHOPPED);
    RemoveMoney(&gSaveBlock1Ptr->money, gShopDataPtr->totalCost);
    PlaySE(SE_REGI);
    PrintMoneyAmountInMoneyBox(0, GetMoney(&gSaveBlock1Ptr->money), 0);

    if (gMartInfo.martType == MART_TYPE_NORMAL)
    {
        gTasks[taskId].func = Task_ReturnToItemListAfterItemPurchase;
    }
    else if (gMartInfo.martType == MART_TYPE_TM)
    {
        gTasks[taskId].func = Task_ReturnToItemListAfterTMShopPurchase;
    }
    else
    {
        gTasks[taskId].func = Task_ReturnToItemListAfterDecorationPurchase;
    }
}

static void Task_ReturnToItemListAfterItemPurchase(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        if ((ItemId_GetPocket(tItemId) == POCKET_POKE_BALLS) && tItemCount > 9 && AddBagItem(ITEM_PREMIER_BALL, tItemCount / 10) == TRUE)
        {
            if (tItemCount > 19)
            {
                BuyMenuDisplayMessage(taskId, gText_ThrowInPremierBalls, BuyMenuReturnToItemList);
            }
            else
            {
                BuyMenuDisplayMessage(taskId, gText_ThrowInPremierBall, BuyMenuReturnToItemList);
            }
        }
        else
        {
            BuyMenuReturnToItemList(taskId);
        }
    }
}

static void Task_ReturnToItemListAfterEVPurchase(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BuyEVMenuReturnToItemList(taskId);
    }
}

static void Task_ReturnToItemListAfterTMShopPurchase(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        RedrawListMenu(tListTaskId);
        BuyMenuReturnToItemList(taskId);
    }
}

static void Task_ReturnToItemListAfterDecorationPurchase(u8 taskId)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BuyMenuReturnToItemList(taskId);
    }
}

static void BuyEVMenuReturnToItemList(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    ClearDialogWindowAndFrameToTransparent(5, 0);
    BuyMenuPrintCursor(tListTaskId, 1);
    PutWindowTilemap(1);
    BuyEVMenuPrintItemDescription(0, FALSE, (void*) gTasks[tListTaskId].data); // actualiza los EVs restantes
    PutWindowTilemap(2);
    schedule_bg_copy_tilemap_to_vram(0);
    BuyMenuAddScrollIndicatorArrows();
    gTasks[taskId].func = Task_BuyEVMenu;
}

static void BuyMenuReturnToItemList(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    ClearDialogWindowAndFrameToTransparent(5, 0);
    BuyMenuPrintCursor(tListTaskId, 1);
    PutWindowTilemap(1);
    PutWindowTilemap(2);
    schedule_bg_copy_tilemap_to_vram(0);
    BuyMenuAddScrollIndicatorArrows();
    gTasks[taskId].func = Task_BuyMenu;
}

static void BuyEVMenuPrintItemQuantityAndPrice(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    FillWindowPixelBuffer(4, PIXEL_FILL(1));
    ConvertIntToDecimalStringN(gStringVar1, tItemCount, STR_CONV_MODE_LEADING_ZEROS, 3);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    BuyMenuPrint(4, gStringVar4, 0, 1, 0, 0);
}

static void BuyMenuPrintItemQuantityAndPrice(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    FillWindowPixelBuffer(4, PIXEL_FILL(1));
    PrintMoneyAmount(4, 38, 1, gShopDataPtr->totalCost, TEXT_SPEED_FF);
    ConvertIntToDecimalStringN(gStringVar1, tItemCount, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    BuyMenuPrint(4, gStringVar4, 0, 1, 0, 0);
}

static void ExitEVBuyMenu(u8 taskId)
{
    gFieldCallback = MapPostLoadHook_ReturnToEVShopMenu;
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_ExitBuyMenu;
}

static void ExitBuyMenu(u8 taskId)
{
    gFieldCallback = MapPostLoadHook_ReturnToShopMenu;
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_ExitBuyMenu;
}

static void Task_ExitBuyMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        RemoveMoneyLabelObject();
        BuyMenuFreeMemory();
        SetMainCallback2(CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

static void ClearItemPurchases(void)
{
    gMartPurchaseHistoryId = 0;
    memset(gMartPurchaseHistory, 0, sizeof(gMartPurchaseHistory));
}

static void RecordItemPurchase(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u16 i;

    for (i = 0; i < 3; i++)
    {
        if (gMartPurchaseHistory[i].itemId == tItemId && gMartPurchaseHistory[i].quantity != 0)
        {
            if (gMartPurchaseHistory[i].quantity + tItemCount > 255)
            {
                gMartPurchaseHistory[i].quantity = 255;
            }
            else
            {
                gMartPurchaseHistory[i].quantity += tItemCount;
            }
            return;
        }
    }

    if (gMartPurchaseHistoryId < 3)
    {
        gMartPurchaseHistory[gMartPurchaseHistoryId].itemId = tItemId;
        gMartPurchaseHistory[gMartPurchaseHistoryId].quantity = tItemCount;
        gMartPurchaseHistoryId++;
    }
}

#undef tItemCount
#undef tItemId
#undef tListTaskId


void CreateEVMartMenu(const u16 *itemsForSale)
{
    CreateEVShopMenu(TRUE);
    SetEVShopItemsForSale(itemsForSale);
    ClearItemPurchases();
    SetShopMenuCallback(EnableBothScriptContexts);
}

void CreatePokemartMenu(const u16 *itemsForSale)
{
    CreateShopMenu(MART_TYPE_NORMAL);
    SetShopItemsForSale(itemsForSale);
    SetShopId(0);
    ClearItemPurchases();
    SetShopMenuCallback(EnableBothScriptContexts);
}

void CreateTMShopMenu(const u16 *itemsForSale, u8 shopId)
{
    CreateShopMenu(MART_TYPE_TM);
    SetTMShopItemsForSale(itemsForSale);
    SetShopId(shopId);
    ClearItemPurchases();
    SetShopMenuCallback(EnableBothScriptContexts);
}

void CreateDecorationShop1Menu(const u16 *itemsForSale)
{
    CreateShopMenu(MART_TYPE_DECOR);
    SetShopItemsForSale(itemsForSale);
    SetShopMenuCallback(EnableBothScriptContexts);
}

void CreateDecorationShop2Menu(const u16 *itemsForSale)
{
    CreateShopMenu(MART_TYPE_DECOR2);
    SetShopItemsForSale(itemsForSale);
    SetShopMenuCallback(EnableBothScriptContexts);
}
