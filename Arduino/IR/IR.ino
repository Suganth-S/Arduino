void setup() 
{
pinMode(1,OUTPUT);// put your setup code here, to run once:
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(7,OUTPUT);
}

void loop() {
  if(digitalRead(7)==LOW)// put your main code here, to run repeatedly:
{
  digitalWrite(2,HIGH);
  delay(1000);
  digitalWrite(1,LOW);
  delay(1000);
  digitalWrite(5,LOW);
  delay(1000);
}
if(digitalRead(7)==HIGH)// put your main code here, to run repeatedly:
{
  digitalWrite(2,LOW);
  delay(1000);
  digitalWrite(1,HIGH);
  delay(1000);
  digitalWrite(5,HIGH);
  delay(1000);
}
}
