#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "voltFunc.h"

//calculates total resistence
// *DELETE* I was not sure which variable was used to decide circuit type.
double totalResistence (double *arr, int type)
{
  double total = 0;
  for (i = 0; i < type; i++) {
    if (circuitType == 1) { 
      total = arr[i] + total;
    }
    else if (circuitType == 2) {  
      total = (1 / arr[i]) + total;  
    }
  }
  return total;
}

//calculates the current using total resistence and voltage
double circuitCurrent (double totalResistence, double voltage)
{
  double current = voltage / totalResistance(arr, type);
  return current;
}
