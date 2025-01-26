int count_visible_from_left(int *row) 
{
    int max_height = 0;
    int visible_count = 0;
    int i = 0;

    while (i < 4) {
        if (row[i] > max_height) {
            max_height = row[i];
            visible_count++;
        }
        i++;
    }
    return visible_count;
}

int count_visible_from_right(int *row) 
{
    int max_height = 0;
    int visible_count = 0;
    int i = 3; // Start from the rightmost element

    while (i >= 0) {
        if (row[i] > max_height) {
            max_height = row[i];
            visible_count++;
        }
        i--;
    }
    return visible_count;
}

int count_visible_from_top(int **grid, int col) 
{
    int max_height = 0;
    int visible_count = 0;
    int i = 0;

    while (i < 4) {
        if (grid[i][col] > max_height) {
            max_height = grid[i][col];
            visible_count++;
        }
        i++;
    }
    return visible_count;
}

int count_visible_from_bottom(int **grid, int col) 
{
    int max_height = 0;
    int visible_count = 0;
    int i = 3; // Start from the bottommost row

    while (i >= 0) {
        if (grid[i][col] > max_height) {
            max_height = grid[i][col];
            visible_count++;
        }
        i--;
    }
    return visible_count;
}