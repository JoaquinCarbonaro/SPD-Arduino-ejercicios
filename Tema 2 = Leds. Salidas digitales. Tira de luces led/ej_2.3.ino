/*Ejercicio 2-3
Prender un led rojo si la suma de dos variables (hardcodeadas) es menor que 10, 
uno verde en caso de que sea mayor que 10 o todos los leds prendidos en caso contrario.
*/

#define LED_ROJO A0
#define LED_VERDE A5
int valor1;
int valor2;
int suma;

void setup()
{
    pinMode(LED_ROJO, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
    valor1 = 1;
    valor2 = 8;
  	suma = valor1 + valor2;
    //Serial.begin(9600);
}

void loop()
{
  	if (suma < 10)
    {
        digitalWrite(LED_ROJO, HIGH);
        delay(1000); 
        digitalWrite(LED_ROJO, LOW);
    }
    else if (suma > 10)
    {
        digitalWrite(LED_VERDE, HIGH);
        delay(1000); 
        digitalWrite(LED_VERDE, LOW);
    }
    else
    {
        digitalWrite(LED_ROJO, HIGH);
        digitalWrite(LED_VERDE, HIGH);
        delay(1000); 
        digitalWrite(LED_ROJO, LOW);
        digitalWrite(LED_VERDE, LOW);
    }
  	
    //Serial.print("Suma: ");
    //Serial.println(suma);
  	delay(1000);

}