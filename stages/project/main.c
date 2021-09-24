/**
 ******************************************************************************
 * @file    peripherals/oled/main.c
 * @author  MDS
 * @date    03042021
 * @brief   I2C example with the SSD1306 OLED Display (0.91 inch, 128x32 pixel). 
 * 			A boundary box, text and a moving cursor is shown on the OLED.
 *          The Blue LED will toggle to indicate periodic reading of the 
 *  		REFERENCE: SSD1306 Datasheet
 * 			Uses D15 (I2C_A_SCL) & D14 (I2C_A_SDA)
 *			Uses the following macros:
 * 				 MODIFY_REG( Register, clear mask (bits to clear), set mask (bits to set))
 *               WRITE_REG( Register, value to set)
 *				 READ_REG( (Register)
 *				 SET_BIT (Register, bit mask to set)
 *				 CLEAR_BIT (Register, bit mask to clear)
 ******************************************************************************
 *
 */
#include "main.h"
//int highorlow=1;
//uint8_t buffer1=0x00;
//uint8_t buffer2=0x00;
//uint16_t buffer2_Encode=0x00;
//uint16_t buffer2_Decode=0x00;
/*
 * Main program
 */
int main(void) 
{
	HAL_Init(); 		// Initialise Board
	Hardware_init();
	s4459843_reg_iss_init();//Initialise Iss modules.
	s4459843_tsk_simulation_init();
	s4459843_tsk_CAG_keypad_init();
	s4459843_tsk_CAG_keypadGrid_init();
	s4459843_tsk_CAG_keypadMnemonic_init();
	s4459843_tsk_joystick_init();
	s4459843_tsk_display_init();
	//s4459843_reg_oled_init();// Initialise OLED peripherals
	//ssd1306_Init();
	//s4459843_reg_iss_init();// Initialise system ISS
	//s4459843_reg_joystick_init();// Initialise joystick peripherals
	//s4459843_tsk_joystick_init();
	//s4459843_tsk_timer_init();
	//s4459843_tsk_oled_init();
	vTaskStartScheduler();
	
	// Cyclic Executive (CE) loop
	/*
	while (1) {

		s4459843_reg_oled_writetwonumbers(20,21);

		BRD_LEDBlueToggle();	//Toggle blue LED on/off
		HAL_Delay(1000);		//Delay for 1s (1000ms)
	}
	*/
	while(1){
	}
	return 0;
	// Cyclic Executive (CE) loop
}

void Hardware_init(void)
{
	BRD_LEDInit();
	// Turn off LEDs
	BRD_LEDRedOff();
	BRD_LEDGreenOff();
	BRD_LEDBlueOff();
	
	// Enable GPIOC Clock
	__GPIOC_CLK_ENABLE();

    GPIOC->OSPEEDR |= (GPIO_SPEED_FAST << 13);	//Set fast speed.
	GPIOC->PUPDR &= ~(0x03 << (13 * 2));			//Clear bits for no push/pull
	GPIOC->MODER &= ~(0x03 << (13 * 2));			//Clear bits for input mode

	// Enable EXTI clock
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

	//select trigger source (port c, pin 13) on EXTICR4.
	SYSCFG->EXTICR[3] &= ~SYSCFG_EXTICR4_EXTI13;
	SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;
	SYSCFG->EXTICR[3] &= ~(0x000F);

	EXTI->RTSR |= EXTI_RTSR_TR13;	//enable rising dedge
	EXTI->FTSR &= ~EXTI_FTSR_TR13;	//disable falling edge
	EXTI->IMR |= EXTI_IMR_IM13;		//Enable external interrupt

	//Enable priority (10) and interrupt callback. Do not set a priority lower than 5.
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 10, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

