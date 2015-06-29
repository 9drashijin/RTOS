  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

.global  testFunc
  .extern  taskSwitch
  .section  .text.testFunc
  .type  testFunc, %function
testFunc: 

 //movs    r0, #0xabababab
 //movs    r1, #0x11111111
 //movs    r2, #0x22222222
 //movs    r3, #0x33333333
 //movs    r4, #0x44444444
 //movs    r5, #0x55555555
 //movs    r6, #0x66666666
 //movs    r7, #0x77777777
 //movs    r8, #0x88888888
 //movs    r9, #0x99999999
 //movs    r10, #0x10101010
 //movs    r11, #0x1a1a1a1a
 //movs    r12, #0x12121212
 //bra 	 :

 ldr	 r3, =#0x123456 //same as movw and movt
 movw.w  r4, 0x123
 movt.w  r4, 0x456
 push 	 {lr}
 movs	 r0, #12
 bl	     dummy
 pop     {lr}

 //push {r0,r1}
 //push {r1,r2}

 stmia 	 sp!, {r0,r1}
 stmia 	 sp!, {r1,r2}

// stmia 	 sp!, {r0,r1}

// ldmia	 sp!, {r0,r1}
// stmdb 	 sp!, {r1,r2,r0}

 bx  	 lr
