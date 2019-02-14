#include<reg51.h>

sbit RAC = P2^1;
sbit RCW = P2^0;
sbit LAC = P2^3;
sbit LCW = P2^2;
void External_Interrupt_Init();
volatile char Key_detect;

void main() {
	P1=0xFF;
	P2=0xFF;
	while(1) {
		if(P1==0xF1) {
			RAC=0; RCW=1;
			LAC=1; LCW=1;
			while(P1==0xF1);
		}
		else if(P1==0xF2) {
			RAC=0; RCW=1;
			LAC=1; LCW=0;
			while(P1==0xF2);
		}
		else if(P1==0xF3) {
			RAC=1; RCW=1;
			LAC=1; LCW=0;
			while(P1==0xF3);
		}
		else if(P1==0xF4) {
			RAC=0; RCW=1;
			LAC=0; LCW=1;
			while(P1==0xF4);
		}
		else if(P1==0xF5) {
			RAC=1; RCW=1;
			LAC=1; LCW=1;
			while(P1==0xF5);
		}
		else if(P1==0xF6) {
			RAC=1; RCW=0;
			LAC=1; LCW=0;
			while(P1==0xF6);
		}
		else if(P1==0xF7) {
			RAC=1; RCW=0;
			LAC=1; LCW=1;
			while(P1==0xF7);
		}
		else if(P1==0xF8) {
			RAC=1; RCW=0;
			LAC=0; LCW=1;
			while(P1==0xF8);
		}
		else if(P1==0xF9) {
			RAC=1; RCW=1;
			LAC=0; LCW=1;
			while(P1==0xF9);
		}
	}
}
void External_Interrupt_Init()
{
	EA  = 1;
	EX0 = 1;
	IT0 = 1;
}
/* ISR is used to check tone is received or not */
void External0_ISR() interrupt 0
{
	Key_detect = 1;
}
