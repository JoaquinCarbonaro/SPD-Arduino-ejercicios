// C++ code
/*Ejercicio 1-0 
Ejercicio en clase. Compartir un proyecto de tinkercad con apellido y nombre en el código del 
proyecto y una placa arduino. 
hacer titilar la led de dos maneras distintas, 
primero dos veces cada 1 seg y luego 2 veces cada medio segundo y volver a repetir.
definir al menos dos variables y mostrar en el monitor serial lo que está ocurriendo.
*/

int ledPin = LED_BUILTIN;  // Pin al que está conectado el LED (generalmente es el pin 13)
int repetitions = 2;       // Número de repeticiones

void setup() 
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  // Inicializa la comunicación con el monitor serial
}

void loop() 
{
  for (int i = 0; i < repetitions; i++) {
    digitalWrite(ledPin, HIGH);
    delay(500);  // Enciende el LED durante 0.5 segundos
    digitalWrite(ledPin, LOW);
    delay(500);  // Apaga el LED durante 0.5 segundos
  }
  Serial.println("LED titilado 2 veces cada 0.5 segundos");

  delay(1000);  // Espera 1 segundo antes de la siguiente secuencia

  for (int i = 0; i < repetitions; i++) 
  {
    digitalWrite(ledPin, HIGH);
    delay(1000);  // Enciende el LED durante 1 segundo
    digitalWrite(ledPin, LOW);
    delay(1000);  // Apaga el LED durante 1 segundo
  }
  Serial.println("LED titilado 2 veces cada 1 segundo");

  delay(1000);  // Espera 1 segundo antes de la siguiente secuencia
}
