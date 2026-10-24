/*
 EcoTrack - Automated Waste Segregation
 ESP32 DevKit V1 + IR + Inductive + Servos + L298N DC Motor
*/

#include <ESP32Servo.h>

#define IR_PIN 13
#define METAL_PIN 12
#define MOTOR_IN1 18
#define MOTOR_IN2 19
#define SERVO_METAL 14
#define SERVO_BIO 27
#define SERVO_NONBIO 26

Servo sMetal, sBio, sNonBio;

void setup() {
  Serial.begin(115200);
  pinMode(IR_PIN, INPUT);
  pinMode(METAL_PIN, INPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  sMetal.attach(SERVO_METAL);
  sBio.attach(SERVO_BIO);
  sNonBio.attach(SERVO_NONBIO);
  sMetal.write(0); sBio.write(0); sNonBio.write(0);
  Serial.println("EcoTrack Ready");
}

void rotateRevolver() {
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  delay(800);
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
}

void loop() {
  if (digitalRead(IR_PIN) == LOW) {
    Serial.println("Waste Detected");
    delay(500);
    rotateRevolver();
    
    if (digitalRead(METAL_PIN) == HIGH) {
      Serial.println("RESULT: METAL");
      sMetal.write(90); delay(1000); sMetal.write(0);
    } else {
      Serial.println("CAPTURE"); // Tell laptop to run YOLOv11
      delay(3000);
      if (Serial.available()) {
        String res = Serial.readStringUntil('\n');
        if (res.indexOf("BIO") >= 0) {
          sBio.write(90); delay(1000); sBio.write(0);
        } else {
          sNonBio.write(90); delay(1000); sNonBio.write(0);
        }
      }
    }
    delay(2000);
  }
}
