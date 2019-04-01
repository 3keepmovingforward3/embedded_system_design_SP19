/*
    Benjamin Blouin
*/

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
/* Xilinx includes. */
#include "xgpio.h"

#define DELAY_1_SECOND		1000UL
/*-----------------------------------------------------------*/
static void gpioInit();
static void prvTaskBTN( void *pvParameters );
static void prvTaskSW( void *pvParameters );
static void prvTaskLED( void *pvParameters );
/*-----------------------------------------------------------*/

#define TIMER_ID	1
static TaskHandle_t xTaskBTN;
static TaskHandle_t xTaskSW;
static TaskHandle_t xTaskLED;
static XGpio swibtwInst, ledInst;
static BaseType_t xLEDCount;
const TickType_t x1second = pdMS_TO_TICKS( DELAY_1_SECOND );


int main( void )
{
	gpioInit();

	XGpio_DiscreteWrite(&ledInst, 1, xLEDCount); //clear leds

	xTaskCreate( 	prvTaskBTN,
					( const char * ) "TaskBTN",
					configMINIMAL_STACK_SIZE,
					NULL,
					tskIDLE_PRIORITY + 1,
					&xTaskBTN );

	xTaskCreate(	prvTaskLED,
				 	( const char * ) "TaskLED",
					configMINIMAL_STACK_SIZE,
					NULL,
					tskIDLE_PRIORITY + 1,
					&xTaskLED );

	xTaskCreate( prvTaskSW,
					 ( const char * ) "TaskSW",
					 configMINIMAL_STACK_SIZE,
					 NULL,
					 tskIDLE_PRIORITY + 1,
					 &xTaskSW );

	/* Start the tasks and timer running. */
	vTaskStartScheduler();

	while(1);
}

/*-----------------------------------------------------------*/
static void prvTaskLED( void *pvParameters )
{
	while(1)
	{
		XGpio_DiscreteWrite(&ledInst,1,xLEDCount);
		vTaskDelay(x1second);
		xLEDCount++;
	}
}

/*-----------------------------------------------------------*/
static void prvTaskSW( void *pvParameters )
{
	while(1)
	{
		if(XGpio_DiscreteRead(&swibtwInst,2)==0)
			{vTaskResume(xTaskBTN);}
		else if (XGpio_DiscreteRead(&swibtwInst,2)==1)
			{vTaskSuspend(xTaskBTN);}
	}
}

/*-----------------------------------------------------------*/
static void prvTaskBTN( void *pvParameters )
{
	while(1)
	{
		if(XGpio_DiscreteRead(&swibtwInst,1)==2)
			{vTaskResume(xTaskLED);}
		else if (XGpio_DiscreteRead(&swibtwInst,1)==1)
			{vTaskSuspend(xTaskLED);}
	}
}

/*-----------------------------------------------------------*/
static void gpioInit(){
	XGpio_Initialize(&swibtwInst,XPAR_AXI_GPIO_0_DEVICE_ID);
	XGpio_Initialize(&ledInst,XPAR_AXI_GPIO_1_DEVICE_ID);

	XGpio_SetDataDirection(&swibtwInst,1,0xf);
	XGpio_SetDataDirection(&swibtwInst,2,0xf);
	XGpio_SetDataDirection(&ledInst,1,0x0);
}
