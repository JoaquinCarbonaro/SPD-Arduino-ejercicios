/*Ejercicio 2-5
Semáforos enfrentados
Dos led rojas, dos led verdes, dos led amarillas, Dos semáforos enfrentados.
*/

#define LED_ROJO 13
#define LED_AMARILLO 12
#define LED_VERDE 11

#define LED_ROJO_PARALELO 5
#define LED_AMARILLO_PARALELO 6
#define LED_VERDE_PARALELO 7


void setup()
{
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_ROJO_PARALELO, OUTPUT);
  pinMode(LED_VERDE_PARALELO, OUTPUT);
  pinMode(LED_AMARILLO_PARALELO, OUTPUT);
}

void loop()
{
	PrendeYApaga(LED_ROJO, LED_VERDE_PARALELO, 2000);
  	PrendeYApaga(LED_AMARILLO, LED_AMARILLO_PARALELO, 1000);
    PrendeYApaga(LED_VERDE, LED_ROJO_PARALELO, 3000);
  	
}



void PrendeYApaga(int led1, int led2, int tiempo)
{
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    delay(tiempo);
	digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    delay(500);
}