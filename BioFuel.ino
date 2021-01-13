
# include <DHT.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//#include <Fonts/FreeMonoBold18pt7b.h>


#define DHTPIN_ONE 7
#define DHTPIN_TWO 10
#define DHTPIN_THREE 11


#define DHTTYPE DHT11

#define Solenoid 8
#define Pump 9

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

DHT dht1 (DHTPIN_ONE, DHTTYPE);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  dht1.begin();
  pinMode (Solenoid, OUTPUT);
  pinMode(Pump, OUTPUT);


  //SCREEN
   // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  // Clear the buffer
  display.clearDisplay();
  printText();
  delay(1500);
//}

}

void loop() {
  // put your main code here, to run repeatedly:

 float Temp = dht1.readTemperature();
// float Temp_two = dht2.readTemperatur

 //Serial.println(Temp);
 if(Temp >= 20){
  digitalWrite(Solenoid, HIGH);
  digitalWrite(Pump, HIGH);
  
 }

// if (Temp = = 25){
 else if (Temp <= 25){
  digitalWrite(Solenoid, LOW);
  digitalWrite(Pump, LOW);
 }


  printText();
  display.display();
  delay(500);
  display.clearDisplay();

}

  void printText() {
  //display.setFont(&FreeMonoBold10pt7b);
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(45, 28);            // Start at top-left corner
  //display.print(Temp);
 // display.drawCircle(92, 8, 3, WHITE);
  display.setCursor(100, 27);
  display.print("C");
  display.setCursor(45, 62);
 // display.print(h);
  display.print("%");

  }
 

  

//}
