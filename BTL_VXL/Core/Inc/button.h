#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"

#define NORMAL_STATE 1
#define PRESSED_STATE 0
#define N0_OF_BUTTONS 4

extern int button_flag[N0_OF_BUTTONS];

int isButtonPressed(int index);
int isButtonLongPressed(int index);
void subKeyProcess();
void getKeyInput();
#endif /* INC_BUTTON_H_ */
