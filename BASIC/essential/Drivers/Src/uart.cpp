#include "uart.h"

void uart_init(void)
{
    RCC->AHB1ENR |= (1U << 0); // enable GPIOA clock
    RCC->APB1ENR |= (1U << 17); // enable USART2 clock

    /* Configure PA2, PA3 for TX and RX*/
    GPIOA->AFR[0] |= 0x7700; // 7 = 0111
    GPIOA->MODER |= 0x00A0;  // enable alternate function to PA2, PA3

    UART2->BRR = 0x0683; // 9600 baudrate
    UART2->CR1 = 0x000C; // enable TX, RX, 8-bit data
    UART2->CR2 = 0x0000; // 1 stop bit
    UART2->CR3 = 0x0000; // no flow control
    UART2->CR1 |= 0x2000; // enable UART2
}