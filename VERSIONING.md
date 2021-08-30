# Versionado de Midele Emerald

Las versiones de Midele Emerald constarán de tres números con el formato "*x.y.z*", los cuales se irán incrementando conforme salgan nuevas versiones.

La versión inicial de **Midele Emerald** viene identificada por el número *1.0.0*

## Cómo incrementar el número de versión

El número de versión se incrementará cuando una nueva versión de Midele sea lanzada al público. Los números se incrementarán siguiendo los siguientes criterios:

- El número "*z*" se incrementará en uno cuando se realicen **correcciones de errores menores** que no afecten demasiado al funcionamiento del juego (p. ej. 1.0.0 -> 1.0.1) Algunos ejemplos de correciones menores serían las siguientes:
    - Corregir algún texto o falta de ortografía.
    - Corregir el moveset de algún Pokémon o entrenador.
    - Corregir algún script que funciona mal bajo ciertas condiciones.
    - Corregir lógica del juego que funciona mal bajo ciertas condiciones.

- El número "y" se incrementará en uno cuando se añadan **nuevas características menores** al juego. Cuando el número "y" es incrementado, el número z se establecerá a 0. (p. ej. 1.0.4 -> 1.1.0) Algunos ejemplos de nuevas características menores serían las siguientes_:
    - Añadir un nuevo entrenador.
    - Añadir un nuevo NPC.
    - Mejorar significativamente un Pokémon o moveset.

- El número "x" se incrementará en uno cuando se realicen **cambios que rompan la compatibilidad con versiones anteriores** del juego. Cuando el número "x" es incrementado, los números "y" y "z" se establecerán a 0. (p. ej. 1.3.7 -> 2.0.0) Algunos ejemplos de cambios que rompen la compatibilidad son los siguientes:
    - Añadir funcionalidad que modifique la estructura de datos de los saves del juego.
    - Añadir nuevas flags.
    - Añadir nuevos Pokémon.

## Registro de cambios

Ver [CHANGELOG.mod](CHANGELOG.md)
