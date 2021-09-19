# Registro de cambios

Registro de cambios de las distintas versiones de Midele Emerald.

## Versión 1.0.0

Versión inicial.

## Versión 1.0.1

Cambios y arreglos de errores de la versión 1.0.1

### General
- Ya no se puede ir a Slateport City si no tienes 2 Medallas y la carta entregada.

- Arreglado error en el que si buscabas un Pokémon shiny forzandole la naturaleza con Syncronize, no funcionaba, siempre salía con naturaleza aleatoria.

- Arreglado error que provocaba que los movimientos de campo de las HM no comprobasen correctamente qué medalla debías poseer para poder utilizarlos.

- Arreglado error que provocaba que llevar Pokémon con ciertas habilidades (p. ej. Magnet Pull) hicesen aparecer Pokémon salvajes que no deberían encontrarse en la zona en la que se estaba.

- Arreglado error en el que la pareja de enamorados de Rusturf Tunnel atravesaba una roca.

- Arreglado error en el que cierto Pokémon de regalo salía con stats incorrectos, los cuales salían bien al recalcularse si lo metes en un PC.

- Actualizado TODO SOBRE MIDELE EMERALD.

### Textos
- Modificado texto inconsistente de los iniciales en el centro Pokémon de Petalburg City.

- Modificado texto inconsistente que indica que no se puede utilizar un movimiento HM hasta obtener su correspondiente medalla.

- Modificado texto inconsistente sobre los MAXIE y ARCHIE en Meteor Falls.

- Arregladas erratas de algunos textos en Route 101.

- Corregida falta de ortografía en texto de Izabe Island.

- Corregida errata en texto de Tiny Mushroom.

### Dexnav
- Arreglado error que permitía que un Pokémon obtenido con Dexnav pudiese tener un mismo movimiento duplicado en dos ranuras de movimiento distintas.

- Arreglado error en el que los Pokémon con 2 o 3 estrellas buscados por Dexnav tenían stats incorrectos y normalmente salían con un solo IV a 31, en vez de varios segun las estrellas que tuviese.

- Arreglado error en el que el Dexnav engañaba en la busqueda de objetos diciendo que el Pokémon tenía cierto objeto que luego no tenía.

### Combate
- Arreglado error en el que los Pokemon dormidos por Yawn a veces despertaban al momento, cuando debería ser 1-3 turnos dormido.

- Añadida transición de monociclo al entrenador Gooses.

- Ahora el Music Player no puede sobreescribir las músicas de combate de los reclutas, administradores y líderes Aqua y Magma.

- Roselia ahora da 2 EV en SATK en vez de 1

- La IA ya no tira Weather Ball tipo Fuego (y otros, en clima) a pokémon con habilidades que lo absorban.

### Objetos

- Las bayas PINAP, WEPEAR, RAZZ, BLUK, y NANAB fueron reducidas de precio de venta

- Arreglado error que hacía que el Itemfinder no pudiese ser utilizado.


## Versión 1.1.0

Cambios y arreglos de errores de la versión 1.1.0.

Debido a los cambios, se recomienda que la partida no esté guardada en los siguientes lugares tras actualizar a esta versión:
- **ROUTE 127**
- **SCORCHED SLAB**
- **MAUVILLE CITY**
- **MONOCYCLE ROUTE**
- **SANTY GYM**
- **SAPPH GYM**

### General

- Actualizado TODO SOBRE MIDELE EMERALD.pdf
- La experiencia ganada aumenta x1.5 tras pasarse la liga.

### Textos

