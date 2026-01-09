#include <Servo.h> // Include the Servo library

// === Motor Pins ===
#define in1 9   // Left motor direction pin 1
#define in2 8   // Left motor direction pin 2
#define in3 7   // Right motor direction pin 1
#define in4 6   // Right motor direction pin 2
#define enA 11  // Left motor speed (PWM)
#define enB 5   // Right motor speed (PWM)

// === Servo Pin and Object ===
#define servoPin 3 // New: Servo connected to digital pin 3
Servo myservo;     // Create a servo object

// === Servo Angles ===
const int centerAngle = 90;
const int leftAngle = 45;
const int rightAngle = 135; // 90 + 45

// === Speed Control ===
int speedLevel1[] = {40, 70, 90, 120, 150, 180, 200, 220, 220, 225}; // 10 levels
int speedLevel2[] = {50, 80, 110, 140, 170, 200, 220, 240, 250, 255}; // 10 levels
int currentSpeedIndex = 5; // Start at level 6 (index 5)
int leftSpeed = speedLevel1[currentSpeedIndex];
int rightSpeed = speedLevel2[currentSpeedIndex];

char command; // Incoming command via Bluetooth

void setup() {
  Serial.begin(9600); // Start serial for Bluetooth

  // Set motor pins as output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  // Attach servo to pin 3 and set to center position
  myservo.attach(servoPin);
  myservo.write(centerAngle); 
  delay(500); // Give time for servo to reach position

  Serial.println("Bluetooth Ready. Send command...");
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();
    Serial.print("Received: ");
    Serial.println(command);

    switch (command) {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': turnLeft(); break;
      case 'R': turnRight(); break;
      case 'S': Stop(); break;
      
      // New Servo Commands
      case 'X': servoLeft(); break; // Turn servo left 45 degrees
      case 'Y': servoRight(); break; // Turn servo right 45 degrees
      case 'C': servoCenter(); break; // Center servo (optional but helpful)

      case '1' ... '9':
        setSpeed(command - '1'); break;
      case '0':
        setSpeed(9); break;

      default:
        Stop(); break;
    }
  }
}

// === Movement Functions (Unchanged) ===

void forward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  // Left motor forward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);   // Right motor forward
  analogWrite(enA, leftSpeed);
  analogWrite(enB, rightSpeed);
  Serial.println("Action: Forward");
}

void backward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);   // Left motor backward
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);  // Right motor backward
  analogWrite(enA, leftSpeed);
  analogWrite(enB, rightSpeed);
  Serial.println("Action: Backward");
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);   // Left motor backward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);   // Right motor forward
  analogWrite(enA, leftSpeed);
  analogWrite(enB, rightSpeed);
  Serial.println("Action: Turn Right");
}

void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  // Left motor forward
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);  // Right motor backward
  analogWrite(enA, leftSpeed);
  analogWrite(enB, rightSpeed);
  Serial.println("Action: Turn Left");
}

void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  Serial.println("Action: Stop");
}

// === Speed Control Function (Unchanged) ===

void setSpeed(int index) {
  if (index >= 0 && index < 10) {
    currentSpeedIndex = index;
    leftSpeed = speedLevel1[index];
    rightSpeed = speedLevel2[index];
    Serial.print("Speed Level: ");
    Serial.print(index + 1);
    Serial.print(" → PWM = ");
    Serial.print(speedLevel1[index]);
    Serial.print(", ");
    Serial.println(speedLevel2[index]);
  }
}

// === Servo Control Functions (New) ===

void servoLeft() {
  myservo.write(leftAngle); // Move to 45 degrees
  Serial.print("Action: Servo Left (");
  Serial.print(leftAngle);
  Serial.println("°)");
}

void servoRight() {
  myservo.write(rightAngle); // Move to 135 degrees
  Serial.print("Action: Servo Right (");
  Serial.print(rightAngle);
  Serial.println("°)");
}

void servoCenter() {
  myservo.write(centerAngle); // Move to 90 degrees
  Serial.print("Action: Servo Center (");
  Serial.print(centerAngle);
  Serial.println("°)");
}