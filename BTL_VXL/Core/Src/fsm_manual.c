/*
 * fsm_manual.c
 *
 *  Created on: Nov 27, 2024
 *      Author: pc
 */
#include "fsm_manual.h"
#include "fsm_automatic.h"
#include "i2c_lcd.h"
void fsm_manual(){
	char buffer[16]; // Buffer để hiển thị dữ liệu lên LCD
	switch(status){
		case MAN_RED_GREEN:
			led_red_green();
			if(timer_flag[1]){
				status = RED_GREEN;
				clearAllLed();
				red = temp_red;
				green = temp_green;
				amber = temp_amber;
				setTimer(1, green*1000);
			}
			if(isButtonPressed(1)){
				status = MAN_RED_AMBER;
				red = 10;
				amber = 10;
				clearAllLed();
				setTimer(1, 1000);
				button_flag[1] = 0;
			}
			if(isButtonPressed(0)){
				status = MODE_2;
				clearAllLed();
				setTimer(0, 1);
				button_flag[0] = 0;
			}
			if(timer_flag[0]){
				--red;
				--green;

				 lcd_goto_XY(0, 1);
				                if (red < 10) {
				                    sprintf(buffer, "TrafficX: 0%d", red);
				                } else {
				                    sprintf(buffer, "TrafficX: %d", red);
				                }
				                lcd_send_string(buffer);

				                // Hiển thị TrafficY (GREEN)
				                lcd_goto_XY(1, 0);
				                if (green < 10) {
				                    sprintf(buffer, "TrafficY: 0%d", green);
				                } else {
				                    sprintf(buffer, "TrafficY: %d", green);
				                }
				                lcd_send_string(buffer);
				//displayLED7SEG(red, 0);
				//displayLED7SEG(green, 1);
				setTimer(0, 1000);
			}
			break;
		case MAN_RED_AMBER:
			led_red_amber();
			if(timer_flag[1]){
				status = RED_GREEN;
				clearAllLed();
				red = temp_red;
				green = temp_green;
				amber = temp_amber;
				setTimer(1, green*1000);
			}
			if(timer_flag[0]){
				--red;
				--amber;
				lcd_goto_XY(0, 1);
				                if (red < 10) {
				                    sprintf(buffer, "TrafficX: 0%d", red);
				                } else {
				                    sprintf(buffer, "TrafficX: %d", red);
				                }
				                lcd_send_string(buffer);

				                // Hiển thị TrafficY (AMBER)
				                lcd_goto_XY(1, 0);
				                if (amber < 10) {
				                    sprintf(buffer, "TrafficY: 0%d", amber);
				                } else {
				                    sprintf(buffer, "TrafficY: %d", amber);
				                }
				                lcd_send_string(buffer);
				//displayLED7SEG(red, 0);
				//displayLED7SEG(amber, 1);


				setTimer(0, 1000);
			}
			if(isButtonPressed(1)){
				status = MAN_GREEN_RED;
				setTimer(1, 1000);
				clearAllLed();
				red = 10;
				green = 10;
				button_flag[1] = 0;
			}
			if(isButtonPressed(0)){
				status = MODE_2;
				clearAllLed();
				setTimer(0, 1);
				button_flag[0] = 0;
			}
			break;
		case MAN_GREEN_RED:
			led_green_red();
			if(timer_flag[0]){
				--red;
				--green;
				 lcd_goto_XY(0, 1);
				                if (green < 10) {
				                    sprintf(buffer, "TrafficX: %d", green);
				                } else {
				                    sprintf(buffer, "TrafficX: %d", green);
				                }
				                lcd_send_string(buffer);

				                // Hiển thị TrafficY (RED)
				                lcd_goto_XY(1, 0);
				                if (red < 10) {
				                    sprintf(buffer, "TrafficY: %d", red);
				                } else {
				                    sprintf(buffer, "TrafficY: %d", red);
				                }
				                lcd_send_string(buffer);
				//displayLED7SEG(green, 0);
				//displayLED7SEG(red, 1);
				setTimer(0, 1000);
			}
			if(timer_flag[1]){
				status = RED_GREEN;
				clearAllLed();
				red = temp_red;
				green = temp_green;
				amber = temp_amber;
				setTimer(1, green*1000);
			}
			if(isButtonPressed(1)){
				status = MAN_AMBER_RED;
				red = 10;
				amber = 10;
				setTimer(1, 1000);
				clearAllLed();
				button_flag[1] = 0;
			}
			if(isButtonPressed(0)){
				status = MODE_2;
				clearAllLed();
				setTimer(0, 1);
				button_flag[0] = 0;
			}
			break;
		case MAN_AMBER_RED:
			led_amber_red();
			if(timer_flag[1]){
				status = RED_GREEN;
				clearAllLed();
				red = temp_red;
				green = temp_green;
				amber = temp_amber;
				setTimer(1, green*1000);
			}
			if(timer_flag[0]){
				--red;
				--amber;
				 lcd_goto_XY(0, 1);
				                if (amber < 10) {
				                    sprintf(buffer, "TrafficX: %d", amber);
				                } else {
				                    sprintf(buffer, "TrafficX: %d", amber);
				                }
				                lcd_send_string(buffer);

				                // Hiển thị TrafficY (RED)
				                lcd_goto_XY(1, 0);
				                if (red < 10) {
				                    sprintf(buffer, "TrafficY: %d", red);
				                } else {
				                    sprintf(buffer, "TrafficY: %d", red);
				                }
				                lcd_send_string(buffer);
				//displayLED7SEG(amber, 0);
				//displayLED7SEG(red, 1);
				controlTime_led();
				setTimer(0, 1000);
			}
			if(isButtonPressed(1)){
				status = MAN_RED_GREEN;
				setTimer(1, 1000);
				clearAllLed();
				red = 10;
				green = 10;
				button_flag[1] = 0;
			}
			if(isButtonPressed(0)){
				status = MODE_2;
				clearAllLed();
				setTimer(0, 1);
				button_flag[0] = 0;
			}
			break;
		default: break;
	}
}


