#include "driver_adc.hpp"

using namespace driver::adc;
using namespace mcal;

void Adc::init(Resolution resolution, SampleTime default_sample_time)
{
    enable_clock();
    //calibrate();
    
    // Power on the ADC
    const uint32_t base = get_base_address();
    reg_access::bit_set(base + reg::adc::offset::cr2, reg::adc::bitpos::cr2::adon);
    
    // Wait for ADC to stabilize
    for(volatile int i = 0; i < 1000; i++);
    
    configure_resolution(resolution);
    
    // Configure default sample time for all channels
    reg_access::reg_set(base + reg::adc::offset::smpr1, 
        static_cast<uint32_t>(default_sample_time) << 0  |
        static_cast<uint32_t>(default_sample_time) << 3  |
        static_cast<uint32_t>(default_sample_time) << 6  |
        static_cast<uint32_t>(default_sample_time) << 9  |
        static_cast<uint32_t>(default_sample_time) << 12 |
        static_cast<uint32_t>(default_sample_time) << 15 |
        static_cast<uint32_t>(default_sample_time) << 18 |
        static_cast<uint32_t>(default_sample_time) << 21 |
        static_cast<uint32_t>(default_sample_time) << 24 |
        static_cast<uint32_t>(default_sample_time) << 27);
    
    reg_access::reg_set(base + reg::adc::offset::smpr2, 
        static_cast<uint32_t>(default_sample_time) << 0  |
        static_cast<uint32_t>(default_sample_time) << 3  |
        static_cast<uint32_t>(default_sample_time) << 6  |
        static_cast<uint32_t>(default_sample_time) << 9  |
        static_cast<uint32_t>(default_sample_time) << 12 |
        static_cast<uint32_t>(default_sample_time) << 15 |
        static_cast<uint32_t>(default_sample_time) << 18 |
        static_cast<uint32_t>(default_sample_time) << 21 |
        static_cast<uint32_t>(default_sample_time) << 24 |
        static_cast<uint32_t>(default_sample_time) << 27);
}
void Adc::configure_channel(Channel channel, SampleTime sample_time, bool enable = true) const
{

}

void Adc::set_mode(Mode mode, Trigger trigger = Trigger::Software, uint8_t discontinuous_count = 0) const
{

}

void Adc::start_conversion() const
{

}
void Adc::stop_conversion() const
{

}

bool Adc::is_conversion_complete() const
{

}

uint16_t Adc::read_conversion_result() const
{

}

/*
 * Private member functions
 */

void Adc::enable_clock() const
{
    if(instance_ == Instance::ADC1) reg_access::reg_or(reg::apb2enr, (1 << 8));
}

void Adc::disable_clock() const
{
    if(instance_ == Instance::ADC1) reg_access::reg_not(reg::apb2enr, (1 << 8));
}

void Adc::configure_resolution(Resolution resolution) const
{
    const uint32_t cr1_addr = get_base_address() + reg::adc::offset::cr1;
            
    // Clear resolution bits
    reg_access::reg_not(cr1_addr, (0x3 << reg::adc::bitpos::cr1::res));
    
    // Set new resolution
    reg_access::reg_or(cr1_addr, (static_cast<uint32_t>(resolution) << reg::adc::bitpos::cr1::res));
}

constexpr uint32_t Adc::get_base_address() const
{
    switch(instance_)
    {
        case Instance::ADC1: return reg::adc1_base;
        default: return 0;
    }
}
