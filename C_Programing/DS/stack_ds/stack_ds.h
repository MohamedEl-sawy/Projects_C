#ifndef _STACK_DS_H
#define _STACK_DS_H

#include "std_types.h"

#define STACK_MAX_SIZE 5

#define STACK_DEBUG

typedef struct stack_ds_t{
   uint32_t StackPointer;
   uint32_t Data[STACK_MAX_SIZE];
}stack_ds_t;


typedef enum {
    STACK_FULL,
    STACK_EMPTY,
    STACK_NOT_FULL

} stackStatus_t;




/**
    @breief initialize tha stack pointer
    *@param  myStack  pointer to the stack
    @retval  status of the initialization process
*/
returnStatus_t stackInit (stack_ds_t *myStack);

returnStatus_t stackPush (stack_ds_t *myStack , uint32_t Value);

returnStatus_t stackPop  (stack_ds_t *myStack , uint32_t *value);

returnStatus_t stackTop  (stack_ds_t *myStack , uint32_t *Value);

returnStatus_t stackSize (stack_ds_t *myStack , uint32_t *stackSize);

returnStatus_t stackDisplay (stack_ds_t *myStack);


#endif // _STACK_DS_H
