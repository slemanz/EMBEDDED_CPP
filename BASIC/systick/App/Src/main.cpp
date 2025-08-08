#include "driver_gpio.hpp"
#include "driver_uart.hpp"
#include "driver_systick.hpp"
#include <cstring>
#include <cstdio>

using namespace driver;

uart::Uart serial(uart::Instance::USART2);

extern "C" int __io_putchar(int ch)
{
    serial.write(reinterpret_cast<uint8_t*>(&ch), 1);
    return ch;
}

extern "C" void SysTick_Handler(void)
{
    systick::Systick::ticks_increment();
}

int main(void)
{
    gpio::Pin pa5(gpio::Port::A, 5);
    pa5.configure(gpio::Mode::Output);

    gpio::Pin pa2(gpio::Port::A, 2);
    pa2.configure(  gpio::Mode::Alternate,
                    gpio::OutputType::PushPull,
                    gpio::Speed::High,
                    gpio::Pull::None,
                    mcal::reg::gpio::altfn::pa2_usart2_tx);

    serial.init(uart::BaudRate::BR_9600, uart::Mode::Tx);
    systick::Systick::init();

    for(uint32_t i = 0; i < 500000; i++); // delay to stable pins

    printf("Board init!!\n");
    
    while(1)
    {
        pa5.toggle();
        systick::Systick::delay_ms(500);
    }
}

