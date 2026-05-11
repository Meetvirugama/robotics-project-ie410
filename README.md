# 🤖 Robotics Project — IE410 (Winter 2026)

## 👥 Team Members

* 202401243 Meet Virugama
* 202401102 Mohammadjunaid S. Kureshi
* 202401204 Shlok Ukani
* 202401198 Ramit Sherashiya
* 202401080 Darshil Kanani

---

## 📌 Project Overview

This project demonstrates object manipulation using a robotic arm through three progressively complex tasks:

1. **Pre-programmed Pick-and-Place** (Open-loop control)
2. **Camera-assisted Pick-and-Place** (Perception-driven control)
3. **Dual-arm Object Handover** (Multi-robot coordination)

The system integrates concepts from kinematics, motion planning, computer vision, and robotic coordination.

---

## ⚙️ System Architecture

### 🔹 Task 1

Arduino directly controls the robotic arm using predefined joint angles.

### 🔹 Task 2

Camera → Python (OpenCV) → Serial Communication → Arduino → Robot

### 🔹 Task 3

Arduino (Robot 1) ↔ Serial Communication ↔ Arduino (Robot 2)

---

## 🧠 Key Concepts Implemented

* Forward & Inverse Kinematics (conceptual understanding)
* Step-based trajectory planning
* Gripper-based object grasping
* Image processing using OpenCV
* Serial communication between systems
* Multi-robot synchronization using handshake protocol

---

## 🧰 Hardware Used

* Arduino Braccio Robot Arm
* Two-finger gripper
* Webcam / Smartphone Camera

---

## 💻 Software Stack

* Python 3
* OpenCV
* Arduino IDE
* PySerial

---

## ▶️ How to Run

### 🔹 Task 1 — Pre-programmed Pick & Place

Upload the following file using Arduino IDE:
arduino/task1_pick_place.ino

---

### 🔹 Task 2 — Camera-Assisted Pick & Place

Install dependencies:
pip install -r requirements.txt

Run:
python python/task2_camera_pick_place.py

⚠️ Update the correct serial port in the Python file before running.

---

### 🔹 Task 3 — Dual Robot Handover

Upload to respective robots:
arduino/task3_master.ino
arduino/task3_slave.ino

---

## 🎥 Demo Video

https://drive.google.com/file/d/1GrtE0H8TUWDI1zfG5Pl3ai5-VM1ELaU1/view?usp=sharing

---

## 📄 Report

Available in:
docs/report.pdf

---

## ⚠️ Assumptions & Limitations

* Fixed lighting conditions for vision-based detection
* Approximate pixel-to-robot mapping (manual calibration)
* Open-loop control (no sensor feedback)
* Limited precision due to servo-based system

---

## 🚀 Future Improvements

* Full inverse kinematics implementation
* Camera calibration using homography
* Smooth trajectory planning (cubic interpolation)
* ROS-based system integration
* Feedback-based control using sensors

---

## 🏁 Conclusion

This project demonstrates a complete pipeline from basic robotic control to perception-based manipulation and multi-robot coordination. It provides practical exposure to real-world robotics challenges involving motion planning, sensing, and system integration.

---
