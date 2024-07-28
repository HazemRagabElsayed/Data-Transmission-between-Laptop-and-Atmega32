/*
 * USART.h
 *
 * Created: 10/6/2019 1:19:54 PM
 *  Author: Hazem Ragab Elsayed
 */ 


#ifndef USART_H_
#define USART_H_
void UART_vInit(unsigned long baud);
void UART_vSendData(char data);
char UART_u8ReceiveData(void);
void UART_vSendstring( char *ptr);
char* UART_vreceivestring(void);
#endif /* USART_H_ */
