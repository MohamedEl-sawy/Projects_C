#include <stdio.h>
#include <stdlib.h>

#include "stack_ds.h"

stack_ds_t Stack1;
stack_ds_t Stack2;

int main()
{
    returnStatus_t ret = RNOK;
    ret = stackInit(&Stack1);
    if (RNOK == ret){
        printf("stcak failed to be intialized !!\n");
    }
    else{
        ret = stackPush(&Stack1 , 11);
        ret = stackPush(&Stack1 , 22);
        ret = stackPush(&Stack1 , 33);
        ret = stackPush(&Stack1 , 44);
        ret = stackPush(&Stack1 , 55);
        ret = stackPush(&Stack1 , 66);
        ret = stackPush(&Stack1 , 77);
        ret = stackPush(&Stack1 , 77);
        ret = stackPush(&Stack1 , 77);
        ret = stackPush(&Stack1 , 77);
    }
    ret = stackInit(&Stack2);
    if (RNOK == ret){
        printf("stcak2 failed to be intialized !!\n");
    }
    return 0;
}
