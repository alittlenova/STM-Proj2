/**
 ******************************************************************************
 * @file    main.h
 * @author  MDS
 * @date    05122019
 * @brief   Used for main.c prototypes and includes.
 ******************************************************************************
 *
 */

#ifndef MAIN_H
#define MAIN_H
#define USE_FREERTOS_SYSTICK
#include "board.h"
#include "processor_hal.h"
#include "oled_pixel.h"
#include "oled_string.h"
#include "fonts.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include "s4459843_reg_iss.h"
//#include "s4459843_reg_keypad.h"
//#include "s4459843_reg_lta1000g.h"
#include "s4459843_reg_oled.h"
#include "s4459843_reg_joystick.h"
#include "s4459843_tsk_oled.h"
#include "s4459843_CAG_simulator.h"
#include "s4459843_CAG_display.h"
#include "s4459843_CAG_keypad_grid.h"
#include "s4459843_CAG_keypad.h"
//extern int highorlow;
//extern uint8_t buffer1;
//extern uint8_t buffer2;
//extern uint16_t buffer2_Encode;
//extern uint16_t buffer2_Decode;
void Hardware_init(void);
#endif
