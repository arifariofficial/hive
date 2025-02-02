#include <stdio.h>
#include <string.h>
#include "rush02.h"

void handle_sextillions(char *num)
{
    process_large_number(num, "sextillion", handle_quintillions);
}

void handle_septillions(char *num)
{
    process_large_number(num, "septillion", handle_sextillions);
}

void handle_octillions(char *num)
{
    process_large_number(num, "octillion", handle_septillions);
}

void handle_nonillions(char *num)
{
    process_large_number(num, "nonillion", handle_octillions);
}

void handle_decillions(char *num)
{
    process_large_number(num, "decillion", handle_nonillions);
}
