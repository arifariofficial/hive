// C0700 Reproduce the behavior of the function strdup
#include <stdlib.h>

char *ft_strdup(char *src)
{
    int i = 0;
    char *dup;

    // Find the length of the source string
    while (src[i])
        i++;

    // Allocate memory for duplicate string (+1 for null terminator)
    dup = (char *)malloc((i + 1) * sizeof(char));
    if (!dup) // Check if malloc failed
        return NULL;

    // Copy characters using while loop
    i = 0;
    while (src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0'; // Null-terminate the string

    return dup;
}

// C0701 Create a function that returns an array of integers containing all values between min (inclusive) and max (exclusive).
#include <stdlib.h>

int *ft_range(int min, int max)
{
    int *range;
    int i = 0;
    int size;

    // Return NULL if min is greater than or equal to max
    if (min >= max)
        return NULL;

    // Calculate the size of the array
    size = max - min;

    // Allocate memory for the array
    range = (int *)malloc(size * sizeof(int));
    if (!range) // Check if malloc failed
        return NULL;

    // Fill the array using while loop
    while (i < size)
    {
        range[i] = min + i;
        i++;
    }

    return range;
}

/*
C0702 Create a function that:
Allocates and fills an array of integers from min (inclusive) to max (exclusive).
Stores the array's address in range.
Returns the size of the allocated array.
If an error occurs, returns -1.
If min >= max, sets range to NULL and returns 0.
*/
#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int i = 0;
    int size;

    // If min is greater than or equal to max, set range to NULL and return 0
    if (min >= max)
    {
        *range = NULL;
        return 0;
    }

    // Calculate the size of the array
    size = max - min;

    // Allocate memory for the array
    *range = (int *)malloc(size * sizeof(int));
    if (!(*range)) // Check if malloc failed
        return -1;

    // Fill the array using while loop
    while (i < size)
    {
        (*range)[i] = min + i;
        i++;
    }

    return size;
}

/*
C0703 Create a function that:
Concatenates all strings in an array, separated by a given sep string.
If size == 0, return an empty string that can be freed.
*/

#include <stdlib.h>

// Function to calculate string length
int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

// Function to copy a string
void ft_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Main function to join strings
char *ft_strjoin(int size, char **strs, char *sep)
{
    int total_len = 0;
    int i = 0;
    char *result;
    char *ptr;

    // Return an empty string if size is 0
    if (size == 0)
    {
        result = (char *)malloc(1);
        if (result)
            result[0] = '\0';
        return result;
    }

    // Calculate total length needed
    while (i < size)
    {
        total_len += ft_strlen(strs[i]);
        i++;
    }
    total_len += (size - 1) * ft_strlen(sep); // Add separators' length

    // Allocate memory
    result = (char *)malloc((total_len + 1) * sizeof(char));
    if (!result)
        return NULL;

    // Copy strings into result
    i = 0;
    ptr = result;
    while (i < size)
    {
        ft_strcpy(ptr, strs[i]);
        ptr += ft_strlen(strs[i]);
        if (i < size - 1)
        {
            ft_strcpy(ptr, sep);
            ptr += ft_strlen(sep);
        }
        i++;
    }
    *ptr = '\0'; // Null-terminate the string

    return result;
}

