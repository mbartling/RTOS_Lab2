#include "TCB.h"

void TCB_SetInitialStack(Tcb_t* pTcb)
{
  int32_t* stack = pTcb->stack;
  pTcb->sp = &stack[STACKSIZE - 16];
  stack[STACKSIZE-1] = 0x01000000; // Set Thumb bit
  //Rest of stack registers are currently random
}