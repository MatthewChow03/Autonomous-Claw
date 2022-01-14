#include <NewPing.h>
#include <Servo.h>

#define TRIG_PIN 11
#define ECHO_PIN 10
#define SERVO_PIN 9

#define MAX_DIST 200

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DIST); // initialize NewPing

Servo myservo; // create servo object

int pos = 0; // static variable for servo position
int dist = 0;

void init_servo_sequence();

void setup()
{
    Serial.begin(9600);

    // Init GPIO
    myservo.attach(9);
    pinMode(ECHO_PIN, INPUT);
    pinMode(TRIG_PIN, OUTPUT);
    
    init_servo_sequence();
}

void loop()
{
    // Measure sonar distance in cm
    dist = sonar.ping_cm();

    if (dist > 40)
      dist = 40;
    if (dist < 15)
      dist = 15;

    Serial.print("dist: ");
    Serial.println(dist);

    // Scale distance based on max distance, then convert to a servo position in degrees
    pos = map(dist, 15, 40, 180, 0); 
    myservo.write(pos);

    Serial.print("pos: ");
    Serial.println(pos);
    Serial.println();
    Serial.println();

    delay(40);

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
