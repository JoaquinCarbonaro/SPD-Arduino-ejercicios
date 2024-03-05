/*
Ejercicio 6.3
Armando el siguiente circuito, tenemos que poder representar las distintas 
combinaciones de colores usando un led rgb y los valores que tomamos con el potenciómetro.
*/

#define pinPotenciometro_R A0 
#define pinPotenciometro_G A1 
#define pinPotenciometro_B A2 
#define pinLED_Rojo 6 
#define pinLED_Verde 3 
#define pinLED_Azul 5 

void setup() 
{
  pinMode(pinPotenciometro_R, INPUT);
  pinMode(pinPotenciometro_G, INPUT);
  pinMode(pinPotenciometro_B, INPUT);
  pinMode(pinLED_Rojo, OUTPUT);
  pinMode(pinLED_Verde, OUTPUT);
  pinMode(pinLED_Azul, OUTPUT);
}

void loop() 
{
  int valorPotenciometro_R = analogRead(pinPotenciometro_R); // Leer el valor del potenciómetro rojo (R)
  int valorPotenciometro_G = analogRead(pinPotenciometro_G); // Leer el valor del potenciómetro verde (G)
  int valorPotenciometro_B = analogRead(pinPotenciometro_B); // Leer el valor del potenciómetro azul (B)

  // Mapear los valores de los potenciómetros a un rango de 0-255 para el control del LED RGB
  int brillo_R = map(valorPotenciometro_R, 0, 1023, 0, 255);
  int brillo_G = map(valorPotenciometro_G, 0, 1023, 0, 255);
  int brillo_B = map(valorPotenciometro_B, 0, 1023, 0, 255);

  // Establecer el color del LED RGB
  analogWrite(pinLED_Rojo, brillo_R);
  analogWrite(pinLED_Verde, brillo_G);
  analogWrite(pinLED_Azul, brillo_B);
}
