#include <NewPing.h>
#include <Servo.h>

#define TRIGGER_PIN 8
#define ECHO_PIN 7
#define MAX_DISTANCE 200
#define SERVO_PIN 10
#define MAX_ANGLE 80
#define ANGLE_STEP 1

int angle = 0;
int dir = 1;

Servo myservo;
NewPing sonar(TRIGGER_PIN,ECHO_PIN,MAX_DISTANCE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(SERVO_PIN);
}

void loop() {
  delay(50);

  myservo.write(MAX_ANGLE + angle);

  Serial.print("Distance : ");
  Serial.print(sonar.ping_cm());
  Serial.print("cm");
  Serial.print("   Angle : ");
  Serial.println(angle);

  if (angle >= MAX_ANGLE || angle <= -MAX_ANGLE) {
    dir = -dir;
  }

  angle += (dir * ANGLE_STEP);
}
