# EcoTrack Technical Design Document

## System Flow
IR Sensor (D13) detects waste entry
-> Revolver rotates (DC Motor + L298N on D18,D19)
-> Inductive Sensor (D12) checks Metal
-> If not Metal, USB Camera captures
-> YOLOv11 on Laptop classifies Bio vs Non-Bio
-> Result sent to ESP32 via Serial 115200
-> ESP32 drives Servos (D14 Metal, D27 Bio, D26 Non-Bio) to push via sliding lid

## Circuit Diagram
ESP32 DevKit V1:
IR VCC->3.3V, GND->GND, OUT->D13
Inductive Sensor: Brown->12V, Blue->GND, Black->Voltage Divider (20k/10k)->D12
Servos: VCC->5V, GND->GND, Signal->D14/D27/D26
L298N: IN1->D18, IN2->D19, ENA->3.3V, 12V Battery

## Impact
Automates collection point, improves recycling for TN ULBs, reward points in App encourage segregation at source.

## Testing
Metal can -> Metal Bin, Banana leaf -> Bio Bin, Plastic -> Non-Bio Bin
