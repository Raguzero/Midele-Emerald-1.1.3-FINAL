#include "global.h"
#include "random.h"

// The number 1103515245 comes from the example implementation of rand and srand
// in the ISO C standard.

EWRAM_DATA static u8 sUnknown = 0;
EWRAM_DATA static u32 sRandCount = 0;

// IWRAM common
u32 gRngValue;
u32 gRng2Value;

u16 Random(void)
{
    gRngValue = 1103515245 * gRngValue + 24691;
    sRandCount++;
    return gRngValue >> 16;
}

void SeedRng(u16 seed)
{
    gRngValue = seed;
    sUnknown = 0;
}

void SeedRng2(u16 seed)
{
    gRng2Value = seed;
}

u16 Random2(void)
{
    gRng2Value = 1103515245 * gRng2Value + 24691;
    return gRng2Value >> 16;
}

u16 RandRange(u16 min, u16 max)
{
    if (min == max)
        return min;

    return (Random() % (max - min)) + min;
}

// Shuffles array of a given length using Fisher-Yates shuffling algorithm
void Shuffle(u16 array[], u16 length) {
  u16 i, j, aux;
  for (i = length - 1; i > 0 ; i--)
  {
    j = Random() % (i + 1);
    aux = array[i];
    array[i] = array[j];
    array[j] = aux;
  }
}
