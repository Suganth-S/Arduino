/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/AnalogInput

 */

#include <SoftwareSerial.h> 
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
#define rx 2                                          //define what pin rx is going to be.
#define tx 3                                          //define what pin tx is going to be.

SoftwareSerial myserial(rx,tx);//define how the soft serial port is going to work.


String inputstring = "";                              //a string to hold incoming data from the PC
String sensorstring = "";                             //a string to hold the data from the Atlas Scientific product
boolean input_stringcomplete = false;                 //have we received all the data from the PC
boolean sensor_stringcomplete = false;                //have we received all the data from the Atlas Scientific product
float ph;                                             //used to hold a floating point number that is the pH. 



void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);                                 //set baud rate for the hardware serial port_0 to 9600
  myserial.begin(9600);                               //set baud rate for software serial port_3 to 9600
  inputstring.reserve(10);                            //set aside some bytes for receiving data from the PC
  sensorstring.reserve(30);                           //set aside some bytes for receiving data from Atlas Scientific product
}

void serialEvent() {                                  //if the hardware serial port_0 receives a char
  char inchar = (char)Serial.read();                  //get the char we just received
  inputstring += inchar;                              //add it to the inputString
  if (inchar == '\r') {                               
    input_stringcomplete = true;                      //if the incoming character is a <CR>, set the flag
  }
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue); if (input_stringcomplete) {                         //if a string from the PC has been received in its entirety                     
    myserial.print(inputstring);                      //send that string to the Atlas Scientific product
    inputstring = "";                                 //clear the string
    input_stringcomplete = false;                     //reset the flag used to tell if we have received a completed string from the PC      
  }

  if (myserial.available() > 0) {                     //if we see that the Atlas Scientific product has sent a character.
    char inchar = (char)myserial.read();              //get the char we just received
    sensorstring += inchar;
    if (inchar == '\r') {
      sensor_stringcomplete = true;                   //if the incoming character is a <CR>, set the flag
    }
  }


  if (sensor_stringcomplete) {                        //if a string from the Atlas Scientific product has been received in its entirety
    Serial.println(sensorstring);                     //send that string to the PC's serial monitor
    ph = sensorstring.toFloat();                      //convert the string to a floating point number so it can be evaluated by the Arduino

    if (ph >= 7.0) {                                  //if the pH is greater than or equal to 7.0
      Serial.println("high");                         //print "high" this is demonstrating that the Arduino is evaluating the pH as a number and not as a string
    }

    if (ph <= 6.999) {                                //if the pH is less than or equal to 6.999
      Serial.println("low");                          //print "low" this is demonstrating that the Arduino is evaluating the pH as a number and not as a string
    }

    sensorstring = "";                                //clear the string:
    sensor_stringcomplete = false;                    //reset the flag used to tell if we have received a completed string from the Atlas Scientific product
  }
}
