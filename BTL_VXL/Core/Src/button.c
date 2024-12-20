#include "global.h"
#include "button.h"

int KeyReg0[N0_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg1[N0_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg2[N0_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg3[N0_OF_BUTTONS] = {NORMAL_STATE};

int TimeOutForKeyPress = 500;
int button_flag[N0_OF_BUTTONS] = {0};
int button_long_pressed[N0_OF_BUTTONS] = {0};

int isButtonPressed(int index){
	if(button_flag[index] == 1)
		return 1;
	return 0;
}

int isButtonLongPressed(int index){
	if(button_long_pressed[index] == 1)
		return 1;
	return 0;
}

void getKeyInput(){
	static int longPressCounter[N0_OF_BUTTONS] = {0};
	for(int i = 0; i < N0_OF_BUTTONS; i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
	}

	KeyReg0[0] = HAL_GPIO_ReadPin(D6_btn1_GPIO_Port, D6_btn1_Pin);
	KeyReg0[1] = HAL_GPIO_ReadPin(D7_btn2_GPIO_Port, D7_btn2_Pin);
	KeyReg0[2] = HAL_GPIO_ReadPin(D8_btn3_GPIO_Port, D8_btn3_Pin);

	for(int i = 0; i < N0_OF_BUTTONS; i++){
		if((KeyReg1[i] == KeyReg0[i]) && (KeyReg2[i] == KeyReg1[i])){
			if(KeyReg2[i] != KeyReg3[i]){
				KeyReg3[i] = KeyReg2[i];

				if(KeyReg3[i] == PRESSED_STATE){
					TimeOutForKeyPress = 500;
					button_flag[i] = 1;
				}
			}
			else{
				TimeOutForKeyPress--;
				if(TimeOutForKeyPress == 0){
					TimeOutForKeyPress = 500;

					if(KeyReg3[i] == PRESSED_STATE){
						button_flag[i] = 1;
					}
					//else release
				}
			}
			if(KeyReg3[i] == PRESSED_STATE){
			  	longPressCounter[i]++;
			  	if(longPressCounter[i] >= 200){
			  		button_flag[i] = 1;
			  		longPressCounter[i] = 170;
			  	}
			}
			else {
				longPressCounter[i] = 0;
			}
		}
	}
}


