#include <stdio.h>

int main()
{
    int K[17][48];
    int i, j;

    /* Example: assume 16 generated DES subkeys */

    printf("Enter 16 DES subkeys.\n");

    for (i = 1; i <= 16; i++)
    {
        printf("Enter K%d (48 bits as 0/1):\n", i);

        for (j = 0; j < 48; j++)
            scanf("%d", &K[i][j]);
    }

    printf("\nDES Decryption Key Schedule:\n");

    /* DES decryption uses keys in reverse order */

    for (i = 16; i >= 1; i--)
    {
        printf("Round %d uses K%d: ", 17 - i, i);

        for (j = 0; j < 48; j++)
            printf("%d", K[i][j]);

        printf("\n");
    }

    return 0;
}
