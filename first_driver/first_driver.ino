/*
 * PIN2 -> motor 1: spin direction 
 * PIN3 -> motor 1: spin direction 
 * PIN4 -> motor 2: spin direction
 * PIN5 -> motor 2: spin direction
 * 
 * PIN9 -> motor 1: speed
 * PIN10-> motor 2: speed
 */
int motor1_pin1 = 2;
int motor1_pin2 = 3;

int motor2_pin1 = 4;
int motor2_pin2 = 5;

int motor1_speed = 9;
int motor2_speed = 10;

void setup() {
  pinMode(motor1_pin1, OUTPUT);
  pinMode(motor1_pin2, OUTPUT);
  pinMode(motor1_speed, OUTPUT);
  
  pinMode(motor2_pin1, OUTPUT);
  pinMode(motor2_pin2, OUTPUT);
  pinMode(motor2_speed, OUTPUT);
}

void motorForward(int pin1, int pin2) {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
}

void motorBackward(int pin1, int pin2) {
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
}

void loop() {
  analogWrite(motor1_speed, 150); // Full speed
  analogWrite(motor2_speed, 150); // Full speed
  motorForward(motor1_pin1, motor1_pin2);
  motorForward(motor2_pin1, motor2_pin2); 

  delay(1500);
  
  digitalWrite(motor1_pin2, LOW);
  digitalWrite(motor2_pin2, LOW);
  
  delay(1500);
}
