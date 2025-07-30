#include "uart.h"
#include <stdio.h>

void uart_init(void)
{
    RCC->AHB1ENR |= (1U << 0); // enable GPIOA clock
    RCC->APB1ENR |= 0x20000; // enable USART2 clock


    /* Configure PA2, PA3 for TX and RX*/
    GPIOA->AFR[0] |= 0x7700; // 7 = 0111
    GPIOA->MODER |= 0x00A0;  // enable alternate function to PA2, PA3

    UART2->BRR = 0x0683; // 9600 baudrate @ 16MHz
    UART2->CR1 = 0x000C; // enable TX, RX, 8-bit data
    UART2->CR2 = 0x000; // 1 stop bit
    UART2->CR3 = 0x000; // no flow control
    UART2->CR1 |= 0x2000; /*enable USART2*/
}

int uart_write(int ch)
{
    while(!(UART2->SR & 0x080)); // wait until tx empty
    UART2->DR = (ch & 0xFF);
    return 1;
}

int uart_read(void)
{
    while(!(UART2->SR & 0x020 ));
    return UART2->DR;
}

extern int __io_putchar(int ch)
{
    uart_write((uint8_t)ch);
    return ch;
}

/*
namespace std{
    struct __FILE{int handle;};

    FILE __stdout;
    FILE __stdin;
    FILE __stderr;

    int fgetc(FILE *f)
    {
        int c;
        c = uart_read();
        if(c == '\r')
        {
            uart_write(c);
            c = '\n';
        }
        uart_write(c);
        return c;
    }

    int fputc(int c, FILE *stream){
        return uart_write(c);
    }
	 

    long int ftell(FILE *stream){
        return 1;
    }

    int fclose(FILE *f){
        return 1;
    }

    int fseek(FILE *f, long nPos, int nMode){
        return 0;
    }
    
    int fflush(FILE *f){
        return 1;
    }
};
*/