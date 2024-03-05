/*
Ejercicio 4-3
Realizar un circuito con dos led y dos pulsadores (un PULL UP y un PULL DOWN)
Al presionar el botón 1 (mientras lo mantenga presionado)se enciende la luz 1.
Al presionar el botón 2 (mientras lo mantenga presionado)se enciende la luz 2
*/

#define LED_1 11
#define LED_2 12
#define BOTON_PULUP 4
#define BOTON_PULLDOWN 5

void setup() 
{
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(BOTON_PULUP, INPUT);
  pinMode(BOTON_PULLDOWN, INPUT);

  digitalWrite(BOTON_PULUP, HIGH);  // Activa la resistencia pull-up interna
  digitalWrite(BOTON_PULLDOWN, LOW);     // Activa la resistencia pull-down externa
}

void loop() 
{
  // Lectura de los valores de los botones
  int estadoBotonPullup = digitalRead(BOTON_PULUP);
  int estadoBotonPulldown = digitalRead(BOTON_PULLDOWN);

  // Encendido de los LEDs mientras los botones estén presionados
  if (estadoBotonPullup == LOW) 
  {
    digitalWrite(LED_1, HIGH);
  } 
  else {
    digitalWrite(LED_1, LOW);
  }

  if (estadoBotonPulldown == HIGH) 
  {
    digitalWrite(LED_2, HIGH);
  } 
  else {
    digitalWrite(LED_2, LOW);
  }

  // Pequeño retardo para evitar el rebote y permitir la detección adecuada de los botones
  delay(10);
}