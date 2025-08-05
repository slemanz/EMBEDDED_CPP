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