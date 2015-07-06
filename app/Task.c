#include "Task.h"
#include "LED.h"
/*	TASK SWITCHING MECHANISM
 *
 * 	- Push the rest of the register
 * 	- Let R0 points to mainTCB
 * 	- Store the current SP into *mainTcb.sp ; through R0
 * 	- Let R0 points to taskOneTcb
 * 	- Load *taskOneTcb ; through R0 in to current SP
 * 	- return from interrupt using "bx lr"
 *
 *	 assembler
 *	 .equ TCB_SP, 	8
 *	 .equ TCB_NAME, 4
 *	 .equ TCB_NEXT, 0
 *	 str r1[r0, #TCB_SP]
 * 	 ldr r1[r0, #TCB_SP]
 *
 * 	 *LinkedList >> Tcb *runningTcb;
 * */



uint8_t taskOneStack[1028];
uint8_t taskTwoStack[1028];

Tcb mainTcb;
Tcb taskOneTcb;
Tcb taskTwoTcb;
Tcb *readyQueue;
Tcb *runningQueue;
Tcb *blockQueue;

CpuContext Context;
CpuContext *cc = (CpuContext *)(((uint32_t)(&taskOneStack[1024])) - sizeof(CpuContext));

void taskOne(void){
	TaskBlock tb1, tb2, tb3, tb4;
	initTaskBlock(&tb1);
	initTaskBlock(&tb2);
	initTaskBlock(&tb3);
	initTaskBlock(&tb4);

	initControl();
	initLED1();
	initLED2();
	initLED3();
	initLED4();

	while(1){
		blink_LED1_yield(&tb1);
		blink_LED2_yield(&tb2);
		blink_LED3_yield(&tb3);
	}
}

//Init all the TCB
void initTcb(){
	mainTcb.name = (uint8_t *)"main_thread";
	mainTcb.sp = 0x12345678;
	taskOneTcb.name = (uint8_t *)"thread_1";
	//taskOneTcb.sp = (uint32_t)&Context;
	taskOneTcb.sp = (uint32_t)cc;
	//taskTwoTcb.name = "thread_2";
	//taskTwoTcb.sp = &taskTwoStack[1028];

	cc->r4   = 0x44444444;
	cc->r5   = 0x55555555;
	cc->r6   = 0x66666666;
	cc->r7   = 0x77777777;
	cc->r8   = 0x88888888;
	cc->r9   = 0x99999999;
	cc->r10  = 0xaaaaaaaa;
	cc->r11  = 0xbbbbbbbb;
	cc->r0   = 0xabababab;
	cc->r1   = 0x11111111;
	cc->r2   = 0x22222222;
	cc->r3   = 0x33333333;
	cc->r12  = 0xcccccccc;
	cc->lr   = 0xFFFFFFF9;
	cc->pc   = (uint32_t)taskOne;
	cc->xpsr = 0x01000000;

	runningQueue = &mainTcb;
	readyQueue = &taskOneTcb;
}
