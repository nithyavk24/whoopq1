/* 
 The code is written cosidering microcontroller ATmega328p using AVR platform
 */

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr.interrupt.h>
#include "adc.h"

#define F_CPU 80000000UL
#define FOSC 80000000
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD -1 //9600 baudrate

/* in C fill in main() to read 100 ADC readings and print them out to a uart*/
/* we want the printout to be in csv format */
/* you can use printf() to send data to the uart output */
/* assume 3 digits of decimal resolution */
/* bonus points if you fill in the details of adcRead() with a mock hardware driver in adc.c and adc.h*/
float32_t my_array[100];
char buffer[4];

void adc_100(){
  uint16_t i;
  Serial_print("reading channel");
  for(i = 0; i< 100 ; i ++){
    my_array[i] =  adc_read();
    delay(500);
  } 
}

void sendData(){
  uint16_t i;
  for(i =0; i<100; i++){
    ftoa(myarray[i],buffer,3);
    Usart_print(buffer);
    Usart_print(", ");
    delay(500);
  }
  USART_Transmit(0x0A); //line feed
  USART_Transmit(0x0D); //carriage return

}

int main()
{
adc_init();       //initialising ADC
USART_init(MYUBRR);    //initialising USART

adc_100();
sendData();

}