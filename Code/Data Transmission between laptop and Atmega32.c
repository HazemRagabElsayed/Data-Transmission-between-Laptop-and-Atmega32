/*
 * Data_Transmission_between_laptop_and_Atmega32.c
 *
 * Created: 18/07/2024 01:50:48 م
 *  Author: Hazem Ragab Elsayed
 */ 

#define F_CPU 8000000UL
#include<util/delay.h>
#include <avr/io.h>

#include"LCD.h"
#include"USART.h"

#define BACKSPACE 8
#define CLC '-'
#define ENTER '\r'

int main(void)
{
	char choice = 'x';
	char data = 'x';
	unsigned char col = 1;
	unsigned char row = 1;
	unsigned char placetoreturn = 16;
	LCD_vInit();
	UART_vInit(9600);
	
	LCD_vSend_string("1:Send");
	LCD_movecursor(2,1);
	LCD_vSend_string("2:Receive");
	do 
	{
		choice = UART_u8ReceiveData();
		
	} while (choice != '1' && choice != '2');
	
	LCD_clearscreen();
	UART_vSendstring("\r\n");
    while(1)
    {
		switch(choice)	
		{
			case '1':
			data = UART_u8ReceiveData();
			switch(data)
			{
				case CLC:
				LCD_clearscreen();
				col = 1;
				row = 1;
				break;
				case BACKSPACE :
				
				LCD_movecursor(row,col);
				if(col == 16 && row == 2)
				{
					
				}
				else if(col>1)
				{
					col--;
				}
				else if(col == 1 && row == 2)
				{
					col = placetoreturn;
					row--;
				}
				LCD_vSend_char(' ');
				if(col == 16 && row == 2)
				{
					col--;
				}
				LCD_movecursor(row,col);
				break;
				case ENTER:
				if(row<2)
				{
					placetoreturn = col;
					col = 1;
					row++;
				}
				break;
				default:
				
				LCD_movecursor(row,col);
				LCD_vSend_char(data);
				if(col<16)
				{
					col++;
				}
				else if(col == 16 && row < 2)
				{
					placetoreturn = col;
					row++;
					col = 1;
				}
			}
			break;
			default:
			break;
			case '2':
			UART_vSendstring("This message is from Atmega32");
			UART_vSendstring("\r\n");
			
		}			
									
			   //TODO:: Please write your application code 
    }
	
	return 0;
}