# Custom-Built 8-Channel RC Transmitter & Receiver System with OLED UI and Realtime Configuration

Take full control of your RC plane with this **feature-rich, Arduino-based 8-channel transmitter and receiver system**. Designed from the ground up for enthusiasts and developers, this system brings flexibility, precision, and reliability together in a compact package.

---

## 🔧 Key Features

### 🎮 8 Independent Channels
- **5 Analog Channels** – Perfect for controlling servos, motors, and variable inputs such as throttle, elevator, and ailerons.
- **3 Digital Channels** – Ideal for toggling switches, landing gear, LEDs, or flight modes.

### 🖥️ Onboard Configuration User Interface
An integrated OLED display with a fully functional, intuitive menu system lets you adjust all key channel parameters in real-time – no need to reprogram or use a PC.

### 📐 Realtime Channel Calibration
- Configure and fine-tune each channel’s **Minimum**, **Maximum**, and **Midpoint** values with ease.
- Make quick adjustments directly from the UI to match the mechanical limits of your servos and control surfaces.

### 🔁 Channel Inversion Capability
Each channel can be independently inverted to match the orientation and response behavior of your hardware setup.

### 💾 EEPROM-Based Configuration Saving
All settings are **permanently saved** to onboard memory. Your preferences remain intact even after powering off the transmitter or receiver, ensuring a seamless and worry-free experience.

### 📡 Robust Wireless Communication
Reliable 2.4GHz communication (e.g., via **nRF24L01 modules**) ensures stable control signal transmission over a significant range – ideal for park flyers, DIY drones, and robotics.

---

## 📟 Display & Control Interface

### OLED Display – 128x64 Resolution  
Crisp, high-contrast visuals for real-time channel monitoring and system configuration.

### Joystick-Based Navigation  
Navigate the menu using a single joystick with intuitive controls mapped to **UP**, **DOWN**, **SELECT**, and **BACK** actions – no need for multiple buttons.

---

## 🧠 Built for Tinkerers & Developers

This system is not just a transmitter – it's a **configurable control platform**. Ideal for:
- Hobbyists designing custom aircraft
- Robotics and drone developers
- RC system experimenters and learners

---

## 📘 Technical Highlights

- **Platform**: Arduino-based (compatible with Nano, Uno, etc.)
- **Display**: SSD1306 128x64 OLED
- **Channel Configuration**: Min, Max, Midpoint, Inversion
- **Memory**: EEPROM-based parameter storage
- **Input**: Joystick-emulated button controls
- **Output**: 8 PWM/Digital signals from the receiver
