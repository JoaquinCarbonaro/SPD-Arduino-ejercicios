/*
Ejercicio 6.1
Debemos lograr mostrar la temperatura y el ingreso de contraseña, solo se podrá cambiar la 
temperatura si se ingresa la contraseña correcta. Podemos bloquear el cambio de temperatura 
si se ingresa una contraseña incorrecta.
*/

#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, A0, A2, A3, A4, A5);

const byte ROWS = 4;
const byte COLS = 4;

char teclas[ROWS][COLS] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte filas[ROWS] = {10, 9, 8, 7};
byte columnas[COLS] = {6, 5, 4, 3};

Keypad teclado = Keypad(makeKeymap(teclas), filas, columnas, ROWS, COLS);

String password = "1234"; // Contraseña permitida
String inputPassword = "";
int tempPin = A1;  // Pin donde está conectado el sensor TMP36

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Ingrese clave:");
}

void loop()
{
  char key = teclado.getKey();

  if (key)
  {
    if (key == '#') // Si se presiona el botón '#' (significa confirmar la contraseña)
    {
      if (inputPassword == password)
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Correct password");
        delay(500);
        lcd.clear();
                
        int rawValue = analogRead(tempPin);
        float voltage = (rawValue / 1024.0) * 5.0;
        float temperature = (voltage - 0.5) * 100.0;
        
        lcd.setCursor(0, 0);
        lcd.print("Temp: " + String(temperature, 1) + "C");
      }
      else
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Temp: 0 C");
        lcd.setCursor(0, 2);
        lcd.print("Locked");
      }
      inputPassword = ""; // Reiniciar la contraseña ingresada
    }
    else
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temp: 0 C");
      inputPassword += key;
      lcd.setCursor(0, 2);
      lcd.print(inputPassword);
    }
  }
}
