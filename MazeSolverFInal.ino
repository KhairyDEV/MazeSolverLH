#include "mario_theme.h"
#include <Arduino.h>
#include "PacmanTheme.h"
#include "pitches.h"

const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;
const int ena = 9;
const int enb = 10;


const int leftSensor = 13;
const int centerSensor = 11;
const int rightSensor = 12;
const int wallSensor = 8;

const int forwardSpeed = 65;
const int turningSpeed = 70;
const int turnDelay = 75;
const int uTurnDelay = 50;
int buzzerPin = A1;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT); 
  playMarioTheme(buzzerPin);
  pinMode(leftSensor, INPUT);
  pinMode(centerSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(wallSensor, INPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  pinMode(7, OUTPUT); 
  pinMode(6, OUTPUT);
}

void loop() {
  bool leftV = digitalRead(leftSensor);
  bool centerV = digitalRead(centerSensor);
  bool rightV = digitalRead(rightSensor);
  bool wallV = digitalRead(wallSensor);

  if (wallV == LOW) {
    stopMotors();
    Serial.println("Wall detected");
        playPacmanTheme(buzzerPin);  
  }
  else if (leftV == HIGH) {
    turnLeft();
    Serial.println("Turn Left");
  }
  else if (centerV == HIGH) {
    moveForward();
    Serial.println("Move Forward");
  }
  else if (rightV == HIGH) {
    turnRight();
    Serial.println("Turn Right");
  }
  else if (leftV == LOW && centerV == LOW && rightV == LOW) {
    uTurn();
    Serial.println("U-Turn");
  }
  else  {
    stopMotors();
    Serial.println("Stop");
  }

}

// Movement functions
void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(ena, forwardSpeed);
  analogWrite(enb, forwardSpeed);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
}

void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(ena, 0);
  analogWrite(enb, turningSpeed);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  delay(turnDelay);
  stopMotors();
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(ena, turningSpeed);
  analogWrite(enb, 0);
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  delay(turnDelay);
  stopMotors();
}

void uTurn() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(ena, 80);
  analogWrite(enb, 80);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  delay(uTurnDelay);
  stopMotors();
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(ena, 0);
  analogWrite(enb, 0);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  delay(10);
}
