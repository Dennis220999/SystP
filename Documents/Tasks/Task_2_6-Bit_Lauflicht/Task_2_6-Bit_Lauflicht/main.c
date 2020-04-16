/*
 * Task_2_6-Bit_Lauflicht.c
 *
 * Created: 16.04.2020 15:20:04
 * Author : Dennis Wolf
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define TOGGLE_BIT(PORT,BIT) PORT ^=(1<<BIT)

void setUp(void){
	//make complete DDRC to an output
	DDRC |= 0b111111;
	//sink complete DDRC
	PORTC &= ~(0b111111);
}
void loop(/*int &numberOfLights*/){
	/*static*/register int positionLamp = 0;
	int direction = -1;
	while(1){
		if(positionLamp==0||positionLamp==5)
			direction*=-1;
		TOGGLE_BIT(PORTC,positionLamp);	//AN
		_delay_ms(100);
		TOGGLE_BIT(PORTC,positionLamp); //AUS
		positionLamp+=direction;
	}	
}
int main(void)
{
	//int numberOfLights = 1; //range between 1-5
	setUp();
	loop(/*numberOfLights*/);
}

