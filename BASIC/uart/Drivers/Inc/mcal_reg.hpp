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
        constexpr std::uint32_t ahb3enr =	rcc_base + 0x38;
      
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

        // GPIO Register addresses
        namespace gpioa
        {
            constexpr std::uint32_t moder       = gpioa_base + gpio_offset::moder;
            constexpr std::uint32_t otyper      = gpioa_base + gpio_offset::otyper;
            constexpr std::uint32_t ospeedr     = gpioa_base + gpio_offset::ospeedr;
            constexpr std::uint32_t pupdr       = gpioa_base + gpio_offset::pupdr;
            constexpr std::uint32_t idr         = gpioa_base + gpio_offset::idr;
            constexpr std::uint32_t odr         = gpioa_base + gpio_offset::odr;
            constexpr std::uint32_t bsrr        = gpioa_base + gpio_offset::bsrr;
            constexpr std::uint32_t lckr        = gpioa_base + gpio_offset::lckr;
            constexpr std::uint32_t afrl        = gpioa_base + gpio_offset::afrl;
            constexpr std::uint32_t afrh        = gpioa_base + gpio_offset::afrh;
        } // gpioa

        namespace gpiob
        {
            constexpr std::uint32_t moder       = gpiob_base + gpio_offset::moder;
            constexpr std::uint32_t otyper      = gpiob_base + gpio_offset::otyper;
            constexpr std::uint32_t ospeedr     = gpiob_base + gpio_offset::ospeedr;
            constexpr std::uint32_t pupdr       = gpiob_base + gpio_offset::pupdr;
            constexpr std::uint32_t idr         = gpiob_base + gpio_offset::idr;
            constexpr std::uint32_t odr         = gpiob_base + gpio_offset::odr;
            constexpr std::uint32_t bsrr        = gpiob_base + gpio_offset::bsrr;
            constexpr std::uint32_t lckr        = gpiob_base + gpio_offset::lckr;
            constexpr std::uint32_t afrl        = gpiob_base + gpio_offset::afrl;
            constexpr std::uint32_t afrh        = gpiob_base + gpio_offset::afrh;
        } // gpiob

        namespace gpioc
        {
            constexpr std::uint32_t moder       = gpioc_base + gpio_offset::moder;
            constexpr std::uint32_t otyper      = gpioc_base + gpio_offset::otyper;
            constexpr std::uint32_t ospeedr     = gpioc_base + gpio_offset::ospeedr;
            constexpr std::uint32_t pupdr       = gpioc_base + gpio_offset::pupdr;
            constexpr std::uint32_t idr         = gpioc_base + gpio_offset::idr;
            constexpr std::uint32_t odr         = gpioc_base + gpio_offset::odr;
            constexpr std::uint32_t bsrr        = gpioc_base + gpio_offset::bsrr;
            constexpr std::uint32_t lckr        = gpioc_base + gpio_offset::lckr;
            constexpr std::uint32_t afrl        = gpioc_base + gpio_offset::afrl;
            constexpr std::uint32_t afrh        = gpioc_base + gpio_offset::afrh;
        } // gpioc

        namespace gpiod
        {
            constexpr std::uint32_t moder       = gpiod_base + gpio_offset::moder;
            constexpr std::uint32_t otyper      = gpiod_base + gpio_offset::otyper;
            constexpr std::uint32_t ospeedr     = gpiod_base + gpio_offset::ospeedr;
            constexpr std::uint32_t pupdr       = gpiod_base + gpio_offset::pupdr;
            constexpr std::uint32_t idr         = gpiod_base + gpio_offset::idr;
            constexpr std::uint32_t odr         = gpiod_base + gpio_offset::odr;
            constexpr std::uint32_t bsrr        = gpiod_base + gpio_offset::bsrr;
            constexpr std::uint32_t lckr        = gpiod_base + gpio_offset::lckr;
            constexpr std::uint32_t afrl        = gpiod_base + gpio_offset::afrl;
            constexpr std::uint32_t afrh        = gpiod_base + gpio_offset::afrh;
        } // gpiod

        namespace gpioe
        {
            constexpr std::uint32_t moder       = gpioe_base + gpio_offset::moder;
            constexpr std::uint32_t otyper      = gpioe_base + gpio_offset::otyper;
            constexpr std::uint32_t ospeedr     = gpioe_base + gpio_offset::ospeedr;
            constexpr std::uint32_t pupdr       = gpioe_base + gpio_offset::pupdr;
            constexpr std::uint32_t idr         = gpioe_base + gpio_offset::idr;
            constexpr std::uint32_t odr         = gpioe_base + gpio_offset::odr;
            constexpr std::uint32_t bsrr        = gpioe_base + gpio_offset::bsrr;
            constexpr std::uint32_t lckr        = gpioe_base + gpio_offset::lckr;
            constexpr std::uint32_t afrl        = gpioe_base + gpio_offset::afrl;
            constexpr std::uint32_t afrh        = gpioe_base + gpio_offset::afrh;
        } // gpioe

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
