int	count_visible_from_left(int *row);
int	count_visible_from_right(int *row);
int	count_visible_from_top(int **grid, int col);
int	count_visible_from_bottom(int **grid, int col);

int	valid_position(int **grid, int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num)
			return (0);
		if (grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_visibility(int **grid, int *inputs)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (count_visible_from_left(grid[i]) != inputs[8 + i])
			return (0);
		if (count_visible_from_right(grid[i]) != inputs[12 + i])
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (count_visible_from_top(grid, i) != inputs[i])
			return (0);
		if (count_visible_from_bottom(grid, i) != inputs[4 + i])
			return (0);
		i++;
	}
	return (1);
}

void	set_next_row_col(int *next_row, int *next_col, int *row, int *col)
{
	if (*col == 3)
	{
		*next_row = *row + 1;
		*next_col = 0;
	}
	else
	{
		*next_row = *row;
		*next_col = *col + 1;
	}
}

int	solve_puzzle(int **grid, int *inputs, int row, int col)
{
	int	next_row;
	int	next_col;
	int	num;

	if (row == 4)
	{
		return (check_visibility(grid, inputs));
	}
	set_next_row_col(&next_row, &next_col, &row, &col);
	num = 1;
	while (num <= 4)
	{
		if (valid_position(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve_puzzle(grid, inputs, next_row, next_col))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
