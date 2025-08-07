#include "driver_gpio.hpp"
#include "driver_uart.hpp"

using namespace driver;

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

    gpio::Pin pa3(gpio::Port::A, 3);
    pa3.configure(  gpio::Mode::Alternate,
                    gpio::OutputType::PushPull,
                    gpio::Speed::High,
                    gpio::Pull::None,
                    mcal::reg::gpio::altfn::pa3_usart2_rx);

    uart::Uart serial(uart::Instance::USART2);
    serial.init(uart::BaudRate::BR_9600, uart::Mode::TxRx);
    
    for(uint32_t i = 0; i < 200000; i++); // delay to stable pins
    
    const char* msg = "Hello UART!\n";
    for(const char* p = msg; *p; ++p)
    {
        while(!serial.is_ready_to_write());
        serial.write(*p);
    }
    
    
    
    
    while(1)
    {
        if(serial.is_data_available())
        {
            uint8_t data = serial.read();
            while(!serial.is_ready_to_write());
            serial.write(data);
        }
    }
}

