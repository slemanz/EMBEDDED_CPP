#include "config.hpp"
#include "driver_adc.hpp"
#include <cstdio>

using namespace driver;
using namespace mcal;

int main(void)
{
    config_drivers();
    //printf("\nBoard init!!\n");

    adc::Adc adc1(adc::Instance::ADC1);
    /*
    adc1.init(adc::Resolution::Bits12);
    adc1.set_mode(adc::Mode::Continuous);
    adc1.configure_channel(adc::Channel::Ch1);
    adc1.start_conversion();
    */

    reg_access::bit_set(reg::apb2enr, 8);
    reg_access::reg_set(reg::adc1_base + reg::adc::offset::sqr3, 1);
    reg_access::reg_set(reg::adc1_base + reg::adc::offset::sqr1, 0);
    reg_access::bit_set(reg::adc1_base + reg::adc::offset::cr2, (reg::adc::bitpos::cr2::adon));
    driver::systick::Systick::delay_ms(100);

    reg_access::bit_set(reg::adc1_base + reg::adc::offset::cr2, (reg::adc::bitpos::cr2::cont));
    reg_access::bit_set(reg::adc1_base + reg::adc::offset::cr2, (reg::adc::bitpos::cr2::swstart));

    uint16_t data = 0;

    printf("\nBoard init 2!!\n");
    
    while(1)
    {
        pa5.toggle();
        printf("%d\n", adc1.is_conversion_complete());
        printf("%lx\n", reg_access::reg_get(reg::adc1_base + reg::adc::offset::sqr3));
        printf("%lx\n", reg_access::reg_get(reg::adc1_base + reg::adc::offset::cr2));
        while(!(reg_access::bit_get(reg::adc1_base + reg::adc::offset::sr, reg::adc::bitpos::sr::eoc)));
        data = adc1.read_conversion_result();
        printf("Adc data: %u\n", data);

        driver::systick::Systick::delay_ms(2000);
    }
}
