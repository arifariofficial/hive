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
    else
        printf("Dict Error");

    printf("\n");
}
