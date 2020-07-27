#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bubblesort.h"

#define TYPE_INT 1
#define TYPE_CHAR 2
#define TYPE_STRUCT 3
#define MAX_N 250

int main(int argc, char **argv) 
{
	/*Get mode and n from file here.*/
	int mode,n;
	size_t elem_cnt, elem_size;
    char number[256];
    FILE *fp = fopen(argv[1], "r");
        if(fp == NULL)
        {
            printf("Error.\n");
        }
    fgets(number, 256, fp); //Gets Line 1(Array Type)
    mode = atoi(number);
    fgets(number, 256, fp); //Gets Line 2(Number of Elements)
    n = atoi(number);
    fgets(number, 256, fp); //Gets Line 3(Space)

	if(mode==TYPE_INT)
	{
		int array[MAX_N+10];
		/*Get array from file here*/
		for(int count = 0; n > count; count++)
        {
            fgets(number, 256, fp);
            array[count] = atoi(number);
        }
		
		puts("ORIGINAL ARRAY:");
		print_int(array,n);

		bubble_sort(array,n,sizeof(int),compare_int_asc);
		puts("ASCENDING ARRAY:");
		print_int(array,n);

		bubble_sort(array,n,sizeof(int),compare_int_dec);
		puts("DESCENDING ARRAY:");
		print_int(array,n);
	}
	else if(mode==TYPE_CHAR)
	{
		char array[MAX_N+10];
		/*Get array from file here*/
		for(int count1 = 0; n>count1; count1++)
       {
           fgets(number, 256, fp);
           array[count1] = number[0];
       }

		puts("ORIGINAL ARRAY:");
		print_char(array,n);

		bubble_sort(array,n,sizeof(char),compare_string_asc);
		puts("ASCENDING ARRAY:");
		print_char(array,n);

		bubble_sort(array,n,sizeof(char),compare_string_dec);
		puts("DESCENDING ARRAY:");
		print_char(array,n);
	}
	else if(mode==TYPE_STRUCT)
	{
		mystruct_t array[MAX_N+10];
		/*Get array from file here*/

		for(int i = 0; i < n; i++)
			fscanf(fp, "%s %d\n", array[i].name, &array[i].age);
		
		puts("ORIGINAL ARRAY:");
		print_struct(array,n);


		bubble_sort(array,n,sizeof(mystruct_t),compare_struct_asc);
		puts("ASCENDING ARRAY:");
		print_struct(array,n);

		bubble_sort(array,n,sizeof(mystruct_t),compare_struct_dec);
		puts("DESCENDING ARRAY:");
		print_struct(array,n);
	}
	else
	{
		return 0;
	}
	fclose(fp);
	return 0;
}
