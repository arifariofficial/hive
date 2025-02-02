#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "rush02.h"

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
    {
        write(1, "Error\n", 6);
        return (1);
    }

    // Validate if the argument is a positive number
    if (!is_valid_number(argv[argc - 1]))
    {
        write(1, "Error\n", 6);
        return (1);
    }

    // If two arguments are provided, use the given dictionary
    if (argc == 3)
        load_dictionary(argv[1]);
    else
        load_dictionary("numbers.dict"); // Default dictionary

    // Convert and print the number
    convert_number(argv[argc - 1]);

    return (0);
}
