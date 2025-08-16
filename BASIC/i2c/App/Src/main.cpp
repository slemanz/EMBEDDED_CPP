#include "config.hpp"
#include <cstdio>
#include <cstdint>
#include "driver_i2c.hpp"

using namespace driver;
using namespace mcal;

// DS1307 I2C address
constexpr uint8_t DS1307_ADDRESS = 0x68;

// DS1307 register addresses
namespace ds1307_reg
{
    constexpr uint8_t SECONDS = 0x00;
    constexpr uint8_t MINUTES = 0x01;
    constexpr uint8_t HOURS = 0x02;
    constexpr uint8_t DAY = 0x03;
    constexpr uint8_t DATE = 0x04;
    constexpr uint8_t MONTH = 0x05;
    constexpr uint8_t YEAR = 0x06;
}

// Convert BCD to decimal
uint8_t bcd_to_dec(uint8_t bcd)
{
    return ((bcd >> 4) * 10) + (bcd & 0x0F);
}

// Convert decimal to BCD
uint8_t dec_to_bcd(uint8_t dec)
{
    return ((dec / 10) << 4) | (dec % 10);
}

// Set time on DS1307
void set_time(driver::i2c::I2C& i2c, uint8_t hours, uint8_t minutes, uint8_t seconds)
{
    uint8_t data[4];
    data[0] = ds1307_reg::SECONDS;
    data[1] = dec_to_bcd(seconds);
    data[2] = dec_to_bcd(minutes);
    data[3] = dec_to_bcd(hours);
    
    i2c.generate_start();
    i2c.send_address(DS1307_ADDRESS, false); // Write operation
    i2c.send_data(data, 4);
    i2c.generate_stop();
}


// Get time from DS1307
void get_time(driver::i2c::I2C& i2c, uint8_t& hours, uint8_t& minutes, uint8_t& seconds)
{
    // Write register address
    uint8_t reg = ds1307_reg::SECONDS;
    
    i2c.generate_start();
    i2c.send_address(DS1307_ADDRESS, false); // Write operation
    i2c.send_data(&reg, 1);
    
    // Read data
    i2c.generate_start();
    i2c.send_address(DS1307_ADDRESS, true); // Read operation
    
    uint8_t data[3];
    i2c.receive_data(data, 3, driver::i2c::AckControl::Enable);
    i2c.generate_stop();
    
    seconds = bcd_to_dec(data[0] & 0x7F);
    minutes = bcd_to_dec(data[1]);
    hours = bcd_to_dec(data[2] & 0x3F); // 24-hour format
}

// Set date on DS1307
void set_date(driver::i2c::I2C& i2c, uint8_t day, uint8_t date, uint8_t month, uint8_t year)
{
    uint8_t data[5];
    data[0] = ds1307_reg::DAY;
    data[1] = dec_to_bcd(day);
    data[2] = dec_to_bcd(date);
    data[3] = dec_to_bcd(month);
    data[4] = dec_to_bcd(year);
    
    i2c.generate_start();
    i2c.send_address(DS1307_ADDRESS, false); // Write operation
    i2c.send_data(data, 5);
    i2c.generate_stop();
}

// Get date from DS1307
void get_date(driver::i2c::I2C& i2c, uint8_t& day, uint8_t& date, uint8_t& month, uint8_t& year)
{
    // Write register address
    uint8_t reg = ds1307_reg::DAY;
    
    i2c.generate_start();
    i2c.send_address(DS1307_ADDRESS, false); // Write operation
    i2c.send_data(&reg, 1);
    
    // Read data
    i2c.generate_start();
    i2c.send_address(DS1307_ADDRESS, true); // Read operation
    
    uint8_t data[4];
    i2c.receive_data(data, 4, driver::i2c::AckControl::Enable);
    i2c.generate_stop();
    
    day = bcd_to_dec(data[0]);
    date = bcd_to_dec(data[1]);
    month = bcd_to_dec(data[2]);
    year = bcd_to_dec(data[3]);
}

// PB6 - I2C1 SCL
// PB7 - I2C1 SDA

int main(void)
{
    config_drivers();

    printf("\nBoard init!!\n");

    i2c::I2C i2c(driver::i2c::Instance::I2C1);
    i2c.init(driver::i2c::Mode::Standard);

    driver::systick::Systick::delay_ms(1000);

    // Set initial time and date
    //set_time(i2c, 14, 30, 0);    // 14:30:00
    //set_date(i2c, 1, 15, 5, 23); // Monday, 15th May 2023
    
    // Read back time and date
    uint8_t hours, minutes, seconds;
    uint8_t day, date, month, year;

    driver::systick::Systick::delay_ms(100);

    while(1)
    {
        get_time(i2c, hours, minutes, seconds);
        get_date(i2c, day, date, month, year);
        printf("time: %02d:%02d:%02d\n", hours, minutes, seconds);
        printf("Day:  %02d/%02d/20%02d\n", date, month, year);
        driver::systick::Systick::delay_ms(5000);
    }
}
