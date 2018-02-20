#include <LiquidCrystal.h>

// Estos son los pines a la Arduino donde la pantalla esta conectada
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Columnas y filas de la pantalla LCD:
  lcd.begin(16, 2);
}

void loop() {
  int control = 0;
  int maxNum = 10;
  int x = 0;
  bool flag = false;
  // Mensaje:
  lcd.print("Contador cutre:");
  // Poner el cursor a la fila 0 (la primera) o a 1 (la segunda fila)
  // Las columnas iran de 0 a 15, ya que es un display de 16 columnas y 2 filas
  lcd.setCursor(15, 1);
  lcd.print(control);
  delay(1000);

  for (x=0; x < maxNum*2; x++){
    lcd.setCursor(15, 1);
    if (flag){
      control--;
    }else{
      control++;
      if (control == maxNum){
        flag = true;
        lcd.setCursor(14, 1);
      }
    }
    lcd.print(control);
    delay(1000);
    // Borramos el 1 del 10
    if (control == maxNum){
      lcd.setCursor(14, 1);
      lcd.print(" ");
    }
  }
  lcd.clear();
  lcd.print("DONE");
  delay(1000);
  lcd.clear();
}
