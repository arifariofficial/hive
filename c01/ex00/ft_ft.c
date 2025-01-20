/* 
Create a function that takes a pointer to int as a parameter, and sets the value "42" to that int.
• Here’s how it should be prototyped : void ft_ft(int *nbr) 
*/

#include <stdio.h>

void ft_ft(int *nbr);

int main() 
{
    int num;

    ft_ft(&num);
    printf("%d", num);
    return 0;
}

void ft_ft(int *nbr) {
    *nbr = 42;
}