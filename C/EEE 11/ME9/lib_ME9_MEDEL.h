//Filename: ME10_MEDEL
//Programmer: Danica Medel
//Date: April 10, 2016
//Program: This program creates a menu of dishes.

#ifndef lib_ME10_MEDEL_h
#define lib_ME10_MEDEL_h

#include <stdio.h>

struct menu_item{
    char name[20];
    int price;
};

/* Function Prototype */
int add_dish(struct menu_item menu[20], int number_dish);

void search_dish(struct menu_item menu[20], int number_dish);

void print_menu(struct menu_item menu[20], int number_dish);

void edit_dish(struct menu_item memu[20], int number_dish);

int edit_price(struct menu_item menu[20], struct menu_item *item, int new_price);

int edit_name(struct menu_item menu[20], struct menu_item *item, char *new_name, int number_dish);

#endif /* lib_ME10_MEDEL_h */
