#include <stdio.h>
#include <string.h>
#include "rush02.h"

void process_large_number(char *num, char *unit, void (*next_handler)(char *))
{
    char large_part[3] = {num[0], num[1], '\0'};
    print_number(large_part);
    printf(" %s", unit);

    if (num[2] != '0' || num[3] != '0' || num[4] != '0' || num[5] != '0' || num[6] != '0')
    {
        printf(" ");
        next_handler(&num[2]);
    }
}

void handle_billions(char *num)
{
    process_large_number(num, "billion", handle_millions);
}

void handle_trillions(char *num)
{
    process_large_number(num, "trillion", handle_billions);
}

void handle_quadrillions(char *num)
{
    process_large_number(num, "quadrillion", handle_trillions);
}

void handle_quintillions(char *num)
{
    process_large_number(num, "quintillion", handle_quadrillions);
}
