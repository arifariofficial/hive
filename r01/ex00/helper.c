/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arislam <arislam@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:02:25 by arislam           #+#    #+#             */
/*   Updated: 2025/01/25 21:05:02 by arislam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		else if (input[i] == ' ' && input[i + 1] == ' ')
		{
			return (0);
		}	
		i++;
	}
	return (count == 16);
}

void parse_input(char *src, int *dest)
{
    int i = 0;    // index through the source string
    int j = 0;    // index for filling dest array

    while (src[i])
    {
        // If it's a digit between '1' and '4', store it
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
	int i;
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
	int	i;
	int	j;
	char c;

	i = 0;
	while(i < 4)
	{
		j = 0;
		while( j < 4)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j !=3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
