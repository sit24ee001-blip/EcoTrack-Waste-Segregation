# EcoTrack - Automated Waste Segregation at Collection Point

EcoTrack is an IoT + AI system mounted on waste collection vehicles for Tamil Nadu ULBs. It automates segregation to improve recycling efficiency.

### How it Works
1. IR sensor detects waste entry
2. Revolver compartment rotates waste to detection zone (DC Motor + L298N)
3. Inductive sensor checks for Metal
4. USB Camera captures image -> YOLOv11 classifies as Biodegradable vs Non-Biodegradable
5. ESP32 DevKit V1 drives Servos to push waste via sliding lid into correct bin: Metal / Bio / Non-Bio

### Hardware Components
- ESP32 DevKit V1, IR Sensor (D13), Inductive Sensor (D12), USB Camera, 3x Servo (D14, D27, D26), DC Motor with L298N (D18,D19), 3 Bins

### Setup Steps
1. Wiring: Connect sensors and servos as per docs/Circuit_Diagram.txt
2. Firmware: Open firmware/EcoTrack_Firmware.ino in Arduino IDE -> Install ESP32 Board -> Select COM Port -> Upload
3. AI Model: Open ai_model/YOLOv11_Training.ipynb in Google Colab -> Train on waste dataset -> Download best.pt
4. App: User app scans QR on bin, sees points for correct segregation, redeem rewards
5. Testing: Place Metal / Bio / Non-Bio waste and verify bin sorting

### Tech Stack
ESP32, Arduino C++, YOLOv11, Python, OpenCV, Flutter, Firebase

### Sample Data
Check sample_data/ folder for test images of Metal, Bio, Non-Bio

### Team: SIT Chennai - TN ULB Problem
### License: MIT
