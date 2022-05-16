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

# 9/03/2022 Angelica Quaranta Barba (30 min)
He intentado añadir la seleccion para los circuitos en el menú para que al pulsar me mostrara un mapa de circuito. No he logrado que cambiara.

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

# 12/03/2022 Angelica Quaranta Barba (40 min)
Implementando estados y singleton para hacer instancias con las clases.


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

# 2/04/2022 Angelica Quaranta Barba (2h)
Probando a unir las clases del resto de compañeros para invocar instancias sus respectivas estancias y mostrarlo. AL principio me daba error al crearlas. 

# 3/04/2022 Miguel Ángel Ferrer García de la Reina @(1h)
He creado las variables en la clase vehiculo

# 3/04/2022 Angelica Quaranta Barba (1h)
Arreglé la creación de las instnacias, las definí correctamente en los .h e inicialicé en los .cpp. Aún seguía sin mostrar nada, no ejecutaba.

# 4/04/2022 Senén Martinez Acame (1h)
Actualizar IA, añadiendirle un atributo Vehiculo para acceder a sus funciones y agregarle setters a IA.

# 4/04/2022 Joan Pascual Izquierdo (1h 30min)
He probado el hacer las colisiones con los mapas de dureza, todavía no funciona

# 4/04/2022 Miguel Ángel Ferrer García de la Reina (2h )
He intentado que el movimiento del vehiculo esté ne la clase vehiculo, pero no cinsigo que funcione.

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

# 7/04/2022 Sergio Tortajada Santonja (1h)
Arreglado lo de repetir, he vuelto a poner que pulsando un botón se genere un mapa distinto, arreglado que le pasaba a Senén por parámetro dos mapas cuando repetía, sprite puesto para que empiece recto y cuando se crea otro mapa la velocidad aceleración cambia a 0 y vuelve a estar recto.

# 7/04/2022 Sergio Tortajada Santonja (10min)
El pendejo de Joan no sabe como funciona la velocidad negativa.

# 8/04/2022 Senén Martinez Acame (30min)
He creado el setup.sh con los comandos para descargar y guardar las imagenes que usemos.

# 9/04/2022 Angelica Quaranta Barba (2h)
He creado una clase manejador y otra de estados para controlar los cambios de estados. He hechos que algunas clases hereden de estados para hacer el cambio entre las clases a la hora de mostrarlo. Anque aún no tenía claro cómo manejarlo bien.

# 9/04/2022 Senén Martinez Acame (1h)
He modificado Vehiculo para que tenga un sprite y asi poder hacer pruebas de movimiento con la IA.

# 9/04/2022 Joan Pascual Izquierdo (45 min)
He estado probando para que calcule la colisión con el mapa de textura con los pixeles de los 4 extremos y no consigo que funcione. Lo otro que he hecho es que las colisiones entre otros coches se comprueben en un método aparte, sólo hay que llamar a colision(sprite1, sprite2) y ya estaría

# 9/04/2022 Senén Martinez Acame (1h 15min)
Estoy intentando usar lo que tengo en el prototipo de la IA para recorrer la ruta, pero no consigo que funcione bien, me esta dando problemas los angulos del vehiculo con respecto al punto al que tiene que ir.

# 9/04/2022 Senén Martinez Acame (2h)
He intentado implementar el recorrido del prototipo en el proyecto final. No funciona muy bien, y no entiendo el motivo, he estado 2 horas probando cosas, pero no he conseguido arreglarlo. Si el lunes no consigo solucionarlo, le preguntare a Fidel cual puede ser el problema.

# 10/04/2022 Miguel Ángel Ferrer García de la Reina (3h)
Nuevo intento pasar el movimiento del vehiculo a una clase externa del main, pero me da problemas con el reloj y no consigo un movimiento fluido.

# 10/04/2022 Senén Martinez Acame (1h 10min)
He podido solucionar el problema del recorrido, ahora funciona perfectamente. Tambien he organizado y pulido la clase IA para que quede mejor estructurada.

