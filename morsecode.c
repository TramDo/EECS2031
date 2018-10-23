#include <stdio.h>
#include <wiringPi.h>
#include "morsecode.h"

#define TIME_UNIT 250
#define DOT_TIME (TIME_UNIT)
#define DASH_TIME (TIME_UNIT*3)
#define LETTER_SPACE_TIME (TIME_UNIT*3)
#define WORD_SPACE_TIME (TIME_UNIT*7)


void init_morse(void)
{
	wiringPiSetup();
	pinMode (1, OUTPUT);
	pinMode (0, OUTPUT);
	
}

void send_dot(void)
{
	digitalWrite(0, HIGH);
	delay (DOT_TIME);
	digitalWrite(0, LOW);
}

void send_dash(void) 
{	
	digitalWrite(0, HIGH);
	delay (DASH_TIME);
	digitalWrite(0, LOW);
}

void wait_letter(void)
{
  delay(LETTER_SPACE_TIME);
  printf("wait for letter\n");
}

void wait_dot(void)
{
  delay(DOT_TIME);
  printf("wait for dot\n");
}

void wait_word(void)
{
  delay(WORD_SPACE_TIME);		
  printf("wait for word\n");
}

void play_buzzer(int msec)
{	
	
	digitalWrite(1, HIGH); 
	delay(msec);
	digitalWrite(1, LOW);
}

char *char2morse(char c)
{
  switch (c)
 {
	case '0':
		return "=====";
	break;
	case '1':
		return "*====";
	break;
	case '2':
		return "**===";
	break;
	case '3':
		return "***==";
	break;
	case '4':	
		return "****=";
	break;
	case '5':	
		return "*****";
	break;
	case '6':		
		return "=****";
	break;
	case '7':
		return "==***";
	break;
	case '8':
		return "===**";
	break;
	case '9':		
		return "====*";
	break;
	case 'I':
		return "**";
	break;
	case 'L':
		return "*=**";
	break;
	case 'U':
		return "**=";
	default:	
		return"non exist";
	break;

 }
}
