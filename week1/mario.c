#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int space = height - i - 1; space > 0; space--)
        {
            printf(" ");
        }
        for (int j = height - i - 1; j < height; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = height - i - 1; j < height; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
