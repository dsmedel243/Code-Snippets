//Filename: ME7_MEDEL
//Programmer: Danica Medel
//Date: March 10, 2016
//Program: This program can get ASCII value of letters using get_ASCII(), accumulate 5 integers using acc5(), generate waveform using gen_wave(), print your name using draw_letter(), and accumulate more than 5 integers.

#include <stdio.h>
#include "lib_ME7_MEDEL.h"
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

int main ()
{
    char option, a, name[19];
    int ctr;
    
    while((option != 'A') && (option != 'B') && (option != 'C') && (option !='D') && (option !='E') && (option != 'F'))
    {
        printf("Choose task by entering the corresponding letter.\nA: Get ASCII value of letters using get_ASCII().\nB: Accumulate 5 integers using acc5().\nC: Generate waveform using gen_wave().\nD: Print your name using draw_letter().\nE: Accumulate integers using accumulate.\nF: Exit.\n");
        printf("What would you like to do? ");
        scanf(" %c", &option);
        
        option = toupper(option);
        assert((option>=65)&&(option<=70));
        
        switch(option){
                
            case 'A':
            {
                get_ASCII();
                break;
            }
            case 'B':
            {
                acc5();
                break;
            }
            case 'C':
            {
                gen_wave();
                break;
            }
            case 'D':
            {
                
                printf("What is your name? ");
                fgets(name, sizeof(name), stdin);
                fgets(name, sizeof(name), stdin);
                if('\n'== name[strlen(name)-1])
                    name[strlen(name)-1]='\0';
                for(ctr=0; ctr<strlen(name) ;ctr++)
                {
                    draw_letter(name[ctr]);
                }
                break;
            }
            case 'E':
            {
                int n, sum;
                int i;
                int numbers[20];
                int cumsum[20];
                
                printf("Input number of integers to accumulate: ");
                scanf("%d", &n);
                
                printf("Input first integer: ");
                for(i=0; i<n; i++)
                {
                    scanf("%d", &numbers[i]);
                    if(i!=n-1)
                        printf("Next integer: ");
                }
                accumulate(numbers, cumsum, n);
                printf("The integer array contains ");
                for(i=0; i<n; i++)
                {
                    if (i<n-1)
                        printf("%d,", numbers[i]);
                    if (i==n-1)
                        printf("%d.\n", numbers[i]);
                }
                printf("The cumulative sum array contains ");
                for(i=0; i<n; i++)
                {
                    if (i<n-1)
                        printf("%d,", cumsum[i]);
                    if (i==n-1)
                        printf("%d.\n", cumsum[i]);
                }
                break;
            }
            case 'F':
            {
                printf("Exit.\n");
                break;
            }
            default:
            {
                printf("Invalid Input.\n");
            }
        }
    }
    return 0;
}
