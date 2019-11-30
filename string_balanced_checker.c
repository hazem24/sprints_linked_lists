/*
 * string_balanced_checker.c
 *
 *  Created on: Nov 29, 2019
 *      Author: LENOVO
 */

#include "string_balanced_checker.h"

/**
 * There are three types of Parantheses.
 * second order ( -> 0x28.
 * 				) -> 0x29.
 * last order   [ -> 0x5B.
 * 				] -> 0x5D.
 * higher order { -> 0x7B.
 * 				} -> 0x7D.
 */
stack_pointer head = NULL;

static char open_parantheses[3]   = {'{','(','['};
static char closed_parantheses[3] = {'}',')',']'};

/**
 * 0 -> {
 * 1 -> (
 * 2 -> [
 * 3 -> }
 * 4 -> )
 * 5 -> ]
 */
static char histogram[6] = {0};

static unsigned char getIndex(unsigned char parantheses);
static unsigned char canPush(unsigned char parantheses, unsigned char pushed);
static unsigned char check_allowed(unsigned char parantheses, unsigned char open_or_closed);
/**
 * return => 1 if balanced otherwise 0.
 */
#if DEBUG == 0
unsigned char checkForBalancedParantheses(char* expression)
{
	/**
	 * 1 - create stack with size of expression.
	 * 2 - push every element to stack.
	 * 3 - check for balanced when we pop from stack.
	 */
	createStack(&head, strlen(expression) + 1);
#if DEBUG == 0
	size_t i = 0, is_balanced = 1;
	char topStackValue = 0;

	for(i = 0; i < strlen(expression); i++)
	{		topStack(&head, &topStackValue);
		if ( topStackValue == 0)/* empty stack. */
		{

			/* empty stack only, open Parantheses can pushed. */
			if (check_allowed(*(expression + i), 1 ))
			{
				push(&head, *(expression + i));
			}else
			{
				is_balanced = 0;
				break;
			}

		}else
		{
			/* according to top of stack (lasted insert element i can predict the new elements which should be inserted).  */
			/**
			 * limit allowed parantheses.
			 	 * if  parantheses -> closed -> all is allowed.
			 	 * if open -> allowed index .
			 	 *
			 */
			if (check_allowed(topStackValue,0) == 1)
			{
				/* all type of parantheses allowed. */
				push(&head, *(expression + i));
			}else if (check_allowed(topStackValue,1) == 1)
			{
				/* push only if topStack <=  expression. */
				char test = canPush(topStackValue, *(expression + i));
				if (test)
				{
					//printf("Checker %d ",test);
					(test > 1) ? pop(&head,&test) : push(&head, *(expression + i));
				}else
				{
					is_balanced = 0;
					break;
				}
			}else
			{
				is_balanced = 0;
				break;
			}
		}
	}
	if (is_balanced != 0) return  stackEmpty();
	return is_balanced;
#endif
}

/**
 * open   -> 1.
 * closed -> 0.
 */
static unsigned char check_allowed(unsigned char parantheses, unsigned char open_or_closed)
{
	/* check if parantheses in opened_allowed array. */
	for(int i = 0; i < 3; i++)
	{
		if (open_or_closed == 1 && parantheses == open_parantheses[i])
		{
			return 1;
		}else if (open_or_closed == 0 && parantheses == closed_parantheses[i])
		{
			return 1;
		}
	}
	return 0;
}

static unsigned char getIndex(unsigned char parantheses)
{
	size_t i = 0;
	for(i = 0; i < 3; i++)
	{
		if (parantheses == open_parantheses[i] || parantheses == closed_parantheses[i])
		{
			return i;
		}
	}
	return -1;
}
static unsigned char canPush(unsigned char parantheses, unsigned char pushed)
{
	if (parantheses == pushed)
	{
		return 1;
	}else if (getIndex(parantheses) == getIndex(pushed))
	{
		return 2;
	}else if (getIndex(parantheses) < getIndex(pushed))
	{
		return 1;
	}
	return 0;
}
#endif

