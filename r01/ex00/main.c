#include <stdlib.h>

void	print(char *str);
int		input_validation(char *input);
void	parse_input(char *src, int *dest);
void	grid_initialization(int **grid);
void	print_grid(int **grid);
int		check_visibility(int **grid, int *constraints);
int		solve_puzzle(int **grid, int *constraints, int row, int col);
int		**allocate_grid(int **input_arr_int);
void	free_resources(int **grid, int *input_arr_int);

int	main(int argc, char **argv)
{
	int	*input_arr_int;
	int	**grid;

	if (argc != 2 || !input_validation(argv[1]))
		return (print("Error"), 1);
	input_arr_int = malloc(16 * 4);
	grid = allocate_grid(&input_arr_int);
	if (!grid)
		return (print("Error"), 1);
	parse_input(argv[1], input_arr_int);
	grid_initialization(grid);
	if (solve_puzzle(grid, input_arr_int, 0, 0))
		print_grid(grid);
	else
		print("Error");
	free_resources(grid, input_arr_int);
	return (0);
}

int	**allocate_grid(int **input_arr_int)
{
	int	**grid;
	int	i;

	grid = malloc(4 * 8);
	i = 0;
	while (i < 4)
	{
		grid[i] = malloc(4 * 4);
		if (!grid[i])
		{
			print("Error");
			while (--i >= 0)
				free(grid[i]);
			free(grid);
			free(*input_arr_int);
			return (0);
		}
		i++;
	}
	return (grid);
}

void	free_resources(int **grid, int *input_arr_int)
{
	int	i;

	free(input_arr_int);
	i = 0;
	while (i < 4)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

// 4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2
// 3 2 1 3 2 3 2 1 3 2 1 3 2 3 2 1
// 4 2 2 1 1 2 2 3 4 2 2 1 1 2 2 4
// 3 2 2 1 2 3 1 2 3 2 1 3 1 3 3 2
// 2 2 3 1 3 1 2 2 3 1 2 2 1 3 2 2