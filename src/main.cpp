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





// #include <Arduino.h>
// #include "servo/servoControl.h"

// void setup() {
//     Serial.begin(9600);
//     myServo.attach(12);  // Attach the servo to pin 12
// }

// void loop() {

//     moveServo(180);  // Move servo to 90 degrees
//     delay(3000);  // Hold position for 5 seconds
//     moveServo(0); // Move servo back to 0 degrees
//     delay(3000);  

// }


#include <Arduino.h>
#include "keypad/keypadHandler.h"
#include "motor/motorControl.h"
#include "ultrasonic/ultrasonicSensor.h"

// Target distances for each floor
#define DIST_FLOOR_0 45
#define DIST_FLOOR_1 30
#define DIST_FLOOR_2 0

void setup() {
    Serial.begin(9600);
    keypadSetup();
    motorSetup();
    ultrasonicSetup();
    Serial.println("Elevator system initialized.");
}

void loop() {
    char key = getKeypadInput();

    if (key != '\0') {
        Serial.print("Key Pressed: ");
        Serial.println(key);

        float targetDistance;

        // Determine target distance
        if (key == '0') targetDistance = DIST_FLOOR_0;
        else if (key == '1') targetDistance = DIST_FLOOR_1;
        else if (key == '2') targetDistance = DIST_FLOOR_2;
        else return; // Invalid key, ignore

        float currentDistance = getDistance();
        Serial.print("Current Distance: ");
        Serial.println(currentDistance);

        // Move motor until target distance is reached
        if (currentDistance < targetDistance - 1) {
            // Need to move DOWN (increase distance)
            moveBackward(100); // Or whatever speed you want
            while (getDistance() < targetDistance - 1) {
                delay(100);  // Small delay for sensor stability
            }
        } else if (currentDistance > targetDistance + 1) {
            // Need to move UP (decrease distance)
            moveForward(100);
            while (getDistance() > targetDistance + 1) {
                delay(100);
            }
        }

        stopMotor();
        Serial.println("Arrived at desired floor.");
        delay(1000); // Debounce before allowing new input
    }
}







