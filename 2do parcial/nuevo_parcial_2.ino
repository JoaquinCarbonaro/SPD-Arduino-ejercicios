#include <Servo.h>

#define LED_AMARILLA 12
#define LED_VERDE 10
#define LED_ROJA 11
#define PULSADOR 13
#define TRIGGER_PIN 1
#define ECHO_PIN 2
#define MOTOR_SERVO 6
#define POTENTIOMETER_PIN A0
#define SENSOR_TEMPERATURA A1

bool luzAmarillaEncendida = false;
Servo miServo;

void setup() 
{
  pinMode(PULSADOR, INPUT_PULLUP);
  pinMode(LED_AMARILLA, OUTPUT);
  pinMode(LED_ROJA, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);
  pinMode(SENSOR_TEMPERATURA, INPUT);
  miServo.attach(MOTOR_SERVO);
  // Inicializar estado inicial
  inicializarLuces();
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
    if (controlarTemperatura())
    {
      activarSensorYMotor();
    }
    else{
        PosicionServoCerrado();
    } 
  } 
  else 
  {
    PosicionServoAbierto();
  }
}

void inicializarLuces() 
{
  digitalWrite(LED_AMARILLA, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_ROJA, LOW);
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
  else {
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
    inicializarLuces();
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
    PosicionServoCerrado();  // Ángulo medio
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

void PosicionServoCerrado() 
{
  miServo.write(90);
}

void PosicionServoAbierto() 
{
  miServo.write(0);
}

bool controlarTemperatura() 
{
  int lecturaSensor = analogRead(SENSOR_TEMPERATURA);
  float voltaje = (lecturaSensor / 1023.0) * 5.0; // Convertir lectura a voltaje
  float temperaturaCelsius = (voltaje - 0.5) * 100; // Calcular la temperatura en grados Celsius

  if (temperaturaCelsius >= 37.5) 
  {
    controlarTitileoLuces(LED_ROJA);
    digitalWrite(LED_VERDE, LOW);
    return false;
  } 
  else 
  {
    controlarTitileoLuces(LED_VERDE);
    digitalWrite(LED_ROJA, LOW);
    return true;
  }
}

// Puntero a función para seleccionar la función de titileo
void (*titileoFuncion)(int) = titileoLento;

void controlarTitileoLuces(int ledEncendida) 
{  
  // Leer el valor del potenciómetro
  int potValue = analogRead(POTENTIOMETER_PIN);

  // Mapear el valor del potenciómetro al rango de velocidad deseado (ajusta según sea necesario)
  int velocidad = map(potValue, 0, 1023, 1000, 6000);

  if (potValue < 300) {
    titileoFuncion = titileoLento;
  } else if (potValue < 700) {
    titileoFuncion = titileoMedio;
  } else {
    titileoFuncion = titileoRapido;
  }
  // Llamar a la función de titileo seleccionada
  titileoFuncion(ledEncendida);
}

void titileoLento(int ledEncendida) 
{
  // Función de titileo lento
  digitalWrite(ledEncendida, HIGH);
  delay(3000);
  digitalWrite(ledEncendida, LOW);
  delay(3000);
}

void titileoMedio(int ledEncendida) 
{
  // Función de titileo medio
  digitalWrite(ledEncendida, HIGH);
  delay(1000);
  digitalWrite(ledEncendida, LOW);
  delay(1000);
}

void titileoRapido(int ledEncendida) 
{
  // Función de titileo rápido
  digitalWrite(ledEncendida, HIGH);
  delay(500);
  digitalWrite(ledEncendida, LOW);
  delay(500);
}
