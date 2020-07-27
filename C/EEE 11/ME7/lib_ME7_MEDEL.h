//Filename: ME7_MEDEL
//Programmer: Danica Medel
//Date: March 10, 2017
//Program: This program can get ASCII value of letters using get_ASCII(), accumulate 5 integers using acc5(), generate waveform using gen_wave(), print your name using draw_letter(), and accumulate more than 5 integers.

#ifndef lib_ME7_MEDEL_h
#define lib_ME7_MEDEL_h

/* Function Prototypes */

/* A function returns the ASCII value of the letter.*/
int get_ASCII();

/* B function returns the final cumulative sum.*/
int acc5();

/* C function returns the period. */
int gen_wave();

/* D function prints own name. */
void draw_letter();

/* E function accumulates integers. */
int accumulate(const int numbers[],int cumsum[], const int n);

#endif /* lib_ME7_MEDEL_h */



