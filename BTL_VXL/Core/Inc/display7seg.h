/*
 * display7seg.h
 *
 *  Created on: Nov 27, 2024
 *      Author: pc
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_
#include "main.h"

void displayLED7SEG(int number, int modify);
void led7seg_run();

void setBuffer(int led0, int led1);

void countAgain();
#endif /* INC_DISPLAY7SEG_H_ */
