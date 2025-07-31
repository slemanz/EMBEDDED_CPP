#include "mcal_reg.h"
#include "uart.h"

int main(void)
{
    uart_init();
    printf("Init the board!\n");

    int num = 234;
    int &ref_alias = num;
    int norm_alias = num;

	printf("num is %d \n", num);                // 234
	printf("ref_alias is %d \n", ref_alias);    // 234
	printf("norm_alias is %d \n", norm_alias);  // 234
        
    ref_alias++;

	printf("num is %d \n", num);                // 235
	printf("ref_alias is %d \n", ref_alias);    // 235
	printf("norm_alias is %d \n", norm_alias);  // 234
	


    while(1)
    {
        
    }
}

