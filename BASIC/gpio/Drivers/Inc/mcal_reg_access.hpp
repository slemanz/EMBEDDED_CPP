#ifndef INC_MCAL_REG_ACCESS_HPP
#define INC_MCAL_REG_ACCESS_HPP

namespace mcal
{
    namespace reg
    {
        template<   typename addr_type,
                    typename reg_type,
                    const addr_type addr,
                    const reg_type val>
        class reg_access
        {
            public:
                static void reg_set()
                {
                    *reinterpret_cast<volatile addr_type*>(addr) = static_cast<reg_type>(val);
                }

                static void reg_or()
                {
                    *reinterpret_cast<volatile addr_type*>(addr) |= static_cast<reg_type>(val);
                }

                static void reg_and()
                {
                    *reinterpret_cast<volatile addr_type*>(addr) &= static_cast<reg_type>(val);
                }

                static void reg_not()
                {
                    *reinterpret_cast<volatile addr_type*>(addr) &= static_cast<reg_type>(~val);
                }
						
                static reg_type reg_get()
                {
                    return *reinterpret_cast<volatile addr_type*>(addr); 
                }
						
                static void bit_set()
                {
					*reinterpret_cast<volatile addr_type*>(addr) |= static_cast<reg_type>(1U<<val);
                }
					
                static void bit_clr()
                {
					*reinterpret_cast<volatile addr_type*>(addr) &= static_cast<reg_type>(~static_cast<reg_type>(1U<<val));
                }

                static void bit_not()
                {
				    *reinterpret_cast<volatile addr_type*>(addr) ^= static_cast<reg_type>(1U<<val);
				}
						
				static bool bit_get()
                {
					return ((reg_get(addr)& static_cast<reg_type>(1U<<val)) != static_cast<reg_type>(0U));
				}
        };

        // Helper macros for register access
        #define MCAL_REG_ACCESS(addr_type, reg_type, address) \
            mcal::reg::reg_access<addr_type, reg_type, address, 0>
            
        #define MCAL_REG_BIT_ACCESS(addr_type, reg_type, address, bit_pos) \
            mcal::reg::reg_access<addr_type, reg_type, address, bit_pos>
    }
}

#endif /* INC_MCAL_REG_ACCESS_HPP */