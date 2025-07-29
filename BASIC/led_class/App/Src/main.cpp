/*
 * Blinky PA5
 */
#include <stdint.h>

// GPIOA = AHB1
// GPIOA = 0x4002 0000
// MODER_REG_OFFSET = 0x00
// ODR_REG_OFFSET = 0x14
// AHB1ENER = AHB1 + RCC + 0x30

class Led
{
    public:
        typedef uint32_t port_type;
        typedef uint32_t bval_type;

        Led(const port_type p, bval_type b):port(p),bval(b)
        {
            *reinterpret_cast<volatile uint32_t *>(port) &= ~(1 << bval);
        }
    
    private:
        const port_type port;
        const port_type bval;
    
};

int main(void)
{
}