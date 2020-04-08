#include "avr_compiler.h"
int change_rate = 1;
int start = 100;
int scale = 100;
int main(){
	DDRB = 0b000111; // sets 0-2 as outputs
	PORTB |= (1 << 3); // enables pull-up resistor
    while (true) {
		if(get_button(3)){
			change(0,2);
			int delay = start;
			for(int i=0;i<scale&&get_button(3);i++){
				delay-=change_rate;
				change(1,0);
				change(0,1);
        		delay_ms(delay);
				change(0,0);
				change(1,1);
       			delay_ms(delay); 
			}
			for(int i=0;i<scale&&get_button(3);i++){
				delay+=change_rate;
				change(1,0);
				change(0,1);
        		delay_ms(delay);
				change(0,0);
				change(1,1);
       			delay_ms(delay); 
			}
		}else{
			change(1,2);
			change(0,1);
			change(0,0);
		}
    } 
}
void delay_ms(int ms ){
   	for (int i = 0; i < ms; i++){
      	_delay_ms(1);
   	}
}
void change(int x, int port){
	if(x==0){
		PORTB &=~(1<<port);
	}else{
		PORTB |=(1<<port);
	}
}  
get_button(int port){
	if(!(PINB & (1<<port))){
		return true;
	}else{
		return false;
	}
}
