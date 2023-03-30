#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "voltFunc.h"

//calculates total resistence
double totalResistence (double *arr, int type, int rNumber)
{
  double total = 0;
  double inverseTotal = 0;
  
  for (int i = 0; i < rNumber; i++) {
    if (type == 1) { 
      total = arr[i] + total;
    }
    else if (type == 2) {  
      total = (1.0 / arr[i]) + total;  
    }
  }
  if (type == 2)
  {
    inverseTotal = 1 / total;
    return inverseTotal;
  }
  return total;
}

//calculates the current using total resistence and voltage
double circuitCurrent (double totalResistence, double voltage)
{
  double current = voltage / totalResistence;
  return current;
}

double inputFunction (int type)
{
    int properInput = 1;
char * collecter = malloc(sizeof(char) * 15);
int input;
if(type == 0)
{ 
printf("please enter the type of resistor: 1 for Series 2 for Parallel\n");
while(properInput != 0){ 
    scanf("%s", collecter);
    int i;
    if(strlen(collecter) == 1){  
    for(i = 0; i < strlen(collecter); ++i)
    {
        if (isdigit(collecter[i])) 
        {
            input = collecter[0];
            input = input - 48; 
            if((input == 1) || (input == 2)) 
            {
                properInput = 0; 
                 continue;
            }
            else
            {
                printf("Invalid input, please enter within the parameters\n"); 
        }
        }
        else
        {
            printf("Invalid input, please enter a positive integer\n"); 
        }
    }}
    else{
        printf("Invalid Input, please only put 1 digit\n"); 
    }
    }
    free(collecter);
    return input;

}
else if (type == 2) {
    printf("please enter the number of resistors (max of 100)\n");
while(properInput != 0){ 
    scanf("%s", collecter);
    int i;
    int condition = 0; 
     
    for(i = 0; i < strlen(collecter); ++i)
    {
        if (!isdigit(collecter[i])) 
        {
            condition = 1;
        }
    }
    if(condition == 0)
    {   
        input = collecter[0];
        input = input - 48; 
        if((input >= 0) && (input <= 100)) 
        {
            properInput = 0; 
            continue;
        }
        else
        {     
            printf("Invalid input, please enter within the parameters\n"); 
        }
            
    }
    else if (condition == 1)
    {
        printf("Invalid input, please enter a positive integer\n"); 
    }
        
        
    }
    free(collecter);
    return input;
    }
    


else {
    printf("please enter voltage of the source\n");
    int deciCounter = 0;
    int i;
    char *temp; 
    int condition = 0;
    int dashCounter = 0;
    while(properInput != 0){
    scanf("%s", collecter); 
    for(i = 0; i < strlen(collecter); ++i) 
    {
        if (!isdigit(collecter[i]))
        {
            if(collecter[i] == '.')
            {
                deciCounter++; 
            }
            else if(collecter[i] == '-')
            {
                dashCounter++;
            }
            else
            {
                condition = 1;
            }
            
            

        }

    }
    if (condition == 0 && (deciCounter < 2) && dashCounter == 0)
    { 
    
    input = strtod(collecter, &temp); 
    return input;
    }
    else
    {
        printf("your input contained: either a letter, too many decimal characters, or was negativeThis is not allowed, please try again\n"); 
    }
}
}
}