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
