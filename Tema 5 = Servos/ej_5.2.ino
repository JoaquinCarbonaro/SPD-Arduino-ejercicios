/*
Ejercicio 5.2
Continuando el ejercicio anterior agregaremos un servo, un led y un botón PULLDOWN, 
el segundo servo solo se moverá si el primer servo supera los 90° prendiendo su led azul.
*/

#include <Servo.h>

Servo servo1;       // Primer servo
Servo servo2;       // Segundo servo
int servoPin1 = 6;  // Pin del primer servo
int servoPin2 = 5;  // Pin del segundo servo
int angulo1 = 0;    // Ángulo inicial del primer servo
int angulo2 = 0;    // Ángulo inicial del segundo servo

#define LED_VERDE 12
#define LED_ROJO 11
#define LED_AZUL 10
#define PULSADOR_SUBE 2
#define PULSADOR_RESET 3
#define PULSADOR_PULLDOWN 4 // Pin del botón PULLDOWN
#define TIEMPO 50

int estadoPulsadorSube = 0;
int ultimoEstadoPulsadorSube = 0;

int estadoPulsadorReset = 0;
int ultimoEstadoPulsadorReset = 0;

int estadoPulsadorPulldown = 1; 
int ultimoEstadoPulsadorPulldown = 1;

void prenderLed(int led, int tiempo);
void apagarLed(int led, int tiempo);

void setup() 
{
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(PULSADOR_SUBE, INPUT_PULLUP);
  pinMode(PULSADOR_RESET, INPUT_PULLUP);
  pinMode(PULSADOR_PULLDOWN, INPUT);
  
  servo1.attach(servoPin1, 500, 2500);
  servo2.attach(servoPin2, 500, 2500);

  servo1.write(angulo1);
  servo2.write(angulo2);
}

void loop() 
{
  estadoPulsadorSube = digitalRead(PULSADOR_SUBE);
  estadoPulsadorReset = digitalRead(PULSADOR_RESET);
  estadoPulsadorPulldown = digitalRead(PULSADOR_PULLDOWN);

  // Código para controlar el primer servo (servo1) y los LEDs (verde y rojo)
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
                for(int i=angulo1; i<=180; i++)
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
            servo1.write(angulo1);
            delay(50);

            if(digitalRead(LED_ROJO) == HIGH)
            {
                apagarLed(LED_VERDE,300);
                //establecer la posición inicial del servo en 0 grados
                servo1.write(angulo1);
                delay(50); 
            }
        }
    }
  
  if(estadoPulsadorPulldown != ultimoEstadoPulsadorPulldown)
    {
        // Código para controlar el segundo servo con el botón PULLDOWN
        if (servo1.read() > 90 && estadoPulsadorPulldown == HIGH) 
            {
                if(digitalRead(LED_AZUL) == LOW)
                {
                    prenderLed(LED_AZUL, 300);
                    for(int i = angulo2; i <= 180; i++)
                    {
                        servo2.write(i);
                        delay(10);
                    } 
                } 
            }
    }

  ultimoEstadoPulsadorSube = estadoPulsadorSube;
  ultimoEstadoPulsadorReset = estadoPulsadorReset;
  ultimoEstadoPulsadorPulldown = estadoPulsadorPulldown;
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