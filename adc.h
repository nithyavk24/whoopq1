#ifndef ADC_H
#define ADC_H

  float32_t adc_read();
  void adc_init();
  void USART_init();
  void USART_Transmit(unsigned char data);
  void Usart_print(char *StringofCharacters);

#endif