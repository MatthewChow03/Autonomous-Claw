#include <NewPing.h>
#include <Servo.h>

#define BLUE_PIN 7
#define RED_PIN 6
#define YELLOW_PIN 5
#define GREEN_PIN 4

#define TRIG_PIN 11
#define ECHO_PIN 10
#define SERVO_PIN 9

#define OPEN 0         // OPEN
#define CLOSE 180      // CLOSE

#define MAX_DIST 200

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DIST); // initialize NewPing
Servo myservo; // create servo object

int pos = 0; // static variable for servo position
int dist = 0;

void init_servo_sequence();
void blink(int pin, int del);
void led_off();

void setup()
{
    Serial.begin(9600);

    // Init GPIO
    myservo.attach(9);
    pinMode(ECHO_PIN, INPUT);
    pinMode(TRIG_PIN, OUTPUT);

    pinMode(BLUE_PIN, OUTPUT);
    pinMode(RED_PIN, OUTPUT);
    pinMode(YELLOW_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    
    //init_servo_sequence();

    myservo.write(OPEN);
}

void loop()
{
    // (0) Blue indicator: initial state
    digitalWrite(BLUE_PIN, 1);
    dist = sonar.ping_cm();

    // ONCE THE FIRST IF IS TRUE, THE NESTED CONDITIONAL TREE CANNOT BE EXITED

    // Ground of pickup side
    if (dist < 20)
    {
      // (1) Green indicator: picked up picked up object
      led_off();
      digitalWrite(GREEN_PIN, 1);
      myservo.write(CLOSE);

      // Wait for above barrier height to be reached
      do
      {
        dist = sonar.ping_cm();
        delay(100); // ping delay
      } while(dist < 50);

      // Moving over barrier
      if (dist > 50)
      {
        // (2) Yellow indicator: passed the barrier
        led_off();
        digitalWrite(YELLOW_PIN, 1);

        // Wait for drop off side to be reached
        do
        {
          dist = sonar.ping_cm();
          delay(100); // ping delay
        } while (dist > 20);

        if (dist < 20)
        {
          // (3) Red indicator: object dropped off
          led_off();
          digitalWrite(RED_PIN, 1);
          myservo.write(OPEN);
          delay(5000);  // TEMPORARY: 5 seconds to bring claw back to original position
        }
      }
  
    }

    // Still waiting for conditions to pass
    // Ping delay
    delay(100);

}

void blink(int pin, int del)
{
  digitalWrite(pin, 1);
  delay(del);
  digitalWrite(pin, 0);
}

void led_off()
{
    digitalWrite(BLUE_PIN, 0);
      digitalWrite(RED_PIN, 0);
        digitalWrite(GREEN_PIN, 0);
          digitalWrite(YELLOW_PIN, 0);
}

void init_servo_sequence()
{
  // Show max (180)
    for (pos = 0; pos <= 180; pos += 1)
    {
        myservo.write(pos);
        delay(3);
    }
    for (pos = 180; pos >= 0; pos -= 1)
    {                       
        myservo.write(pos); 
        delay(3);
    }

    delay(100);

    // Show 90
    for (pos = 0; pos <= 90; pos += 1)
    {
        myservo.write(pos);
        delay(3);
    }
    for (pos = 90; pos >= 0; pos -= 1)
    {                       
        myservo.write(pos); 
        delay(3);
    }

    delay(100);

    // Show 45
    for (pos = 0; pos <= 45; pos += 1)
    {
        myservo.write(pos);
        delay(3);
    }
    for (pos = 45; pos >= 0; pos -= 1)
    {                       
        myservo.write(pos); 
        delay(3);
    }
}


/***
// Electronic Component Test

while(1)
    {
        blink(BLUE_PIN, 1000);
        blink(RED_PIN, 1000);
        blink(YELLOW_PIN, 1000);
        blink(GREEN_PIN, 1000);
        delay(1000);
    }

**/