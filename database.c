/*
 * database.c
 *
 *  Created on: Nov 30, 2019
 *      Author: LENOVO
 */


#include "database.h"

static int number_of_databases = 0;
static int position = 0;

void createDataBase(nodePtr* info)
{
	createList(info);
	printf("database created !.");
	number_of_databases++;
}

void insertDataBase(nodePtr* info, int data)
{
	insertToList(info, position, data);
	position++;
}

void deleteFromDataBase(nodePtr* info, int* data)
{
	position--;
	deleteFromList(info, position, data);
}

int search_data_base(nodePtr* info, int search_key)
{
	return searchIntoList(info, search_key);
}


void sort_database(nodePtr* info)
{
	sortList(info);
}

int operation(char*);
