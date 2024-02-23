/*
 * Using a single HC-SR04
 */

const int trig_pin = 6;
const int echo_pin = 7;

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, inches, cm;
  
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  duration = pulseIn(echo_pin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(duration);
  Serial.print(" duration, ");
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(200);
}

long microsecondsToInches(long microseconds) {
  /*
   * According to Parallax's datasheet for the PING))), there are 73.746
   * microseconds per inch (i.e. sound travels at 1130 feet per second).
   * This gives the distance travelled by the ping, outbound and return,
   * so we divide by 2 to get the distance of the obstacle.
   */
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  /* The speed of sound is 340 m/s or 29 microseconds per centimeter.
   * The ping travels out and back, so to find the distance of the object we
   * take half of the distance travelled.
  */
  return microseconds / 29 / 2;
}
