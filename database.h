/*
 * database.h
 *
 *  Created on: Nov 30, 2019
 *      Author: LENOVO
 */

#ifndef DATABASE_H_
#define DATABASE_H_


#include "linked_list.h"

void createDataBase(nodePtr* info);

void insertDataBase(nodePtr* info, int data);

void deleteFromDataBase(nodePtr* info, int* data);

int search_data_base(nodePtr* info, int search_key);

void sort_database(nodePtr* info);

int operation(char*);


#endif /* DATABASE_H_ */
