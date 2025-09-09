#include "stack_ds.h"
//#include <stdio.h> // Include this for printf

/**
    *@brief Check if stack is full
    *@param  myStack  pointer to the stack
    @retval  status of the stack
*/
static stackStatus_t stackFull(stack_ds_t *myStack){
    if(myStack->StackPointer == STACK_MAX_SIZE-1){
        return STACK_FULL;
    }
    else{
        return STACK_NOT_FULL;
    }
}

/**
    *@brief Check if stack is empty
    *@param  myStack  pointer to the stack
    @retval  status of the stack
*/
static stackStatus_t stackEmpty(stack_ds_t *myStack){
    if(myStack->StackPointer == -1){
        return STACK_EMPTY;
    }
    else{
        return STACK_NOT_FULL; // Change STACK_NOT_FULL to STACK_NOT_EMPTY
    }
}

/**
    *@brief Initialize the stack pointer
    *@param  myStack  pointer to the stack
    @retval  status of the initialization process
*/
returnStatus_t stackInit(stack_ds_t *myStack){
    returnStatus_t ret = ROK; // Change RNOK to ROK
    if (NULL == myStack){
        ret = RNOK;
    }
    else{
        myStack->StackPointer = -1;
        ret = ROK;
    }
    return ret;
}

/**
    *@brief Push value onto the stack
    *@param  myStack  pointer to the stack
    *@param  Value    value to push onto the stack
    @retval  status of the push operation
*/
returnStatus_t stackPush(stack_ds_t *myStack, uint32_t Value){
    returnStatus_t ret = RNOK;
    if((NULL == myStack) || (STACK_FULL == stackFull(myStack))){
        #ifdef STACK_DEBUG
        printf("Error !! stack is full, can't push (%i)!!.\n", Value);
        #endif // STACK_DEBUG
        ret = RNOK;
    }
    else{
        myStack->StackPointer++; // Increment the stack pointer
        myStack->Data[myStack->StackPointer] = Value;
        #ifdef STACK_DEBUG
        printf("Value (%i) pushed to stack.\n", Value);
        #endif // STACK_DEBUG
        ret = ROK;
    }
    return ret;
}

/**
    *@brief Pop value from the stack
    *@param  myStack  pointer to the stack
    *@param  value    pointer to store the popped value
    @retval  status of the pop operation
*/
returnStatus_t stackPop(stack_ds_t *myStack, uint32_t *value){
    returnStatus_t ret = RNOK;
    if((NULL == myStack) || (STACK_EMPTY == stackEmpty(myStack))){
        #ifdef STACK_DEBUG
        printf("Error !! stack is empty, can't pop!!.\n");
        #endif // STACK_DEBUG
        ret = RNOK;
    }
    else{
        *value = myStack->Data[myStack->StackPointer];
        myStack->StackPointer--; // Decrement the stack pointer
        #ifdef STACK_DEBUG
        printf("Value (%i) popped from stack.\n", *value);
        #endif // STACK_DEBUG
        ret = ROK;
    }
    return ret;
}

/**
    *@brief Get the top value from the stack without popping
    *@param  myStack  pointer to the stack
    *@param  Value    pointer to store the top value
    @retval  status of the operation
*/
returnStatus_t stackTop(stack_ds_t *myStack, uint32_t *Value){
    returnStatus_t ret = RNOK;
    if((NULL == myStack) || (STACK_EMPTY == stackEmpty(myStack))){
        #ifdef STACK_DEBUG
        printf("Error !! stack is empty!!.\n");
        #endif // STACK_DEBUG
        ret = RNOK;
    }
    else{
        *Value = myStack->Data[myStack->StackPointer];
        #ifdef STACK_DEBUG
        printf("Top value of stack is (%i).\n", *Value);
        #endif // STACK_DEBUG
        ret = ROK;
    }
    return ret;
}

/**
    *@brief Get the size of the stack
    *@param  myStack     pointer to the stack
    *@param  stackSize   pointer to store the size of the stack
    @retval  status of the operation
*/
returnStatus_t stackSize(stack_ds_t *myStack, uint32_t *stackSize){
    returnStatus_t ret = ROK;
    *stackSize = myStack->StackPointer + 1; // Size is 1 greater than the stack pointer
    return ret;
}

/**
    *@brief Display the contents of the stack
    *@param  myStack  pointer to the stack
    @retval  status of the operation
*/
returnStatus_t stackDisplay(stack_ds_t *myStack){
    returnStatus_t ret = RNOK;
    if((NULL == myStack) || (STACK_EMPTY == stackEmpty(myStack))){
        #ifdef STACK_DEBUG
        printf("Error !! stack is empty!!.\n");
        #endif // STACK_DEBUG
        ret = RNOK;
    }
    else{
        printf("Stack contents:\n");
        for(int i = 0; i <= myStack->StackPointer; i++){
            printf("%i\n", myStack->Data[i]);
        }
        ret = ROK;
    }
    return ret;
}
