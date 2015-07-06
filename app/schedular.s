  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

.global  schedular
.global  SysTick_Handler
.extern  taskSwitch

.extern HAL_IncTick
.extern taskOneStack
.extern taskTwoStack
.extern CpuContext
.extern mainTcb
.extern readyQueue
.extern runningQueue

  .section  .text.schedular
  .type  schedular, %function
schedular:
//ldr    r0,  =#runningQueue

/*
 ldr    r0,  =#0xabababab
 ldr    r1,  =#0x11111111
 ldr    r2,  =#0x22222222
 ldr    r3,  =#0x33333333
 ldr    r4,  =#0x44444444
 ldr    r5,  =#0x55555555
 ldr    r6,  =#0x66666666
 ldr    r7,  =#0x77777777
 ldr    r8,  =#0x88888888
 ldr    r9,  =#0x99999999
 ldr    r10, =#0xaaaaaaaa
 ldr    r11, =#0xbbbbbbbb
 ldr    r12, =#0xcccccccc
 ldr    lr,  =#0xdddddddd
 push	{r0}
 b		 .
*/


.align 0
.type  SysTick_Handler, %function
 SysTick_Handler:
// Your Code Starts here :
// Push the rest of the register

push	{r4-r11}

ldr    r0,  =runningQueue   //mov address of runningQ(mainTcb) to r0
ldr    r1,  [r0]		    //deref runningQ, then content mov to r1
ldr    r2,  [r1,#4]		    //value of mainTcb sp 0x12345678

str	   sp,  [r1,#4]		    // Store the sp value

ldr    r0,  =readyQueue     //mov address of taskOne to r0
ldr    r1,  [r0]			//deref readyQ, then content mov to r1
ldr    lr,  [r1,#4]			//value of taskOne move to lr

ldr    r0,  [lr,#32]		//should get 0xabababab
ldr    r1,  [lr,#36]		//should get 0x11111111
ldr    r2,  [lr,#40]		//should get 0x22222222
ldr    r3,  [lr,#44]		//should get 0x33333333
ldr    r4,  [lr,#0]			//should get 0x44444444
ldr    r5,  [lr,#4]			//should get 0x55555555
ldr    r6,  [lr,#8]			//should get 0x66666666
ldr    r7,  [lr,#12]		//should get 0x77777777
ldr    r8,  [lr,#16]		//should get 0x88888888
ldr    r9,  [lr,#20]		//should get 0x99999999
ldr    r10, [lr,#24]		//should get 0xaaaaaaaa
ldr    r11, [lr,#28]		//should get 0xbbbbbbbb
ldr    r12, [lr,#48]		//should get 0xcccccccc
//ldr    lr,  [r12,#52]
ldr    pc,  [lr,#56]		// Load back the pc address
bx 		lr					// branch back

//b		schedular
//push	{r4}
//push	{r5}
//push	{r6}
//push	{r7}
//push	{r8}
//push	{r9}
//push	{r10}
//push	{r11}

 //push {r7, lr}
 //add r7, sp, #0
 //bl HAL_IncTick
 //pop {r7, pc}
