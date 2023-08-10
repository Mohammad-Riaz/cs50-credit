#include <cs50.h>
#include <stdio.h>

long numDigits(long n);
long getFirst2Digits(long input);

int main(void)
{
    long sum;
    long num = 0;
    long checkSum = 0;
    long i = 100;
    long j = 10;
    bool valid = false;

    do
    num = get_long("Number: ");
    while (num < 0);


    while ((num * 10) > i)
    {
        sum = (num % i / j) * 2;
        i *= 100;
        j *= 100;

        if (sum > 9)
            checkSum += (1 + (sum % 10));
        else
            checkSum += sum;
    }

    i = 10;
    j = 1;

    while((num*10) > i)
    {
        sum = (num % i / j);
        i *= 100;
        j *= 100;
        checkSum += sum;
    }

    if (checkSum % 10 == 0)
        valid = true;


    if (valid && (numDigits(num) == 15  && (getFirst2Digits(num) == 34 || getFirst2Digits(num) == 37)))
        printf("AMEX\n");
    else if (valid && (numDigits(num) == 16 && (getFirst2Digits(num) > 50 && getFirst2Digits(num) < 56)))
        printf("MASTERCARD\n");
    else if (valid && ((numDigits(num) == 16 || numDigits(num) == 13) && (getFirst2Digits(num) > 39 && getFirst2Digits(num) < 50 )))
        printf("VISA\n");
    else
        printf("INVALID\n");
}

long numDigits(long n)
{
    if (n < 10) return 1;
    return 1 + numDigits(n / 10);
}

long getFirst2Digits(long input)
{
    long local = input;

    while (local >= 100)
    {
        local /= 10;
    }

    return local;
}