- Corregida falta de ortografía sobre el alcalde de Izabe.
- Corregidas faltas de ortografía en evento de ruta 101.
- Corregido texto de NPC de Petalburg Woods.
- Corregido texto de NPC de Route 120.
- Corregido texto de NPC de evento de Devon Corp.
- Corregidos textos de Gooses gym.
- Corregidos varios textos de Izabe Island.
- Corregidos textos de Mauville Ruins.
- Corregidos varios textos de mensajes de batalla.
- Corregidos varios textos de la POKéDEX.
- Corregido texto de Granite Cave.
- Corregido texto de Oceanic Museum 2F.
- Corregidos textos sobre POKéMON de Littleroot Town lab.
- Corregida la frase de la entrenadora GOLDIE que se salía del cuadro de texto.
- Añadido texto sobre el starter DARK PIKA en el NPC de Petalburg Woods Pokémon Center.
- Las cartas de los Pokémon de intercambio Salandit, Eevee y Charmander han sido corregidas.
- Corregido texto post-intercambio en IZABE que podía hacer crashear el juego.

### Sonido
- Corregidas músicas de Jirachi, Celebi y Mew.
- Añadida música de WALLY al MUSIC PLAYER.

### Eventos

- Arreglado error en el que un NPC atravesaba a otro al caminar en un evento de Mt. Pyre.
- Añadido un paso más al script de movimiento del entrenador que bloquea el PC en Oldale Town.
- Movido NPC de Izabe en Mauville más a la izquierda.
- Ahora la tienda del EV changer se cierra correctamente al cancelar la selección de POKéMON.
- La tienda de MT solo permite comprar un MT de cada tipo, y su texto se cierra correctamente.
- Corregida comprobación del NPC de los tickets de evento.
- Arreglado error en el que los guardias de la liga te atravesaban al hablarles desde izquierda/derecha.
- Añadida confirmación adicional al NPC de resetear entrenadores.

### Mapas

- Arreglada tileset atravesable en RUTA 127.
- Corregido un poco el tileset de SCORCHED SLAB.
- Corregida tileset atravesable en Santy Gym.
- Eliminada hierba al lado de las estructuras del ACRO CYCLE.
- Añadidas colisiones a tiles negras de SapphGym.

### Combate

- Corregido el poder de consecutivos Fury Cutter.
- Corregida la habilidad DRY SKIN que ocasionaba el bug de no desaparecer dicho POKéMON debilitado del campo de batalla al terminarse el combate, por haber sido debilitado por el daño del clima soleado al llevar dicha habilidad.
- Corregido cierto error de Blizzard en clima de granizo.
- Corregido el RIOLU con set ilegal de BRAWLY.
- Ya no pierdes dinero cuando CHERYL te derrota.
- Corregidas inconsistencias en algunos equipos de entrenadores (como el hecho de llevar SPORE cuando realmente lo aprenden a mayor nivel).
- Mejorado el equilibrio de stats y moveset en bosses.
- Modificado el equipo de BRAWLY.

### IA
- Corregida la IA para que no pierda el tiempo en cálculos innecesarios.
- Corregida la IA en el cálculo de poder de algunos movimientos (Explosion, Knock Off, fuego vs Dry Skin, etc.)
- Corregida la IA en el uso de Substituto a poca vida, y de Fake Out y otros ataques de prioridad en algunos momentos clave.
- Mejorada IA de Helping Hand.
- Diversas mejores de la IA (combates dobles, MIST...)
- Correcciones en la IA de Sleep Talk y Rest.
- Mejorada la IA a la hora de cambiar el Pokémon.

### Pokémon

- TROPIUS ha sido mejorado y ahora recibe un boost de x1.5 Ataque y Velocidad cuando lleva equipada una NANAB BERRY/BAYA LATANO.
- Ahora TROPIUS salvaje puede llevar equipada la NANAB BERRY/BAYA LATANO.
- Mayor estabilidad en el movepool de algunos POKéMON.
- Nivel de Pokémon de regalo en Izabe reducido de 45 a 40.
- Ahora es menos común encontrar a LEDIAN salvaje con el objeto LUCKY PUNCH.
- 25% de shiny en los huevos obtenidos en FALLARBOR mediante Heart Scale.
- 50% de shiny en DARK PIKA y WINTASS de casino. Además, DARK PIKA se obtiene al nivel 5.

### Objetos

- Focus Sash sustituye a Big Pearl como premio en Random Battles.
- Varios objetos de tipo medicina pueden ser usados de forma repetida desde el menú.
