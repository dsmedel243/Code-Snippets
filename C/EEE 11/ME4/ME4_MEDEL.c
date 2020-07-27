//Filename: ME4_MEDEL
//Programmer: Danica Medel
//Date: February 24, 2016
//Program: This program can either get ASCII value of letters, accumulate 5 integers, or generate a waveform.
#include <stdio.h>

/* Function Prototypes */

/* A function returns the ASCII value of the letter.*/
int A();

/* B function returns the final cumulative sum.*/
int B();

/* C function returns the period. */
int C();

/* D function exits the program */
int D();


int main ()
{
    char option, a;
    
    while((option != 'A') && (option != 'B') && (option != 'C') && (option !='D'))
    {
        printf("Choose task by entering the corresponding letter.\nA: Get ASCII value of letters.\nB: Accumulate 5 integers.\nC: Generate waveform.\nD: Exit.\n");
        printf("What would you like to do? ");
        scanf(" %c", &option);
        
        switch(option){
                
            case 'A':
            {
                //A();
                printf("The function return value is %d\n", A());
                break;
            }
            case 'B':
            {
                //B();
                printf("The function return value is %d\n", B());
                break;
            }
            case 'C':
            {
                //C();
                printf("The function return value is %d\n", C());
                break;
            }	
            case 'D':
            {
                //D();
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

/* A function returns the ASCII value of the letter.*/
int A()
{
    
    char a;
    
    while (!((a >= 'A') && (a <= 'Z')) || !((a >= 'a') && (a <= 'z')))
        {
            printf("Input a letter: ");
            scanf(" %c", &a);
                if (((a >= 'A') && (a <= 'Z')) || ((a >= 'a') && (a <= 'z')))
                    {
                        printf("You entered %c.\n", a);
                        printf("The ASCII value of %c is '%c' = %d .\n", a, a, a);
                        break;
                    }
                else
                    {
                        printf("This is not a letter of the alphabet.\n");
                    }
        }
    return(a);
}


/* B function returns the final cumulative sum.*/
int B()
{
    
    int b1, b2, b3, b4, b5, b6;
    
    printf("Input 5 integers to accumulate: \n");
    scanf("%d", &b1);
    printf("Cumulative sum is %d.\n", b1);
    printf("Next integer: ");
    scanf("%d", &b2);
    printf("Cumulative sum is %d.\n", b1 + b2);
    printf("Next integer: ");
    scanf("%d", &b3);
    printf("Cumulative sum is %d.\n", b1 + b2 + b3);
    printf("Next integer: ");
    scanf("%d", &b4);
    printf("Cumulatove sum is %d.\n", b1 + b2 + b3 + b4);
    printf("Next integer: ");
    scanf("%d", &b5);
    printf("Cumulative sum is %d.\n", b1 + b2 + b3 + b4 + b5);
    b6 = b1 + b2 + b3 + b4 + b5;
    
    return(b6);
    
}

/* C function returns the period. */
int C()
{
    
    int period, loop1, loop2, loop3, loop4, line1, line2, line3, line4, line5, line6, line7, line8;
    

    printf("Enter period: ");
    scanf(" %d", &period);
    
    for(loop1=0; loop1 < (166 / period); loop1++)
    {
        for(line1=0; line1 < (period/ 2) + 1; line1++){
            printf("x");
        }
        for(line2=0; line2 < (period/ 2) - 1; line2++){
            printf(" ");
        }
    }
    printf("\n");
    
    for(loop2=0; loop2 < (330 / period); loop2++)
    {
        printf("x");
        for(line4=0; line4 < (period/ 2) - 1; line4++){
            printf(" ");
        }
    }
    printf("\n");
    
    for(loop3=0; loop3 < (330 / period); loop3++)
    {
        printf("x");
        for(line6=0; line6 < (period/ 2) - 1; line6++){
            printf(" ");
        }
    }
    printf("\nx");
    
    for(loop4=0; loop4 < (166 / period); loop4++)
    {
        for(line8=0; line8 < (period/ 2) - 1; line8++){
            printf(" ");	
        }
        for(line7=0; line7 < (period/ 2) + 1; line7++){
            printf("x");	
        }
        
    }
    printf("\n");
    
    return(period);
    
    
}

/* D function exits the program */
int D()
{
    printf("Exit.\n");
}