# 10/04/2022 Joan Pascual Izquierdo (3h 30 min)
He estado intentando que funcione las colisiones de mejor forma y no lo he cnseguido, no he llegado a tener un mejor resultado, siepre fallaba en algo y provocaba lo siguiente: Violación de segmento (`core' generado). Así que, al final, lo dejé como antes

# 10/04/20022 ANgelica Quaranta Barba (3h)
He intentando crear un motor y que desde juego llamara e instanciara al resto de clases de los componentes de juego para iniciarlo, al igual que modifiqué el main inicializando solo con el menu, motor y juego. He intentado que main no tuviera mucho código y fuera en juego donde se cargara la mayoría de las cosas. No me ha dado resultado.

# 11/04/2022 Angelica Quaranta Barba (2h 30 min)
Se ha modificado los MakeLists de las carpetas juego y motor. He intentado solucionar los errores y conflictos generados entre las clases y llamadas entre ellas. Ya no me aperece el error 'sin definir', pero aún existen conflictos que no me permiten ejecutar el juego. No he conseguido que se mostrara el menú y el resto de cosas, creo que no tengo bien implementado los singleton y las instancias.

# 11/04/2022 Sergio Tortajada Santonja (1h 30 min)
Segmentos de hielo en el mapa.

# 12/04/2022 Joan Pascual Izquierdo (45 min)
Arreglando gran parte de los problemas de las colisiones y empezando la solución final de éstas

# 17/04/2022 Senén Martínez Acame (1h 20 min)
Implementado que se pueda activar y desactivar que se dibuje el recorrido con la O y que recorra el camino con la P.
Modificado los archivos xml para que los puntos del recorrido esten mas suavizados y de una mejor sensacion de recorrido.

# 19/04/2022 Joan Pascual Izquierdo (1h)
He intentado arreglar el problema que había con la colisión de arriba cuando ponía que calculara la colisión con más de 2 puntos, no lo he conseguido, pero he encontrado otra solución, que la colisión de arriba la calcule con el centro (una solución equivalente al error, es decir, absurdo).

# 19/04/2022 Senén Martínez Acame (1h 10min)
Añadido que ahora el sprite de la IA rota para orientarse en funcion de la direccion del camino que tiene que recorrer.

# 22/04/2022 Miguel Ángel Ferrer García de la Reina (30min)
Sprites actualizados en el juego.

# 24/04/2022 Miguel Ángel Ferrer García de la Reina (2h 30min)
Ceadas 4 parejas de sprites diferentes. Cada pareja con dos colores distintos, que se pueden cambiar si no nos convencen.

# 25/04/2022 Joan Pascual Izquierdo (30 min)
He intentado incorporar las colisiones en el proyecto final pero, entre el movimiento y el coger los trozos de vía correspondientes que no estoy viendo cómo hacerlo ahora mismo, lo único que he hecho ha sido incorporar los métodos de colisiones en el main del proyecto final

# 26/04/2022 Joan Pascual Izquierdo (1h 30 min)
Tratrando de incorporar las colisiones al proyecto final, he intentado una solución a lo que hacemos actualmente de no poner los trozos de mapa con sus texturas que era el cargar el trozo de carretera que había y abrir la textura de ese trozo y ya calcular las colisiones, pero no funciona porque existe un reloj y otras cosas que no se que serán.

# 26/04/2022 Senén Martínez Acame (20min)
Corregido el reseteo del mapa, ahora la IA comienza siempre desde el mismo punto cuando se reinicia el nivel, en lugar de moverse al punto de inicio.

# 27/04/2022 Angelica Quaranta Barba (2h)
Probando a implementar una interfaz para el juego mediante estados para cambiar del menu inicial al juego y del juego al menu final. No conseguido de esta manera, pero la estructura de las 3 partes están. Fallos en el main.

# 27/04/2022 Senén Martínez Acame (1h 30min)
Implementado menu de inicio. El menu esta implementado como un switch desde el main. Lo ideal seria implementarlo con el patron state, intentaremos aplicarlo de esa forma para la entrega final, pero de momento tenemos algo funcional.

# 28/04/2022 Joan Pascual Izquierdo (45 min)
Incorporadas con éxito las colisiones. En todo caso queda arreglar las reducciones de velocidad y las reacciones con las colisiones.

# 30/04/2022 Senén Martínez Acame (1h 15min)
Adaptada la IA a los añadidos de meta y salida del mapa.

# 30/04/2022 Angelica Quaranta Barba (30 min)
Haciendo pruebas en el main para comprobar funcionamiento y fallos del menu junto con el juego.

# 03/05/2022 Angelica Quaranta Barba (2h)
Creado el menu final. Al principio lo hice hederado del menu principal pero no me daba resultado así que lo volví a hacer como si fuera uno independiente para tratarlos como dos objetos distintos.

# 05/05/2022 Angelica Quaranta Barba (30 min)
Pequeñas modificaciones en el menu final. Para que se viera como el principal.

# 05/05/2022 Senén Martínez Acame (1h 25min)
Creada variaciones de recorrido en las curvas.

# 05/05/2022 Senén Martínez Acame (2h)
Adaptada la IA para que pueda tomar las curvas de distinta forma, y correcciones de las curvas.

# 05/05/2022 Sergio Tortajada Santonja(12h)
Tiempo que no me he puesto de juntar el circuito y la ia con Senén, colisiones con Joan, implementación de salida y meta, rellenado de huecos cercanos al recorrido y corrección de fallos

# 06/05/2022 Senén Martínez Acame (1h 50min)
Seleccion de tipo de recorrido para curvas dependiendo de si hay nieve o no.

# 06/05/2022 Joan Pascual Izquierdo (2h 15min)
(Este log es un conjunto de lo que hice otro día y no apunté en su momento, y hoy) Mejorado el tema de la reacción del coche ante colisiones, añadiendo varios intervalos con los que al coche se le aplica más deceleración (intentando "replicar" un poco la fuerza normal que se le da al coche cuando impacta contra  un objeto sólido).

# 06/05/2022 Joan Pascual Izquierdo/Sergio Tortajada Santonja (1h)
Intento de mejora de colisiones y el cambio a Menu_final (sale mal, la pantalla se pone en negro y ya)

# 06/05/2022 Joan Pascual Izquierdo/Sergio Tortajada Santonja/Angélica Quaranta Barba (1h 30min)
Cambio a Menu_final (sale mal, la pantalla se pone en negro y ya)

# 07/05/2022 Sergio Tortajada Santonja(10 min)
Cambiada rotación en terreno de hielo.

# 07/05/2022 Senén Martínez Acame(30 min)
Solucionado el problema de los cambios del menu.

# 07/05/2022 Miguel Ángel Ferrer  García de la Reina (30 min)
Cambio en la rotacion del vehiculo para que no de tirones, y cambiada la velocidad de la IA.

# 08/05/2022 Joan Pascual Izquierdo/Sergio Tortajada Santonja(1h 20min)
Menú to flamoso, cambiando cosas de menu y menu final: hemos puesto el color de la letra seleccionada en rojo, que hay más contraste de color que el verde que había para que se vea mejor, hemos puesto un delineado en negro a la letra para difereciarla del fondo, porque no se veía bien las letras por la cantidad de blanco del fondo y, la imagen del fondo, que es una imagen azul y blanca (por eso es el cambio a rojo y el delineado).

# 08/05/2022 Joan Pascual Izquierdo/Sergio Tortajada Santonja(30min)
Hemos hecho que se resalte más la opción seleccionada del menú y arreglado un problema que habia con la rotación cuando te salías del mapa.

# 08/05/2022 Angelica Quaranta Barba (30 min)
Con las últimas modificaciones del menú se mostrtaban mal y daba problemas aunque se ejecutara. He realizado unos cambios en pocas líneas del main y del menu final y ya están arreglados y funcionan correctamente. El problema era con el tamaño del array y las posiciones de las opciones, y faltaba modificar un caso en el main.

# 08/05/2022 Sergio Tortajada Santonja (10 min)
Ahora puedes perder

# 08/05/2022 Miguel Ángel Ferrer García de la Reina (2h)
Implementado el menu para seleccionar el coche

# 08/05/2022 Sergio Tortajada Santonja (10 min)
Arreglado problemas con los sprites cuando cambias de coche

# 09/05/2022 Sergio Tortajada Santonja (30 min)
Imagen de fondo en el circuito y colisión marcha atrás

# 08/05/2022 Joan Pascual Izquierdo/Sergio Tortajada Santonja(20min)
Ajustando las velocidaddes de colisiones, la rotación en la zona de "hierba" del trozo de nieve, y otros detalles menores.

# 08/05/2022 Miguel Ángel Ferrer García de la Reina (1h 30m)
Puestos los prites de los enemigos y distintas estadisticas para cada coche

# 08/05/2022 Joan Pascual Izquierdo/Sergio Tortajada Santonja(30min)
Balanceo de coches (parche 1.1).

# 10/05/2022 Sergio Tortajada Santonja (30 min)
Música de menú y de juego

# 10/05/2022 Senén Martínez Acame(1 h)
Añadido que el coche haga ruido de motor cuando acelera y que cese cuando dejas de acelerar, y tambien la velocidad de la IA es parametrizable.

# 10/05/2022 Sergio Tortajada Santonja (1 h)
Cosas volando de fondo para que no quede tan soso

# 13/05/2022 Angelica Quaranta Barba (1h 35min)
Probando a poner borde al minimapa con un shape de rectángulo, un sprite y una view.

# 13/05/2022 Senén Martínez Acame(1h 15min)
Rellenar documentacion.

# 13/05/2022 Sergio Tortajada Santonja(20min)
Borde minimapa

# 13/05/2022 Sergio Tortajada Santonja(20min)
Cronometro con minutos

# 14/05/2022 Senén Martínez Acame(1h 25min)
Implementado layout donde se muestra el cronometro, controles de movimiento con WASD ademas de con las flechas. Hay que arreglar un bug que cuando se reseta el mapa el cronometro no se reinicia bien.

# 14/05/2022 Joan Pascual Izquierdo(5min)
Vuelven pingu y el/la zorro/a.

# 15/05/2022 Joan Pascual Izquierdo(45min)
Probando los coches e intentando balancear un poco el F1, que sigue siendo el peor con diferencia.
La reducción de giro ahora es porcentual (como he subido un poco el giro al F1, es la misma para él que si fuera con la forma de antes, pero al kart le afecta algo más, aunque no se note apenas).

# 15/05/2022 Joan Pascual Izquierdo(30min)
Velocímetro incorporado, necesito un símbolo o alguna palabra mejor que speed para poner delante del la velocidad (está multiplicada por 2 porque la velocidad máxima del F1 es 70 y no puede ser que un F1 corra a su velocidad máxima por debajo de los 140 km/h).

# 15/05/2022 Angelica Quaranta Barba (1h 35min)
Creado un menú para elegir la dificultad del juego. Implementado y se muestra. A falta de cambiar la IA según la dificultad escogida.

# 15/05/2022 Joan Pascual Izquierdo(1h)
Ajustes de posición del velocímetro, el kart no tiene ya tanta ventaja porque sufre una mayor penalización en la nieve (un extra de 1.6, ya que con la nueva reducción se quedaba con 9.6), y más ajustes de balanceo.
Arreglo de problemas para hacer un merge.

# 15/05/2022 Joan Pascual Izquierdo(40min)
Arreglando y centrando menu_dificultad y poniendo un velocimetro.

# 15/05/2022 Angelica Quaranta Barba/Joan Pascual Izquierdo/Sergio Tortajada Santonja(1h)
Añadidos más moradores de la grieta, y implementando a ZA WARUDOOOOOOOOOOOOOOOOO.

# 15/05/2022 Joan Pascual Izquierdo/Sergio Tortajada Santonja/Angelica Quaranta Barba(50min)
(Joan)Arreglado menu_coche, ahora está centrado, como todos los demás menús.
(Sergio)Arreglando el ZA WARUDO.
(Angie)Desarrollando más el Ten-sheet.