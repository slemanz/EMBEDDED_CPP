#include "driver_uart.hpp"

using namespace driver::uart;
using namespace mcal::reg;

void Uart::init(BaudRate baudrate, Mode mode, WordLength word_length,
                StopBits stop_bits, Parity parity) const
{
    enable_clock();
    disable();

    set_baudrate(baudrate);

    const uint32_t base = get_base_address();

    // configure word length, parity and mode
    uint32_t cr1_value = 0;
    
    if(word_length == WordLength::Bits9) cr1_value |= usart::mask::cr1::m;
    if(parity != Parity::None)
    {
        cr1_value |= usart::mask::cr1::pce;
        if(parity == Parity::Odd) cr1_value |= usart::mask::cr1::ps;
    }

    if(static_cast<uint8_t>(mode) &0x01) // Rx enabled
    {
        cr1_value |= usart::mask::cr1::re;
    }

    if(static_cast<uint8_t>(mode) &0x02) // Tx enabled
    {
        cr1_value |= usart::mask::cr1::te;
    }

    uint32_t cr2_value = static_cast<uint32_t>(stop_bits) << 12;

    // set registers
    reg_access::reg_set(base + usart::offset::cr1, cr1_value);
    reg_access::reg_set(base + usart::offset::cr2, cr2_value);

    enable();
}

void Uart::enable() const
{
    const uint32_t cr1_addr = get_base_address() + usart::offset::cr1;
    reg_access::reg_or(cr1_addr, usart::mask::cr1::ue);
}

void Uart::disable() const
{
    const uint32_t cr1_addr = get_base_address() + usart::offset::cr1;
    reg_access::reg_not(cr1_addr, usart::mask::cr1::ue);
}

/*
 * OTHER METHODS
 */

constexpr uint32_t Uart::get_base_address() const
{
    switch(instance_)
    {
        case Instance::USART1: return usart1_base;
        case Instance::USART2: return usart2_base;
        case Instance::USART6: return usart6_base;
        default: return 0;
    }
}

void Uart::enable_clock() const
{
    switch (instance_)
    {
        case Instance::USART1: 
            reg_access::bit_set(apb2enr, 4); break;
        case Instance::USART2: 
            reg_access::bit_set(apb1enr, 17); break;
        case Instance::USART6: 
            reg_access::bit_set(apb2enr, 5); break;
    }
}

void Uart::set_baudrate(BaudRate baudrate) const
{
    // Assuming 16 Mhz
    constexpr uint32_t pclk = 16000000;
    const uint32_t brr_addr = get_base_address() + usart::offset::brr;

    uint32_t usartdiv = (pclk + (static_cast<uint32_t>(baudrate) / 2U))/static_cast<uint32_t>(baudrate);
    reg_access::reg_set(brr_addr, usartdiv);
}