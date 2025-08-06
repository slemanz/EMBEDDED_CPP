#ifndef INC_MCAL_REG_HPP
#define INC_MCAL_REG_HPP

#include <cstdint>
#include "mcal_reg_access.hpp"

namespace mcal
{
    namespace reg
    {
        // global base address
        constexpr std::uint32_t periph_base = 0x40000000U;

        // Individual unit base addresses
        constexpr std::uint32_t apb1periph_base = periph_base;
        constexpr std::uint32_t apb2periph_base = periph_base + 0x00010000U;
        constexpr std::uint32_t ahb1periph_base = periph_base + 0x00020000U;

        constexpr std::uint32_t rcc_base        = ahb1periph_base + 0x00003800U;
      
        constexpr std::uint32_t ahb1enr =	rcc_base + 0x30;
        constexpr std::uint32_t ahb2enr =	rcc_base + 0x34;
        constexpr std::uint32_t apb1enr =	rcc_base + 0x40;
        constexpr std::uint32_t apb2enr =	rcc_base + 0x44;
      
        constexpr std::uint32_t gpioa_base      = ahb1periph_base +  0x0000;
        constexpr std::uint32_t gpiob_base      = ahb1periph_base +  0x0400;
        constexpr std::uint32_t gpioc_base      = ahb1periph_base +  0x0800;
        constexpr std::uint32_t gpiod_base      = ahb1periph_base +  0x0C00;
        constexpr std::uint32_t gpioe_base      = ahb1periph_base +  0x1000;

        constexpr std::uint32_t usart1_base     = apb2periph_base +  0x1000;
        constexpr std::uint32_t usart2_base     = apb1periph_base +  0x4400;
        constexpr std::uint32_t usart6_base     = apb2periph_base +  0x1400;

        
        // Port registers.
        namespace gpio_offset
        {
            constexpr std::uint32_t moder       = 0x00;
            constexpr std::uint32_t otyper      = 0x04;
            constexpr std::uint32_t ospeedr     = 0x08;
            constexpr std::uint32_t pupdr       = 0x0C;  
            constexpr std::uint32_t idr         = 0x10;  
            constexpr std::uint32_t odr         = 0x14;  
            constexpr std::uint32_t bsrr        = 0x18;  
            constexpr std::uint32_t lckr        = 0x1C;  
            constexpr std::uint32_t afrl        = 0x20;  
            constexpr std::uint32_t afrh        = 0x24;  
        } // gpio_offset

        // usart register offset
        namespace usart_offset
        {   
            constexpr std::uint32_t sr          = 0x00;
            constexpr std::uint32_t dr          = 0x04;
            constexpr std::uint32_t brr         = 0x08;
            constexpr std::uint32_t cr1         = 0x0C;
            constexpr std::uint32_t cr2         = 0x10;
            constexpr std::uint32_t cr3         = 0x14;
            constexpr std::uint32_t gtpr        = 0x18;
        } // usart_offset
    } // reg
} // mcal


#endif /* INC_MCAL_REG_HPP */
