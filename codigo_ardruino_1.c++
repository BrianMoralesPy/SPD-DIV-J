/*
Primero, se definen una serie de constantes simbólicas usando 
#define, que asigna nombres legibles a valores numéricos. 
Estas constantes se utilizan en todo el programa para referirse 
a pines, valores y tiempos, lo que hace que el código sea más 
legible y fácil de mantener.
Se declaran variables enteras para llevar un registro del número 
que se muestra (countDigit) y para controlar el estado de los 
botones SUBE, BAJA y RESET. También se declaran variables previas 
(subePrevia, bajaPrevia y resetPrevia) para ayudar a detectar cuándo 
se presionan los botones.
En la función setup(), se configuran los pines en el 
microcontrolador. Los pines se configuran como entradas con 
resistencia de pull-up para los botones (SUBE, BAJA, y RESET) 
y como salidas para los segmentos del display de 7 segmentos y 
los dígitos del display.
Se llama a la función prenderDisplaySieteSegNumeros(0) para inicializar el display 
mostrando el número 0.
En la función loop(), el programa entra en un bucle infinito 
que se ejecuta continuamente. Primero, se llama a la función 
keypressed() para detectar si se ha presionado algún botón.
Si se presiona el botón SUBE, el valor de countDigit se incrementa 
en 1. Se verifica si countDigit supera 99 y, en ese caso, se vuelve 
a 0.
Si se presiona el botón BAJA, el valor de countDigit se decrementa 
en 1. Se verifica si countDigit es menor que 0 y, en ese caso, se 
establece en 99.
Si se presiona el botón RESET, el valor de countDigit se restablece 
a 0.
Luego, se llama a la función mostarValorAcutalDisplaySieteSeg(countDigit) para mostrar 
el valor actual de countDigit en el display de 7 segmentos.
La función prenderDisplaySieteSegNumeros(int digit) controla qué segmentos deben estar
encendidos en el display de 7 segmentos para mostrar un dígito 
específico. Se configuran los pines A, B, C, D, E, F y G para 
controlar qué segmentos están encendidos, dependiendo del valor 
del dígito proporcionado.
La función prenderDisplayUnidadyDecenas(int digito) se utiliza para alternar 
entre los dígitos del display. Esto permite que el programa 
muestre el número en el dígito de las unidades o en el dígito de 
las decenas.
La función verificarSubeBajaReset(void) verifica el estado de los botones SUBE, 
BAJA y RESET y detecta cuándo se presionan. Devuelve un valor 
correspondiente al botón presionado o 0 si no se ha presionado 
ningún botón.
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

int contarDigito = 0;
int sube = 1;
int subePrevia = 1;
int baja = 1;
int bajaPrevia = 1;
int reset = 1;
int resetPrevia = 1;


void setup()
{
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
  prenderDisplaySieteSegNumeros(0);
}

void loop()
{
  int valor = verificarSubeBajaReset();
    
  if (valor == SUBE)
  {
    contarDigito++;
    if (contarDigito > 99)
      contarDigito = 0;
  }
  
  else if (valor  == BAJA)
  {
    contarDigito--;
    if (contarDigito < 0)
      contarDigito = 99;
  }
  
  else if (valor  == RESET)
  {
    contarDigito = 0;
  }
  mostarValorAcutalDisplaySieteSeg(contarDigito);
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
  prenderDisplaySieteSegNumeros(numero/10);
  prenderDisplayUnidadyDecenas(DECENA);
  prenderDisplayUnidadyDecenas(APAGADOS);
  prenderDisplaySieteSegNumeros(numero - 10* ((int)numero/10));
  prenderDisplayUnidadyDecenas(UNIDAD);
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