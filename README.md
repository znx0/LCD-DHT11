# Embedded Environmental Monitor (LCD / DHT)

<p align="center">
  <img src="images/IM3.jpg" width="80%" alt="AtherSense Main Hardware Setup" />
  <br>
  <em>Main hardware architecture running live ambient temperature and humidity sensing.</em>
</p>

Arduino-based environmental monitoring solution designed to track indoor climate metrics in real time. By interfacing a DHT11 sensor with a 16x2 LCD display, the system processes live temperature and humidity telemetry directly on the microcontroller, providing clear and instantaneous visual output.

## Features
- Real-Time Telemetry: Instant continuous updates for ambient temperature (°C) and relative humidity (%).
- Modular Hardware Architecture: Circuit design and pin mapping structured for quick testing, hardware isolation, and easy component swapping.
- Efficient Polling Cycle: Optimized code logic to prevent sensor heating and ensure accurate readings without blocking execution loops.

## Hardware
- **🧠 Microcontroller:** Arduino (Uno, Nano or compatible)
- **🌡️ Sensor:** DHT11 Temperature & Humidity Sensor
- **🖥️ Display:** 16x2 LCD Module
- **🔘 Control:** Push Button (for mode toggle/Reset) & Potentiometer (LCD brightness)

## 🔬 Testing Components Separately

Before assembling the full system, it is recommended to test each component individually using the standalone test scripts located in the [`tests/`](./tests) directory. This ensures all modules, pins, and wiring are functioning correctly.

### 🌡️ [DHT11 Sensor](https://components101.com/sites/default/files/component_datasheet/DFR0067%20DHT11%20Datasheet.pdf)

Reads ambient data and outputs temperature (°C) and humidity (%) directly to the Serial Monitor.
* **Test Script:** [`tests/dht11_test.ino`](./tests/dht11_test.ino)

<p align="center">
  <img src="images/montagemDHT11.png" width="460"/>
  <img src="images/DHT11.jpg" width="180"/>
</p>

### 🔘 [Push Buttons](https://components101.com/switches/push-button)

Verifies digital input reading and pull-up/pull-down resistor logic.
* **Test Script:** [`tests/button_test.ino`](./tests/button_test.ino)

<p align="center">
  <img src="images/montagemButton.png" width="400"/>
  <img src="images/Button.png" width="300"/>
</p>

### 🖥️  [LCD Display](https://www.vishay.com/docs/37484/lcd016n002bcfhet.pdf)

Initializes the display, renders 'Hello World' to test characters to ensure proper wiring and contrast.
If needed, you can rotate the potentiometer to adjust the brightness of the screen.
* **Test Script:** [`tests/lcd_test.ino`](./tests/lcd_test.ino)

<p align="center">
  <img src="images/LDC.png" width="600"/>
</p>

| LCD         | Arduino    | LCD        | Arduino               |
|-------------|------------|------------|-----------------------|
| RS          | Digital 12 | RW         | GND                   |
| Enable (E)  | Digital 11 | VSS        | GND                   |
| D4          | Digital 5  | VCC        | 5V                    |
| D5          | Digital 4  | LED+ (A)   | 5V (220Ω)             |
| D6          | Digital 3  | LED- (K)   | GND                   |
| D7          | Digital 2  | Vo         | Potentiometer Output  |

## 🛠️ Final Assembly & Demonstration

Once all standalone tests pass, assemble the full circuit on your main breadboard following the layout below.

### Assembly Steps
1. **Validate Components:** Ensure all modules passed the individual tests in `tests/`.
2. **Breadboard Wiring:** Connect the Arduino, DHT11, 16x2 LCD, potentiometer, and push button according to your pin mapping.
3. **Configure Pinout:** Open the main firmware (`src/main.ino`) and adjust the pin definitions if your hardware layout differs:

```cpp
// Default Pin Configuration
#define DHTPIN 2
#define BUTTON_PIN 3
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

<p align="center">
  <img src="images/IM1.jpg" width="500"/>
</p>

## 🎥 Demonstration

https://github.com/user-attachments/assets/131c299c-a692-46e8-a27a-be6d3c95b56f
