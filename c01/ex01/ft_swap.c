/*
Create a function that takes a pointer to pointer to pointer to pointer to pointer to pointer to pointer to pointer to pointer to int as a parameter and sets the value "42" to that int.
• Here’s how it should be prototyped : void ft_ultimate_ft(int *********nbr);
*/

#include <stdio.h>

void ft_swap(int *a, int *b);

int main(){
    int num1, num2;

    num1 = 10;
    num2 = 20;

    printf("Before swap\n a: %d b:%d", num1, num2);
    ft_swap(&num1, &num2);    
    printf("\nAfter swap\n a: %d b:%d", num1, num2);

    return 0;
}

void ft_swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}