#include <Servo.h>  // Include the Servo library

Servo myServo;  // Create a servo object to control a servo

int irSensorPin = 2;  // Pin where the IR sensor is connected
int irSensorValue = 0;  // Variable to store the value from the IR sensor
int servoPin = 9;  // Pin where the servo motor is connected

void setup() {
  myServo.attach(servoPin);  // Attach the servo on pin 9 to the servo object
  pinMode(irSensorPin, INPUT);  // Set the IR sensor pin as an input
  myServo.write(0);  // Initialize the servo position to 0 degrees
}

void loop() {
  irSensorValue = digitalRead(irSensorPin);  // Read the value from the IR sensor
  
  if (irSensorValue == HIGH) {  // If the IR sensor detects an object
    myServo.write(180);  // Rotate the servo to 180 degrees
    delay(1000);  // Wait for 1 second
    myServo.write(0);  // Rotate the servo back to 0 degrees
  }
  
  delay(100);  // Small delay to avoid multiple detections for a single object
}
