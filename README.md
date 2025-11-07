# VL53L0X Distance Sensor with SSD1306 OLED Display

This project demonstrates how to interface the **VL53L0X Time-of-Flight distance sensor** with an **SSD1306 OLED display** using an **ESP32-C3** microcontroller. It continuously measures distance and displays the result on the OLED screen.

## Hardware Requirements

- ESP32-C3 development board  
- VL53L0X Time-of-Flight distance sensor  
- SSD1306 OLED display (128x64, I²C interface)  
- Jumper wires  
- Breadboard (optional)

## Libraries Used

Make sure to install the following libraries via the Arduino Library Manager:

- `Adafruit_VL53L0X`
- `Adafruit_SSD1306`
- `Adafruit_GFX`
- `Wire` (built-in)

## Wiring Guide

| Component     | ESP32-C3 Pin |
|---------------|--------------|
| VL53L0X SDA   | GPIO 8       |
| VL53L0X SCL   | GPIO 9       |
| OLED SDA      | GPIO 8       |
| OLED SCL      | GPIO 9       |
| GND           | GND          |
| VCC           | 3.3V         |

> Note: Both the VL53L0X and SSD1306 share the same I²C bus.

## Code Overview

### Setup

- Initializes serial communication at 115200 baud.
- Sets up I²C on GPIO 8 (SDA) and GPIO 9 (SCL).
- Initializes the OLED display at address `0x3C`.
- Initializes the VL53L0X sensor.

### Loop

- Reads distance data from the VL53L0X.
- Displays the distance in millimeters on the OLED.
- If the sensor is out of range, it shows `"Out of range"`.

## Display Output

- `"Dist: XXXXmm"` — when a valid measurement is available  
- `"Out of range"` — when the sensor cannot detect a valid target

## Timing

- The loop updates the display every **200 milliseconds**.

## Troubleshooting

- If the OLED or sensor fails to initialize, the program halts with an error message on the serial monitor and OLED.
- Ensure correct I²C wiring and address (`0x3C` for OLED).

## License

This project is open-source and free to use under the MIT License.


This project is open-source and free to use under the MIT License.
