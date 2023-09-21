#include <stdio.h>

int main ()
{
    int nbr = 0;
    scanf("%d", &nbr);
    int length = 0;
    int temp = nbr;
    while (temp / 10 != 0)
    {
        temp /= 10;
        length++;
    }
    length++;
    while (length--)
    {
        printf("%d", nbr % 10);
        nbr /= 10;
    }
    return 0;
}