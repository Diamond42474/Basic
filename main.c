#include "avr_compiler.h"
int change_rate = 1;
int start = 100;
int scale = 100;
int main(){
	DDRB = 0b000111;
    while (true) {
		
		if(PINB & (1<<3)){
			change(1,2);
		}else{
			change(0,2);
		}
		/*
		int delay = start;
		for(int i=0;i<scale;i++){
			delay-=change_rate;
			change(1,0);
			change(0,1);
        	delay_ms(delay);
			change(0,0);
			change(1,1);
       		delay_ms(delay); 
		}
		for(int i=0;i<scale;i++){
			delay+=change_rate;
			change(1,0);
			change(0,1);
        	delay_ms(delay);
			change(0,0);
			change(1,1);
       		delay_ms(delay); 
		}
		*/
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
