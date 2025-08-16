#include "driver_i2c.hpp"

using namespace driver::i2c;
using namespace mcal;

void I2C::init(Mode mode,
        AddressingMode addressing = AddressingMode::Bit7,
        DutyCycle duty_cycle = DutyCycle::Ratio2_1) const
{
    enable_clock();
    disable();
    
    // Reset I2C
    uint32_t base = get_base_address();
    reg_access::bit_set(base + reg::i2c::offset::cr1, reg::i2c::bitpos::cr1::swrst);
    reg_access::bit_clr(base + reg::i2c::offset::cr1, reg::i2c::bitpos::cr1::swrst);
    
    // Configure timing
    configure_timing(mode, duty_cycle);
    
    // Enable I2C
    enable();
}

void I2C::enable() const
{
    uint32_t base = get_base_address();
    reg_access::reg_or(base + reg::i2c::offset::cr1, (1 << 0));
}

void I2C::disable() const
{
    uint32_t base = get_base_address();
    reg_access::reg_not(base + reg::i2c::offset::cr1, (1 << 0));
}

void I2C::set_own_address(uint16_t address, AddressingMode mode) const
{

}

void I2C::generate_start() const
{

}

void I2C::generate_stop() const
{

}

void I2C::send_address(uint8_t address, bool read) const
{

}

void I2C::send_data(uint8_t data) const
{

}

uint8_t I2C::receive_data(AckControl ack) const
{

}

bool I2C::is_busy() const
{

}

bool I2C::is_transfer_complete() const
{

}

// ... other method implementations ...

constexpr uint32_t I2C::get_base_address() const
{
    switch(instance_)
    {
        case Instance::I2C1: return reg::i2c1_base;
        case Instance::I2C2: return reg::i2c2_base;
        case Instance::I2C3: return reg::i2c3_base;
        default: return 0;
    }
}

void I2C::enable_clock() const
{
    if      (instance_ == Instance::I2C1) reg_access::bit_set(reg::apb1enr, 21);
    else if (instance_ == Instance::I2C2) reg_access::bit_set(reg::apb1enr, 22);
    else if (instance_ == Instance::I2C3) reg_access::bit_set(reg::apb1enr, 23);
}

void I2C::configure_timing(Mode mode, DutyCycle duty_cycle) const
{
    uint32_t base = get_base_address();
            
    // Standard mode timing (100 kHz)
    uint32_t ccr_value = 0x28;  // Default for 100 kHz
    uint32_t trise_value = 0x09; // Default for 100 kHz
            
    if(mode == Mode::Fast)
    {
        if(duty_cycle == DutyCycle::Ratio2_1)
        {
            ccr_value = 0x1E;  // 400 kHz with 2:1 duty cycle
        }
        else
        {
            ccr_value = 0x1F;  // 400 kHz with 16:9 duty cycle
        }
        trise_value = 0x05;   // For 400 kHz
    }
            
    reg_access::reg_set(base + reg::i2c::offset::ccr, ccr_value);
    reg_access::reg_set(base + reg::i2c::offset::trise, trise_value);
}