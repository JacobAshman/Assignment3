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
    if (type == 1) { //series
      total = arr[i] + total;
    }
    else if (type == 2) {  //parallel
      total = (1.0 / arr[i]) + total;  
    }
  }
  if (type == 2) //find the total resistence by taking the inverse of the summation in a parallel circuit
  {
    inverseTotal = 1 / total;
    return inverseTotal;
  }
  return total;
}

//calculates the current using total resistence and voltage
double circuitCurrent (double totalResistence, double voltage)
{
    //uses ohms law
  double current = voltage / totalResistence;
  return current;
}

double inputFunction (int type)
{
int properInput = 1; //loop condition
char * collecter = malloc(sizeof(char) * 15); //defines the collecter variable, used to temporarily stor input
int input; //used for just the circuit type
if(type == 0)
{ //circuit type input
//printf("please enter the type of resistor: 1 for Series 2 for Parallel\n");
while(properInput != 0){ 
    scanf("%s", collecter);
    int i;
    if(strlen(collecter) == 1){  
    for(i = 0; i < strlen(collecter); ++i)
    {
        if (isdigit(collecter[i])) 
        {
            input = collecter[0];
            input = input - 48; //converts from ascci into a number
            if((input == 1) || (input == 2)) 
            {
                free(collecter); //frees collecter before terminating the function
                return input;
                
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
    
    

}
else if (type == 2) {// used for resistor number
   // printf("please enter the number of resistors (max of 100)\n"); : used for testing
while(properInput != 0){ 
    scanf("%s", collecter);
    int i; //loop variable
    char *temp; //used for strtol function
    int condition = 0; //keeps track of validity of the input
     
    for(i = 0; i < strlen(collecter); ++i)
    {
        if (!isdigit(collecter[i])) 
        {
            condition = 1;
        }
    }
    if(condition == 0)
    {   
        input = strtol(collecter, &temp, 10);
        if((input >= 0) && (input <= 100)) 
        {
            free(collecter);
            return input;
        }
        else //if the integer is outside of the parameters
        {     
            printf("Invalid input, please enter within the parameters\n"); 
        }
            
    }
    else if (condition == 1) //if there is a non integer within the input
    {
        printf("Invalid input, please enter a positive integer\n"); 
    }
        
        
    }
    
    }
    


else {
    
    int i; //used for the for loop
    char *temp; //used for strtod
    
    while(properInput != 0){
    int condition = 0; //keeps track of any non integer characters
    int deciCounter = 0; //if this is greater than 1 the input is invalid
    
    scanf("%s", collecter); 
    for(i = 0; i < strlen(collecter); ++i) 
    {
        if (!isdigit(collecter[i]))
        {
            if(collecter[i] == '.')
            {
                deciCounter++; 
            }
            else
            {
                condition = 1;
            }
            
            

        }

    }
    if (condition == 0 && (deciCounter < 2))
    { 
    input = strtod(collecter, &temp); 
    free(collecter);
    return input;
    }
    else
    {
        printf("your input contained: either a letter, too many decimal characters, or was negative \nThis is not allowed, please try again\n"); 
    }
}
}
}