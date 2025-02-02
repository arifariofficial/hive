#include <unistd.h>

void	print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	input_validation(char *input)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] >= '1' && input[i] <= '4')
		{
			count++;
		}
		else if (input[i] != ' ')
		{
			return (0);
		}	
		i++;
	}
	return (count == 16 && i <= 31);
}

void	parse_input(char *src, int *dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] >= '1' && src[i] <= '4')
		{
			dest[j] = src[i] - '0';
			j++;
		}
		i++;
	}
}

void	grid_initialization(int **grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_grid(int **grid)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
