#include <Servo.h>

#define LED_AMARILLA 12
#define PULSADOR 13
#define TRIGGER_PIN 1
#define ECHO_PIN 2
#define MOTOR_SERVO 6

bool luzAmarillaEncendida = false;
Servo miServo;

void setup() 
{
  pinMode(PULSADOR, INPUT_PULLUP);
  pinMode(LED_AMARILLA, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
   
  miServo.attach(MOTOR_SERVO);

  // Inicializar estado inicial
  inicializarLuz();
}

void loop() 
{
  if (detectarPulsador()) 
  {
    cambiarEstadoLuces();
    delay(300);  // Evitar rebote del botón
  }

  if (luzAmarillaEncendida) 
  {
    activarSensorYMotor();
  } 
  else 
  {
    PosicionServoAbierto();
  }
}

void inicializarLuz() 
{
  digitalWrite(LED_AMARILLA, LOW);
}

bool detectarPulsador() 
{
  static bool estadoAnterior = HIGH;  // Almacenar el estado anterior
  bool estadoActual = digitalRead(PULSADOR);

  // Cambio de estado detectado
  if (estadoActual == LOW && estadoAnterior == HIGH) 
  {
    estadoAnterior = estadoActual;
    return true;
  } 
  else 
  {
    estadoAnterior = estadoActual;
    return false;
  }
}

void cambiarEstadoLuces() 
{
  luzAmarillaEncendida = !luzAmarillaEncendida;
  if (luzAmarillaEncendida) 
  {
    digitalWrite(LED_AMARILLA, HIGH);
  } else {
    inicializarLuz();
  }
}

void activarSensorYMotor() 
{
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Medir el tiempo de respuesta del sensor ultrasónico
  unsigned long duration = pulseIn(ECHO_PIN, HIGH);
  // Calcular la distancia en centímetros
  int distancia = duration * 0.0343 / 2;

  // Verificar la distancia y activar el motor si es necesario
  if (distancia >= 200) 
  {
    miServo.write(90);  // Ángulo medio
  } 
  else if (distancia >= 0 && distancia <= 200) 
  {
    PosicionServoAbierto();
  } 
  else 
  {
    PosicionServoAbierto();   // Ángulo mínimo
  }
}

void PosicionServoAbierto() 
{
  miServo.write(0);
}