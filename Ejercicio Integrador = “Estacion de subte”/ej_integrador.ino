/*
Ejercicio Integrador 1
“Estacion de subte”
Consigna :
La empresa  “UTN FRA Robotics” ganó la licitación de un proyecto, y deberá Implementar 
un sistema que permita al usuario saber a qué estación de subte está llegando, aparte  
el sistema muestra las estaciones que faltan hasta llegar a destino, para ello debemos 
utilizar 4 LEDs y el display de 7 segmentos. El sistema deberá arrancar apagado, luego 
de cambiar la posición del interruptor empezará y hará lo pedido.
*/

#define LED_ROJO 13
#define LED_AMARILLO 12
#define LED_VERDE 11
#define LED_AZUL 10

#define A 8
#define B 7
#define C A1
#define D A2
#define E A3
#define F 6
#define G 5

#define interruptorPin 9

int estacionesFaltantes = 4;  // Inicialmente, quedan 4 estaciones por encenderse

void setup() 
{
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(interruptorPin, INPUT_PULLUP);  // Configurar el pin del interruptor como entrada con pull-up      
}

void loop() 
{
  if (digitalRead(interruptorPin) == LOW) 
  {  // Verificar si el interruptor está en la posición activada
    if (estacionesFaltantes >= 0) 
    {
      estacionesFaltantes--;

      // Enciende el LED correspondiente
      switch (estacionesFaltantes) 
      {
        case 3:
          digitalWrite(LED_ROJO, HIGH);
          mostrarNumero(3);
          break;
        case 2:
          digitalWrite(LED_AMARILLO, HIGH);
          mostrarNumero(2);
          break;
        case 1:
          digitalWrite(LED_VERDE, HIGH);
          mostrarNumero(1);
          break;
        case 0:
          digitalWrite(LED_AZUL, HIGH);
          mostrarNumero(0);
          break;
      }
      delay(1500);
    } 
  
    if (estacionesFaltantes == -1)
    {
        // Apagar todos los LEDs y el display de 7 segmentos
        digitalWrite(LED_ROJO, LOW);
        digitalWrite(LED_AMARILLO, LOW);
        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_AZUL, LOW);
        apagarDisplay();
        estacionesFaltantes = 4;  // Reinicia la cantidad de estaciones faltantes
    }
  }
}

void mostrarNumero(int digit) 
{
  // Apaga todos los segmentos
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);

  // Enciende los segmentos correspondientes para mostrar el número
  switch (digit) 
    {
    case 0:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      break;
    case 1:
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 2:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(G, HIGH);
      break;
    }
}

void apagarDisplay() 
{
  // Apaga todos los segmentos del display
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}
