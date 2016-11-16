// These constants won't change:
const int sensorPin = A1;    // pin that the sensor is attached to
const int motor1 = 5;     // pin that motor 1's low is attached to
const int motorHigh1 = 6;    // pin that motor 1's high is attached to
const int motorLow1 = 7;        // pin that motor 1's enable is attached to
const int motorHigh2 = 8;        // pin that motor 2's enable is attached to
const int motorLow2 = 9;     // pin that motor 2's low is attached to
const int motor2 = 10;    // pin that motor 2's high is attached to

void setup() {
  // turn on LED to signal the start of the calibration period:
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // read the sensor:
  int analogValue = analogRead(sensorPin);
  if(analogValue>300){
    digitalWrite(motorLow1,LOW);
    digitalWrite(motorHigh1,HIGH);
    digitalWrite(motor1,HIGH);
  }else{
    digitalWrite(motorLow1,HIGH);
    digitalWrite(motorHigh1,LOW);
    digitalWrite(motor1,HIGH);
  }
  
  
  if(analogValue<300){
     digitalWrite(motorLow2,LOW);
     digitalWrite(motorHigh2,HIGH);
     digitalWrite(motor2,HIGH);
  }else{
     digitalWrite(motorLow2,HIGH);
     digitalWrite(motorHigh2,LOW);
     digitalWrite(motor2,HIGH);
  }
  // fade the LED using the calibrated value:
  Serial.println(analogValue);
}
