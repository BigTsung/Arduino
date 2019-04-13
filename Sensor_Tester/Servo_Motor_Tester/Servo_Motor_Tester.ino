#include <Servo.h>
const int pinNum = 7;
Servo servo;
int angle = 0;
int lastAngle = -1;
bool add = true;

void setup() {
  servo.attach(pinNum, 500, 2400);
  servo.write(90); // 一開始先置中90度
  delay(3000);
}

void loop() 
{
  if(angle >= 180)
    add = false;
  else if(angle <= 0)
    add = true;
  
  if(add)
    angle++;
  else
    angle--;
  
  servo.write(angle);

  delay(5);
}
