const int TriggerPin = 8;      //Trig pin
const int EchoPin   = 9;         //Echo pin
long Duration       = 0;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(TriggerPin, OUTPUT);  // Trigger is an output pin
  pinMode(EchoPin, INPUT);      // Echo is an input pin
  Serial.begin(9600);          // Serial Output
}

void loop() 
{
  // put your main code here, to run repeatedly:
  digitalWrite(TriggerPin, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TriggerPin, HIGH);          // Trigger pin to HIGH
  delayMicroseconds(10);                   // 10us high 
  digitalWrite(TriggerPin, LOW);           // Trigger pin to HIGH
 
  Duration = pulseIn(EchoPin,HIGH);        // Waits for the echo pin to get high
                                           // returns the Duration in microseconds
  long Distance_cm = Distance(Duration);   // Use function to calculate the distance
 
  Serial.print("Distance = ");             // Output to serial
  Serial.print(Distance_cm);
  Serial.println(" cm");
 
  delay(1000);                             // Wait to do next measurement
}

long Distance(long time)
{
  long DistanceCalc;                      // Calculation variable
   
  DistanceCalc = ((time * 0.034) / 2);     // Actual calculation in cm
    //DistanceCalc = time / 74 / 2;         // Actual calculation in inches
  return DistanceCalc;                    // return calculated value
}
