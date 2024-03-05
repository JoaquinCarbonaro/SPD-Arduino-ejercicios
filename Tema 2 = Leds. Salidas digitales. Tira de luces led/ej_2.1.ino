/*Ejercicio 2-1
Al ejercicio 1-2 de la clase anterior reemplazar por un led rojo si es par y un led 
verde si es impar en el enunciado, cumpliendo con la misma consigna.

Declarar una variable contador. En el loop incrementar en 1 el contador, y cuando el contador 
sea par, debemos encender el led integrado  3 veces cada 500 milisegundos, en caso contrario 
si el número es impar debemos encender el led una vez 2 segundos. Mostrar el valor del contador 
por el monitor serial.
*/

int contador = 0;
#define LED_ROJO A0
#define LED_VERDE A5

void setup()
{
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
    contador ++;
    Serial.print("Contador: ");
    Serial.println(contador);
    
    if (contador % 2 == 0)
    {
        if (contador % 2 == 0) 
        {
          // Contador par, enciende el LED 3 veces cada 500 ms
          for (int i = 0; i < 3; i++) 
          {
              digitalWrite(LED_ROJO, HIGH);
              delay(250);
              digitalWrite(LED_ROJO, LOW);
              delay(250);
          }
    	}
    }
    else
    {
        digitalWrite(LED_VERDE, HIGH);
        delay(2000); // Wait for 1000 millisecond(s)
        digitalWrite(LED_VERDE, LOW);
        delay(1000);
    }    
}