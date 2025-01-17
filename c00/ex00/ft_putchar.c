#include <unistd.h>

void	ft_putchar(char c);

int main()
{
	char	my_char;

	my_char = 'a';
	ft_putchar(my_char);
	return 0;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
