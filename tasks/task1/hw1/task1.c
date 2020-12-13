/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : task1
Version : 1
Date    : 12/13/2020
Author  : smmgh
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 12.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>

// Declare your global variables here
static unsigned  int time_count ;//.5sec counter
// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{  

     // 12 MHz/8 = 1500 kHz, which has a period of 1/1500 kHz = 0.66 �s
    //  225 * 0.66 �s = 150 �s
    //  3333 * 150 �s = 500 ms  
    //  256 � 225 = 31 
        
    TCNT0 = 31;
       ++time_count; /*increment .5 second counter*/
    if (time_count == 3333)
  {
        PORTC.0 = (PORTC.0 ^ 1); /*complement port bit to blink LED*/
        time_count = 0; /*reset time counter for next .5 second*/ 
   }



}

void main(void)
{

    DDRC = 0x01; /*set lsb for output*/

    /*set timer 0 prescaler to clk/8*/
    TCCR0=0x02;
    TCNT0=31;
   

    /* unmask Timer 0 overflow interrupt*/
    TIMSK=0x01;

    /* enable interrupts */
    #asm("sei")
    while(1) 
    {

      }
}
