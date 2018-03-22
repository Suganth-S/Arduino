void setup()  { 
  // declare pin 9 to be an output:
  pinMode(9, OUTPUT);
  beep(50000);
  beep(50000);
  beep(50000);
  delay(10);
} 

void loop()  
{ 
  beep(2000); 
}

void beep(unsigned char delayms)
{
  digitalWrite(9, HIGH);      // Almost any value can be used except 0 and 255
                           // experiment to get the best tone
  delay(delayms);          // wait for a delayms ms
  digitalWrite(9, LOW);       // 0 turns it off
  delay(delayms);          // wait for a delayms ms   
}  
