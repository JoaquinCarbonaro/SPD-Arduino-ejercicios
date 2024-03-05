/*Ejercicio 1-1
Ejercicio realizado en clase. Primer proyecto arduino. Encender y apagar el led de la 
placa cada 500 ms. Mostrar los milisegundos por el monitor serial
*/

int contador = 0;

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  Serial.println(contador);
  contador ++;
}

