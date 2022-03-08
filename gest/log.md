# Log del trabajo realizado por dia
**El log es obligatorio**

## 20210108 FidelAznar @(1h)
Debe contener un sub item como el anterior, con la fecha de la entrada y las cuestiones generales que se realizaron, así como el tiempo total dedicado en la sesión. 

## 24/2/2022 Senén Martínez Acame @(1h)
Me he dedicado a buscar informacion por internet sobre el desarrollo e implementacion de una IA en juegos de carrera. Tambien le he preguntado a Fidel sobre fuentes o recursos con los que poder trabajar.

## 26/2/2022 Senén Martínez Acame @(2h)
He modificado el CMakeCache para que cree el ejexcutable del Prototipo IA, he modificado el main.cpp para crear otro sprite y ver su funcionamiento, y he empezado a crear una clase NPC.

# 20220226 JoanPascual @(1h30m)
Realizado el prototipo, añadido un segundo sprite y he intentado encontrar la información necesaria para hacer las colisiones(pd. no he encontrado algo que me funcione/entienda).

## 4/3/2022 Senén Martínez Acame @(2h)
He creado la clase ai con intencion de poder usarla para la inteligencia artificial, he descargado y probado el programa Tiled para ver su funcionamiento, como guarda los archivos en formato xml/tsx, y como usarlos para hacer un recorrido en los mapas.

## 5/3/2022 Senén Martínez Acame @(1h 30min)
Creado y guardado los archivos xml/tsx del mapa, tiles y su imagen; pruebas de movimiento de la ia e investigacion acerca del uso de los archivos XML en VSCode.

# 5/3/2022 JoanPascual @(1h30m)
Búsqueda de información acerca de colisiones e inmplementación de éstas (no funcionan todavía)

## 5/3/2022 Senén Martínez Acame @(50min)
He conseguido que la IA persiga al jugador, intento de usar la clase Sprite como propiedad de la clase ai.

## 6/3/2022 Senén Martínez Acame @(1h)
Implementada la clase ai correctamente con la funcion de perseguir al jugador.

## 7/3/2022 Senén Martínez Acame @(1h)
La IA persigue al jugador de forma un poco mas eficiente, pero da problemas para seguirlo en movimiento.

## 7/3/2022 Senén Martínez Acame @(1h)
Agregado en ej_modulos los archivos de TinyXML2 (.h y .cpp) para poder leer y usar los archivos xml de los mapas y las rutas de los npc. He comprobado que no me diesen conflicto y que al compilar y agregar al CMake no diesen problema.

## 26/2/2022 Angelica Quaranta Barba @(1h)
Creado Menu.h y Menu.cpp para mostrar 3 opciones por pantalla. Estructura creada.

## 2/3/2022 Angelica Quaranta Barba @(5h)
Problema para incluir la fuente del texto. Solucionado y probado 3 fuentes disitintas, mostrando las 3 opciones centradas en la ventana. Añadido color a los textos. Problemas para cambiar entre las opciones con el teclado.

## 6/3/2022 Angelica Quaranta Barba @(30min)
Cambiado los setColor por setFillColor y pruebas para la selección de la opción con Enter.

## 7/3/2022 Angelica Quaranta Barba @(1h)
Funciona la selección de las opciones (por terminal se indica que has seleccionado), y al seleccionar "Salir" se cierra la ventana.
Creado Menu_empezar.h, Menu_empezar.cpp, Menu_opciones-h y Menu_opciones. Estructura creada en el menu de empezar para que muestre las opciones de los tipos de circuitos.

## 8/3/2022 Angelica Quaranta Barba @(30min)
Intento de cambiar de menú al seleccionar "empezar".

## 8/3/2022 Senén Martínez Acame @(2h)
He intentado arreglar el problema de que la IA no persigue al jugador cuando este se mueve, pero no he podido. A priori los calculos estan bien y no parece que haya nada raro.