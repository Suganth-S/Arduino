/*
PORTABLE SIREN
Arduino-Producing a wailing sound as a loud warning signal
LED Flsher for Visual Alert
source: http://www.electroschematics.com/9548/arduino-siren-sound-alarm/
*/
 
#define ALARMSOUNDER 5 
#define ALARMSWITCH 8
int i = 0; 
int val = LOW; 
int pre_val = LOW; 
int state = 0; 
void setup()
{
    pinMode(ALARMSOUNDER, OUTPUT); 
    pinMode(ALARMSWITCH, INPUT); 
}
void loop()
{
    state = digitalRead(ALARMSWITCH);
    if (state == 1)
    {
        for(i = 0; i < 255; i = i + 2)
        {
            analogWrite(ALARMSOUNDER, i);
            delay(10);
        }
        for(i = 255; i > 1; i = i - 2)
        {
            analogWrite(ALARMSOUNDER, i);
            delay(5);
        }
        for(i = 1; i <= 10; i++)
        {
            analogWrite(ALARMSOUNDER, 200);
            delay(100);
            analogWrite(ALARMSOUNDER, 25);
            delay(100);
        }
    }
    else
    {
        analogWrite(ALARMSOUNDER,0);
    }
    pre_val = val; 
}

