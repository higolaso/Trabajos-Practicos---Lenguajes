// Librerias

#include <Servo.h>

// Constantes

#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6

// Variables

Servo topServo;
Servo bottomServo;
int frequency = 0;
int color=0;

// Funciones

// -

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20% (Configurando la escala de frecuencia al 20%)
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  topServo.attach(7);
  bottomServo.attach(8);
  Serial.begin(9600);
}
void loop() {
  topServo.write(115);
  delay(500);
  
  for(int i = 115; i > 65; i--) {
    topServo.write(i);
    delay(2);
  }
  delay(500);
  
  color = readColor();
  delay(10);  
  switch (color) {
    case 1:
    bottomServo.write(50);
    break;
    case 2:
    bottomServo.write(75);
    break;
    case 3:
    bottomServo.write(100);
    break;
    case 4:
    bottomServo.write(125);
    break;
    case 5:
    bottomServo.write(150);
    break;
    case 6:
    bottomServo.write(175);
    break;
    
    case 0:
    break;
  }
  delay(300);
  
  for(int i = 65; i > 29; i--) {
    topServo.write(i);
    delay(2);
  } 
  delay(200);
  
  for(int i = 29; i < 115; i++) {
    topServo.write(i);
    delay(2);
  }
  color=0;
}
// Custom Function - readColor() (Funcion customizada - read(leer)color())
int readColor() {
  // Setting red filtered photodiodes to be read (Configurando los fotodiodos rojos para la lectura)
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency (Leyendo las frecuencias de la salida)
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  // Printing the value on the serial monitor (Imprimiendo el valor en el monitor)
  Serial.print("R= "); //printing name (imprimiendo nombre)
  Serial.print(frequency); //printing RED color frequency (imprimiendo frecuencia del color ROJO)
  Serial.print("  ");
  delay(50);
  // Setting Green filtered photodiodes to be read (Configurando los fotodiodos verdes para la lectura)
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency (Leyendo las frecuencias de la salida)
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  // Printing the value on the serial monitor (Imprimiendo el valor en el monitor)
  Serial.print("G= "); //printing name (imprimiendo nombre)
  Serial.print(frequency); //printing RED color frequency (imprimiendo frecuencia del color ROJO)
  Serial.print("  ");
  delay(50);
  // Setting Blue filtered photodiodes to be read (Configurando los fotodiodos azules para la lectura)
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency (Leyendo las frecuencias de la salida)
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor (Imprimiendo el valor en el monitor)
  Serial.print("B= "); //printing name (imprimiendo nombre)
  Serial.print(frequency); //printing RED color frequency (imprimiendo frecuencia del color ROJO)
  Serial.println("  ");
  delay(50);
  if(R<45 & R>32 & G<65 & G>55){
    color = 1; // Rojo
  }
  if(G<55 & G>43 & B<47 &B>35){
    color = 2; // Naranja
  }
  if(R<53 & R>40 & G<53 & G>40){
    color = 3; // Verde
  }
  if(R<38 & R>24 & G<44 & G>30){
    color = 4; // Amarillo
  }
  if(R<56 & R>46 & G<65 & G>55){
    color = 5; // Marron
  }
  if (G<58 & G>45 & B<40 &B>26){
    color = 6; // Azul
  }
  return color;  
}
