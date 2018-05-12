#include <stdio.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "operators.h"

#define EXIT 'e'

void banner();
void menu();

int main()
{
    float x, y;
    double result;
    char option;
    
    banner();
    do
    {
        menu(&option);
        if(option != EXIT)
        {
            printf("Insert first number: ");
            scanf("%f", &x);
            __fpurge(stdin);
            printf("Insert second number: ");
            scanf("%f", &y);
            __fpurge(stdin);
            
            switch(option)
            {
                case SUM:
                    result = sum(x, y);
                    break;
                case MINUS:
                    result = minus(x, y);
                    break;
                case MULTIPLY:
                    result = multiply(x, y);
                    break;
                case DIVISION:
                    result = division(x, y);
                    break;
                default:
                    printf("Invalid Option!\n"); 
            }
            printf("Result is: %lf\n\n", result);
            printf("Do you want continue?[y/n]\n");
            __fpurge(stdin);
            option = getchar();
            if(tolower(option) == 'n')
                option = EXIT;  
        }
    } while(option != EXIT);
}

void banner()
{
    printf("*********************\n");
    printf("*  CALCULATOR v1.0  *\n");
    printf("*********************\n");    
}

void menu(int *option)
{
    printf("**********************\n");
    printf("*  Choose an option  *\n");
    printf("*                    *\n");
    printf("* [+] Addition       *\n");
    printf("* [-] Subtraction    *\n");
    printf("* [*] Multiply       *\n");
    printf("* [/] Division       *\n");
    printf("* [e] Exit           *\n");
    printf("*                    *\n");
    printf("**********************\n\n");
    printf("Option: ");
    __fpurge(stdin);
    *option = getchar();
}