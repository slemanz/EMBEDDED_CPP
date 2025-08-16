#include "config.hpp"
#include "driver_gpio.hpp"
#include "driver_uart.hpp"
#include "driver_systick.hpp"

using namespace driver;

uart::Uart serial(uart::Instance::USART2);

// PB6 - I2C1 SCL
// PB7 - I2C1 SDA

gpio::Pin pb6(gpio::Port::B, 6);
gpio::Pin pb7(gpio::Port::B, 7);

void config_drivers()
{
    gpio::Pin pa1(gpio::Port::A, 1);
    pa1.configure(  gpio::Mode::Analog,
                    gpio::OutputType::PushPull,
                    gpio::Speed::High,
                    gpio::Pull::None);

    gpio::Pin pa2(gpio::Port::A, 2);
    pa2.configure(  gpio::Mode::Alternate,
                    gpio::OutputType::PushPull,
                    gpio::Speed::High,
                    gpio::Pull::None,
                    mcal::reg::gpio::altfn::pa2_usart2_tx);

    pb6.configure(  gpio::Mode::Alternate,
                    gpio::OutputType::OpenDrain,
                    gpio::Speed::High,
                    gpio::Pull::None,
                    4U);

    pb7.configure(  gpio::Mode::Alternate,
                    gpio::OutputType::OpenDrain,
                    gpio::Speed::High,
                    gpio::Pull::None,
                    4U);

    serial.init(uart::BaudRate::BR_9600, uart::Mode::Tx);
    systick::Systick::init();
    systick::Systick::delay_ms(1000);
}

extern "C" int __io_putchar(int ch)
{
    serial.write(reinterpret_cast<uint8_t*>(&ch), 1);
    return ch;
}

extern "C" void SysTick_Handler(void)
{
    systick::Systick::ticks_increment();
}