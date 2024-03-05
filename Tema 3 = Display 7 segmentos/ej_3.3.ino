/*
Ejercicio 3-3
Crear un algoritmo que represente un contador binario, 
el primer led (que se encuentra a la izq) es el más significativo los valores van de 0 a 15.
*/

#define b_1 12
#define b_2 11
#define b_3 10
#define b_4 9

void setup() 
{
  pinMode(b_1, OUTPUT);
  pinMode(b_2, OUTPUT);
  pinMode(b_3, OUTPUT);
  pinMode(b_4, OUTPUT);
}


void loop() 
{
  for (int i = 0; i <= 15; i++) 
  {
    printSegmentos(i);
    delay(1000); // Espera 1 segundo
  }
}

void printSegmentos(int digit) 
{
    // Apagar todos los segmentos
    digitalWrite(b_1, LOW);
    digitalWrite(b_2, LOW);
    digitalWrite(b_3, LOW);
    digitalWrite(b_4, LOW);
    
    switch (digit) 
    {
        case 1:
        digitalWrite(b_4, HIGH);
        break;
        case 2:
        digitalWrite(b_3, HIGH);
        break;
        case 3:
        digitalWrite(b_3, HIGH);
        digitalWrite(b_4, HIGH);
        break;
        case 4:
        digitalWrite(b_2, HIGH);
        break;
        case 5:
        digitalWrite(b_2, HIGH);
        digitalWrite(b_4, HIGH);
        break;
        case 6:
        digitalWrite(b_2, HIGH);
        digitalWrite(b_3, HIGH);
        break;
        case 7:
        digitalWrite(b_2, HIGH);
        digitalWrite(b_3, HIGH);
        digitalWrite(b_4, HIGH);
        break;
        case 8:
        digitalWrite(b_1, HIGH);
        break;
        case 9:
        digitalWrite(b_1, HIGH);
        digitalWrite(b_4, HIGH);
        break;
        case 10:
        digitalWrite(b_1, HIGH);
        digitalWrite(b_3, HIGH);
        break;
        case 11:
        digitalWrite(b_1, HIGH);
        digitalWrite(b_3, HIGH);
        digitalWrite(b_4, HIGH);
        break;
        case 12:
        digitalWrite(b_1, HIGH);
        digitalWrite(b_2, HIGH);
        break;
        case 13:
        digitalWrite(b_1, HIGH);
        digitalWrite(b_2, HIGH);
        digitalWrite(b_4, HIGH);
        break;
        case 14:
        digitalWrite(b_1, HIGH);
        digitalWrite(b_2, HIGH);
        digitalWrite(b_3, HIGH);
        break;
        case 15:
        digitalWrite(b_1, HIGH);
        digitalWrite(b_2, HIGH);
        digitalWrite(b_3, HIGH);
        digitalWrite(b_4, HIGH);
        break;
    }
}

