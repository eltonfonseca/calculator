#include <stdio.h>
#include <stdlib.h>
#include "../include/division.h"

double division(float x, float y)
{
    if(y == 0.0)
    {
        printf("Error: Division by zero!");
        exit(1);
    }
    else
        return x / y;
}