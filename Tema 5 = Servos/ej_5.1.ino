/*
Ejercicio 5.1
Consigna:
Para el siguiente proyecto debemos mover el servo utilizando el botón “Sube” 
de 0 a 180 grados deberá estar prendido el led verde y apagado el rojo, el botón 
“Reset” nos servirá para posicionar el servo en 0 grados prendiendo el led rojo y 
apagando el verde. Recordemos que tenemos que regresar a los 0 grados despacio, 
utilizando un delay de 50 milisegundos.
*/


/*
---SOLO SE MUEVE MIENTRAS PRESIONAS---

#include <Servo.h>
#define SERVO 6
#define BOTON_UNO 2
#define BOTON_DOS 3
#define LED_ROJO 11
#define LED_VERDE 12

//Servo
Servo myServo;
int contadorGrados=0;

void setup()
{
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(BOTON_UNO, INPUT_PULLUP);
  pinMode(BOTON_DOS, INPUT_PULLUP);

  myServo.attach(SERVO,500,2500);
  myServo.write(0);

}

void loop()
{
  int apretoBoton;
  int apretoStop;
  apretoBoton = digitalRead(BOTON_UNO);
  apretoStop = digitalRead(BOTON_DOS);
  
  
  if(apretoBoton == 0)
  {
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_VERDE, HIGH);
    contadorGrados++;
    delay(50);
    myServo.write(contadorGrados);
  }
  
  if(apretoStop == 0)
  {
    digitalWrite(LED_ROJO, HIGH);
    digitalWrite(LED_VERDE, LOW);
    for(int i=contadorGrados;i>=0;i--)
    {
      myServo.write(i);
      delay(50);
    }
    contadorGrados=0;
  }
}
*/


//exporto la biblioteca
#include <Servo.h>

//creo un objeto para manejar el servo
Servo servo1;

#define LED_VERDE 12
#define LED_ROJO 11
#define PULSADOR_SUBE 2               
#define PULSADOR_RESET 3
#define TIEMPO 50

//creo las variables: servo Pin y le asigne el pin al que lo conecte
//y angulo va a ser el angulo que va adquirir el servo al moverse
int servoPin = 6;
int angulo = 0;

//Se declaran variables para almacenar el estado actual y el estado anterior de los pulsadores 
// Estas variables se utilizan para detectar cambios en el estado de los pulsadores.
int estadoPulsadorSube = 0;
int ultimoEstadoPulsadorSube = 0;

int estadoPulsadorReset = 0;
int ultimoEstadoPulsadorReset = 0;

//Se declaran funciones
void prenderLed(int led, int tiempo);
void apagarLed(int led, int tiempo);

void setup()
{
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(PULSADOR_SUBE,INPUT_PULLUP);
  pinMode(PULSADOR_RESET,INPUT_PULLUP);
  
  //vincula el servo a la terminal
  //500 representa el pulso mínimo y 2500 representa el pulso máximo.
  servo1.attach(servoPin,500,2500);
  
  //para la posicion inicial del servo sea 0 grados
  servo1.write(angulo);
}

void loop()
{
  estadoPulsadorSube = digitalRead(PULSADOR_SUBE);
  estadoPulsadorReset = digitalRead(PULSADOR_RESET);
  
  if(estadoPulsadorSube != ultimoEstadoPulsadorSube)
    {
        // Si el pulsador está presionado
        if(estadoPulsadorSube == LOW)
        {
            //invierte el estado del LED verde
            //Si el LED verde está apagado, se enciende; y si está encendido, se apaga.
            digitalWrite(LED_VERDE, !digitalRead(LED_VERDE));
            
            //verifica si el LED verde está apagado.
            if(digitalRead(LED_VERDE) == HIGH)
            {
                apagarLed(LED_ROJO, 300);

                //incrementa gradualmente el ángulo del servo desde su posición actual hasta 180 grados 
                for(int i=angulo; i<=180; i++)
                {
                    servo1.write(i);
                    delay(10);
                }
            }
        }
    }
  
  if(estadoPulsadorReset != ultimoEstadoPulsadorReset)
    {
        if(estadoPulsadorReset == LOW)
        {
            digitalWrite(LED_ROJO, !digitalRead(LED_ROJO));
            
            //se establece la posición del servo en el ángulo actual
            //Esto asegura que el servo se detenga en su posición actual.
            servo1.write(angulo);
            delay(50);

            if(digitalRead(LED_ROJO) == HIGH)
            {
                apagarLed(LED_VERDE,300);
                //establecer la posición inicial del servo en 0 grados
                servo1.write(angulo);
                delay(50); 
            }
        }
    }
  
  ultimoEstadoPulsadorSube = estadoPulsadorSube;
  ultimoEstadoPulsadorReset = estadoPulsadorReset;
}

void prenderLed(int led, int tiempo)
{
  digitalWrite(led, HIGH);
  delay(tiempo);
}

void apagarLed(int led, int tiempo)
{
  digitalWrite(led, LOW);
  delay(tiempo);
}