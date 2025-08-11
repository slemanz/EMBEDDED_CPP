#include "driver_spi.hpp"

using namespace driver::spi;
using namespace mcal;

void Spi::init(Mode mode, BaudRate baudrate, DataSize data_size, BitOrder bit_order) const
{

}
                
void Spi::enable() const
{

}

void Spi::disable() const
{

}

bool Spi::is_busy() const
{

}

bool Spi::is_tx_empty() const
{

}

bool Spi::is_rx_not_empty() const
{

}

void Spi::read(uint8_t *data, uint32_t Len) const
{

}

void Spi::write(uint8_t *data, uint32_t Len) const
{

}

void Spi::transfer(uint8_t *dataTx, uint8_t *dataRx, uint32_t Len) const
{

}

constexpr uint32_t Spi::get_base_address() const
{
    switch(instance_)
    {
        case Instance::SPI1: return reg::spi1_base;
        case Instance::SPI2: return reg::spi2_base;
        case Instance::SPI3: return reg::spi3_base;
        case Instance::SPI4: return reg::spi4_base;
        default: return 0;
    }
}

void Spi::enable_clock() const
{

}

void Spi::disable_clock() const
{

}