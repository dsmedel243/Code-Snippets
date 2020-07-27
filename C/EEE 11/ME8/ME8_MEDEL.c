//Filename: ME8_MEDEL
//Programmer: Danica Medel
//Date: April 7, 2016
//Program: This program creates a menu of dishes.

#include <stdio.h>
#include <string.h>
#include "lib_ME9_MEDEL.h"

int main() {
    struct menu_item menu[20];
    int i = 0;
    static int number_dish;
    int option;
    
    for(int x = 0; x < 20; x++)
    {
        for(int y = 0; y < 20; y++)
        {
            menu[x].name[y] = '\0';
            menu[x].price = 0;
        }
    }
    while(option != 4)
    {
        printf("What do you want to do?\n");
        printf("1. Add a dish to menu.\n");
        printf("2. Search a dish from the menu.\n");
        printf("3. Print menu.\n");
        printf("4. Exit program.\n");
        
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                number_dish = add_dish(menu, number_dish);
                break;
                
            case 2:
                search_dish(menu, number_dish);
                break;
                
            case 3:
                print_menu(menu, number_dish);
                break;
                
            case 4:
                printf("Exit.\n");
                break;
                
            default:
                printf("Invalid Input\n");
                printf("Choose only from options 1-4.\n");

        }
    }
    
    return 0;
    
}
