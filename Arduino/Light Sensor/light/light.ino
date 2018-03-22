int sensorPin = A0;    // select the input pin for the potentiometer
//int ledPin = 13;      // select the pin for the LED
int sensorValue = 5;  // variable to store the value coming from the sensor


void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(11,OUTPUT);
}


/*void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);
}*/
void loop()
{
  sensorValue=analogRead(A0);
  if(sensorValue <= 14)
  digitalWrite(13,HIGH);
  else
  digitalWrite(13,LOW);
  Serial.println(5);
  delay(2);
}

