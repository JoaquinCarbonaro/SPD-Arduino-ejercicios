/*
Ejercicio 5.3
Controlar la posición del servo usando un potenciómetro.
*/

#include <Servo.h>

#define PIN_SERVO 3
#define PIN_POTENCIOMETRO A0

// Variables
Servo miServo;
int angulo = 0;

void setup() 
{
  //permite al servo moverse de acuerdo con las instrucciones que recibe a través del pin especificado.  
  miServo.attach(PIN_SERVO);
}

void loop() 
{
  int lecturaPot = analogRead(PIN_POTENCIOMETRO); //lee el valor del potenciómetro
  angulo = map(lecturaPot, 0, 1023, 0, 180); //mapea el valor del potenciómetro al rango de ángulo del servo

  miServo.write(angulo); // Mueve el servo al ángulo determinado por el potenciómetro
  delay(15); // Pequeño retardo para suavizar la lectura
}
