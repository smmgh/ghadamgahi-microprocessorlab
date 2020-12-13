/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : task3
Version : 1
Date    : 12/13/2020
Author  : smmgh
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 1.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <delay.h>
// Declare your global variables here
int i=0;

void main(void)
{
// Declare your local variables here
DDRA =0x00;
DDRB =0xFF;

while (1)
      {
      // Place your code here
             if (PINA.0==1){
                for(i=0;i<8;i++){
                    PORTB = PORTB *2 ;
                    delay_ms(100);   
                } 
                for(i=0;i<8;i++){
                    PORTB = PORTB /2 ;
                    delay_ms(100);   
                } 
             }
                
      }
}
