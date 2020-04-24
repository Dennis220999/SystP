/*
 * Task_1_Ampelschaltung.c
 *
 * Created: 16.04.2020 14:38:00
 * Author : Dennis Wolf
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define TOGGLE_BIT(PORT,BIT) PORT^=(1<<BIT)

void setUp(void){
	//make DDD2-DDD4 outputs
	DDRD |= 0b000011100; //0b000011100;
	//output low
	PORTD &= ~(0b000011100);		
}
void loop(void){
	while(1){
		TOGGLE_BIT(PORTD,DDD2); //turn ON RED
		_delay_ms(3000);
		TOGGLE_BIT(PORTD,DDD3); //turn ON YELLOW
		_delay_ms(1000);
		TOGGLE_BIT(PORTD,DDD2);
		TOGGLE_BIT(PORTD,DDD3); //turn RED & YELLOW OFF
		TOGGLE_BIT(PORTD,DDD4); //turn ON GREEN
		_delay_ms(3000);
		TOGGLE_BIT(PORTD,DDD4); //turn OFF GREEN
		TOGGLE_BIT(PORTD,DDD3); //turn ON YELLOW
		_delay_ms(1000);
		TOGGLE_BIT(PORTD,DDD3); //turn OFF YELLOW		
	}
}
int main(void)
{
	setUp();
    loop();
}

