#include "adc.h"

float32_t myValue;
uint16_t var;


float32_t adc_read(){
  char buffer[4];
  startconversion();
  var = ADC;
  myValue = (var /2.3) * 14; // random calculation on ADC value to generate a float 
  return myValue;
}

void adc_init()
{
  ADMUX = (1<<REFS0); //setting the ADC reference voltage to VCC
  ADMUX = (1<<MUX0) | (1<<MUX2);//assuming to read the voltage from pin28 / PC%/ ADC5 of atmgea 328p
  ADMUX = (0<<ADLAR) // ADCL - 8 bits , ADCH  - 2 bits
  ADCSRA = (1<<ADEN)| (1<<ADIE) | (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2); //ADEN enables ADC, ADCIE ADC Interrupt enable, ADPS0,ADPS1,ADPS2-prescale selection division factor to 128 
  DIDR0 = (1<<ADC50); //digital input disable register 0 , disables the digital input buffer on PC5, ADC50, pin28
  startconversion();
}

void startconversion(){
  ADCSRA |= (1<<ADSC); //ADC status register A, ADSC bit is set to start conversion
}




void USART_init(unsigned int baudrate){

  unsigned char n;
  // set baud rate
  UBRR0H = (unsigned char) (baudrate >>8)
  UBRR0L = (unsigned char) baudrate;

  //enable UART receiver and transmitter
  UCSRB0 = ((1<<RXCIE0) | (1<<RXEN0) | (1<<TXEN0));

  //setting frame format to 8 bit mode
  UCSR0C = (1<<URSEL) | (1<<USCZ00) | (1<< USCZ01)

 
}

void USART_Transmit(unsigned char data){
  // waits for UDRE to be empty
  while(!(UCSRA & (1<<UDRE)));
  //data placed to UDR register after UDRE is empty
  UDR = data;
}


void Usart_print(char *StringofCharacters){
  //sends string of characters 
  while(*StringofCharacters > 0){
    USART_Transmit(*StringofCharacters++);
  }
}




