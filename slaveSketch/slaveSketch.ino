int IRSensor = 5; // connect ir sensor to arduino pin 2
int LED = 13; // conect Led to arduino pin 13

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

byte flicker[] = {200, 0,200, 0,200, 0,200, 0,200, 0,200, 0,200, 0, 200};
int keyboardActive = 0;
String b = "led";

#define echoPin 4 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

void setup() 
{
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (LED, OUTPUT); // Led pin OUTPUT

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}

void loop()
{
  int statusSensor = digitalRead (IRSensor);

  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  Serial.println(distance);
  Serial.println(statusSensor);
  
  if(((distance > 10) && (distance < 20)) && (statusSensor == 1) && (keyboardActive == 0))
  {
    Serial.println("hand1");
    keyboardActive = 1;
  }

  String a = Serial.readString(); // read the incoming data as string
  Serial.println(a);

  if ((keyboardActive == 1) && (a.equals(b)))
  {
    for(int i=0; i,7; i++)
    {
      analogWrite(LED, flicker[i]);
      delay(5);
    }
  }

}
