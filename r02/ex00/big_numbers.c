#include <stdio.h>
#include <string.h>
#include "rush02.h"

char *find_in_dict(char *num);
void handle_tens(char *num);

void handle_hundreds(char *num)
{
    char hundreds[2] = {num[0], '\0'};

    print_number(hundreds);
    printf(" hundred");

    if (num[1] != '0' || num[2] != '0')
    {
        printf(" ");
        handle_tens(&num[1]);
    }
}

void handle_thousands(char *num)
{
    char thousands[2] = {num[0], '\0'};

    print_number(thousands);
    printf(" thousand");

    if (num[1] != '0' || num[2] != '0' || num[3] != '0')
    {
        printf(" ");
        handle_hundreds(&num[1]);
    }
}

void handle_millions(char *num)
{
    char millions[2] = {num[0], '\0'};

    print_number(millions);
    printf(" million");

    if (num[1] != '0' || num[2] != '0' || num[3] != '0' || num[4] != '0' || num[5] != '0')
    {
        printf(" ");
        handle_thousands(&num[1]);
    }
}
