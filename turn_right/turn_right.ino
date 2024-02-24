int motor1_pin1 = 2;
int motor1_pin2 = 3;
int motor2_pin1 = 4;
int motor2_pin2 = 5;
int motor1_speed = 9;
int motor2_speed = 10;

void setup() {
  /*
   * MOTOR 1:
   *  () => (pin1, pin2, speed)
   */
  pinMode(motor1_pin1, OUTPUT);
  pinMode(motor1_pin2, OUTPUT);
  pinMode(motor1_speed, OUTPUT);

  /*
   * MOTOR 2:
   *  () => (pin1, pin2, speed)
   */
  pinMode(motor2_pin1, OUTPUT);
  pinMode(motor2_pin2, OUTPUT);
  pinMode(motor2_speed, OUTPUT);
}

void loop() {
  analogWrite(motor1_speed, 255);
  analogWrite(motor2_speed, 255);
  
  delay(1000);
  
  turnRightDeg20();
  stop();
  
  turnLeftDeg20();
  stop();
  delay(4000);
}

void turnRightDeg20() {
  // ! At max speed is 20 degrees
  delay(200); // it starts steady
  digitalWrite(motor1_pin1, HIGH);
  digitalWrite(motor1_pin2, LOW);
  digitalWrite(motor2_pin1, LOW);
  digitalWrite(motor2_pin2, HIGH);
  delay(110);
}

void turnLeftDeg20() {
  // ! At max speed is 20 degrees
  delay(200); // it starts steady
  digitalWrite(motor1_pin1, LOW);
  digitalWrite(motor1_pin2, HIGH);
  digitalWrite(motor2_pin1, HIGH);
  digitalWrite(motor2_pin2, LOW);
  delay(110);
}

void stop(){
  digitalWrite(motor1_pin1, LOW);
  digitalWrite(motor1_pin2, LOW);
  digitalWrite(motor2_pin1, LOW);
  digitalWrite(motor2_pin2, LOW);
}

void motorForward(int pin1, int pin2) {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
}

void motorBackward(int pin1, int pin2) {
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
}
