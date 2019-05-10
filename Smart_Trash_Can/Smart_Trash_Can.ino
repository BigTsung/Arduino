#include <Servo.h>

const int TriggerPin  = 8;      //Trig pin
const int EchoPin     = 9;         //Echo pin
long Duration         = 0;

Servo servo;
const int pinNum      = 7;

const int checkDistance = 7;
const int checkTime     = 1000;
const int openTime      = 3000;
const int closeTime     = 2000;

unsigned long startTime;
bool flag_for_time_count = false;

void setup() 
{
  pinMode(TriggerPin, OUTPUT);  // Trigger is an output pin
  pinMode(EchoPin, INPUT);      // Echo is an input pin
  Serial.begin(9600);          // Serial Output

  servo.attach(pinNum, 500, 2400);
  servo.write(90); // 一開始先置中90度
}

void loop() 
{
  SettingForDistanceSensor();
  
  long Distance_cm = Distance(Duration);   // Use function to calculate the distance  
  if(Distance_cm < checkDistance)
  {
      Serial.print("open!");
      servo.write(15);
      delay(openTime);
      Serial.print("close!");
      servo.write(90);
      delay(closeTime);
    
//      if(flag_for_time_count == false)
//      {
//        flag_for_time_count = true;
//        startTime = millis();
//
//        Serial.println("Record start time");
//      }
//      
//      Serial.println(millis() - startTime);
//      
//      if(millis() - startTime >= checkTime)
//      {
//        Serial.print("opening!");
//        servo.write(10);
//        delay(openTime);
//        servo.write(90);
//        delay(closeTime);
//         Serial.print("closeed!");
//        flag_for_time_count = false;
//      }
  }
  else
  {
      Serial.print("Nothing!!");
//    flag_for_time_count = false;
  } 
}

void SettingForDistanceSensor()
{
  digitalWrite(TriggerPin, LOW);
  digitalWrite(EchoPin, LOW);                   
  delayMicroseconds(5);
  digitalWrite(TriggerPin, HIGH);          // Trigger pin to HIGH
  delayMicroseconds(10);                   // 10us high 
  digitalWrite(TriggerPin, LOW);           // Trigger pin to HIGH
 
  Duration = pulseIn(EchoPin, HIGH);        // Waits for the echo pin to get high
}

long Distance(long time)
{
  long DistanceCalc;                      // Calculation variable
   
  DistanceCalc = ((time * 0.034) / 2);     // Actual calculation in cm
  return DistanceCalc;                    // return calculated value
}

//unsigned long CalculateDeltaTime()
//{
//  unsigned long currentTime = millis();
//  unsigned long deltaTime = currentTime - oldTime;
//  oldTime = currentTime;
//  return deltaTime;
//}
