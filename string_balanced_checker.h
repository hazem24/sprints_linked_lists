/*
 * string_balanced_checker.h
 *
 *  Created on: Nov 29, 2019
 *      Author: LENOVO
 */

#ifndef STRING_BALANCED_CHECKER_H_
#define STRING_BALANCED_CHECKER_H_

#include "stack.h"
#include <string.h>

extern stack_pointer head;

#define DEBUG 0
unsigned char checkForBalancedParantheses(char* expression);

#endif /* STRING_BALANCED_CHECKER_H_ */
