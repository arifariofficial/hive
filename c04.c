/* C0400 Create a function that counts and returns the number of characters in a string */
int ft_strlen(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

/* C0401 Create a function that displays a string of characters on the standard output */

void ft_putstr(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
}

/* C0403 Create a function that displays the number entered as a parameter. The function has to be able to display all possible values within an int type variable */
void ft_putnbr(int nb) {
    char c;

    // Handle the minimum integer value
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }

    // Handle negative numbers
    if (nb < 0) {
        write(1, "-", 1);
        nb = -nb;
    }

    // Recursively handle numbers with more than one digit
    if (nb > 9) {
        ft_putnbr(nb / 10); // Write the leading digits
    }

    // Write the last digit
    c = (nb % 10) + '0';
    write(1, &c, 1);
}

/* C0403
Write a function that converts the initial portion of the string pointed by str to its int representation
• The string can start with an arbitray amount of white space (as determined by isspace(3))
• The string can be followed by an arbitrary amount of + and - signs, - sign will change
the sign of the int returned based on the number of - is odd or even.
• Finally the string can be followed by any number of the base 10.
• Your function should read the string until the string stop following the rules and return
the number found until now.
• You should not take care of overflow or underflow. result can be undefined in that case.
• Here’s an example of a program that prints the atoi return value:
$>./a.out " ---+--+1234ab567"
-1234
*/

int ft_atoi(char *str) {
    int i = 0;
    int sign = 1;
    int result = 0;

    // Skip whitespace characters
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r') 
    {
        i++;
    }

    // Handle '+' and '-' signs
    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            sign = -sign;
        }
        i++;
    }

    // Convert digits to integer
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return sign * result;
}

/* C0404
Create a function that displays a number in a base system in the terminal.
• This number is given in the shape of an int, and the radix in the shape of a string of characters.
• The base-system contains all useable symbols to display that number :
◦ 0123456789 is the commonly used base system to represent decimal numbers
◦ 01 is a binary base system ;
◦ 0123456789ABCDEF an hexadecimal base system ;
◦ poneyvif is an octal base system.
• The function must handle negative numbers.
• If there’s an invalid argument, nothing should be displayed. Examples of invalid arguments :
◦ base is empty or size of 1;
◦ base contains the same character twice ;
◦ base contains + or - ;
*/
void ft_putchar(char c)
{
    write(1, &c, 1);
}

int is_valid_base(char *base)
{
    int i, j;

    for (i = 0; base[i] != '\0'; i++)
    {
        if (base[i] == '+' || base[i] == '-')
            return 0;
        for (j = i + 1; base[j] != '\0'; j++)
        {
            if (base[i] == base[j])
                return 0;
        }
    }
    return (i > 1);
}

void ft_putnbr_base(int nbr, char *base)
{
    int base_len;

    if (!is_valid_base(base))
        return;

    base_len = 0;
    while (base[base_len] != '\0')
        base_len++;

    if (nbr == -2147483648) // Handle INT_MIN separately
    {
        ft_putchar('-');
        ft_putnbr_base(-(nbr / base_len), base);
        ft_putchar(base[-(nbr % base_len)]);
        return;
    }

    if (nbr < 0)
    {
        ft_putchar('-');
        nbr = -nbr;
    }

    if (nbr >= base_len)
    {
        ft_putnbr_base(nbr / base_len, base);
    }
    ft_putchar(base[nbr % base_len]);
}

/* C0405
Write a function that converts the initial portion of the string pointed by str to int representation.
• str is in a specific base given as a second parameter.
• excepted the base rule, the function should work exactly like ft_atoi.
• If there’s an invalid argument, the function should return 0. Examples of invalid arguments :
◦ base is empty or size of 1;
◦ base contains the same character twice ;
◦ base contains + or - or whitespaces;
*/
int is_valid_base(char *base) {
    int i, j;

    // Base should have at least 2 characters
    if (!base || !base[0] || !base[1])
        return (0);

    // Check for invalid characters and duplicates
    for (i = 0; base[i]; i++) {
        if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
            return (0);
        for (j = i + 1; base[j]; j++) {
            if (base[i] == base[j])
                return (0);
        }
    }
    return (1);
}
