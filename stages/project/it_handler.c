/**
 ******************************************************************************
 * @file    it_handler.c
 * @author  MDS
 * @date    02022021
 * @brief   Must only be used to for interrupt handlers. Only callbacks must be
 *          called in this file. No other code must be present.
 ******************************************************************************
 *
 */

#include "main.h"
//#include "s4459843_reg_keypad.h"
//#include "s4459843_reg_joystick.h"

/*
 * Interrupt handler for EXTI 2 IRQ Handler
 */ 
void EXTI2_IRQHandler(void) {
	if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_2) != 0x00u)
	{
		s4459843_reg_joystick_iss_isr(GPIO_JOYSTICKZ);
		__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_2);
	}
}
/*
 * Interrupt handler for EXTI 3 IRQ Handler
 */ 
void EXTI3_IRQHandler(void) {
	if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_3) != 0x00u)
	{
		s4459843_reg_keypad_iss_isr(GPIO_ROW1);
		__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_3);
	}
} 
/*
 * Interrupt handler for EXTI 9 to 5 IRQ Handler
 */ 
void EXTI9_5_IRQHandler(void) {
	if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_5) != 0x00u)
	{
		s4459843_reg_keypad_iss_isr(GPIO_ROW2);
		__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_5);
	}
}
/*
 * Interrupt handler for EXTI 15 to 10 IRQ Handler
 */ 
void EXTI15_10_IRQHandler(void) {
	if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_10) != 0x00u)
	{
		s4459843_reg_keypad_iss_isr(GPIO_ROW3);
		__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_10);
	}
	
	
	if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_15) != 0x00u)
	{
		s4459843_reg_keypad_iss_isr(GPIO_ROW4);
		__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_15);
	}
	
	if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_13) != 0x00u)
	{
		modeSwitch();
		__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_13);
	}
}
