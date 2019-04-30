#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);
void mario(int n);

int main(void)
{
    int p = get_positive_int();
    mario(p);
}

int get_positive_int(void)
{
    int a = get_int("Height: ");
    if(a < 1)
    {
        get_positive_int();
    }
    return a;
}

void mario(int n)
{
    int v = n;
    for(int j = 0; j <= n; j++)
    {
        for(int i = 0; i < v; i++)
        {
            printf(" ");
        }
        for(int k = 0; k < j; k++)
        {
            printf("#");
        }
        printf("  ");
        for(int k = 0; k < j; k++)
        {
            printf("#");
        }
        printf("\n");
        v--;
    }
    }

