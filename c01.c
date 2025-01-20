/* C0108 Create a function which sorts an array of integers by ascending order.
The arguments are a pointer to int and the number of ints in the array */

#include <stdio.h>

void	ft_swap(int *a, int *b);
void	ft_sort_int_tab(int *tab, int size);

int main()
{
	int size = 6;
	int tab[] = {4, 98, 34, 31, 9, 33};

	ft_sort_int_tab(tab, size);
	for ( int i = 0; i < size; i++ )
	{
		printf("%d", tab[i]);
	}
	return 0;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int swapped;

	while (1)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[ i + 1]);
				swapped = 1;
			}
			i++;
		}
		if (!swapped)
			break;
	}
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}