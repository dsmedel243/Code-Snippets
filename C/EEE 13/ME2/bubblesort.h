#ifndef __BUBBLESORT_H__
#define __BUBBLESORT_H__

typedef struct mystruct {
	char name[30];
	int age;
} mystruct_t;

void bubble_sort(void *array, size_t elem_cnt, size_t elem_size, int (*compare)(void *, void *));

int compare_int_asc(void *a, void *b);

int compare_int_dec(void *a, void *b);

int compare_string_asc(void *a, void *b);

int compare_string_dec(void *a, void *b);

int compare_struct_asc(void *a, void *b);

int compare_struct_dec(void *a, void *b);

void print_int(int *array, int n);

void print_char(char *array, int n);

void print_struct(mystruct_t *array, int n);


#endif /* __BUBBLESORT_H__ */