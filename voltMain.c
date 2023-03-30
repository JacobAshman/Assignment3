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
int continuing = 1;
int circuitType;
double voltage;
int resistorNumber;
while(continuing == 1){


printf("Welcome to the average Voltage calculator!\n");
printf("please enter the type of resistor: 1 for Series 2 for Parallel\n");
circuitType = inputFunction(0);
//printf("%d\n", circuitType);
printf("please enter voltage of the source\n");
voltage = inputFunction(1);
//printf("%lf\n", voltage);
printf("please enter the number of resistors (max of 100)\n");
resistorNumber = inputFunction(2);
printf("%d\n",resistorNumber);






//asks for the resistor values
char * collecter = malloc(sizeof(char) * 15);
double * resistors = malloc(sizeof(double) * resistorNumber);
int i = 0;
int j;
char *temp;
int k = 0;
int l = 0;
int m = 0;
int deciNum = 0;
int condition = 1;
while (i < resistorNumber) 
{
    printf("please enter the value of resistor %d:   ", i+1);
    scanf("%s", collecter);
    for(j = 0; j < strlen(collecter); ++j)
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
    if(condition == 1 && deciNum < 2)
    {
        resistors[i] = strtod(collecter, &temp);
        i++;
    }
    else{
        printf("that is not an acceptable input\n");
    }
}

  
double resistenceTotal = totalResistence(resistors, circuitType, resistorNumber);

double curcuitCurrent = circuitCurrent(resistenceTotal, voltage);

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
continuing = inputFunction(0);

}
printf("Thank you for using this system. Goodbye!\n");
}

