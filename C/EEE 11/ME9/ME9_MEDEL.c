//Filename: ME9_MEDEL
//Programmer: Danica Medel
//Date: April 21, 2016
//Program: This program creates a menu of dishes.

#include <stdio.h>
#include <string.h>
#include "lib_ME10_MEDEL.h"

int main() {
    struct menu_item menu[20];
    struct menu_item *item;
    int i;
    char search_name2[20];
    char new_name[100];
    static int number_dish;
    int option, option2, new_price;
    int counter = 0;
    
    for(int x = 0; x < 20; x++)
    {
        for(int y = 0; y < 20; y++)
        {
            menu[x].name[y] = '\0';
            menu[x].price = 0;
        }
    }
    while(option != 5)
    {
        printf("What do you want to do?\n");
        printf("1. Add a dish to menu.\n");
        printf("2. Search a dish from the menu.\n");
        printf("3. Print menu.\n");
        printf("4. Edit dish.\n");
        printf("5. Exit program.\n");
        
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
                printf("Enter the name of dish to edit\n");
                scanf("%s", search_name2);
                for(i = 0,counter=0; i < number_dish; i++)
                {
                    if(strcmp(search_name2, menu[i].name) == 0)
                    {
                        printf("Dish\t\t\t\tPrice\n");
                        printf("%s\t\t\t\t%d\n", menu[i].name, menu[i].price);
                        counter = 1;
                        break;
                    }
                }
                
                
                if(counter == 0)
                {
                    printf("No dish found.\n");
                }
                
                if(counter == 1)
                {
                option2 = 0;
                    while(option2 != 3)
                    {
                        printf("What do you want to do?\n");
                        printf("1. Edit name.\n");
                        printf("2. Edit price.\n");
                        printf("3. Go back to Main Menu.\n");
                        
                        scanf("%d", &option2);
                        
                        switch(option2)
                        {
                            case 1:
                                edit_name(menu, &menu[i], new_name, number_dish);
                                break;
                                
                            case 2:
                                edit_price(menu, &menu[i], new_price);
                                break;
                                
                            case 3:
                                printf("Main Menu.\n");
                                break;
                                
                            default:
                                printf("Invalid Input.\n");
                                printf("Choose only from options 1-3.\n");
                        }
                    }
                }
                break;
                
            case 5:
                printf("Exit.\n");
                break;
                
            default:
                printf("Invalid Input.\n");
                printf("Choose only from options 1-4.\n");
                
        }
    }
    
    return 0;
    
}
