/*
Ejercicio 3-1
 Encender cada segmento de un display 7 segmentos. Generar la secuencia.
*/
#define LED_A 12
#define LED_B 13
#define LED_C 7
#define LED_D 8
#define LED_E 9
#define LED_F 11


void setup()
{
  pinMode(LED_A , OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(LED_D, OUTPUT);
  pinMode(LED_E, OUTPUT);
  pinMode(LED_F, OUTPUT);
}

void loop()
{
  PrendeApaga(LED_A);
  PrendeApaga(LED_B);
  PrendeApaga(LED_C);
  PrendeApaga(LED_D);
  PrendeApaga(LED_E);
  PrendeApaga(LED_F);
}

void PrendeApaga(int led)
{
    digitalWrite(led, HIGH);
    delay(200);
	digitalWrite(led, LOW);
    delay(200);
}