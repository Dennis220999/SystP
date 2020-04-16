/*
 * Task_1_Ampelschaltung.c
 *
 * Created: 16.04.2020 14:38:00
 * Author : Dennis Wolf
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/delay.h>

#define TOGGLE_BIT(PORT,BIT) PORT^=(1<<BIT)

void setUp(void){
	//make DDC0-DDC2 outputs
	DDRC |= 0b000111;
	//output DDC0-DDC2 low
	PORTC &= ~(0b000111);
		
}
void loop(void){
	while(1){
		TOGGLE_BIT(DDRC,DDC0); //turn ON RED
		_delay_ms(1000);
		TOGGLE_BIT(DDRC,DDC1); //turn ON YELLOW
		_delay_ms(100);
		TOGGLE_BIT(DDRC,DDC0);
		TOGGLE_BIT(DDRC,DDC1); //turn RED & YELLOW OFF
		TOGGLE_BIT(DDRC,DDC2); //turn ON GREEN
		_delay_ms(1000);
		TOGGLE_BIT(DDRC,DDC2); //turn OFF GREEN
		TOGGLE_BIT(DDRC,DDC1); //turn ON YELLOW
		_delay_ms(100);
		TOGGLE_BIT(DDRC,DDC1); //turn OFF YELLOW		
	}
}
int main(void)
{
	void setUp();
    void loop();
}

