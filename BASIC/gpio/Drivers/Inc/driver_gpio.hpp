#ifndef INC_DRIVER_GPIO_HPP
#define INC_DRIVER_GPIO_HPP

#include <cstdint>
#include "mcal_reg.hpp"

namespace driver
{
    namespace gpio
    {
        enum class Port : uint8_t
        {
            A,
            B,
            C,
            D,
            E,
            H
        };

        enum class Mode : uint8_t
        {
            Input = 0x00,
            Output = 0x01,
            Alternate = 0x02,
            Analog = 0x03
        };

        enum class OutputType : uint8_t
        {
            PushPull = 0x00,
            OpenDrain = 0x01
        };

        enum class Speed : uint8_t
        {
            Low = 0x00,
            Medium = 0x01,
            High = 0x02,
            VeryHigh = 0x03
        };

        enum class Pull : uint8_t
        {
            None = 0x00,
            Up = 0x01,
            Down = 0x02
        };

        enum class State : bool
        {
            Low = false,
            High = true
        };

        class Pin
        {

        }
    }
}

#endif /* INC_DRIVER_GPIO_HPP */