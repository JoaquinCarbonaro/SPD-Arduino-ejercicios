/*Ejercicio 4-5
Debemos arreglar el siguiente código para que funcione correctamente el proyecto
https://www.tinkercad.com/things/c5vImB9lSuY 
Video del funcionamiento Correcto
https://drive.google.com/file/d/1zbrn1OY7D1wLoF9e2e9RYhZM9lC0x2k0/view?usp=sharing
*/

/*
Consigna:
Al presionar el boton UNO debera cambiar 
la forma que encienden los leds
por ejemplo:
1,2,3,4,5 a 5,4,3,2,1
Cuando dejo de presionar:
1,2,3,4,5
*/

#define LED_UNO 7
#define LED_DOS 8
#define LED_TRES 9
#define LED_CUATRO 10
#define LED_CINCO 11

#define TIEMPO 100

#define BOTON 2

void setup() {
  pinMode(LED_UNO, OUTPUT);
  pinMode(LED_DOS, OUTPUT);
  pinMode(LED_TRES, OUTPUT);
  pinMode(LED_CUATRO, OUTPUT);
  pinMode(LED_CINCO, OUTPUT);
  pinMode(BOTON, INPUT_PULLUP);
}

void loop() {
  int apretoBoton = digitalRead(BOTON);

    if (apretoBoton == LOW) 
    {
      EnciendeApagaLed(LED_CINCO);
      EnciendeApagaLed(LED_CUATRO);
      EnciendeApagaLed(LED_TRES);
      EnciendeApagaLed(LED_DOS);
      EnciendeApagaLed(LED_UNO);
    }
    else
    {
      EnciendeApagaLed(LED_UNO);
      EnciendeApagaLed(LED_DOS);
      EnciendeApagaLed(LED_TRES);
      EnciendeApagaLed(LED_CUATRO);
      EnciendeApagaLed(LED_CINCO);
    }
}

void EnciendeApagaLed(int led) 
{
  digitalWrite(led, HIGH);
  delay(TIEMPO);
  digitalWrite(led, LOW);
  delay(TIEMPO);
}