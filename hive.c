// C00-05 Print unique 3 digits combination
void ft_print_comb(void)
{
    int	a;
	int	b;
	int	c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{	
				write(1, &a, 1);
				write(1, &b, 1);
				write(1, &c, 1);
				if (a != '7' || b != '8' || c != '9')
					write(1, ", ", 2);
				c++;
			}
			b++;
		}
		a++;
	}
}
// C01-07 Reverse a an integer array
void ft_rev_int_tab(int *tab, int size)
{
    int i = 0;
    int temp;
    while (i < size / 2 )
    {
        temp = tab[i];
        tab[i] = tab[size - 1 - i];
        tab[size -1 - i] = temp;
        i++;
    } 
}

// C01-08 Sort the array
void ft_rev_int_tab(int *tab, int size)
{
    int i;
    int swapped;
    int temp;
    while (1)
    {
        i = 0;
        swapped = 0;
        while (i < size - 1 )
        {
            if (tab[i] > tab[i + 1])
            {
                temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
                swapped = 1;
            }
            i++;
        }
        if (!swapped)
            break;
    }
}

// C02-00 Reproduce the behaviour of strcpy()
char *ft_strcpy(char *dest, char *src)
{
    while (*src)
    {
        *dest = *src;
        src++;
        dest++;
    }
    return dest;
} 

// C02-01 Reproduce the behaviour of strncpy()
