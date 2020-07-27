//Filename: ME8_MEDEL
//Programmer: Danica Medel
//Date: April 7, 2016
//Program: This program creates a menu of dishes.

#include "lib_ME9_MEDEL.h"
#include <string.h>

int add_dish(struct menu_item menu[20], int number_dish)
{
    int i, j;
    int counter = 0;
    
    while(counter == 0)
    {
        counter = 0;
        printf("What is the name of the dish?\n");
        scanf("%s", menu[number_dish].name);
        for(j = 0; j < number_dish; j++)
        {
            if(strcmp(menu[number_dish].name, menu[j].name) == 0)
            {
                printf("Dish has already been added.\n");
                break;
            }
            else
            {
                counter++;
            }
        }
        if (j == number_dish)
        {
            while (!(menu[number_dish].price > 0))
            {
                printf("What is the price of the dish?\n");
                scanf("%d", &menu[number_dish].price);
                
                if (!(menu[number_dish].price > 0))
                {
                    printf("Prices should be positive integers\n");
                }
            }
            break;
            
            printf("Dish Added: %s P%d\n", menu[number_dish].name, menu[number_dish].price);
            
        }

    }
    
    i++;
    number_dish += i;
    
    return number_dish;
    
}

void search_dish(struct menu_item menu[20], int number_dish)
{
    int flag;
    char search_name[20];
    printf("Search dish: ");
    scanf("%s", search_name);
    
    
    for(int i = 0; i < number_dish; i++)
    {
        if(strcmp(search_name, menu[i].name) == 0)
        {
            printf("Dish\t\t\t\tPrice\n");
            printf("%s\t\t\t\t%d\n", menu[i].name, menu[i].price);
            break;
        }
        
    }
    
}

void print_menu(struct menu_item menu[20], int number_dish)
{
    printf("MENU\n");
    printf("Dish\t\t\t\tPrice\n");
    for(int i = 0; i < number_dish; i++)
    {
        printf("%s\t\t\t\tP%d\n", menu[i].name, menu[i].price);
    }
}