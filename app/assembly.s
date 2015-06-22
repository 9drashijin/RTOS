  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

.global  testFunc

  .section  .text.testFunc
  .type  testFunc, %function
testFunc: 
 movs    r0, #0x12
 movs    r1, #0x34
 movs    r2, #0x56
 ldr	 r3, =#0x123456 //same as movw and movt
 movw.w  r4, 0x123
 movt.w  r4, 0x456
 bx  	 lr
