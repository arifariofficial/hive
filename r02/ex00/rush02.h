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

// Large Numbers
void handle_billions(char *num);
void handle_trillions(char *num);
void handle_quadrillions(char *num);
void handle_quintillions(char *num);
void handle_sextillions(char *num);
void handle_septillions(char *num);
void handle_octillions(char *num);
void handle_nonillions(char *num);
void handle_decillions(char *num);

// Helper for Large Numbers
void process_large_number(char *num, char *unit, void (*next_handler)(char *));

#endif
