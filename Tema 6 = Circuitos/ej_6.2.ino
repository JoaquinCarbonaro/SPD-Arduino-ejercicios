/*
Ejercicio 6.2
Armar el termómetro, indicando con los leds la temperatura leída.
*/

#define SENSOR_PIN A0
#define LED_ROJO 3
#define LED_VERDE 4
#define LED_AZUL 5

void setup() 
{
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  //Serial.begin(9600);
}

void loop() 
{
  int lectura = analogRead(SENSOR_PIN); // Leer el valor analógico del sensor TMP36
  float voltage = (lectura / 1023.0) * 5.0; // Convertir la lectura analógica a voltaje
  float temperature = (voltage - 0.5) * 100.0; // Convertir el voltaje a temperatura en grados Celsius

  /*
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println("°C");
  */

  // Encender los LEDs según la temperatura
  if (temperature < 20.0) 
  {
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AZUL, HIGH);
  } 
  else if (temperature > 70.0) 
  {
    digitalWrite(LED_ROJO, HIGH);
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AZUL, HIGH);
  } 
  else 
  {
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AZUL, HIGH);
  }
  delay(1000); // Puedes ajustar el tiempo de muestreo
}
