#include "mcal_reg.h"
#include "uart.h"
#include <iostream>

int main(void)
{
    uart_init();

    while(1)
    {
        uart_write('Y');
        for(int i = 0; i < 1000000; i++);
    }
}