#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bubblesort.h"

int compare_int_asc(void *a, void *b) 
{
	int num1 = *((int*)a);
    int num2 = *((int*)b);
 
    if(num1 > num2)
        return -1;
    else if (num1 < num2)
        return 1;
    else 
        return 0;
}

int compare_int_dec(void *a, void *b) 
{
	int num1 = *((int*)a);
    int num2 = *((int*)b);
 
    if(num1 > num2)
        return 1;
    else if (num1 < num2)
        return -1;
    else 
        return 0;
}

int compare_string_asc(void *a, void *b) 
{
	char num1[10];
    char num2[10];
    for(int i = 0; i < 10; i++)
    {
        num1[i] = *((char*)a);
        num2[i] = *((char*)b);
    }
    if(strcmp(num1, num2) > 0)
		return 1;
	else if(strcmp(num1, num2) < 0)
		return -1;
	else
		return 0;
}

int compare_string_dec(void *a, void *b) 
{
	char num1[10];
    char num2[10];
    for(int i = 0; i < 10; i++)
    {
        num1[i] = *((char*)a);
        num2[i] = *((char*)b);
    }
    if(strcmp(num1, num2) > 0)
		return -1;
	else if(strcmp(num1, num2) < 0)
		return 1;
	else
		return 0;
}

int compare_struct_asc(void *a, void *b) 
{
	if(strcmp(((mystruct_t*)a)->name, ((mystruct_t*)b)->name) > 0)
		return 1;
	else if(strcmp(((mystruct_t*)a)->name, ((mystruct_t*)b)->name) < 0)
		return -1;
	else if(strcmp(((mystruct_t*)a)->name, ((mystruct_t*)b)->name) == 0){
		if( ((mystruct_t*)a)->age > ((mystruct_t*)b)->age )
			return 1;
		else if(((mystruct_t*)a)->age < ((mystruct_t*)b)->age)
			return -1;
	}
	else
		return 1;
}

int compare_struct_dec(void *a, void *b)
{	
	if(strcmp(((mystruct_t*)a)->name, ((mystruct_t*)b)->name) > 0)
		return -1;
	else if(strcmp(((mystruct_t*)a)->name, ((mystruct_t*)b)->name) < 0)
		return 1;
	else if(strcmp(((mystruct_t*)a)->name, ((mystruct_t*)b)->name) == 0)
    {
		if(((mystruct_t*)a)->age > ((mystruct_t*)b)->age)
			return -1;
		else if(((mystruct_t*)a)->age < ((mystruct_t*)b)->age)
			return 1;
	}
	else
		return 1;	
}


void print_int(int *array, int n)
{
	for(int i=0; i<n; i++)
		printf("%d ",array[i]);
	puts("");
}

void print_char(char *array, int n)
{
	array[n] = 0;
	puts(array);
}

void print_struct(mystruct_t *array, int n)
{
	for(int i=0; i<n; i++)
		printf("(%s,%d) ",array[i].name, array[i].age);
	puts("");
}
void bubble_sort(void *array, size_t elem_cnt, size_t elem_size, int (*compare)(void *, void *))
{
	if(elem_size == 4)
    {
        for(int count = 0; count < (elem_cnt - 1); count++)
        {
            for(int count1 = 0; count1 < elem_cnt - count - 1; count1++)
            {
                int result = compare(&((int*)array)[count1], &((int*)array)[count1+1]);
                if (result < 0)
                {
                    int temp = ((int*)array)[count1];
                    ((int*)array)[count1] = ((int*)array)[count1+1];
                    ((int*)array)[count1+1] = temp;
                }
            }
        }
    }
    else if(elem_size == 1)
    {
        for(int count = 0; count < (elem_cnt - 1); count++)
        {
            for(int count1 = 0; count1 < elem_cnt - count - 1; count1++)
            {
                int result = compare(&((char*)array)[count1], &((char*)array)[count1+1]);
                if (result > 0)
                {
                    char temp = ((char*)array)[count1];
                    ((char*)array)[count1] = ((char*)array)[count1+1];
                    ((char*)array)[count1+1] = temp;
                }
            }
        }
    }
	else if(elem_size == sizeof(mystruct_t))
	{
		for(int count = 0; count < (elem_cnt - 1); count++)
        {
            for(int count1 = 0; count1 < elem_cnt - count - 1; count1++)
            {
                int result = compare(&((mystruct_t*)array)[count1], &((mystruct_t*)array)[count1+1]);
				if (result > 0)
                {
                    mystruct_t temp = ((mystruct_t*)array)[count1];
                    ((mystruct_t*)array)[count1] = ((mystruct_t*)array)[count1+1];
                    ((mystruct_t*)array)[count1+1] = temp;
                }
            }
        }
	}

}