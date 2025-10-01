
#include "NewPing.h"
#define TRIGGER_PIN 2
#define ECHO_PIN 12

#define MAX_DISTANCE 40

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
Serial.begin(9600);
}

void loop() {
Serial.print("Distance = ");
//Serial.print(sonar.ping_in());
//Serial.print((sonar.ping() / 2) * 0.0343);
int iterations = 5;
Serial.print((sonar.ping_median(iterations) / 2) * 0.0341);
Serial.println(" cm");
delay(10000);
}