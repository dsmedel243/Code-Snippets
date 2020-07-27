//Filename: ME8_MEDEL
//Programmer: Danica Medel
//Date: April 7, 2016
//Program: This program creates a menu of dishes.

#ifndef lib_ME8_MEDEL_h
#define lib_ME8_MEDEL_h

#include <stdio.h>

struct menu_item{
    char name[20];
    int price;
};

/* Function Prototype */
int add_dish(struct menu_item menu[20], int number_dish);

void search_dish(struct menu_item menu[20], int number_dish);

void print_menu(struct menu_item menu[20], int number_dish);

#endif /* lib_ME8_MEDEL_h */
