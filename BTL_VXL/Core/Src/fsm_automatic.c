///*
// * fsm_automatic.c
// *
// *  Created on: Nov 27, 2024
// *      Author: pc
// */
#include "i2c_lcd.h"
#include "fsm_automatic.h"

void run_traffic_light(){
	if(timer_flag[0]){
		blinkingLed(status);
		setTimer(0, 500);
	}
}

//void display_count(const char *label, int count, int row, int col) {
//    char buffer[16];
//    lcd_goto_XY(row, col); // Đặt vị trí trên LCD
//    if (count < 10) {
//        sprintf(buffer, "%s: 0%d", label, count); // Định dạng số < 10
//    } else {
//        sprintf(buffer, "%s: %d", label, count);  // Định dạng số >= 10
//    }
//    lcd_send_string(buffer); // Hiển thị lên LCD
//}

void fsm_automatic(){
	int amber_dummy;
	int green_dummy;

	switch(status){
		case INIT:
			status = RED_GREEN;
			setTimer(1, 3000);//300
			setTimer(0, 100);//0
			lcd_init();
			lcd_clear_display();
			clearAllLed();
			red = temp_red;
			amber = temp_amber;
			green = temp_green;
//			temp_red = max_red;
//			temp_amber = max_amber;
//			temp_green = max_green;
			//getSend();
			break;
		case RED_GREEN:
			led_red_green();
			if(timer_flag[0]){
				--red;
				--green;
				char buffer[16];
				                //lcd_clear_display();
				                // Hiển thị TrafficX
				                lcd_goto_XY(0, 1);
				                if (red < 10) {
				                    sprintf(buffer, "TrafficX: 0%d", red);
				                } else {
				                    sprintf(buffer, "TrafficX: %d", red);
				                }
				                lcd_send_string(buffer);

				                // Hiển thị TrafficY
				                lcd_goto_XY(1, 0);
				                if (green < 10) {
				                    sprintf(buffer, "TrafficY: 0%d", green);
				                } else {
				                    sprintf(buffer, "TrafficY: %d", green);
				                }
				                lcd_send_string(buffer);

				//displayLED7SEG(red, 0);
				//displayLED7SEG(green, 1);
				controlTime_led();
				setTimer(0, 1000);
			}
			if(timer_flag[1]){
				status = RED_AMBER;
				clearAllLed();
				controlTime_led();
				amber_dummy = amber*1000;
				setTimer(1, amber_dummy);
			}
			if(isButtonPressed(1)){
				status = MAN_RED_GREEN;
				setTimer(1, 1000);
				clearAllLed();
				red = 10;
				green = 10;
				button_flag[1] = 0;
				setTimer(0, 1000);
			}
			if(isButtonPressed(0)){
				lcd_clear_display();
				status = MODE_2;
				clearAllLed();
				setTimer(0, 1000);
				button_flag[0] = 0;
			}
			break;
		case RED_AMBER:
			led_red_amber();
			if(timer_flag[0]){
				--red;
				--amber;
				char buffer[16];
				                //lcd_clear_display();
				                // Hiển thị TrafficX
				                lcd_goto_XY(0,1);
				                if (red < 10) {
				                    sprintf(buffer, "TrafficX: 0%d", red);
				                } else {
				                    sprintf(buffer, "TrafficX: %d", red);
				                }
				                lcd_send_string(buffer);
				                // Hiển thị TrafficY
				                lcd_goto_XY(1, 0);
				                if (amber < 10) {
				                    sprintf(buffer, "TrafficY: 0%d", amber);
				                } else {
				                    sprintf(buffer, "TrafficY: %d", amber);
				                }
				                lcd_send_string(buffer);
//				displayLED7SEG(red, 0);
//				displayLED7SEG(amber, 1);


				controlTime_led();
				setTimer(0, 1000);
			}
			if(timer_flag[1]){
				status = GREEN_RED;
				clearAllLed();
				controlTime_led();
				green_dummy = green*1000;
				setTimer(1, green_dummy);
			}
			if(isButtonPressed(1)){
				status = MAN_RED_AMBER;
				setTimer(1, 1000);
				clearAllLed();
				red = 10;
				amber = 10;
				button_flag[1] = 0;
				setTimer(0, 1000);
			}
			if(isButtonPressed(0)){
				lcd_clear_display();
				status = MODE_2;
				clearAllLed();
				setTimer(0, 1000);
				button_flag[0] = 0;
			}
			break;
		case GREEN_RED:
			led_green_red();
			if(timer_flag[0]){
				--red;
				--green;
				char buffer[16];
				                //lcd_clear_display();

				                // Hiển thị TrafficX
				                lcd_goto_XY(0, 1);
				                if (green < 10) {
				                    sprintf(buffer, "TrafficX: 0%d", green);
				                } else {
				                    sprintf(buffer, "TrafficX: %d", green);
				                }
				                lcd_send_string(buffer);

				                // Hiển thị TrafficY
				                lcd_goto_XY(1, 0);
				                if (red < 10) {
				                    sprintf(buffer, "TrafficY: 0%d", red);
				                } else {
				                    sprintf(buffer, "TrafficY: %d", red);
				                }
				                lcd_send_string(buffer);
				//displayLED7SEG(green, 0);
				//displayLED7SEG(red, 1);
				controlTime_led();
				setTimer(0, 1000);
			}
			if(timer_flag[1]){
				status = AMBER_RED;
				clearAllLed();
				controlTime_led();
				amber_dummy = amber*1000;
				setTimer(1, amber_dummy);
			}
			if(isButtonPressed(1)){
				status = MAN_GREEN_RED;
				red = 10;
				green = 10;
				clearAllLed();
				setTimer(1, 1000);
				button_flag[1] = 0;
				setTimer(0, 1000);
			}
			if(isButtonPressed(0)){
				lcd_clear_display();
				status = MODE_2;
				clearAllLed();
				setTimer(0, 1000);
				button_flag[0] = 0;
			}
			break;
		case AMBER_RED:
			led_amber_red();
			if(timer_flag[0]){
				--red;
				--amber;
				char buffer[16];
				                //lcd_clear_display();

				                // Hiển thị TrafficX
				                lcd_goto_XY(0, 1);
				                if (amber < 10) {
				                    sprintf(buffer, "TrafficX: 0%d", amber);
				                } else {
				                    sprintf(buffer, "TrafficX: %d", amber);
				                }
				                lcd_send_string(buffer);

				                // Hiển thị TrafficY
				                lcd_goto_XY(1, 0);
				                if (red < 10) {
				                    sprintf(buffer, "TrafficY: 0%d", red);
				                } else {
				                    sprintf(buffer, "TrafficY: %d", red);
				                }
				                lcd_send_string(buffer);
				//displayLED7SEG(amber, 0);
				//displayLED7SEG(red, 1);
				controlTime_led();
				setTimer(0, 1000);
			}
			if(timer_flag[1]){
				status = RED_GREEN;
				controlTime_led();
				clearAllLed();
				green_dummy = green*1000;
				setTimer(1, green_dummy);
			}
			if(isButtonPressed(1)){
				status = MAN_AMBER_RED;
				red = 10;
				amber = 10;
				setTimer(1, 1000);
				clearAllLed();
				button_flag[1] = 0;
				setTimer(0, 1000);
			}
			if(isButtonPressed(0)){
				lcd_clear_display();
				status = MODE_2;
				clearAllLed();
				setTimer(0, 1000);
				button_flag[0] = 0;
			}
			break;
		default: break;
	}
}



