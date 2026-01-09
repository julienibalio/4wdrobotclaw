# 🤖 Arduino Bluetooth 4WD Car with Servo Claw

<video src="Demo3.mp4" controls width="600"></video>

This project demonstrates how to control a **4-wheel drive (4WD) robotic car** with an attached **servo-powered claw** using Arduino and Bluetooth.  
The car can move in all directions, adjust speed levels, and operate the claw via Bluetooth commands.

---

## 📌 Features
- 🔹 Remote control via Bluetooth (HC-05/HC-06 module)
- 🔹 4WD motor driver setup (L298N or similar)
- 🔹 10 adjustable speed levels (PWM control)
- 🔹 Commands for **Forward, Backward, Left, Right, Stop**
- 🔹 Servo claw control: **Left, Right, Center**
- 🔹 Serial feedback for debugging and monitoring

---

## 🛠️ Hardware Requirements
- Arduino Uno / Nano / Mega
- L298N Motor Driver (or equivalent)
- HC-05 / HC-06 Bluetooth Module
- 4 DC Motors + Wheels (4WD setup)
- Servo motor (for claw mechanism)
- Power supply (Battery pack)
- Jumper wires

---

## ⚡ Pin Configuration
| Component         | Arduino Pin | Description              |
|-------------------|-------------|--------------------------|
| Left Motor Dir1   | 9           | Motor A direction        |
| Left Motor Dir2   | 8           | Motor A direction        |
| Right Motor Dir1  | 7           | Motor B direction        |
| Right Motor Dir2  | 6           | Motor B direction        |
| Left Motor Speed  | 11          | PWM (Motor A enable)     |
| Right Motor Speed | 5           | PWM (Motor B enable)     |
| Servo Claw        | 3           | Servo signal pin         |

---

## 🎮 Bluetooth Commands
| Command | Action |
|---------|--------|
| `F` | Forward |
| `B` | Backward |
| `L` | Turn Left |
| `R` | Turn Right |
| `S` | Stop |
| `X` | Servo Left (45°) |
| `Y` | Servo Right (135°) |
| `C` | Servo Center (90°) |
| `1`–`9` | Speed levels 1–9 |
| `0` | Speed level 10 (max) |

---

## 📜 Code Overview
- **Movement Functions:** `forward()`, `backward()`, `turnLeft()`, `turnRight()`, `Stop()`
- **Speed Control:** `setSpeed(index)` adjusts PWM values for left/right motors
- **Servo Control:** `servoLeft()`, `servoRight()`, `servoCenter()` move claw positions
- **Bluetooth Input:** Commands are read via `Serial.read()` and mapped to actions

---

## ▶️ Getting Started
1. Upload the provided Arduino sketch to your board.
2. Pair your Bluetooth module with your phone (default password: `1234` or `0000`).
3. Use a Bluetooth terminal app to send commands (`F`, `B`, `L`, `R`, `S`, `X`, `Y`, `C`, `1`–`0`).
4. Watch your car and claw respond in real time!

---


## 📫 Author
**Julien G. Ibalio**  

---

## 🌟 Acknowledgments
This project blends **Arduino robotics** with **Bluetooth control** and a **servo claw**, making it a fun and practical way to learn about embedded systems, motor drivers, and wireless communication.
