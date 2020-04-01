#include "avr_compiler.h"

void change(int x, int port){
	if(x==0){
		PORTB &=~(1<<port);
	}else{
		PORTB |=(1<<port);
	}
}

int main(){
	DDRB = 0b000011;
    while (true) {
        //PORTB |=(1<<0);
	change(1,0);
        _delay_ms(250);
        //PORTB &=~(1<<0);
	change(0,0);
        _delay_ms(250); 
    }   
}
