#include <LiquidCrystal.h>

#define COLS 16 // Columnas del LCD
#define ROWS 2 // Filas del LCD
#define VELOCIDAD 300

#include <DHT11.h>

int pin=8;
int led_rojo = 10;
int led_amarillo = 9;

DHT11 dht11(pin);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String texto_fila = "VIVERO - CALLIZAYA";

void setup() {
  Serial.begin(9600); 
  lcd.begin(COLS, ROWS);
}


void loop() {

  // Obtenemos el tamaño del texto
  int tam_texto=texto_fila.length();

  // Mostramos entrada texto por la izquierda
  for(int i=tam_texto; i>0 ; i--)
  {
    String texto = texto_fila.substring(i-1);

    // Limpiamos pantalla
    lcd.clear();

    //Situamos el cursor
    lcd.setCursor(0, 0);

    // Escribimos el texto
    lcd.print(texto);

    // Esperamos
    delay(VELOCIDAD);
  }


  for(int i=1; i<=16;i++)
  {
    // Limpiamos pantalla
    lcd.clear();

    //Situamos el cursor
    lcd.setCursor(i, 0);

    // Escribimos el texto
    lcd.print(texto_fila);

    // Esperamos
    delay(VELOCIDAD);
  }

  // Desplazamos el texto hacia la izquierda en la segunda fila
  for(int i=16;i>=1;i--)
  {
    // Limpiamos pantalla
    lcd.clear();

    //Situamos el cursor
    lcd.setCursor(i, 1);

    // Escribimos el texto
    lcd.print(texto_fila);

    // Esperamos
    delay(VELOCIDAD);
  }

  // Mostramos salida del texto por la izquierda
  for(int i=1; i<=tam_texto ; i++)
  {
    String texto = texto_fila.substring(i-1);

    // Limpiamos pantalla
    lcd.clear();

    //Situamos el cursor
    lcd.setCursor(0, 1);

    // Escribimos el texto
    lcd.print(texto);

    // Esperamos
    delay(VELOCIDAD);
  }

   int err;
   float temp, hum;
   if((err = dht11.read(hum, temp)) == 0)
      {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Temperatura ");
      lcd.print(temp);
    lcd.setCursor(0,1);
    lcd.print("Humedad " );
    lcd.print(hum);
    delay(2000);
      }
   else
      {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Sin Datos");
    lcd.setCursor(0,1);
    lcd.print("Sin Datos");
    delay(2000);
      }


}
