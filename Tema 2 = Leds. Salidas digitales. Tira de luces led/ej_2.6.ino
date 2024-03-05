// C++ code
/*
Ejercicio 2-6
Auto fantastico tira de luces: hacer que 6 luces de color rojo , 
se muestren con el siguiente patron 
a=1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6...etc. 
b=1,2,3,4,5,6,5,4,3,2,1,2,3,4,5,6,5,4,3,2,1,2 ...etc 
https://www.youtube.com/watch?v=YPL7QPCfVZc 
https://www.youtube.com/watch?v=td1Ub_Pg_Hw
*/

#define LED_UNO 6
#define LED_DOS 7
#define LED_TRES 8
#define LED_CUATRO 9
#define LED_CINCO 10
#define LED_SEIS 11


void setup()
{
  pinMode(LED_UNO, OUTPUT);
  pinMode(LED_DOS, OUTPUT);
  pinMode(LED_TRES, OUTPUT);
  pinMode(LED_CUATRO, OUTPUT);
  pinMode(LED_CINCO, OUTPUT);
  pinMode(LED_SEIS, OUTPUT);
}

void loop()
{
    //declaro las variables
    int patron;
    //inicializo variables
    patron = 1;

    if(patron == 1)
    {
        PrendeYApaga(LED_UNO);
        PrendeYApaga(LED_DOS);
        PrendeYApaga(LED_TRES);
        PrendeYApaga(LED_CUATRO);
        PrendeYApaga(LED_CINCO);
        PrendeYApaga(LED_SEIS);
    }
    else
    {
        PrendeYApaga(LED_UNO);
        PrendeYApaga(LED_DOS);
        PrendeYApaga(LED_TRES);
        PrendeYApaga(LED_CUATRO);
        PrendeYApaga(LED_CINCO);
        PrendeYApaga(LED_SEIS);

        PrendeYApaga(LED_CINCO);
        PrendeYApaga(LED_CUATRO);
        PrendeYApaga(LED_TRES);
        PrendeYApaga(LED_DOS);        
    }
}


void PrendeYApaga(int led)
{
    digitalWrite(led, HIGH);
    delay(500);
	digitalWrite(led, LOW);
    delay(500);
}