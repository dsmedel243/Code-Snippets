//Filename: ME7_MEDEL
//Programmer: Danica Medel
//Date: March 10, 2017
//Program: This program can get ASCII value of letters using get_ASCII(), accumulate 5 integers using acc5(), generate waveform using gen_wave(), print your name using draw_letter(), and accumulate more than 5 integers.

#include <stdio.h>
#include <ctype.h>


/* this function returns the ASCII value of the letter.*/
int get_ASCII(void)
{
    
    char a;
    
    while (!((a >= 'A') && (a <= 'Z')) || !((a >= 'a') && (a <= 'z')))
    {
        printf("Input a letter: ");
        scanf(" %c", &a);
        
        int ISA=isalpha(a);
        
        if (isalpha(a))
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


/* this function accumulates 5 integers.*/
int  acc5(void)
{
    
    printf("Input 5 integers to accumulate: ");
    
    int numbers[5];
    int cumsum[5];
    int sum=0;
    int i;
    
    for(i=0; i<5; i++)
    {
        scanf("%d", &numbers[i]);
        sum += numbers [i];
        cumsum[i] = sum;
        printf("Cumulative sum is %d.\n", sum);
        
        if(i!=4)
            printf("Next integer: ");
    }
    
    printf("The integer array contains ");
    for(i=0; i<5; i++)
    {
        if (i<4)
            printf("%d,", numbers[i]);
        if (i==4)
            printf("%d.\n", numbers[i]);
    }
    
    printf("The cumulative sum array contains ");
    for(i=0; i<5;i++)
    {
        if (i<4)
            printf("%d,", cumsum[i]);
        if (i==4)
            printf("%d.\n", cumsum[i]);
    }
    return 0;
    
}

/* this function returns the period and generates a waveform. */
int gen_wave(void)
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

/* this function prints your name */
void draw_letter(int character)
{
    switch(character)
    {
            
        case 'D':
        {
            //prints D
            printf("* *   \n");
            printf("*  * \n");
            printf("*   *\n");
            printf("*   *\n");
            printf("*  * \n");
            printf("**   \n\n");
            break;
        }
            
        case 'A':
        {
            //printfs A
            printf("  *  \n");
            printf(" * * \n");
            printf("*   *\n");
            printf("*****\n");
            printf("*   *\n");
            printf("*   *\n\n");
            break;
        }
            
        case 'N':
        {
            //prints N
            printf("*   *\n");
            printf("**  *\n");
            printf("*   *\n");
            printf("* * *\n");
            printf("*  **\n");
            printf("*   *\n\n");
            break;
        }
            
        case 'I':
        {
            //prints I
            printf("*****\n");
            printf("  *  \n");
            printf("  *  \n");
            printf("  *  \n");
            printf("  *  \n");
            printf("*****\n\n");
            break;
        }
            
        case 'C':
        {
            //prints C
            printf("*****\n");
            printf("*    \n");
            printf("*    \n");
            printf("*    \n");
            printf("*    \n");
            printf("*****\n\n");
            break;
        }
        case 1:
        {
            printf("  *  \n");
            printf(" **  \n");
            printf("  *  \n");
            printf("  *  \n");
            printf("  *  \n");
            printf("*****\n\n");
            
        }
        case 2:
        {
            printf(" *** \n");
            printf("*   *\n");
            printf("   * \n");
            printf("  *  \n");
            printf(" *   \n");
            printf("*****\n\n");
        }
        case 3:
        {
            printf(" *** \n");
            printf("*   *\n");
            printf("   * \n");
            printf("   * \n");
            printf("*   *\n");
            printf(" *** \n\n");
        }
            
    }
}

/* this function accumulates integers*/
int accumulate(const int numbers[],int cumsum[], const int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum+=numbers[i];
        cumsum[i] = sum;
    }
    return cumsum[n - 1];
}
