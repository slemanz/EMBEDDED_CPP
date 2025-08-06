#include "driver_gpio.hpp"
#include "mcal_reg.hpp"

using namespace driver::gpio;
using namespace mcal::reg;

void Pin::configure(Mode mode, OutputType otype, Speed speed, Pull pull, uint8_t alternate) const
{
    enable_clock();

    set_mode(mode);
    set_output_type(otype);
    //set_speed(speed);
    //set_pull(pull);

    if(mode == Mode::Alternate)
    {
        //set_alternate_function(alternate);
    }
}

void Pin::set_mode(Mode mode) const
{
    const uint32_t moder_addr = get_port_base() + gpio_offset::moder;
    const uint32_t shift = 2 * pin_;

    reg_access::reg_not(moder_addr, (0x3 << shift));
    reg_access::reg_or(moder_addr, (static_cast<uint32_t>(mode) << shift));
}

void Pin::set_output_type(OutputType otype) const
{
    const uint32_t otyper_addr = get_port_base() + gpio_offset::otyper;
    reg_access::reg_not(otyper_addr, (0x1 << pin_));
    reg_access::reg_or(otyper_addr, (static_cast<uint32_t>(otype) << pin_));
}

void Pin::toggle() const
{
    const uint32_t odr_addr = (get_port_base()) + gpio_offset::odr;
    reg_access::bit_not(odr_addr, pin_);
}

void Pin::enable_clock() const
{
    if(port_ == Port::A) reg_access::reg_or(ahb1enr, (1 << 0));
}