/*
Ejercicio 1-3
Consigna SUMA, si la suma de dos números hardcodeados es:
a) 3 que prenda el led integrado 300 milisegundos y luego se apague.
b) 4 que prenda el led integrado 600 milisegundos y luego se apague.
c) 5 que prenda el led integrado 1000 milisegundos y luego se apague.
d) De otra forma, que prenda 2 segundos, luego se apague y que prenda 
500 milisegundos más y se apague.
*/

// C++ code
//
int valor1;
int valor2;
int suma;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    valor1 = 1;
    valor2 = 8;
  	suma = valor1 + valor2;
    //Serial.begin(9600);
}

void loop()
{
  	if (suma == 3)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(300); 
        digitalWrite(LED_BUILTIN, LOW);
    }
    else if (suma == 4)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(600); 
        digitalWrite(LED_BUILTIN, LOW);
    }
    else if (suma == 5)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(1000); 
        digitalWrite(LED_BUILTIN, LOW);
    }
    else
    {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(2000); 
        digitalWrite(LED_BUILTIN, LOW);
        delay(500); 
        digitalWrite(LED_BUILTIN, HIGH);
    }
  	
    //Serial.print("Suma: ");
    //Serial.println(suma);
  	delay(1000);

}