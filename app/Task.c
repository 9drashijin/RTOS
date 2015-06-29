#include "Task.h"

uint8_t taskOneStack[1028];
uint8_t taskTwoStack[1028];

Tcb mainTcb;
Tcb taskOneTcb;
Tcb taskTwoTcb;
CpuContext Context;
CpuContext *cc = (CpuContext *)(((uint32_t)(&taskOneStack[1024])) - sizeof(CpuContext));

void taskOne(void){
 return;
}

//Init all the TCB
void initTcb(){
	mainTcb.name = "main_thread";
	mainTcb.sp = 0;
	taskOneTcb.name = "thread_1";
	taskOneTcb.sp = (uint32_t)cc;
	//taskTwoTcb.name = "thread_2";
	//taskTwoTcb.sp = &taskTwoStack[1028];

	Context.r4   = 0x44444444;
	Context.r5   = 0x55555555;
	Context.r6   = 0x66666666;
	Context.r7   = 0x77777777;
	Context.r8   = 0x88888888;
	Context.r9   = 0x99999999;
	Context.r10  = 0xaaaaaaaa;
	Context.r11  = 0xbbbbbbbb;
	Context.r0   = 0xabababab;
	Context.r1   = 0x11111111;
	Context.r2   = 0x22222222;
	Context.r3   = 0x33333333;
	Context.r12  = 0xcccccccc;
	Context.lr   = 0xFFFFFFF9;
	Context.pc   = (uint32_t)taskOne;
	Context.xpsr = 0x01000000;

}
