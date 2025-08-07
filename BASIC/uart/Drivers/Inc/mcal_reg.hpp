#ifndef INC_MCAL_REG_HPP
#define INC_MCAL_REG_HPP

#include <cstdint>
#include "mcal_reg_access.hpp"

namespace mcal
{
    namespace reg
    {
        constexpr uint32_t BIT(uint32_t pos)
        {
            return (1U << pos);
        }

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


        namespace usart
        {
            // USART register offsets
            namespace offset
            {
                constexpr std::uint32_t sr         = 0x00;
                constexpr std::uint32_t dr         = 0x04;
                constexpr std::uint32_t brr        = 0x08;
                constexpr std::uint32_t cr1        = 0x0c;
                constexpr std::uint32_t cr2        = 0x10;
                constexpr std::uint32_t cr3        = 0x14;
                constexpr std::uint32_t gtpr       = 0x18;
            }

            /// Bit positions (for shift operations and mask generation)
            namespace bitpos
            {
                namespace cr1
                {
                    constexpr uint32_t sbk          = 0;    ///< Send break
                    constexpr uint32_t rwu          = 1;    ///< Receiver wakeup
                    constexpr uint32_t re           = 2;    ///< Receiver enable
                    constexpr uint32_t te           = 3;    ///< Transmitter enable
                    constexpr uint32_t idleie       = 4;    ///< IDLE interrupt enable
                    constexpr uint32_t rxneie       = 5;    ///< RX not empty interrupt enable
                    constexpr uint32_t tcie         = 6;    ///< Transmission complete interrupt enable
                    constexpr uint32_t txeie        = 7;    ///< TX empty interrupt enable
                    constexpr uint32_t peie         = 8;    ///< Parity error interrupt enable
                    constexpr uint32_t ps           = 9;    ///< Parity selection
                    constexpr uint32_t pce          = 10;   ///< Parity control enable
                    constexpr uint32_t wake         = 11;   ///< Wakeup method
                    constexpr uint32_t m            = 12;   ///< Word length
                    constexpr uint32_t ue           = 13;   ///< USART enable
                } // namespace cr1

                namespace sr
                {
                    constexpr uint32_t pe           = 0;
                    constexpr uint32_t fe           = 1;
                    constexpr uint32_t nf           = 2;
                    constexpr uint32_t ore          = 3;
                    constexpr uint32_t idle         = 4;
                    constexpr uint32_t rxne         = 5;
                    constexpr uint32_t tc           = 6;
                    constexpr uint32_t txe          = 7;
                    constexpr uint32_t busy         = 8;
                } // namespace sr1
            } //namespace bitpos
            
            namespace mask
            {
                namespace cr1
                {
                    constexpr uint32_t sbk      = BIT(bitpos::cr1::sbk);
                    constexpr uint32_t rwu      = BIT(bitpos::cr1::rwu);
                    constexpr uint32_t re       = BIT(bitpos::cr1::re);
                    constexpr uint32_t te       = BIT(bitpos::cr1::te);
                    constexpr uint32_t idleie   = BIT(bitpos::cr1::idleie);
                    constexpr uint32_t rxneie   = BIT(bitpos::cr1::rxneie);
                    constexpr uint32_t tcie     = BIT(bitpos::cr1::tcie);
                    constexpr uint32_t txeie    = BIT(bitpos::cr1::txeie);
                    constexpr uint32_t peie     = BIT(bitpos::cr1::peie);
                    constexpr uint32_t ps       = BIT(bitpos::cr1::ps);
                    constexpr uint32_t pce      = BIT(bitpos::cr1::pce);
                    constexpr uint32_t wake     = BIT(bitpos::cr1::wake);
                    constexpr uint32_t m        = BIT(bitpos::cr1::m);
                    constexpr uint32_t ue       = BIT(bitpos::cr1::ue);
                } // namespace cr1

                namespace sr
                {
                    constexpr uint32_t pe       = BIT(bitpos::sr::pe);
                    constexpr uint32_t fe       = BIT(bitpos::sr::fe);
                    constexpr uint32_t nf       = BIT(bitpos::sr::nf);
                    constexpr uint32_t ore      = BIT(bitpos::sr::ore);
                    constexpr uint32_t idle     = BIT(bitpos::sr::idle);
                    constexpr uint32_t rxne     = BIT(bitpos::sr::rxne);
                    constexpr uint32_t tc       = BIT(bitpos::sr::tc);
                    constexpr uint32_t txe      = BIT(bitpos::sr::txe);
                    constexpr uint32_t busy     = BIT(bitpos::sr::busy);
                } // namespace sr
            } // namespace mask
        } // namespace uart

    } // reg
} // mcal

#endif /* INC_MCAL_REG_HPP */