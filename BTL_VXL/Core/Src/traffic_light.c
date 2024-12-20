#include "traffic_light.h"


void clearAllLed(){
    HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, RESET);
    HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, RESET);
    HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, RESET);
    HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, RESET);
}

void led_red_green(){
    HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, SET);  // Red LED
    HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, SET);    // Red LED
    HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, RESET);  // Green LED
    HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, SET);    // Green LED
}

void led_red_amber(){
    HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, SET);  // Red LED
    HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, SET);    // Red LED
    HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, SET);    // Amber LED
    HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, RESET);  // Green LED
}

void led_green_red(){
    HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, RESET); // Green LED
    HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, SET);    // Red LED
    HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, SET);    // Amber LED
    HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, SET);    // Green LED
}

void led_amber_red(){
    HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, SET);  // Red LED
    HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, RESET);  // Green LED
    HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, SET);    // Amber LED
    HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, SET);    // Green LED
}

void init_traffic_light(){
    setTimer(1, 100);

    clearAllLed();
    led_red_green();
    led_red_amber();
}

void controlTime_led(){
    if(red <= 0) red = temp_red;
    if(green <= 0) green = temp_green;
    if(amber <= 0) amber = temp_amber;
}

void blinkingLed(int mode){
	switch(mode){
		case MODE_2:
			HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, SET);
			HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, SET);
			HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, SET);
			HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, SET);//11 đỏ

			break;
		case MODE_3:
			HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, SET);
			HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, RESET);
			HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, SET);
			HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, RESET);//01 vàng
			break;
		case MODE_4:
			HAL_GPIO_WritePin(D10_LED1_GPIO_Port, D10_LED1_Pin, RESET);//10 xanh
			HAL_GPIO_WritePin(D9_LED0_GPIO_Port, D9_LED0_Pin, SET);
			HAL_GPIO_WritePin(D4_LED1_GPIO_Port, D4_LED1_Pin, RESET);
			HAL_GPIO_WritePin(D3_LED0_GPIO_Port, D3_LED0_Pin, SET);

			break;
		default: break;
	}
}





