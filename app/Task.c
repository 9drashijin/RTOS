#include "Task.h"

uint8_t taskOneStack[1028];
uint8_t taskTwoStack[1028];

Tcb mainTcb;
Tcb taskOneTcb;
Tcb taskTwoTcb;

void taskOne(void){
 return;
}

//Init all the TCB
void initTcb(){
	mainTcb.name = "main_thread";
	mainTcb.sp = 0;
	taskOneTcb.name = "thread_1";
	taskOneTcb.sp = &taskOneStack[1028];
	taskTwoTcb.name = "thread_2";
	taskTwoTcb.sp = &taskTwoStack[1028];
}
