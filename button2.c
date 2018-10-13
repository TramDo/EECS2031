#include <wiringPi.h>
#include <stdio.h>

#define LedPin 0
#define ButtonPin 1

int main (int argc, char *argv[]) 
{
        wiringPiSetup();

	pinMode (ButtonPin, INPUT);
	pinMode (LedPin, OUTPUT);

	pullUpDnControl(ButtonPin, PUD_UP);

	for (;;)
	{
	
	if (digitalRead(ButtonPin) == 0)
	{
		digitalWrite(LedPin, HIGH);
	}
	else
	{
		digitalWrite(LedPin, LOW);
	}

	} 
	
	return 0;
}
