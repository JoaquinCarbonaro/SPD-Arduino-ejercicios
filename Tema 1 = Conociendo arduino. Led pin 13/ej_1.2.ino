/*Ejercicio 1-2
Declarar una variable contador. En el loop incrementar en 1 el contador, y cuando el contador 
sea par, debemos encender el led integrado  3 veces cada 500 milisegundos, en caso contrario 
si el número es impar debemos encender el led una vez 2 segundos. Mostrar el valor del contador 
por el monitor serial.
*/

// C++ code
//

int contador = 0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
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
              digitalWrite(LED_BUILTIN, HIGH);
              delay(250);
              digitalWrite(LED_BUILTIN, LOW);
              delay(250);
          }
    	}
    }
    else
    {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(2000); // Wait for 1000 millisecond(s)
        digitalWrite(LED_BUILTIN, LOW);
        delay(1000);
    }    
}