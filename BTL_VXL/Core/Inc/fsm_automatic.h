#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "main.h"
#include "global.h"
#include "traffic_light.h"
#include "timer.h"
#include "display7seg.h"
#include "button.h"

void blinkingLed(int mode);
void run_traffic_light();
void fsm_automatic();
void display_count(const char *label, int count, int row, int col);
#endif
