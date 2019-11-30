/**
 * @file stack.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-11-29
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief STACK_TYPE 0 => LINKED LIST.
 * 1 = >ARRAY
 * 
 */
#define STACK_TYPE 1
typedef struct
{
    char val;
}Stack;

typedef Stack* stack_pointer;


void createStack(stack_pointer* info, int size);

void push(stack_pointer* info, char data);

void pop(stack_pointer* info, char* data);

void topStack(stack_pointer* info, char* data);


unsigned char stackEmpty();

#endif
