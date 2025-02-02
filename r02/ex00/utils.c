#include <stdio.h>
#include <stdlib.h>
#include "rush02.h"

// Function to check if a string is a valid positive number
int is_valid_number(char *str)
{
    int i = 0;

    // Check for empty string
    if (!str[i])
        return (0);

    // Ensure all characters are digits
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}
