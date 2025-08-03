# Arduino-Based 8-Channel RC Transmitter & Receiver System

A fully-featured, custom-built **8-channel RC transmitter and receiver system** designed using Arduino, featuring real-time configuration via an OLED UI, EEPROM memory for persistent settings, and robust 2.4GHz wireless communication. Ideal for RC planes, DIY drones, robotics, and experimental control systems.

---

## 🚀 Features

### ✅ **8 Independent Channels**
- **5 Analog Channels** – Smooth control over throttle, elevator, rudder, ailerons, etc.
- **3 Digital Channels** – Perfect for switches, gear control, lights, or flight modes.

### 🖥️ **OLED Display with Real-Time UI**
- Integrated **128x64 SSD1306 OLED display**
- Fully navigable UI using a joystick (emulating UP, DOWN, SELECT, BACK)
- View and adjust channel values live during operation

### ⚙️ **Configurable Parameters per Channel**
- Set **Minimum**, **Maximum**, and **Midpoint** positions for all channels
- **Invert** any channel individually to match hardware requirements

### 💾 **EEPROM-Based Settings Storage**
- Save all configurations to EEPROM
- Retains all settings even after power cycle or shutdown

### 📡 **Wireless Communication**
- Uses **nRF24L01 (2.4GHz)** modules for reliable transmission
- Designed for stable and responsive communication range

---

## 📦 System Overview

| Component    | Description                           |
|--------------|---------------------------------------|
| **Transmitter** | Reads analog/digital inputs, sends data via RF |
| **Receiver**    | Receives data and outputs PWM/digital signals |
| **UI Input**    | 1x Joystick (used for navigating the UI) |
| **Display**     | 128x64 OLED (SSD1306, I2C interface) |
| **Wireless**    | nRF24L01 or compatible 2.4GHz RF modules |
| **MCU**         | Arduino Nano / Uno (Transmitter and Receiver) |

---

## 🔧 Hardware Requirements

- 2 × Arduino boards (Nano or Uno recommended)
- 1 × Joystick module (for menu navigation)
- 1 × OLED display (SSD1306, 128x64, I2C)
- 2 × nRF24L01 RF modules
- Potentiometers / Switches for channel inputs
- Servos / Actuators for channel outputs
- Optional: External power supply, regulator, or booster (for RF module stability)

---

## 🔌 Wiring Summary

### Transmitter
- Analog pins → Potentiometers
- Digital pins → Switches
- I2C (A4/A5) → OLED
- Digital pins (CE, CSN) → nRF24L01

### Receiver
- nRF24L01 input → SPI pins
- Output pins → Servo PWM signals (D3–D10 etc.)
- EEPROM used for saving configurations

---

## 📂 File Structure

