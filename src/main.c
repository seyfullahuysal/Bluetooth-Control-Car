#include "inc/lm4f120h5qr.h"
#include "inc/hw_types.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "utils/uartstdio.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>



void init_UARTstdio()
{
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	ROM_GPIOPinConfigure(0x00000001);
	ROM_GPIOPinConfigure(0x00000401);
	ROM_GPIOPinTypeUART(0x40004000, 0x00000001 | 0x00000002);
	UARTStdioInit(0);
}

void init_port_D()
{
   volatile unsigned long delay;

   SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOD; // activate port D
   delay = SYSCTL_RCGC2_R;  	// allow time for clock to stabilize
   GPIO_PORTD_DIR_R |= 0b1111;	// make PD3-0 out
   GPIO_PORTD_AFSEL_R &= ~0b1111; // regular port function
   GPIO_PORTD_DEN_R |= 0b1111;	// enable digital I/O on PD3-0
}

void init_port_F() {
   volatile unsigned long delay;
   SYSCTL_RCGCGPIO_R |= 0x00000020;  // 1) activate clock for Port F
   delay = SYSCTL_RCGCGPIO_R;      	// allow time for clock to start
   GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock GPIO Port F
   GPIO_PORTF_CR_R = 0x1F;       	// allow changes to PF4-0
   // only PF0 needs to be unlocked, other bits can't be locked
   GPIO_PORTF_AMSEL_R = 0x00;    	// 3) disable analog on PF
   GPIO_PORTF_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
   GPIO_PORTF_DIR_R = 0b01110;      	// 5) PF4,PF0 in, PF3-1 out
   GPIO_PORTF_AFSEL_R = 0x00;    	// 6) disable alt funct on PF7-0
   GPIO_PORTF_PUR_R = 0x11;      	// enable pull-up on PF0 and PF4
   GPIO_PORTF_DEN_R = 0x1F;      	// 7) enable digital I/O on PF4-0
}


void systick_handler()
{
	char hangisi;
	hangisi=UARTgetc();
		   UARTprintf("okunan = %c\n",hangisi);

		   if(hangisi=='2')
		   {
					hangisi=UARTgetc();
					UARTprintf("okunan = %c\n",hangisi);


					if(hangisi=='C')
					{

						hangisi=UARTgetc();
						UARTprintf("okunan = %c\n",hangisi);
						if(hangisi=='U')
						{
							GPIO_PORTD_DATA_R&=~0b0010;
							///////////////////////////
							GPIO_PORTF_DATA_R&=~0b01000;
						}
						else if(hangisi=='D')
						{
							GPIO_PORTD_DATA_R|=0b0010;
							//////////////////////////
							GPIO_PORTF_DATA_R|=0b01000;
						}

					}
					else if(hangisi=='B')
					{
							hangisi=UARTgetc();
							UARTprintf("okunan = %c\n",hangisi);


							if(hangisi=='U')
							{
								GPIO_PORTD_DATA_R&=~0b0001;
								///////////////////////////
								GPIO_PORTF_DATA_R&=~0b00010;

							}

							else if(hangisi=='D')
							{
								GPIO_PORTD_DATA_R|=0b0001;
								////////////////////////////
								GPIO_PORTF_DATA_R|=0b00010;
							}
					}
					else if(hangisi=='E')
					{


							hangisi=UARTgetc();
							UARTprintf("okunan = %c\n",hangisi);
							if(hangisi=='U')
							{
								GPIO_PORTD_DATA_R&=~0b0100;
								////////////////////////////
								GPIO_PORTF_DATA_R&=~0b00100;

							}
							else if(hangisi=='D')
							{
								GPIO_PORTD_DATA_R|=0b0100;
								///////////////////////////
								GPIO_PORTF_DATA_R|=0b00100;

							}

					 }

					else if(hangisi=='D')
					{
						hangisi=UARTgetc();
						UARTprintf("okunan = %c\n",hangisi);

						if(hangisi=='U')
						{
							GPIO_PORTD_DATA_R&=~0b1000;
							////////////////////////////
							GPIO_PORTF_DATA_R&=~0b01110;
						}

						else if(hangisi=='D')
						{
							GPIO_PORTD_DATA_R|=0b1000;
							/////////////////////////////
							GPIO_PORTF_DATA_R|=0b01110;
						}

					}


		   	   }



}

void SysTick_Init(unsigned long period){
 NVIC_ST_CTRL_R = 0;     	// disable SysTick during setup
 NVIC_ST_RELOAD_R = period-1;// reload value
 NVIC_ST_CURRENT_R = 0;  	// any write to current clears it
 NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x40000000; // priority 2
 NVIC_ST_CTRL_R = 0x07; // enable SysTick with core clock and interrupts
 // enable interrupts after all initialization is finished
}

static inline void disable_interrupts() {
    asm("CPSID I");
}

static inline void enable_interrupts() {
    asm("CPSIE I");
}

static inline void wait_for_interrupt() {
    asm("WFI");
}




int main()
{

   init_UARTstdio();
   init_port_D();
   init_port_F();
   SysTick_Init(1600);
   enable_interrupts();


   while (1)
   {

	   wait_for_interrupt();

    }

}




