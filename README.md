# LCD Temperature & Humidity Reader

Arduino-based temperature and humidity monitor using a DHT11 sensor and a 16x2 LCD display.

## Features
- Real-time temperature and humidity readings
- Reset statistics via push button

## Hardware
- Arduino Uno/Nano
- DHT11 sensor
- 16x2 LCD display
- 2x push buttons

## Wiring

### 1. DHT11 Sensor

<p align="center">
  <img src="images/montagemDHT11.png" width="350"/>
  <img src="images/DHT11.jpg" width="200"/>
</p>

### 2.Push Buttons

<p align="center">
  <img src="images/montagemButton.png" width="350"/>
  <img src="images/Button.png" width="250"/>
</p>

### 3. LCD Display 

![LCD Wiring](images/LDC.png)

| LCD         | Arduino    | LCD        | Arduino               |
|-------------|------------|------------|-----------------------|
| RS          | Digital 12 | RW         | GND                   |
| Enable (E)  | Digital 11 | VSS        | GND                   |
| D4          | Digital 5  | VCC        | 5V                    |
| D5          | Digital 4  | LED+ (A)   | 5V (220Ω)             |
| D6          | Digital 3  | LED- (K)   | GND                   |
| D7          | Digital 2  | Vo         | Potentiometer Output  |

### Final Assembly (Demo)

![Complete Setup](/images(IM1.jpg)
![Complete Setup](/images(IM2.jpg)
![Complete Setup](/images(IM3.jpg)
