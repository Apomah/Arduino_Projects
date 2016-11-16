#include <Servo.h>      // include the servo library


Servo servoMotor;       // creates an instance of the servo object to control a servo
// These constants won't change:
const int sensorPin = A1;    // pin that the sensor is attached to
const int motor1 = 5;     // pin that motor 1's low is attached to
const int motorHigh1 = 6;    // pin that motor 1's high is attached to
const int motorLow1 = 7;        // pin that motor 1's enable is attached to
const int motorHigh2 = 8;        // pin that motor 2's enable is attached to
const int motorLow2 = 9;     // pin that motor 2's low is attached to
const int motor2 = 10;    // pin that motor 2's high is attached to
const int ledPin = 4;       // pin that the LED is attached to
const int ledPin0 = 3;      // pin that the LED is attached to
const int ledPin1 = 2;      // pin that the LED is attached to
const int servoPin = 11;       // Control pin for servo motor

void setup() {
  
  // Sets the different Arduino Pins as outputs
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  
  // attaches the servo on pin 2 to the servo object
  servoMotor.attach(servoPin);
  
  // initialize serial communications:
  Serial.begin(9600);
}

void loop() {
  // read the sensor:
  int analogValue = analogRead(sensorPin);
  
  
  // Beginning of Motor Section
  
  // Sets the conditions for the first motor to go forwards or backwards (the 300 should be modified to reflect the flex sensor's values)
  if(analogValue>650){
    digitalWrite(motorLow1,LOW);
    digitalWrite(motorHigh1,HIGH);
    digitalWrite(motor1,HIGH);
  }else{
    digitalWrite(motorLow1,HIGH);
    digitalWrite(motorHigh1,LOW);
    digitalWrite(motor1,HIGH);
  }
  
  // Sets the conditions for the second motor to go forwards or backwards (the 300 should be modified to equal the modified 300 above)
  if(analogValue<650){
     digitalWrite(motorLow2,LOW);
     digitalWrite(motorHigh2,HIGH);
     digitalWrite(motor2,HIGH);
  }else{
     digitalWrite(motorLow2,HIGH);
     digitalWrite(motorHigh2,LOW);
     digitalWrite(motor2,HIGH);
  }
  // End of Motor Section
  
  
  //  Beginning of LED Section
  
  // if the analog value is between the values, turn on the LED attached to the pin corresponding to ledPin:
  if (analogValue > 500 && analogValue < 550) {
    digitalWrite(ledPin, HIGH);
  } 
  else {
    digitalWrite(ledPin,LOW); 
  }

  // if the analog value is between either set of values, turn on the LED attached to the pin corresponding to ledPin0:
  if (analogValue > 550 and analogValue < 675 or analogValue > 675 and analogValue < 800) {
    digitalWrite(ledPin0, HIGH);
  } 
  else {
    digitalWrite(ledPin0,LOW); 
  }
  
  // if the analog value is between the set of values, turn on the LED attached to the pin corresponding to ledPin1:
  if (analogValue > 800 && analogValue < 850) {
    digitalWrite(ledPin1, HIGH);
  } 
  else {
    digitalWrite(ledPin1,LOW); 
  }
  // End of LED Portion
  
  
  // Beginning of Servo Section
  
  // if your sensor's range is less than 0 to 1023, you'll need to modify the map() function to use the values you discovered:
  int servoAngle = map(analogValue, 500, 850, -79, 379);
  // Ensures the values going into servoAngle do not exceed -79 to 379 (these should reflect the last two values above) for the servo doesn't try to over extend
  servoAngle = constrain(servoAngle, -79, 379);
  // move the servo using the angle from the sensor:
  servoMotor.write(servoAngle);
  // End of Servo Section
  
  
  //Prints the Flex Sensor values to the serial monitor to be inputed into the respective fields above (anything that refers to an analog or sensor value)
  Serial.println(analogValue);
}
