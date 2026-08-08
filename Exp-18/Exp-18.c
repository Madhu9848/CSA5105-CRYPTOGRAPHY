#include <stdio.h>

int main()
{
    int C[28], D[28];
    int subkey[48];

    int i;

    printf("Enter 28 bits for C:\n");

    for (i = 0; i < 28; i++)
        scanf("%d", &C[i]);

    printf("Enter 28 bits for D:\n");

    for (i = 0; i < 28; i++)
        scanf("%d", &D[i]);

    /*
       Simplified demonstration:
       Take 24 bits from C and 24 bits from D.
    */

    for (i = 0; i < 24; i++)
        subkey[i] = C[i];

    for (i = 0; i < 24; i++)
        subkey[24 + i] = D[i];

    printf("\n48-bit Subkey:\n");

    for (i = 0; i < 48; i++)
        printf("%d", subkey[i]);

    printf("\n");

    return 0;
}
