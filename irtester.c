#include <stdio.h>
#include <wiringPi.h>
#include "ifttt.h"

int main(int argc, char *argv[])
{
  int i;
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);

  while(1) {
    digitalWrite(2, HIGH);
    
    printf("Waiting for reset\n");
    while(digitalRead(0) == 1);
    digitalWrite(1, LOW);
    ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/215934276", "Tram", "wave", "reset");
    
    printf("Waiting for event\n");
    while(digitalRead(0) == 0);
    digitalWrite(1, HIGH);
    printf("Alarm\n");
    printf("Trying to connect to server\n");
    ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/215934276", "Tram", "wave", "make sound");
  }

/*
  ifttt("https://maker.ifttt.com/trigger/button_pressed/with/key/56-YpOKO17vOh-gimC2xK1qRAhRdzXXXX", "my1", "my 2", "my 333334");
*/


 
  /*NOTREACHED*/
  return 0 ;
}
