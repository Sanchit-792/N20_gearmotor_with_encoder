#include <Encoder.h>

// Motor Driver Pins
int PWMA = 5;
int AIN1 = 4;
int AIN2 = 3;
int STBY = 11;

// Encoder Pins
int encoderC1 = A0;
int encoderC2 = A1;

// Motor Speed
int motorSpeed = 100;
int maxMotorSpeed = 255;

// Create Encoder Object
Encoder motorEncoder(encoderC1, encoderC2);

void setup() {
  Serial.begin(115200);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  
  digitalWrite(STBY, HIGH); // Enable motor driver
}

void loop() {
  // Read Encoder Position
  long pos = motorEncoder.read();
  Serial.print("Encoder Position: ");
  Serial.println(pos);

  // Move Motor Forward
  moveMotor(motorSpeed);

  delay(100); // Small delay for stability
}

void moveMotor(int speed) {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, speed);
}

void stopMotor() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 0);
}
