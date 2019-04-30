#include <cs50.h>
#include <stdio.h>
#include <unistd.h>

int mint(char e);

int main(void)
{
    int num[16];
    string cardnum = get_string("Number: ");
    int d = sizeof(cardnum) / 4;
    printf("%i\n", d);
    for(int i = 0; i < d; i++)
    {
        num[i] = mint(cardnum[i]);
    }
    printf("%s\n", cardnum);
    printf("%i\n", num[0]);
}

int mint(char e)
{
    int ret;
    if(e == '0')
    {
        ret = 0;
        return ret;
    }
    if(e == '1')
    {
        ret = 1;
        return ret;
    }
    if(e == '2')
    {
        ret = 2;
        return ret;
    }
    if(e == '3')
    {
        ret = 3;
        return ret;
    }
    if(e == '4')
    {
        ret = 4;
        return ret;
    }
    if(e == '5')
    {
        ret = 5;
        return ret;
    }
    if(e == '6')
    {
        ret = 6;
        return ret;
    }
    if(e == '7')
    {
        ret = 7;
        return ret;
    }
    if(e == '8')
    {
        ret = 8;
        return ret;
    }
    if(e == '9')
    {
        ret = 9;
        return ret;
    }
    else
    {
        printf("One of the chars was not a decimal character\n");
    }
    return 1;
}

