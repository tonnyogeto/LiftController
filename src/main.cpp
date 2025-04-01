

// #include <Arduino.h>


// #include <Servo.h>  // Standard Servo library for Arduino Uno

// Servo myServo;  // Create a Servo object

// #define SERVO_PIN 9 // Define the PWM pin for the servo (change if needed)

// void setup() {
//   myServo.attach(SERVO_PIN);  // Attach the servo to the pin
//   Serial.begin(9600);  // Start serial communication for debugging
//   Serial.println("Servo Motor Control Initialized");
// }

// void loop() {
//   // Move the servo to 0 degrees
//   myServo.write(0);
//   Serial.println("Servo at 0 degrees");
//   delay(1000);


//   // Move the servo to 180 degrees
//   myServo.write(180);
//   Serial.println("Servo at 180 degrees");
//   delay(1000);
// }


#include <Arduino.h>
#include "motor/motorControl.h"
#include "keypad/keypadHandler.h"

// Function to check keypad and control motor
void handleKeypad() {
    digitalWrite(4, LOW); // Activate Col 1
    if (!digitalRead(2)) {
        Serial.println("Key 1 Pressed - Moving Forward");
        moveForward(150);  // Move forward at speed 150
        delay(3000);       // Run for 3 seconds
        stopMotor();       // Stop after 3 seconds
    }

    digitalWrite(7, LOW); // Activate Col 2
    if (!digitalRead(3)) {
        Serial.println("Key 0 Pressed - Moving Backward");
        moveBackward(150); // Move backward at speed 150
        delay(3000);       // Run for 3 seconds
        stopMotor();       // Stop after 3 seconds
    }

    delay(200); // Debounce delay
}

void setup() {
    motorSetup();  // Initialize motor pins
    Serial.println("System Ready");
}

void loop() {
    handleKeypad();  // Continuously check keypad input
}






