// #include <Arduino.h>
// #include "motor/motorControl.h"
// #include "keypad/keypadHandler.h"

// #define MOTOR_SPEED_50RPM 38  // PWM value for 50 RPM

// void setup() {
//     Serial.begin(9600);
//     motorSetup();
//     keypadSetup();
//     Serial.println("System Ready");
// }

// void loop() {
//     char key = getKeypadInput();

//     if (key == '1') {
//         Serial.println("Key 1 Pressed - Moving Forward at 50 RPM");
//         moveForward(MOTOR_SPEED_50RPM);
//         delay(3000);
//         stopMotor();
//     } 
//     else if (key == '0') {
//         Serial.println("Key 0 Pressed - Moving Backward at 50 RPM");
//         moveBackward(MOTOR_SPEED_50RPM);
//         delay(3000);
//         stopMotor();
//     }

//     delay(200); // Small delay for debounce
// }





#include <Arduino.h>
#include "servo/servoControl.h"

void setup() {
    Serial.begin(9600);
    myServo.attach(12);  // Attach the servo to pin 12
}

void loop() {

    moveServo(90);  // Move servo to 90 degrees
    delay(3000);  // Hold position for 5 seconds
    moveServo(0); // Move servo back to 0 degrees
    delay(3000);  

}







