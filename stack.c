/**
 * @file stack.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-11-29
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "stack.h"
//static stack_pointer head = NULL;
#if STACK_TYPE == 1
static int stack_consumed_size;
static int stack_size;
//static stack_pointer
#endif
#if STACK_TYPE == 1
void createStack(stack_pointer* info, int size)
{
    stack_size = size;
    *info = (stack_pointer) calloc(size,sizeof(char));
    if (*info == NULL)
    {
        printf("\nStack can't be init, no memory available.\n");
    }else
    {
    	printf("\nStack Created!.\n");
    }
}
#endif
void push(stack_pointer* info, char data)
{
    #if STACK_TYPE == 1
    /* logic of stack array. */
        if(stack_consumed_size < stack_size)
        {
            (*info)->val = data;
            (*info)++;/* stack pointer to next empty element. */
            stack_consumed_size++;
            printf("\n%c is pushed to stack.\n", data);
        }else
        {
            printf("\nNo Space in stack.\n");
        }
        
    #endif

}

void pop(stack_pointer* info, char* data)
{
    #if STACK_TYPE == 1
        /* logic of stack array. */
		if (stack_consumed_size == 0)
		{
			printf("\nStack UnderFlow.\n");
		}
		else if((*info)->val == 0)
        {
            (*info)--;
            *data = (*info)->val;
            printf("\n%c popped from stack.\n", *data);
            (*info)->val = 0;/* return it back to 0. */
            stack_consumed_size--;

        }else
        {
            printf("\nNo Stack Available please Create one.\n");
        }
    #endif
}

void topStack(stack_pointer* info, char* data)
{
	if (*info == NULL)
	{
		printf("No Stack Created.");
	}else
	{
		if (stack_consumed_size == 0)
		{
			*data = 0; /* no data inserted in stack. */
		}else
		{
			(*info)--;
			*data = (*info)->val;
			(*info)++;/* return stack pointer to the empty place. */
		}
	}
}

unsigned char stackEmpty()
{
	if (stack_consumed_size == 0) return 1;

	return 0;
}
