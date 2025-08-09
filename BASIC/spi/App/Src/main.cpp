#include "config.hpp"
#include "driver_adc.hpp"
#include <cstdio>

using namespace driver;
using namespace mcal;

int main(void)
{
    config_drivers();


    printf("\nBoard init!!\n");
    
    while(1)
    {
        pa5.toggle();
        driver::systick::Systick::delay_ms(200);
    }
}
