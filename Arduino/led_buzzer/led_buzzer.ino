// the setup function runs once when you press reset or power the board
void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(8, OUTPUT);
    // initialize digital pin LED_BUILTIN as an output.
  pinMode(10, OUTPUT);
   // declare pin 9 to be an output:
  pinMode(9, OUTPUT);
  beep(50000);
  beep(50000);
  beep(50000);
  delay(10);
 }
// the loop function runs over and over again forever
void loop() {
  digitalWrite(8, LOW);// turn the LED on (HIGH is the voltage level)
  delay(10000);                       // wait for a second
  digitalWrite(8, HIGH);    // turn the LED off by making the voltage LOW
  delay(10000);    // wait for a second
   digitalWrite(10, LOW);// turn the LED on (HIGH is the voltage level)
  delay(10000);                       // wait for a second
  digitalWrite(10, HIGH);    // turn the LED off by making the voltage LOW
  delay(10000);    // wait for a second
  beep(2000); 
  }
  void beep(unsigned char delayms)
{
  digitalWrite(9, HIGH);      // Almost any value can be used except 0 and 255
                           // experiment to get the best tone
  delay(2000);          // wait for a delayms ms
  digitalWrite(9, LOW);       // 0 turns it off
  delay(2000);          // wait for a delayms ms   
}  
