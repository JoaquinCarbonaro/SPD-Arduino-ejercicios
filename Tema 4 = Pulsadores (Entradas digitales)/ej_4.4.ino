/*
Ejercicio 4-4 
En secuencia :
Tenemos tres botones y tres luces (verde , amarilla y roja)

Secuencia correcta : 
al presionar el botón 1 se enciende la luz verde, 
al presionar el botón 2 se enciende la luz amarilla(solo si esta la verde encendida), 
al presionar el botón 3 se enciende la luz roja(solo si esta la verde y amarilla encendida), 

Secuencia Incorrecta : 
a)
al presionar el botón 1 se enciende la luz verde.
al presionar el botón 3 se apagan todas las luces. 

b)
al presionar el botón 1 se enciende la luz verde,
al presionar el botón 2 se enciende la luz amarilla(solo si esta la verde encendida), al presionar el botón 2 o 1 se apagan todas las luces. 
*/

#define VERDE 13
#define AMARILLO 12
#define ROJO 11
#define BOTON_1 2
#define BOTON_2 3
#define BOTON_3 4

// Variables para control de luces
bool ledVerde = false;
bool ledAmarilla = false;
bool ledRoja = false;

void setup() {
  
  // Configuración de pines y botones
  pinMode(BOTON_1, INPUT_PULLUP);
  pinMode(BOTON_2, INPUT_PULLUP);
  pinMode(BOTON_3, INPUT_PULLUP);
  pinMode(VERDE, OUTPUT);
  pinMode(AMARILLO, OUTPUT);
  pinMode(ROJO, OUTPUT);
}

void loop() {
  // Control de luces
  digitalWrite(VERDE, ledVerde);
  digitalWrite(AMARILLO, ledAmarilla);
  digitalWrite(ROJO, ledRoja);

  // Lectura de los valores de los botones
  int estadoBoton1 = digitalRead(BOTON_1);
  int estadoBoton2 = digitalRead(BOTON_2);
  int estadoBoton3 = digitalRead(BOTON_3);

  // Secuencia de luces y botones
  if (estadoBoton1 == LOW) {
    ledVerde = true;
    ledAmarilla = false;
    ledRoja = false;
  }

  if (estadoBoton2 == LOW && ledVerde) {
    ledAmarilla = true;
  }

  if (estadoBoton3 == LOW && ledVerde && ledAmarilla) {
    ledRoja = true;
  }

  // Pequeño retardo para evitar el rebote 
  delay(10);
}
