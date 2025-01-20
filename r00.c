#include <unistd.h>

void	ft_putchar(char c);
void	rush(int x, int y);
void	write_row(char *row, int length);
int	digit_converter(char *input);
int	input_check(char *input);

int	main(int params, char **input)
{
	int	x;
	int	y;

	if (params == 3)
	{
		if (input_check(input[1]) && input_check(input[2]))
		{
			x = digit_converter(input[1]);
			y = digit_converter(input[2]);
			rush(x, y);
		}
		else
		{
			rush(42, 42);
		}
	}
	else
	{
		rush(42, 42);
	}	
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rush(int x, int y)
{
	int		i;

	if (x <= -1)
		x = -x;
	if (y <= -1)
		y = -y;
	if (x == 0 || y == 0)
	{
		write_row("0", 1);
		return ;
	}
	write_row("/*\\", x);
	i = 0;
	while (i < y - 2)
	{
		write_row("* *", x);
		i++;
	}
	if (y > 1)
	{
		write_row("\\*/", x);
	}
}

void	write_row(char *row, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (i == 0)
		{
			ft_putchar(row[0]);
		}
		else if (i < length -1)
		{
			ft_putchar(row[1]);
		}
		else
		{
			ft_putchar(row[2]);
		}
		i++;
	}
	ft_putchar('\n');
}

int	digit_converter(char *input)
{
	int	counter;
	int	return_value;
	int	tens;

	counter = 0;
	return_value = 0;
	tens = 1;
	while (*input != '\0')
	{
		counter++;
		input++;
	}
	while (counter > 0)
	{
		input--;
		return_value += (*input - '0') * tens;
		tens = tens * 10;
		counter--;
	}
	return (return_value);
}

int	input_check(char *input)
{
	int		counter;
	char	c;

	counter = 0;
	while (input[counter] != '\0')
	{
		c = input[counter];
		if (counter == 0)
		{
			if (!((c >= '0' && c <= '9') || c == '-'))
				return (0);
		}
		else
		{
			if (!(c >= '0' && c <= '9'))
				return (0);
		}
		counter++;
	}
	return (1);
}