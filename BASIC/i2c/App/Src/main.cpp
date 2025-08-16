#include "config.hpp"
#include <cstdio>
#include <cstdint>

using namespace driver;
using namespace mcal;

// PB6 - I2C1 SCL
// PB7 - I2C1 SDA

int main(void)
{
    config_drivers();

    printf("\nBoard init!!\n");

    driver::systick::Systick::delay_ms(1000);
    while(1)
    {
    }
}
