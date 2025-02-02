#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "rush02.h"

#define BUFFER_SIZE 1024
#define MAX_ENTRIES 100

t_dict dictionary[MAX_ENTRIES];  // Array to store dictionary entries
int dict_size = 0;  // Track number of entries

// Helper function to trim spaces
char *trim_spaces(char *str)
{
    while (*str == ' ') str++;  // Trim leading spaces
    char *end = str + strlen(str) - 1;
    while (end > str && *end == ' ') *end-- = '\0'; // Trim trailing spaces
    return str;
}

// Function to parse a single dictionary entry
void parse_line(char *line)
{
    char *colon = strchr(line, ':'); // Find the colon separator
    if (!colon) return; // Skip invalid lines

    *colon = '\0'; // Split number and word
    char *number = trim_spaces(line);
    char *word = trim_spaces(colon + 1);

    if (*number == '\0' || *word == '\0') return; // Skip empty entries

    // Store in dictionary struct
    dictionary[dict_size].number = strdup(number);
    dictionary[dict_size].word = strdup(word);
    dict_size++;
}

// Function to load dictionary into memory
void load_dictionary(char *filename)
{
    int fd;
    char buffer[BUFFER_SIZE + 1];
    int bytes_read;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        write(1, "Dict Error\n", 11);
        return;
    }

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read <= 0)
    {
        write(1, "Dict Error\n", 11);
        close(fd);
        return;
    }
    buffer[bytes_read] = '\0';

    // Process dictionary line by line
    char *line = strtok(buffer, "\n");
    while (line)
    {
        parse_line(line);
        line = strtok(NULL, "\n");
    }

    close(fd);
}
