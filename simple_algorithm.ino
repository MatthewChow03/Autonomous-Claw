#include <NewPing.h>
#include <Servo.h>

#define SERVO_PIN 9

#define RED 6
#define GREEN 5

#define TRIG_PIN 11
#define ECHO_PIN 10

#define OPEN 0    
#define CLOSE 120

#define MAX_DIST 200

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DIST); // initialize NewPing
Servo myservo;

int dist = 0;
int last_position = 0;

void setup() {

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);

  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);

  Serial.begin(9600);
  myservo.attach(9);

  //myservo.write(last_position);

}
  
void loop() {


  digitalWrite(RED, 0);
  digitalWrite(GREEN, 1);
  dist = sonar.ping_cm();

  Serial.println(dist);
  if (dist <= 0)
  {
    dist = 0;
  }
  if (dist >= 180)
  {
    dist = 180;
  }

  if (dist < 25)
  {
    digitalWrite(RED, 1);
    digitalWrite(GREEN, 0);
    delay(1000);
    if (last_position == 0)
    {
      last_position = 180;
    }
    else if (last_position == 180)
    {
      last_position = 0;
    }
    myservo.write(last_position);
    delay(2000);
  }
  else
  {
    delay(100);
  }



  /*
  digitalWrite(RED, 0);
  digitalWrite(GREEN, 1);
  dist = sonar.ping_cm();

  Serial.println(dist);
  if (dist <= 0)
  {
    dist = 0;
  }
  if (dist >= 180)
  {
    dist = 180;
  }

  if (dist < 25)
  {
    digitalWrite(RED, 1);
    digitalWrite(GREEN, 0);
    delay(1000);
    if (last_position == 0)
    {
      last_position = 110;
    }
    else if (last_position == 110)
    {
      last_position = 0;
    }
    myservo.write(last_position);
    delay(2000);
  }
  else
  {
    delay(100);
  }




*/

}
