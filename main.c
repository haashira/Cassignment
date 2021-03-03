#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>

#define personnummer 10
#define FORMAT "YYMMDDnnnC"

// calculating control digit
int controldigit(int pnr[])
{
    int sum = 0;
    for (int i = 0; i < 9; i++) // going through first 9 digits of personnummer
    {
        if ((i % 2) == 0)
        {
            sum += ((pnr[i] * 2) % 10) + ((pnr[i] * 2) / 10); // case for all even position digits
        }
        else
        {
            sum += pnr[i]; // case for all odd position digits
        }
    }
    return sum;
}

void control(int sum, int nr)
{
    int controldigit = sum % 10;
    if (controldigit != 0)
    {
        controldigit = 10 - controldigit;
    }

    if (controldigit == nr) // checking calculated controldigit with user input
    {
        printf("The personnummer you have entered is correct\n");
    }
    else
    {
        printf("The personnummer you have entered is incorrect\n");
    }
}

int main(void)
{
    int pnr[personnummer];
    char format[] = FORMAT;

    printf("Enter your personnummer in the format of %s: ", format); //prompting user input according to specified format
    for (int i = 0; i < personnummer; i++)
    {
        scanf("%1d-", &pnr[i]);
    }

    if ((pnr[2] == 0 && pnr[3] == 0) || (pnr[2] == 1 && pnr[3] > 2) || (pnr[4] == 1 && pnr[5] == 0) || (pnr[4] == 3 && pnr[5] > 1)) // checking if month is equal to 0 or more than 12 or if day is 0 or more than 31
    {
        printf("The personnummer you have entered is incorrect\n");
    }
    else
    {
        control((controldigit(pnr)), pnr[9]);
    }
    return 0;
}
