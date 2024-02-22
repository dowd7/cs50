#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);
    // TODO: Calculate number of years until we reach threshold

    int year = 0;
    int population = start;
    while (true)
    {
        if (population >= end)
        {
            break;
        }
        population = population + population / 3 - population / 4;
        year++;
        if (population >= end)
        {
            break;
        }
    }

    // TODO: Print number of years
    printf("Years: %i\n", year);
}
