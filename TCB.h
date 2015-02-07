#ifndef __TCB_H__
#define __TCB_H__

#include <stdint.h>

#define MAXNUMTHREADS 3  /** Maximum number of threads*/
#define STACKSIZE 100 /** number of 32bit words in stack */

typedef struct _Tcb {
  int32_t* sp;        //!< Stack Pointer
                      //!< Valid for threads not running        
  struct _Tcb* next;  //!< Next TCB Element
//  struct _Tcb* prev;  //!< Previous TCB element
  int32_t id;         //!< Thread ID
  int32_t state_sleep;//!< used to suspend execution
  int32_t priority;   //!< Thread priority
  int32_t state_blocked; //!<Used in lab 3
  int32_t stack[STACKSIZE]; //!<Thread stack
} Tcb_t;

Tcb_t TcbTable[MAXNUMTHREADS];
Tcb_t* RunningThread; 

void TCB_SetInitialStack(Tcb_t* pTcb);
Tcb_t* TCB_InsertNode(Tcb_t* root);

#endif /*__TCB_H__*/
