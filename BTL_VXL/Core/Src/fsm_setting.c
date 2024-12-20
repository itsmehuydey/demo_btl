/*
 * fsm_setting.c
 *
 *  Created on: Nov 27, 2024
 *      Author: pc
 */

#include "fsm_setting.h"
#include "fsm_automatic.h"
#include "i2c_lcd.h"
void fsm_setting(){
	char buffer[16];
	switch(status){
		case MODE_1:
			status = INIT;
			break;
		case MODE_2:
			//displayLED7SEG(status, 1);
			//displayLED7SEG(adj_red, 0);
			// Hiển thị "Mode_2"
			//lcd_clear_display();
			            lcd_goto_XY(0, 1);
			            sprintf(buffer, "Mode: %d", status);
			            lcd_send_string(buffer);

			            // Hiển thị "Red"
			            lcd_goto_XY(1, 0);
			            if (adj_red < 10) {
			                sprintf(buffer, "Red: 0%d", adj_red);
			            } else {
			                sprintf(buffer, "Red: %d", adj_red);
			            }
			            lcd_send_string(buffer);

			if(timer_flag[0]){
				blinkingLed(status);
				setTimer(0, 500);
			}
			if(isButtonPressed(0)){
				status = MODE_3;
				clearAllLed();
				button_flag[0] = 0;
			}
			if(isButtonPressed(1)){
				button_flag[1] = 0;
				adj_red++;
				if(adj_red == 100)
					adj_red = 1;
				lcd_goto_XY(1, 0);
				                if (adj_red < 10) {
				                    sprintf(buffer, "Red: 0%d", adj_red);
				                } else {
				                    sprintf(buffer, "Red: %d", adj_red);
				                }
				                lcd_send_string(buffer);
			}
			if(isButtonPressed(2)){
				button_flag[2] = 0;
				if(adj_red > 2 && adj_red < 98){
					amber = ((temp_green < adj_red) ? (adj_red - temp_green) : temp_amber);

					if(green + amber < 100){
						green = adj_red - amber;
						red = adj_red;

						temp_red = red;
						temp_amber = amber;
						temp_green = green;
					}
					else{
						reTime();
					}
				}
				else{
					red = max_red;
					amber = max_amber;
					green = max_green;
				}
				clearAllLed();
				status = RED_GREEN;
				setTimer(1, green*1000);
				setTimer(0, 1);
			}

			break;
		case MODE_3:
			// Hiển thị "Mode_3"
			//lcd_clear_display();
			            lcd_goto_XY(0, 1);
			            sprintf(buffer, "Mode: %d", status);
			            lcd_send_string(buffer);

			            // Hiển thị "Amber"
			            lcd_goto_XY(1, 0);
			            if (adj_amber < 10) {
			                sprintf(buffer, "Amber: 0%d", adj_amber);
			            } else {
			                sprintf(buffer, "Amber: %d", adj_amber);
			            }
			            lcd_send_string(buffer);
			//displayLED7SEG(status, 1);
			//displayLED7SEG(adj_amber, 0);
			if(timer_flag[0]){
				blinkingLed(status);
				setTimer(0, 500);
			}
			if(isButtonPressed(0)){
				status = MODE_4;
				clearAllLed();
				button_flag[0] = 0;
			}
			if(isButtonPressed(1)){
				button_flag[1] = 0;
				adj_amber++;
				if(adj_amber == 100)
					adj_amber = 1;
				lcd_goto_XY(1, 0);
				                if (adj_amber < 10) {
				                    sprintf(buffer, "Amber: 0%d", adj_amber);
				                } else {
				                    sprintf(buffer, "Amber: %d", adj_amber);
				                }
				                lcd_send_string(buffer);
				//displayLED7SEG(adj_amber, 0);
			}
			if(isButtonPressed(2)){
				button_flag[2] = 0;
				green = ((adj_amber < temp_red) ? (temp_red - adj_amber) : temp_green);


				if((green + adj_amber) < 100){
					red = green + adj_amber;
					amber = adj_amber;
					temp_red = red;
					temp_amber = amber;
					temp_green = green;
				}
				else{
					reTime();
				}
				clearAllLed();
				status = RED_GREEN;
				setTimer(1, green*1000);
				setTimer(0, 1);
			}

			break;
		case MODE_4:
			// Hiển thị "Mode_3"
						//lcd_clear_display();
			            lcd_goto_XY(0, 1);
			            sprintf(buffer, "Mode: %d", status);
			            lcd_send_string(buffer);

			            // Hiển thị "Amber"
			            lcd_goto_XY(1, 0);
			            if (adj_amber < 10) {
			                sprintf(buffer, "Green: 0%d", adj_green);
			            } else {
			                sprintf(buffer, "Green: %d", adj_green);
			            }
			            lcd_send_string(buffer);
			//displayLED7SEG(status, 1);
			//displayLED7SEG(adj_green, 0);
			if(timer_flag[0]){
				blinkingLed(status);
				setTimer(0, 500);
			}
			if(isButtonPressed(0)){
				status = MODE_EXTEND;
				clearAllLed();
				button_flag[0] = 0;
			}
			if(isButtonPressed(1)){
				button_flag[1] = 0;
				adj_green++;
				if(adj_green == 100)
					adj_green = 1;
				lcd_goto_XY(1, 0);
								                if (adj_amber < 10) {
								                    sprintf(buffer, "Green: 0%d", adj_green);
								                } else {
								                    sprintf(buffer, "Green: %d", adj_green);
								                }
								                lcd_send_string(buffer);
				//displayLED7SEG(adj_green, 0);
			}
			if(isButtonPressed(2)){
				button_flag[2] = 0;
				amber = ((adj_green < temp_red) ? (temp_red - adj_green) : temp_amber);

				if(adj_green + amber < 100){
					red = adj_green + amber;
					green = adj_green;
					temp_red = red;
					temp_amber = amber;
					temp_green = green;
				}
				else{
					reTime();
				}
				clearAllLed();
				status = RED_GREEN;
				setTimer(1, green*1000);
				setTimer(0, 1);
			}
			break;
		case MODE_EXTEND:
		            // Hiển thị "Mode_EXTEND"
		            lcd_goto_XY(0, 1);
		            sprintf(buffer, "Mode: priority");
		            lcd_send_string(buffer);

		            // Hiển thị "Amber Blinking"
		            lcd_goto_XY(1, 0);
		            lcd_send_string("Amber Blinking");

		            if (timer_flag[2]) {
		                static int led_state = 0;  // Keep track of the LED state (0 = OFF, 1 = ON)

		                if (led_state == 0) {
		                    // Turn on the LEDs for MODE_3 (adjust the pins as per your hardware configuration)
		                    HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, SET);
		                    HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, RESET);
		                    HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, SET);
		                    HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, RESET);
		                    led_state = 1;  // Switch to ON state
		                } else {
		                    // Turn off the LEDs
		                    HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, RESET);
		                    HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, RESET);
		                    HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, RESET);
		                    HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, RESET);
		                    led_state = 0;  // Switch to OFF state
		                }

		                setTimer(2, 1000);  // Restart the timer with a 1-second interval
		            }
		            //clearAllLed();
		            // If any button is pressed, return to INIT state
		            if(isButtonPressed(0)) {
		                clearAllLed();  // Clear all LEDs when transitioning to INIT
		                status = MODE_1;  // Return to INIT state
		                button_flag[0] = 0;
		            }

		            break;
		default:
			break;
	}
}
