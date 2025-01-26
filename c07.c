// C07-00 Reproduce the behavior of the function strdup
#include <stdlib.h>
int ft_str_length(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}
char *ft_strdup(char *src)
{
    char *duplicate = malloc( ft_str_length(src) + 1); // Allocate memory for the new string (+1 for null-terminator)
    int i = 0;    
    if (!duplicate)
        return 0;
    while ( src[i])
    {
        duplicate[i] = src[i];
        i++;
    }
    duplicate[i] = '\0';
    return duplicate;
}
