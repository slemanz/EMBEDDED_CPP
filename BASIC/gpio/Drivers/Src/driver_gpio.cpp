#include "driver_gpio.hpp"
#include "mcal_reg_access.hpp"

using namespace driver::gpio;

void Pin::configure(Mode mode, OutputType otype, Speed speed, Pull pull, uint8_t alternate) const
{
    set_mode(mode);
    set_output_type(otype);
    set_speed(speed);
    set_pull(pull);

    if(mode == Mode::Alternate)
    {
        set_alternate_function(alternate);
    }
}

void Pin::set_mode(Mode mode) const
{
    constexpr uint32_t moder_offset = 0x00;
    const uint32_t moder_addr = static_cast<uint32_t>(port_) + moder_offset;
    const uint32_t shift = 2 * pin_;

    mcal::reg::reg_access<uint32_t, uint32_t, moder_addr, ~(0x3U << shift)>::reg_and();

    MCAL_REG_ACCESS(uint32_t, uint32_t, moder_addr)
        ::reg_or(static_cast<uint32_t>(mode) << shift);
}