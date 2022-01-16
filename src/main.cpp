#include <Arduino.h>  //I coded this in PlatformIO so this Arduino Library must be included

#define trig 10
#define echo 13
#define buzz 8      // buzzer pin

float duration, distance;

void beep(int proximity);
void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzz, OUTPUT);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) * 0.0343;

  Serial.print("Distance: ");
  if (distance >= 400 || distance <= 2)
  {
    Serial.println("Out of range");
  }
  else
  {
    Serial.print(distance);
    Serial.println(" cm");
    beep(floor(distance));
  }
}
void beep(int proximity)
{
  int distan = proximity;
  if (proximity <= 150)
  {
    digitalWrite(buzz, HIGH);
    delay(50);
    digitalWrite(buzz, LOW);
    delay(distan * 10);
  }
  else
  {
    digitalWrite(buzz, LOW);
  }
}