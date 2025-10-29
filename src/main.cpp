#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_VL53L0X.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial.begin(115200);
  Wire.begin(8, 9); // ESP32-C3 I²C pins

  Serial.println("VL53L0X with SSD1306 OLED");

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED init failed");
    while (1);
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("VL53L0X");
  display.display();
  delay(1000);

  Serial.println("Initializing VL53L0X sensor...");

  if (!lox.begin()) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Sensor init failed!");
    display.display();
    while (1);
  }
}

void loop() {
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);

  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);

  if (measure.RangeStatus != 4) {
    display.print("Dist: ");
    display.print(measure.RangeMilliMeter);
    display.println("mm");
  } else {
    display.println("Out of range");
  }

  display.display();
  delay(200);
}
