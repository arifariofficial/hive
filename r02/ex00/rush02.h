#ifndef RUSH02_H
#define RUSH02_H

typedef struct s_dict
{
    char *number;
    char *word;
} t_dict;

// Function Prototypes
int is_valid_number(char *str);
void load_dictionary(char *filename);
void convert_number(char *str);

char *find_in_dict(char *num);
void print_number(char *num);
void handle_tens(char *num);
void handle_hundreds(char *num);
void handle_thousands(char *num);
void handle_millions(char *num);

#endif
