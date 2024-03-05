/*Ejercicio 2-4
Semáforo simple:
Deberás hacer un semáforo que encienda la luz roja por dos segundo , 
luego la amarilla por 1 segundo y por último la verde por 3 segundos, 
con 0,5 segundos entre cada luz
*/

#define LED_ROJO A0
#define LED_AMARILLO A2
#define LED_VERDE A5

void setup()
{
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  //Serial.begin(9600);
}

void loop()
{
    //Serial.print("Contador: ");
    //Serial.println(contador);
    
    digitalWrite(LED_ROJO, HIGH);
    delay(2000);
    digitalWrite(LED_ROJO, LOW);

    delay(500);

    digitalWrite(LED_AMARILLO, HIGH);
    delay(1000);
    digitalWrite(LED_AMARILLO, LOW);

    delay(500);

    digitalWrite(LED_VERDE, HIGH);
    delay(3000);
    digitalWrite(LED_VERDE, LOW);

    delay(500);
   
}