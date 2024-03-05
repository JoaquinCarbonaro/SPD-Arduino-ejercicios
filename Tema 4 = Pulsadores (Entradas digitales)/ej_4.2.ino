/*
Ejercicio 4-2
Realizar un circuito con una led y dos pulsadores (un PULL UP y un PULL DOWN) un 
botón la apaga y otro la enciende.
*/

#define LED 12
#define BOTON_ENCENDER 4
#define BOTON_APAGAR 5

bool ledEncendido = false;

void setup() 
{
  pinMode(LED, OUTPUT);
  pinMode(BOTON_ENCENDER, INPUT);
  pinMode(BOTON_APAGAR, INPUT);

  digitalWrite(BOTON_ENCENDER, HIGH);  // Activa la resistencia pull-up interna
  digitalWrite(BOTON_APAGAR, LOW);     // Activa la resistencia pull-down externa
}

void loop() 
{
  int sensor_encender = digitalRead(BOTON_ENCENDER);
  int sensor_apagar = digitalRead(BOTON_APAGAR);
  
  if (sensor_encender == LOW) 
  {
    // Botón de encendido presionado
    ledEncendido = true;
  }
  
  if (sensor_apagar == HIGH) 
  {
    // Botón de apagado presionado
    ledEncendido = false;
  }

  if (ledEncendido) 
  {
    digitalWrite(LED, HIGH);
  } 
  else 
  {
    digitalWrite(LED, LOW);
  }
}
