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

## 7/3/2022 Miguel Ángel Ferrer García de la Reina @(2h)
Implementado un reloj que mejora la sensacion de movimiento pero no es el reloj que se explicó en clase.

## 8/3/2022 Miguel Ángel Ferrer García de la Reina @(1h:37min)
Reloj en funcionamiento pero aún hay problemas con la rotación

## 8/3/2022 Angelica Quaranta Barba @(30min)
Intento de cambiar de menú al seleccionar "empezar".

## 8/3/2022 Senén Martínez Acame @(2h)
He intentado arreglar el problema de que la IA no persigue al jugador cuando este se mueve, pero no he podido. A priori los calculos estan bien y no parece que haya nada raro.

## 9/3/2022 Senén Martínez Acame @(2h)
He podido implementar correctamente que la IA siga la ruta establecida a traves de un archivo XML que se le pasa.

## 9/3/2022 Joan Pascual Izquierdo (1h 30min)
Seguimos probando con hitboxes (no actualicé el log en su momento)

## 9/3/2022 Joan Pascual Izquierdo (30min)
busqué información de por que no me funcionaba bien y era porque compobaba si el sprite1 colisionaba con sigo mismo, así que daba que sí y, por eso, no se movía (soy muy tonto).

## 11/03/2022 Sergio Tortajada Santonja (2h)
Me he visto muchos videos de como pintar mapas con sfml (no se si cuenta para el log)

## 11/03/2022 Sergio Tortajada Santonja (2h 30 min)
Hay un trozo de circuto y se pinta en el juego, desde el main

## 12/03/2022 Senén Martínez Acame (1h 30min)
He empezado a implementar la primera clase vehiculo para desarrollar el prototipo de las mejoras.

## 12/03/2022 Joan Pascual Izquierdo (40min)
Creación de los proyectos "poderes" y "personajes", y hacer un poder que es el de más velocidad (sólo lo he hecho hacia arriba porque si no lo hacía así, tenía que poner diferentes botones para hacer ese boost de velocidad en las demás direcciones)

## 12/03/2022 Joan Pascual Izquierdo (1h 10min)
Creación de un sprite de un personaje y cagandose en todo, de lo detallado que lo he hecho para el mal rollo que da

## 12/03/2022 Sergio Tortajada Santonja (3h)
Procedural hecho(aun no lo he probado) y pintar mas de un trozo de mapa

## 12/03/2022 Sergio Tortajada Santonja (40min)
La camara sigue al personaje y un par de arreglos al procedural(aun no lo he probado)

## 12/03/2022 Miguel Ángel Ferrer García de la Reina @(2h)
Intentando arreglar el problema del giro pero aún no he podido. Aceleracion y freno conseguidas;

## 13/03/2022 Sergio Tortajada Santonja (20min)
Segmentos del circuitos creados en png

## 13/03/2022 Sergio Tortajada Santonja (3h)
Procedural hecho

## 14/03/2022 Senén Martínez Acame (30 min)
He implementado un sistema de mejora de velocidad y giro muy basico. Falta poder estructurar y organizar las mejoras (crear su propia clase) y mejorar los controles del vehiculo para tener un mejor resultado.

## 14/03/2022 Sergio Tortajada Santonja (15min)
Cambiado una cosa de los randoms porque hacia casi todo rectas

## 15/03/2022 Sergio Tortajada Santonja (1h 20min)
Minimapa, segmentos minimos para el procedural y cargar y descargar mapa con la l

# 15/03/2022 Senén Martinez Acame (1h)
Con ayuda del prototipo de los controles de Miguel he podido implementar las mejoras para los valores de velocida, giro y aceleracion.

## 15/03/2022 Miguel Ángel Ferrer García de la Reina @(2h)
Ya no hay giros erraticos al pasar por 0 o 360 angulos, pero aún no es perfecto

