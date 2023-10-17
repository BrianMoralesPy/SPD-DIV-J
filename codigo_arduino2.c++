/*
en esta parte se mantiene la anterior parte solo que se agrega un
switchslide para mostras si es en HIGH los numeros del 0 al 99 y si
es primo tambien del 0 a 99 agregamos una funcion que recibe el num
y luego verifica si el número es primo comprobando que no sea menor 
o igual a 1, y luego buscando divisores potenciales en el rango 
de 2 a la raíz cuadrada del número. Si no se encuentra ningún divisor en 
ese rango, se considera que el número es primo; de lo contrario, 
se considera que no es primo.
numeroEsPrimo(int numero):
Esta función toma un número entero numero como argumento.
Comienza comprobando si el número es menor o igual a 1. Si es así, devuelve false inmediatamente porque los números primos son mayores que 1 y no incluyen el 1 ni los números negativos.
Luego, realiza un bucle for que va desde i = 2 hasta i * i <= numero. En otras palabras, busca divisores potenciales en el rango de 2 a la raíz cuadrada de numero.
Si encuentra un divisor (es decir, numero % i == 0), devuelve false porque el número no es primo.
Si el bucle completa sin encontrar divisores, entonces devuelve true, indicando que el número es primo.
buscarSiguientePrimo(int inicio):
Esta función toma un número entero inicio como argumento y se utiliza para encontrar el siguiente número primo mayor que inicio.
Comienza con un número numero igual a inicio + 1.
Luego, entra en un bucle while que se ejecuta indefinidamente (etiquetado como while (true)).
En cada iteración del bucle, verifica si numero es primo utilizando la función numeroEsPrimo que describí anteriormente. Si es primo, devuelve ese número como el siguiente primo mayor.
Si no es primo, incrementa numero en uno y continúa buscando hasta encontrar el siguiente número primo.
buscaranteriorPrimo(int inicio):
Esta función toma un número entero inicio como argumento y se utiliza para encontrar el anterior número primo mayor que inicio.
Comienza con un número numero igual a inicio - 1.
Luego, entra en un bucle while que se ejecuta indefinidamente (etiquetado como while (true)).
En cada iteración del bucle, verifica si numero es primo utilizando la función numeroEsPrimo que describí anteriormente. Si es primo, devuelve ese número como el siguiente primo mayor.
Si no es primo, incrementa numero en uno y continúa buscando hasta encontrar el siguiente número primo.
la funcion ApagarLeds() apaga todos los leds y tambien pregunta si la temperatura del sensor , si es != a 358 no prende el motor
si es 358 de voltaje 
*/
#define A 12
#define B 13
#define C 7
#define D 8
#define E 9
#define F 11
#define G 10
#define SUBE 4
#define BAJA 3
#define RESET 5
#define UNIDAD A4
#define DECENA A5
#define APAGADOS 0
#define TIMEDISPLAYON 10
#define SWITCHSLIDE 2
#define MOTOR A3

int temperaturaRead = 0;
int contarDigito = 0;
int sube = 1;
int subePrevia = 1;
int baja = 1;
int bajaPrevia = 1;
int reset = 1;
int resetPrevia = 1;


void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  prenderDisplaySieteSegNumeros(0);
}

