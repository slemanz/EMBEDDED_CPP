#include "config.hpp"
#include "driver_adc.hpp"
#include "driver_spi.hpp"
#include <cstdio>

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

    spi::Spi spi1(spi::Instance::SPI1);
    spi1.init(spi::Mode::Mode0, spi::BaudRate::Div16);

    uint8_t data_tx[10] = "Hello";

    printf("SPI1 CR1: ");
    printf("%lX\n", reg_access::reg_get(reg::spi1_base + reg::spi::offset::cr1));
    
    driver::systick::Systick::delay_ms(1000);
    while(1)
    {
        pa4.write(gpio::State::Low);
        spi1.write(data_tx, 5);
        while(spi1.is_busy());
        pa4.write(gpio::State::High);
        driver::systick::Systick::delay_ms(1000);
    }
}
