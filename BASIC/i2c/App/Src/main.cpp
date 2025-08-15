#include "config.hpp"
#include <cstdio>
#include <cstdint>

using namespace driver;
using namespace mcal;

// PA4 - GPIO NSS
// PA5 - SPI1_SCK  (AF05)
// PA6 - SPI1_MISO (AF05)
// PA7 - SPI1_MOSI (AF05)

int main(void)
{
    config_drivers();

    printf("\nBoard init!!\n");

    driver::systick::Systick::delay_ms(1000);
    while(1)
    {
    }
}
