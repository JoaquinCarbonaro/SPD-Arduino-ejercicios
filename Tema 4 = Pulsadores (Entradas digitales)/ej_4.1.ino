/*
Ejercicio 4-1
(primer botón) colocar un botón INPUT_PULLUP, que permita encender una luz por 
3 segundos cada vez que se presiona y está apagada. 
*/

#define LED 12
#define BOTON 3

void setup() 
{
  //necesitamos configurar la entrada como
  //INPUT_PULLUP si no agregamos la resistencia externa
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() 
{
  int sensorVal = digitalRead(BOTON);
 
  if (sensorVal == 0) 
  {
    digitalWrite(LED, HIGH);
  	delay(3000);
    digitalWrite(LED, LOW);
  	delay(1000);
    
  }
}