#include "driver_uart.hpp"

using namespace driver::uart;
using namespace mcal::reg;

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
    const uint32_t brr_addr = get_base_address() + usart_offset::brr;

    uint32_t usartdiv = (pclk + (static_cast<uint32_t>(baudrate) / 2U))/static_cast<uint32_t>(baudrate);
    reg_access::reg_set(brr_addr, usartdiv);
}