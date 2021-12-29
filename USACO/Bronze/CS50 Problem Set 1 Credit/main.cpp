#include <stdio.h>

int card_number[100], card_type = -1;

void input() {
    long long c, tmp;
    scanf("%lld", &c);
    //printf("%ld\n", c);
    tmp = c;
    if (5 <= c / 1000000000000000 && c / 1000000000000000 < 6) {
        card_type = 0;
    } else if (4 <= c / 1000000000000000 && c / 1000000000000000 < 5) {
        card_type = 1;
    } else if (4 <= c / 1000000000000 && c / 1000000000000 < 5) {
        card_type = 1;
    } else if (3 <= c / 100000000000000 && c / 100000000000000 < 4) {
        if (34 <= c / 10000000000000 && c / 10000000000000 < 35)
        {
            card_type = 2;
        }
        if (37 <= c / 10000000000000 && c / 10000000000000 < 38)
        {
            card_type = 2;
        }
    }
    for (int i = 0; i < 16; i++) {
        card_number[i] = c % 10;
        //printf("%d ", card_number[i]);
        c /= 10;
    }
}

bool verification()
{
    int cnt = 0;
    for (int i = 0; i < 16; i++)
    {
        if (i % 2 == 1)
        {
            if (card_number[i] * 2 > 9)
            {
                cnt += card_number[i] * 2 % 10;
                cnt += (card_number[i] * 2 / 10) % 10;
            }
            else
            {
                cnt += card_number[i] * 2;
            }
        }
    }
    for (int i = 0; i < 16; i++)
    {
        if (i % 2 == 0) {
            cnt += card_number[i];
        }
    }
    if (cnt % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    input();
    if (card_type == 0 && verification())
    {
        printf("MASTERCARD\n");
    }
    else if (card_type == 1 && verification())
    {
        printf("VISA\n");
    }
    else if (card_type == 2 && verification())
    {
        printf("AMEX\n");
    }
    else {
        printf("INVALID\n");
    }
}