#Primer Parcial SPD
#Brian Paul Morales Peralta Div J SPD
PARTE 1
/*
Primero, se definen una serie de constantes simbólicas usando  #define, que asigna nombres legibles a valores numéricos.Estas constantes se utilizan en todo el programa 
para referirse a pines, valores y tiempos, lo que hace que el código sea más legible y fácil de mantener. Se declaran variables enteras para llevar un registro del número 
que se muestra (countDigit) y para controlar el estado de los botones SUBE, BAJA y RESET. También se declaran variables previas (subePrevia, bajaPrevia y resetPrevia) para 
ayudar a detectar cuándo se presionan los botones. En la función setup(), se configuran los pines en el microcontrolador. Los pines se configuran como entradas con 
resistencia de pull-up para los botones (SUBE, BAJA, y RESET) y como salidas para los segmentos del display de 7 segmentos y los dígitos del display.Se llama a la función 
renderDisplaySieteSegNumeros(0) para inicializar el display mostrando el número 0. En la función loop(), el programa entra en un bucle infinito que se ejecuta continuamente. Primero, se llama a la función 
keypressed() para detectar si se ha presionado algún botón.Si se presiona el botón SUBE, el valor de countDigit se incrementa en 1. Se verifica si countDigit supera 99 y, 
en ese caso, se vuelve a 0. Si se presiona el botón BAJA, el valor de countDigit se decrementa en 1. Se verifica si countDigit es menor que 0 y, en ese caso, se establece en 99.
Si se presiona el botón RESET, el valor de countDigit se restablece a 0. Luego, se llama a la función mostarValorAcutalDisplaySieteSeg(countDigit) para mostrar 
el valor actual de countDigit en el display de 7 segmentos. La función prenderDisplaySieteSegNumeros(int digit) controla qué segmentos deben estar encendidos en el display de 
7 segmentos para mostrar un dígito específico. Se configuran los pines A, B, C, D, E, F y G para controlar qué segmentos están encendidos, dependiendo del valor del dígito 
proporcionado. La función prenderDisplayUnidadyDecenas(int digito) se utiliza para alternar entre los dígitos del display. Esto permite que el programa muestre el número del
dígito de las unidades o en el dígito de las decenas.La función verificarSubeBajaReset(void) verifica el estado de los botones SUBE, BAJA y RESET y detecta cuándo se presionan. Devuelve un valor 
correspondiente al botón presionado o 0 si no se ha presionado ningún botón.
LINK: https://www.tinkercad.com/things/eGtlJKsUgIY
*/
PARTE 2
/*
en esta parte se mantiene la anterior parte solo que se agrega un switchslide para mostras si es en HIGH los numeros del 0 al 99 y si es primo tambien del 0 a 99 
agregamos una funcion que recibe el num y luego verifica si el número es primo comprobando que no sea menor  o igual a 1, y luego buscando divisores potenciales en el rango 
de 2 a la raíz cuadrada del número. Si no se encuentra ningún divisor en ese rango, se considera que el número es primo; de lo contrario, se considera que no es primo.
numeroEsPrimo(int numero):Esta función toma un número entero numero como argumento. Comienza comprobando si el número es menor o igual a 1. Si es así, devuelve false 
inmediatamente porque los números primos son mayores que 1 y no incluyen el 1 ni los números negativos. Luego, realiza un bucle for que va desde i = 2 hasta i * i <= numero. 
En otras palabras, busca divisores potenciales en el rango de 2 a la raíz cuadrada de numero. Si encuentra un divisor (es decir, numero % i == 0), devuelve false porque 
el número no es primo. Si el bucle completa sin encontrar divisores, entonces devuelve true, indicando que el número es primo. buscarSiguientePrimo(int inicio):
Esta función toma un número entero inicio como argumento y se utiliza para encontrar el siguiente número primo mayor que inicio. Comienza con un número numero igual a inicio + 1.
Luego, entra en un bucle while que se ejecuta indefinidamente (etiquetado como while (true)). En cada iteración del bucle, verifica si numero es primo utilizando la función 
numeroEsPrimo que describí anteriormente. Si es primo, devuelve ese número como el siguiente primo mayor. Si no es primo, incrementa numero en uno y continúa buscando hasta 
encontrar el siguiente número primo. buscaranteriorPrimo(int inicio): Esta función toma un número entero inicio como argumento y se utiliza para encontrar el anterior número 
primo mayor que inicio.Comienza con un número numero igual a inicio - 1. Luego, entra en un bucle while que se ejecuta indefinidamente (etiquetado como while (true)).
En cada iteración del bucle, verifica si numero es primo utilizando la función numeroEsPrimo que describí anteriormente. Si es primo, devuelve ese número como el siguiente 
primo mayor. Si no es primo, incrementa numero en uno y continúa buscando hasta encontrar el siguiente número primo. la funcion ApagarLeds() apaga todos los leds y tambien 
pregunta si la temperatura del sensor , si es != a 358 no prende el motor si es 358 de voltaje
LINK: https://www.tinkercad.com/things/hJ4kCsR2t8z
*/
PARTE 3
/*
esta parte lo unico que integra es un fotodiodo que lo que hace es medir la temperatura mediante los rayos del sol
y si tiene una determinada cantidad de luz con el sensor de luz apagan el motor y no funciona el programa si tiene
358 y 11 de valor encienden el motor y por ende el programa funciona como antes
LINK: https://www.tinkercad.com/things/a2mycRyfPHh?sharecode=9SBwZpHEst9cS1hqZJR3ZwhYHUeCBtc2o7gF00haGYE
*/
