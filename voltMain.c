#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h> 
#include <limits.h>

#include "voltFunc.h"

int main(int argc, char **argv) {

//make resistor array
    //probably doubles
//make user input for battery voltage & resistors

//make final print statements
int circuitType;
double voltage;
int resistorNumber;

printf("Welcome to the average Voltage calculator!\n");
//printf("please enter the type of resistor: 1 for Series 2 for Parallel\n");
circuitType = inputFunction(0);
//printf("%d\n", circuitType);
//printf("please enter voltage of the source\n");
voltage = inputFunction(1);
//printf("%lf\n", voltage);
//printf("please enter the number of resistors (max of 100)\n");
resistorNumber = inputFunction(2);
//printf("%d\n",resistorNumber);





/*
//asks for the resistor values
char * collecter = malloc(sizeof(char) * 15);
int circuitType;
int properInput = 1;
printf("remeber to change this to a welcome message\n");
while(properInput != 0){ 
    printf("please enter the circuit type: 1 for series or 2 for parallel\n");
    scanf("%s", collecter);
    int i;
    if(strlen(collecter) == 1){  
    for(i = 0; i < strlen(collecter); ++i)
    {
        if (isdigit(collecter[i])) 
        {
             circuitType = collecter[0];
            circuitType = circuitType - 48; 
            if((circuitType == 1) || (circuitType == 2)) 
            {
                properInput = 0; 
                 continue;
            }
            else
            {
                printf("Invalid input, please put a 1 or a 2\n"); 
        }
        }
        else
        {
            printf("Invalid input, please enter a number\n"); 
        }
    }}
    else{
        printf("Invalid Input, please only put 1 digit\n"); 
    }
    }
*/
}