/*
 * Using a single HC-SR04
 */
const int motor1_pin1 = 2;
const int motor1_pin2 = 3;
const int motor2_pin1 = 4;
const int motor2_pin2 = 5;
const int ultra1_trig = 6;
const int ultra1_echo = 7;

const int motor1_speed = 9;
const int motor2_speed = 10;

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
  
  /*
   * Ultrasonic Sensor 1:
   *  (trig, echo) => (duration)
   */
  pinMode(ultra1_trig, OUTPUT);
  pinMode(ultra1_echo, INPUT);
}

/******************************************************* 
 *  THE LOOP
 *******************************************************/

void loop() {
  long distance1;
  analogWrite(motor1_speed, 255);
  analogWrite(motor2_speed, 255);

  distance1 = getDistance(ultra1_trig, ultra1_echo);

  if (distance1 > 20) {
    moveForwawrdCm5();
  } else {
    turnRightDeg20();
  }
  stop();
}

/******************************************************* 
  Movements Functions
*/
void moveForwawrdCm5() {
  digitalWrite(motor1_pin1, LOW);
  digitalWrite(motor1_pin2, HIGH);
  digitalWrite(motor2_pin1, LOW);
  digitalWrite(motor2_pin2, HIGH);
  delay(200);
}

void turnRightDeg20() {
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
  delay(500);
}

/******************************************************* 
  Ultrasonic Sensor Measurement Functions
*/
long getDistance(int trig_pin, int echo_pin) {
  const int numReadings = 5;
  long readings[numReadings];
  long total = 0;
  long average = 0;

  for (int i = 0; i < numReadings; i++) {
    readings[i] = _getDistance(trig_pin, echo_pin);
    total += readings[i];
    delay(30); // delay to allow the sensor to stabilize
  }
  
  for (int i = 0; i < numReadings - 1; i++) {
    for (int j = i + 1; j < numReadings; j++) {
      if (readings[i] > readings[j]) {
        long temp = readings[i];
        readings[i] = readings[j];
        readings[j] = temp;
      }
    }
  }
  
  // median value
  if (numReadings % 2 == 0) {
    return (readings[numReadings / 2] + readings[numReadings / 2 - 1]) / 2;
  } else {
    return readings[numReadings / 2];
  }
}

long _getDistance(int trig_pin, int echo_pin) {
  long cm;
  
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  cm = pulseIn(echo_pin, HIGH)/ 29 / 2;
  
  // delay(100);
  return cm;
}


/******************************************************* */
