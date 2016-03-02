
#include <Wire.h>                  
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);
#include "DHT.h"
#define DHTPIN 3 //Conectamos el Sensor al pin digital 9
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

int input;
int sw=0;
boolean Start=false;
int mensaje=0;

void setup() {
lcd.begin(16,2);// Indicamos medidas de LCD
dht.begin();
 pinMode(6, OUTPUT); 
 pinMode(A0,OUTPUT);// foco ventanas leds bicolor
 pinMode(A1,OUTPUT); // foco Rojo
 pinMode(A2,OUTPUT);// foco Verde
 pinMode(A3,OUTPUT);// motor uno
 pinMode(A4,OUTPUT);// motor dos
 pinMode(A5,OUTPUT);
  Serial.begin(9600); 
}
void loop() { 
int h = dht.readHumidity();    // Lee la humedad
int t= dht.readTemperature();

if (Serial.available()>0){
    mensaje =Serial.read();
    if (mensaje=='1'){
      Start=true;
    }
    else
    {
      Start=false;
    }
  }
  if (Start==true){
    float h = dht.readHumidity(); //Se lee la humedad
    float t = dht.readTemperature(); //Se lee la temperatura
    //Se imprimen las variables
    Serial.println(h);
    delay(10); //Este delay nos servirá para la lectura de datos en Java
    Serial.println(t);
    delay(2000); //Se espera 2 segundos para seguir leyendo //datos
  }
/////////////////////////////////////////////////// 
lcd.clear();//Elimina todos los simbolos del LCD
lcd.setCursor(0,0);//Posiciona la primera letra despues del segmento 5 en linea 1              
lcd.print("Humedad Relativa ");
lcd.setCursor(6,1);
lcd.print(h);//Escribe la humedad
lcd.print(" %");   

delay (2500);
///////////////////////////////////////////////////              
lcd.clear();
lcd.setCursor(3,0);
lcd.print("Temperatura "); 
lcd.setCursor(6,1);
lcd.print(t);//Escribe la temperatura
lcd.print(" C'");   

if(t>25){

  if(sw==0){
    for(int i=0;i<=30;i++){
VentiladorOn();
digitalWrite(A0,HIGH);
    }
    sw=1;
  }
}
if(t<=20){
 if(sw==1){
    for(int i=0;i<=30;i++){
VentiladorOff();
digitalWrite(A0,LOW);
    }
    sw=0;
  }
}             
delay (2500);
///////////////////////////////////////////////////             
lcd.clear();
lcd.setCursor(0,0);
lcd.print("   Datos Clima");   
                  
  delay (2500);
}


void VentiladorOn(){
  digitalWrite(A3,HIGH);
   digitalWrite(A4,HIGH);
}


void VentiladorOff(){
  digitalWrite(A3,LOW);
   digitalWrite(A4,LOW);
}

