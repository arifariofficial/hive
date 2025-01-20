#include <stdio.h>

void ft_ft(int *nbr);

int main() 
{
    int num;

    ft_ft(&num);
    return 0;
}

void ft_ft(int *nbr) {
    *nbr = 42;
}