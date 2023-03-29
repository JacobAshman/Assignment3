#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "voltFunc.h"

int main(int argc, char **argv) {

//make resistor array
    //probably doubles
//make user input for battery voltage & ressitors

//make final print statements



int properInput = 1;
char collecter[15]; // change this to malloc
int circuitType;
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
        else
        {
            printf("Invalid input, please enter a number\n"); 
        }
    }}
    else{
        printf("Invalid Input, please only put 1 digit\n"); 
    }
    }
    properInput = 1;


}