/*
 * LED_BUTTON_bb.c
 *
 *  Created on: 	26 Jan 2018
 *      Author: 	Benjamin Blouin
 *     Version:		1.0
 */


/* Include Files */
#include "xparameters.h"
#include "xgpio.h"
#include "xstatus.h"

/* Definitions */
#define BTNS_DEVICE_ID  XPAR_AXI_GPIO_0_DEVICE_ID	/* GPIO device that BTNs are connected to */
#define LEDS_DEVICE_ID  XPAR_AXI_GPIO_1_DEVICE_ID	/* GPIO device that LEDs are connected to */
#define LED_DELAY 20000000							/* Software delay length */

XGpio BTNInst, LEDInst;								/* GPIO Device driver instance */

// Function Prototypes
void board_variable_init(); // Used to initialize the GPIOs and set DDRs

/* Main function. */
int main(void){

	/* Globally used variables:
	 * 		btn_id =  button pressed identification
	 * 		btn_status_pressed = used to determine if the button is still pressed, or has been depressed
	 * 		Delay = used to delay LED changes so behavior can be shown
	*/
	static int btn_id, btn_status_pressed, Delay;

	/* Behavior variables:
	 * 		led_count_up_zero = used for first two cases since both can start from zero
	 * 		led_case4_ = used for third case initialization which starts at nine
	 * 		led_sentinal_case_3 = used to determine when bar graph is full, which changes behavior
	 */
	int led_count_up_zero = 0;
	int led_case4_ = 9;
	int led_sentinal_case_3 = 0;

	/* Board Initialization*/
	board_variable_init();

	XGpio_DiscreteWrite(&LEDInst, 1, 0);  /* Clears LEDs */

	/* Start Behaviors */
	while(1)
	{
		btn_id = XGpio_DiscreteRead(&BTNInst, 1); /* Initial Button Input Read */

		/* Button Value Change
		 * Saved only if the button has been pressed
		 * If this wasn't here there button ID would be overwritten each time
		 * the while loop is executed
		 * This also resets the count start for all cases
		*/
		if(btn_id != 0)
		{
			led_count_up_zero = 0;
			led_case4_ = 9;
			btn_status_pressed = btn_id;
		}

		/* Begin Cases
		 * Case 1: The rightmost push button 0 is the system RESET
		 * and when released the LED count starts at 0 (0000)
		 * and increases as straight binary with roll over
		 * (that is, 0000, 0001, 0010…1111, 0000, 0001…)
		 *
		 * Case 2: If push button 1 is pressed singly all further
		 * count and LED operations are suspended (LED count is fixed).
		 * When push button 1 is released the LED count is
		 * set to 0 (0000) and decreases as straight binary
		 * (that is, 0000, 1111, 1110, 1101,…0000, 1111, 1110…).
		 *
		 * Case 3: If push button 2 is pressed singly all further count
		 * and LED operations are suspended (LED count is fixed).
		 * When push button 2 is released the LED count is set to 0 (0000)
		 * and increases as an increasing and decreasing, repeating bar graph
		 * (that is, 0000, 0001, 0011, 0111, 1111, 0111, 0011, 0001, 0000, 0001, 0011…).
		 *
		 * Case 4: If the leftmost push button 3 is pressed singly
		 * all further count and LED operations are suspended (LED count is fixed).
		 * When push button 3 is released the LED count is set to 1001
		 * and is a repeating pattern
		 * (that is, 1001, 0110, 1010, 0101, 1100, 0011, 1001, 0110, …).
		 *
		 * All cases re-test if a button is still pressed; if it is the
		 * case is not changed, and the value displayed at LEDs is static
		 */
		switch (btn_status_pressed)
		{
		case(1):
				btn_id = XGpio_DiscreteRead(&BTNInst, 1);
				if(btn_id == 0)
				{
				XGpio_DiscreteWrite(&LEDInst, 1, led_count_up_zero);
				led_count_up_zero = led_count_up_zero + 1;
				}
				break;

		case(2):
				btn_id = XGpio_DiscreteRead(&BTNInst, 1);
				if(btn_id == 0)
					{
						XGpio_DiscreteWrite(&LEDInst, 1, led_count_up_zero);
						led_count_up_zero = led_count_up_zero - 1;
					}
				break;

		case(4):
				btn_id = XGpio_DiscreteRead(&BTNInst, 1);
				if(btn_id == 0)
				{
					XGpio_DiscreteWrite(&LEDInst, 1, led_count_up_zero);
						if(led_sentinal_case_3 == 0)
						{
							led_count_up_zero = led_count_up_zero * 2 + 1;
								if(led_count_up_zero == 15){led_sentinal_case_3 = 1;}
						}
						else if(led_sentinal_case_3 == 1)
						{
							led_count_up_zero = led_count_up_zero / 2;
								if(led_count_up_zero == 0){led_sentinal_case_3 = 0;}
						}
				}
				break;

		case(8):
				btn_id = XGpio_DiscreteRead(&BTNInst, 1);
				if(btn_id == 0)
				{
					XGpio_DiscreteWrite(&LEDInst, 1, led_case4_);
					if(led_case4_ == 9){led_case4_ = 6;}
					else if(led_case4_ == 6){led_case4_ = 10;}
					else if(led_case4_ == 10){led_case4_ = 5;}
					else if(led_case4_ == 5){led_case4_ = 12;}
					else if(led_case4_ == 12){led_case4_ = 3;}
					else if(led_case4_ == 3){led_case4_ = 9;}
				}
				break;

		default:	/* Canonical */
			break;

		}
		for (Delay = 0; Delay < LED_DELAY; Delay++);	/* Used to allow human readable output */
	}
	return(0);
}

void board_variable_init(){

	/* GPIO LED driver initialization */
	XGpio_Initialize(&LEDInst, LEDS_DEVICE_ID);


	/* GPIO Button driver initialization */
	XGpio_Initialize(&BTNInst, BTNS_DEVICE_ID);


	/*Set the direction for the LEDs to output. */
	XGpio_SetDataDirection(&LEDInst, 1, 0x00);

	/*Set the direction for the BTNs to input. */
	XGpio_SetDataDirection(&BTNInst, 1, 0xFF);

}
