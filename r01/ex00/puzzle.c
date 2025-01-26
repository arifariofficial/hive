
#include <stdio.h>

int count_visible_from_left(int *row);
int count_visible_from_right(int *row);
int count_visible_from_top(int **grid, int col);
int count_visible_from_bottom(int **grid, int col);

int valid_position(int **grid, int row, int col, int num)
{
    int i;

    i = 0;
    while (i < 4)
    {
        // Check for duplicate in the row
        if (grid[row][i] == num)
            return 0;

        // Check for duplicate in the column
        if (grid[i][col] == num)
            return 0;

        i++;
    }
    return 1;
}

int check_visibility(int **grid, int *inputs) {
    int i = 0;

    // Check rows (left and right visibility)
    while (i < 4) {
        if (count_visible_from_left(grid[i]) != inputs[8 + i])
            return 0; // Left visibility for row i doesn't match
        if (count_visible_from_right(grid[i]) != inputs[12 + i])
            return 0; // Right visibility for row i doesn't match
        i++;
    }

    // Check columns (top and bottom visibility)
    i = 0;
    while (i < 4) {
        if (count_visible_from_top(grid, i) != inputs[i])
            return 0; // Top visibility for column i doesn't match
        if (count_visible_from_bottom(grid, i) != inputs[4 + i])
            return 0; // Bottom visibility for column i doesn't match
        i++;
    }

    return 1; // All inputs satisfied
}

int solve_puzzle(int **grid, int *inputs, int row, int col) 
{
    if (row == 4) 
        return check_visibility(grid, inputs);

    int next_row = (col == 3) ? row + 1 : row;
    int next_col = (col == 3) ? 0 : col + 1;

    int num = 1;
    while (num <= 4) {
        if (valid_position(grid, row, col, num)) {
            grid[row][col] = num;

            if (solve_puzzle(grid, inputs, next_row, next_col))
                return 1;

            grid[row][col] = 0; // Backtrack
        }
        num++;
    }
    return 0; // No solution
}