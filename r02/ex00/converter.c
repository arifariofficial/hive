#include <stdio.h>
#include <string.h>
#include "rush02.h"

extern t_dict dictionary[];
extern int dict_size;

char *find_in_dict(char *num)
{
    int i = 0;
    while (i < dict_size)
    {
        if (strcmp(dictionary[i].number, num) == 0)
            return dictionary[i].word;
        i++;
    }
    return NULL;
}

void print_number(char *num)
{
    char *word = find_in_dict(num);
    if (word)
        printf("%s", word);
}

void handle_tens(char *num)
{
    char tens[3] = {num[0], '0', '\0'};
    char ones[2] = {num[1], '\0'};

    if (num[0] == '1' || num[1] == '0')
        print_number(num);
    else
    {
        print_number(tens);
        printf("-");
        print_number(ones);
    }
}

void convert_number(char *num)
{
    int len = strlen(num);

    if (find_in_dict(num))
        print_number(num);
    else if (len == 2)
        handle_tens(num);
    else if (len == 3)
        handle_hundreds(num);
    else if (len >= 4 && len <= 6)
        handle_thousands(num);
    else if (len >= 7 && len <= 9)
        handle_millions(num);
    else if (len >= 10 && len <= 12)
        handle_billions(num);
    else if (len >= 13 && len <= 15)
        handle_trillions(num);
    else if (len >= 16 && len <= 18)
        handle_quadrillions(num);
    else if (len >= 19 && len <= 21)
        handle_quintillions(num);
    else if (len >= 22 && len <= 24)
        handle_sextillions(num);
    else if (len >= 25 && len <= 27)
        handle_septillions(num);
    else if (len >= 28 && len <= 30)
        handle_octillions(num);
    else if (len >= 31 && len <= 33)
        handle_nonillions(num);
    else if (len >= 34 && len <= 36)
        handle_decillions(num);
    else
        printf("Dict Error");
}