void loop() {
  int switchPosition = digitalRead(SWITCHSLIDE);
  temperaturaRead = analogRead(A1);
  if (temperaturaRead == 358)
  { 
  	digitalWrite(MOTOR,1);
    if (switchPosition == HIGH) 
    {
        int valor = verificarSubeBajaReset();
        if (valor == SUBE) 
        {
        contarDigito++;
        if (contarDigito > 99)
            contarDigito = 0;
        } 
        else if (valor == BAJA) 
        {
        contarDigito--;
        if (contarDigito < 0)
            contarDigito = 99;
        } 
        else if (valor == RESET) 
        {
        contarDigito = 0;
        }
    }
    else if (switchPosition == LOW) 
    {
        if (!numeroEsPrimo(contarDigito))
        {
        	contarDigito = buscarSiguientePrimo(contarDigito);
        }
        int valor = verificarSubeBajaReset();
        if (valor == SUBE) 
        {
        contarDigito++;
        if (contarDigito > 99)
            contarDigito = 0;
        } else if (valor == BAJA) 
        {
        contarDigito = buscarPrimoAnterior(contarDigito);
        if (contarDigito < 0)
            contarDigito = 99;
        } else if (valor == RESET) 
        {
        contarDigito = 0;
        }
    }
    mostarValorAcutalDisplaySieteSeg(contarDigito);
  }
  else if (temperaturaRead == 20) 
  {
    digitalWrite(MOTOR, 0);
    apagarDisplays();
  } else 
  	{
    apagarDisplays();
  	}
  Serial.print(" ");
  Serial.println(temperaturaRead);
}
void prenderDisplaySieteSegNumeros(int digito)
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  
  switch (digito)
  {
    case 0:
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      break;
    }
    case 1:
    {
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    }
    case 2:
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(G, HIGH);
      break;
    }
    case 3:
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(G, HIGH);
      break;
    }
    case 4:
    {
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    }
    case 5:
    {
      digitalWrite(A, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    }
    case 6:
    {
      digitalWrite(A, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    }
    case 7:
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    }
    case 8:
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    }
    case 9:
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    }
  }
}


void prenderDisplayUnidadyDecenas(int digito)
{
  if (digito == UNIDAD)
  {
    digitalWrite(UNIDAD, LOW);
    digitalWrite(DECENA, HIGH);
    delay(TIMEDISPLAYON);
  }
  else if (digito == DECENA)
  {
    digitalWrite(UNIDAD, HIGH);
    digitalWrite(DECENA, LOW);
    delay(TIMEDISPLAYON);
  }
  else
  {
    digitalWrite(UNIDAD, HIGH);
    digitalWrite(DECENA, HIGH);
  }
}  


void mostarValorAcutalDisplaySieteSeg(int numero)
{
  prenderDisplayUnidadyDecenas(APAGADOS);
  prenderDisplaySieteSegNumeros(numero / 10);
  prenderDisplayUnidadyDecenas(DECENA);
  prenderDisplayUnidadyDecenas(APAGADOS);
  prenderDisplaySieteSegNumeros(numero - 10 * (numero / 10));
  prenderDisplayUnidadyDecenas(UNIDAD);  
}

bool numeroEsPrimo(int numero) {
  if (numero <= 1) return false;
  for (int i = 2; i * i <= numero; i++) {
    if (numero % i == 0) return false;
  }
  return true;
}

int buscarSiguientePrimo(int inicio) {
  int numero = inicio + 1;
  while (true) {
    if (numeroEsPrimo(numero)) {
      return numero;
    }
    numero++;
  }
}
int buscarPrimoAnterior(int inicio) {
  int numero = inicio - 1;
  while (numero >= 2) {
    if (numeroEsPrimo(numero)) {
      return numero;
    }
    numero--;
  }
}

void apagarDisplays() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(UNIDAD, LOW);
  digitalWrite(DECENA, LOW);
}
int verificarSubeBajaReset(void)
{
  sube = digitalRead(SUBE);
  baja = digitalRead(BAJA);
  reset = digitalRead(RESET);
  
  if (sube)
    subePrevia = 1;
  if (baja)
    bajaPrevia = 1;
  if (reset)
    resetPrevia = 1;
  
  if (sube == 0 && sube != subePrevia)
  {
    subePrevia = sube;
    return SUBE;
  }
  if (baja == 0 && baja != bajaPrevia)
  {
    bajaPrevia = baja;
    return BAJA;
  }
  if (reset == 0 && reset != resetPrevia)
  {
    resetPrevia = reset;
    return RESET;
  }
  return 0;
}

