/* C0500
Create an iterated function that returns a number. This number is the result of a factorial operation based on the number given as a parameter.
• If the argument is not valid the function should return 0.
• Overflows must not be handled, the function return will be undefined
*/
int ft_iterative_factorial(int nb)
{
    if (nb < 0) // If the number is negative, return 0 (invalid input).
        return 0;

    int result = 1; // Initialize result to 1, as factorial starts from 1.

    for (int i = 1; i <= nb; i++) // Iterate from 1 to the given number.
    {
        result *= i; // Multiply result by the current number.
    }

    return result; // Return the final factorial value.
}

/* C0501
• Create a recursive function that returns the factorial of the number given as a parameter.
• If the argument is not valid the function should return 0.
• Overflows must not be handled, the function return will be undefined.
*/
int ft_recursive_factorial(int nb)
{
    if (nb < 0) // Invalid input
        return 0;
    if (nb == 0 || nb == 1) // Base cases
        return 1;
    return nb * ft_recursive_factorial(nb - 1); // Recursive case
}

/* C0502
Create an iterated function that returns the value of a power applied to a number.
• A power lower than 0 returns 0.
• Overflows must not be handled.
• We’ve decided that 0 power 0 will returns 1
*/
int ft_iterative_power(int nb, int power)
{
    int result = 1;

    // A power lower than 0 returns 0
    if (power < 0)
        return 0;

    // Iterate power times, multiplying nb
    while (power > 0)
    {
        result *= nb;
        power--;
    }

    return result;
}