# 16/03/2022 Senén Martínez Acame (1h 15min)
Implementada una clase mejora donde guarda los valores y las funciones de esta para una mejor estructuracion.

# 17/03/2022 Senén Martínez Acame (2h)
Se ha podido implementar que se la IA pueda recorrer varios fragmentos de ruta seguidos.

# 19/03/2022 Senén Martínez Acame (45min)
He optimizado el metodo de obtencion de las rutas.

# 20/03/2022 Senén Martínez Acame (1h)
He realizado pruebas con un factor de varianza en los nodos de la ruta, para ver como se comporta la IA al hacer el recorrido, tambien aumentando el margen de aproximacion al proximo nodo para pasar al siguiente. Aumentar mucho el margen hace que el recorrido sea erratico. La varianza puede servir para que el recorrido tenga un margen de maniobra. Corregido que las mejoras de un mismo tipo no se solapen.

# 26/03/2022 Senén Martínez Acame (2h)
En la rama developer se han creado los primeros archivos y carpetas donde se almacenaran los componentes de los prototipos de cada uno. No son definitivos, pueden ir variando con el desarrollo. En la rama experimental se ha implementado un metodo para visualizar el la ruta que tiene que recorrer, un margen con distancia maxima y minima, y el trazado de la ruta que hace la IA.

# 30/03/2022 Senén Martínez Acame (35min)
Ligera modificacion del prototipo de mejora, ahora el cambio de valor lo hace la propia clase y en vez de sumar un valor, lo multiplica. Tambien restaura el valor por su cuenta. He trasladado el prototipo al proyecto grupal.

# 31/03/2022 Senén Martínez Acame (40min)
He intentado probar el build desde el proyecto para poder ejecutar el juego, pero da problemas. Es algo relacionado con los directorios del CMake, le he preguntado a Fidel para que me pueda decir como poder resolverlo.

# 2/04/2022 Senén Martínez Acame (1h30min)
Adaptado la clase IA al proyecto, el constructor crea y procesa los archivos xml.

# 2/04/2022 Sergio Tortajada Santonja(20min)
Mapas en blanco y negro hechos

# 2/04/2022 Sergio Tortajada Santonja(1h 30min)
Dibujado del mapa desde la clase circuito y pasado a developer

# 3/04/2022 Miguel Ángel Ferrer García de la Reina @(1h)
He creado las variables en la clase vehiculo

# 4/04/2022 Senén Martinez Acame (1h)
Actualizar IA, añadiendirle un atributo Vehiculo para acceder a sus funciones y agregarle setters a IA.

# 4/04/2022 Joan Pascual Izquierdo (1h 30min)
He probado el hacer las colisiones con los mapas de dureza, todavía no funciona

# 5/04/2022 Joan Pascual Izquierdo (20 minutos)
Ya sé como funciona la función de las colisiones con mapas de dureza, ya funciona. Ahora funciona con todos los píxeles del sprite.

# 5/04/2022 Senén Martinez Acame (1h 15min)
IA adaptada para que traze la ruta que se crea en Circuito. Me falta que Circuito este implementado del todo para poder hacer las pruebas de que funcione correctamente.

# 5/04/2022 Joan Pascual Izquierdo (1h)
He intentado que se compruebe la colisión con todos los píxeles del sprite y no funcionaban las colisiones en un lado y cuando colisionabas con el borde negro de arriba, se producía un fallo de violación del segmento (`core'); así que lo he quitado y he hecho que en la zona grisa vaya más lento.

# 6/04/2022 Senén Martinez Acame (50min)
He estado probando que la IA genere bien los puntos de ruta con la generacion de Circuito. A veces al ejecutar el juego, se queda colgado, es posible que sea por la generacion de la IA a partir del mapa del circuito, tendre que seguir probando y mirando a ver.

# 7/04/2022 Senén Martinez Acame (1h 30min)
La IA crea el recorrido en funcion del circuito creado correctamente. Sigue dando problemas a veces al cargar.