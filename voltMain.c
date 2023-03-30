/*
code written by: Luke Swanson, Chloe Holmes, and Jacob Ashman
Date 3/30/2023

This program takes input of circuit type, voltage, number of resistors and thier resistence values
and it outputs total resistence and average amps of the circuit.

extra credit was attempted
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h> 
#include <limits.h>

#include "voltFunc.h"

int main(int argc, char **argv) {


int continuing = 1; //main body loop
int circuitType; // holds the type of circuit, 1 for series 2 for parallel
double voltage; //holds the voltage
int resistorNumber; //holds the number of resistors
while(continuing == 1){

//gathers all the inputs here
printf("Welcome to the average Voltage calculator!\n");
printf("please enter the type of resistor: 1 for Series 2 for Parallel\n");
circuitType = inputFunction(0);

printf("please enter voltage of the source\n");
voltage = inputFunction(1);

printf("please enter the number of resistors (max of 100)\n");
resistorNumber = inputFunction(2);







//asks for the resistor values
//this loop was not done with input Function as it was a little bit different than the other input requirements 
char * collecter = malloc(sizeof(char) * 15);
double * resistors = malloc(sizeof(double) * resistorNumber);
int i = 0; //loop variables
int j;
char *temp; //used for strtod function
while (i < resistorNumber) //loop for number of resistor
{
    int deciNum = 0; //keeps track of decimals in the input, greater than 1 returns an error
    int condition = 1;//keeps track of number of non number characters
    printf("please enter the value of resistor %d:   ", i+1);
    scanf("%s", collecter);
    for(j = 0; j < strlen(collecter); ++j) //loop to check if input is valid
    {
        if (!isdigit(collecter[j]))
        {
            if (collecter[j] == '.')
            {
                deciNum++;
            }
            else 
            {
                condition = 0;
            }
        }
    }
    if(condition == 1 && deciNum < 2) //input is valid continues the loop
    {
        resistors[i] = strtod(collecter, &temp);
        i++;
    }
    else{
        printf("that is not an acceptable input\n");
    }
}

  
double resistenceTotal = totalResistence(resistors, circuitType, resistorNumber); //calculation functions

double curcuitCurrent = circuitCurrent(resistenceTotal, voltage);

//final print statements  organizing final data
printf("User - entered input ----------------\n");
if (circuitType == 1)
{
    printf("Circuit Type                : Series\n");
}
else{
    printf("Circuit Type                : Parallel\n");
}
printf("Voltage of Battery (volts)  : %lf\n", voltage);
printf("Number of Resistors         : %d\n", resistorNumber);
for(i = 1; i <= resistorNumber; i++)
{
    printf("--- Resistor %d (ohms)      : %lf\n", i, resistors[i-1]);
}
printf("computer-generated output------------\n");
printf("Total resistance (ohms)     : %lf\n", resistenceTotal);
printf("Amplitude (amps)            : %lf\n", curcuitCurrent);
printf("Would you like to analize anouther circuit?(1 for yes, 2 for no)\n");
continuing = inputFunction(0); //reuses circuit type input function as they are functionally identical in use.

}
printf("Thank you for using this system. Goodbye!\n");
}

