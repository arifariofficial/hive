// C0600 Write a C program that prints its own name, followed by a new line.
#include <unistd.h>

void ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

int main(int argc, char **argv)
{
    (void)argc; // Unused variable
    ft_putstr(argv[0]);
    write(1, "\n", 1);
    return 0;
}

// C0601  Write a C program that prints all given arguments, one per line, in the same order as provided in the command line.

int main(int argc, char **argv)
{
    int i = 1; // Start from 1 to skip the program name

    while (i < argc)
    {
        ft_putstr(argv[i]);
        write(1, "\n", 1);
        i++;
    }
    return 0;
}

// C0602 Write a C program that prints all given arguments, one per line, but in reverse order from how they were provided in the command line.

int main(int argc, char **argv)
{
    int i = argc - 1; // Start from the last argument

    while (i > 0) // Stop at argv[0] (program name should not be printed)
    {
        ft_putstr(argv[i]);
        write(1, "\n", 1);
        i--;
    }
    return 0;
}

// C0603 Write a C program that prints all given arguments, one per line, sorted in ASCII order.

#include <unistd.h>

// Function to compare two strings
int ft_strcmp(char *s1, char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

// Function to print a string using write
void ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

// Function to swap two strings
void ft_swap(char **s1, char **s2)
{
    char *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int main(int argc, char **argv)
{
    int i;
    int j;
    int sorted;

    // Bubble Sort using while loops
    i = 1;
    while (i < argc - 1)
    {
        j = 1;
        sorted = 1; // Track if sorting is complete

        while (j < argc - i)
        {
            if (ft_strcmp(argv[j], argv[j + 1]) > 0)
            {
                ft_swap(&argv[j], &argv[j + 1]);
                sorted = 0; // Sorting is still needed
            }
            j++;
        }
        if (sorted) // If no swaps were made, sorting is done
            break;
        i++;
    }

    // Print sorted arguments using while loop
    i = 1;
    while (i < argc)
    {
        ft_putstr(argv[i]);
        write(1, "\n", 1);
        i++;
    }
    return 0;
}

