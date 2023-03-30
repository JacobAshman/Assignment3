//where functions are defined

//used to calculate the total resistence
//takes resistor value array, circuit type, and resistor ammount
double totalResistence (double *arr, int type, int rNumber);

//calculated total current
//takes total resistence and voltage
double circuitCurrent (double totalResistence, double voltage);

//gathers input from the user
//takes the type of input: 0 = circuit type
//                         1 = voltage
//                         2 = resistor ammount
double inputFunction (int type);