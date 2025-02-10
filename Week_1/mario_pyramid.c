#include <cs50.h>
#include <stdio.h>

void print_bricks(int rows);
void print_spaces(int space);

int main(void)
{
    int rows;
    do
    {
        rows = get_int("How many rows? ");
    } while (rows < 1); // prevent nonsense

    printf("\n");
    for (int n = 0; n < rows; n++)
    {
        print_spaces(rows - (n + 1));
        print_bricks(n + 1);
        printf("  ");
        print_bricks(n + 1);
        printf("\n");
    }
    printf("\n");
}

void print_bricks(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        printf("#");
    }
}

void print_spaces(int space)
{
    for (int j = 0; j < space; j++)
    {
        printf(" ");
    }
}
