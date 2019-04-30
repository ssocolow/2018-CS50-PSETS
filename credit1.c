#include <stdio.h>
#include <cs50.h>
#include <string.h>

int mint(char e);

int main(void)
{
    //make arrays to hold the digits
    int cardnums[16];
    int multdigits[16];
    int notmultdigits[8];

    //get the card number
    string cardchars = get_string("Number:  ");

    //get the length so we don't have to keep calling the strlen function during the for loop
    int number_of_cardchars = strlen(cardchars);
    for(int i = 0; i < number_of_cardchars; i++)
    {
        //copy the chars into ints and put it into an array
        cardnums[i] = mint(cardchars[i]);
    }

    //getting which kind of credit card it is
    string result;
    if(number_of_cardchars == 15)
    {
        result = "AMEX";
    }
    else if(number_of_cardchars == 13)
    {
        result = "VISA";
    }
    else if(number_of_cardchars == 16 && cardnums[0] == 4)
    {
        result = "VISA";
    }
    else
    {
        result = "MASTERCARD";
    }

    //multiplying the even numbers by two and storing their digits in the multdigits array
    //if the number has more than one digit, it's first digit is put into the i location in multdigits, then its second digit is put into the next spot.
    for(int j = 0; int i = 0; i < number_of_cardchars; i += 2 && j++)
    {
        int q = cardnums[i] * 2;
            if(q == 10)
            {
                multdigits[j] = 1;
                multdigits[j+1] = 0;
                j++;
            }
            else if(q == 11)
            {
                multdigits[j] = 1;
                multdigits[j+1] = 1;
                j++;
            }
            else if(q == 12)
            {
                multdigits[j] = 1;
                multdigits[j+1] = 2;
                j++;
            }
            else if(q == 13)
            {
                multdigits[j] = 1;
                multdigits[j+1] = 3;
                j++;
            }
            else if(q == 14)
            {
                multdigits[j] = 1;
                multdigits[j+1] = 4;
                j++;
            }
            else if(q == 15)
            {
                multdigits[j] = 1;
                multdigits[j+1] = 5;
                j++;
            }
            else if(q == 16)
            {
                multdigits[j] = 1;
                multdigits[j+1] = 6;
                j++;
            }
            else if(q == 17)
            {
                multdigits[j] = 1;
                multdigits[j+1] = 7;
                j++;
            }
            else if(q == 18)
            {
                multdigits[j] = 1;
                multdigits[j+1] = 8;
                j++;
            }
            else
            {
                multdigits[j] = q;
            }
    }

    //putting the other numbers into the notmultdigits array
    for(int i = 1; i <= number_of_cardchars; i += 2)
    {
        notmultdigits[i/2] = cardnums[i];
    }

    //calculating the sum of the multdigits and the notmuldigits then checking if the modulus 10 is 0
    //if so, then print the result
    //if not then print INVALID
    int sum;
    for(int i = 0; i < 15; i++)
    {
        sum += multdigits[i];
    }
    for(int i = 0; i < 7; i++)
    {
        sum += notmultdigits[i];
    }

    if(sum % 10 = 0)
    {
        printf("%s\n", result);
    }
    else
    {
        printf("INVALID\n");
    }
}

//the function for making a char (character) into an int if it is a decimal digit
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