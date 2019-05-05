#include <stdio.h>
#include <cs50.h>
#include <string.h>

int mint(char e);

int main(void)
{
    //make the notmultdigits array to hold the notmultdigits
    int notmultdigits[8];

    //clear notmultdigits of garbage values
    for(int i = 0; i < 8; i++)
    {
        notmultdigits[i] = 0;
    }

    //get the card number as a string
    string cardchars = get_string("Enter credit card number to see if it passes a verification checksum (without hyphens or spaces):  ");

    //get the length so we don't have to keep calling the strlen function during the for loops
    int number_of_cardchars = strlen(cardchars);

    //make an array to hold the integer versions of the card chars
    int cardnums[number_of_cardchars];

    //store the result of number_of_cardchars * 2 so it doesn't need to be repeatedly called
    int __d__ = number_of_cardchars * 2;

    //make the multdigits array for the multiplied by 2 digits
    //in the worst possible scenario, all the digits when multiplied by two would be greater than 10 and we need to store the digits (not the numbers themselves)
    int multdigits[__d__];

    //make each int in the multdigits array 0 so no garbage values
    for(int i = 0; i < __d__; i++)
    {
        multdigits[i] = 0;
    }

    //copy the chars into ints and put it into the cardnums array
    for(int i = 0; i < number_of_cardchars; i++)
    {
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
    else if(number_of_cardchars == 16)
    {
        result = "MASTERCARD";
    }
    else
    {
        result = "Checksum passed, but credit card brand not recognized";
    }

    //multiplying the even numbers by two and storing their digits in the multdigits array
    //if the number has more than one digit, it's first digit is put into the i location in multdigits, then its second digit is put into the next spot.
    for(int i = number_of_cardchars - 2, j = 0; i >= 0; i -= 2 , j++)
    {
        int q = cardnums[i] * 2;
        //printf("%i\n",q);
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

    //testing
    for(int i = 0; i < 15; i++)
    {
        //printf("%i\n", multdigits[i]);
    }

    //putting the other numbers into the notmultdigits array
    for(int i = number_of_cardchars - 1, j = 0; i >= 0; i -= 2 , j++)
    {
        notmultdigits[j] = cardnums[i];
        //printf("%i\n", notmultdigits[j]);
    }

    //calculating the sum of the multdigits and the notmuldigits then checking if the modulus 10 is 0
    //if so, then print the result
    //if not then print INVALID
    int sum = 0;

    for(int i = 0; i < __d__; i++)
    {
        sum += multdigits[i];
    }

    for(int i = 0; i < 8; i++)
    {
        sum += notmultdigits[i];
    }
    //printf("%i\n",sum);


    if(sum % 10 == 0)
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