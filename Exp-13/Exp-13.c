#include <stdio.h>

int mod26(int x)
{
    x = x % 26;

    if (x < 0)
        x += 26;

    return x;
}

int inverseMod26(int a)
{
    int i;

    for (i = 1; i < 26; i++)
    {
        if ((a * i) % 26 == 1)
            return i;
    }

    return -1;
}

int main()
{
    int P[2][2];
    int C[2][2];

    int det, invDet;
    int invP[2][2];
    int K[2][2];

    int i, j, k;
    int sum;

    printf("Enter plaintext matrix P (2x2):\n");

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &P[i][j]);

    printf("Enter ciphertext matrix C (2x2):\n");

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &C[i][j]);

    /* Determinant */
    det = mod26(P[0][0] * P[1][1]
              - P[0][1] * P[1][0]);

    invDet = inverseMod26(det);

    if (invDet == -1)
    {
        printf("Plaintext matrix has no inverse modulo 26.\n");
        return 0;
    }

    /* Inverse of P */
    invP[0][0] = mod26(invDet * P[1][1]);
    invP[0][1] = mod26(-invDet * P[0][1]);
    invP[1][0] = mod26(-invDet * P[1][0]);
    invP[1][1] = mod26(invDet * P[0][0]);

    /* K = C * P^-1 */

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            sum = 0;

            for (k = 0; k < 2; k++)
                sum += C[i][k] * invP[k][j];

            K[i][j] = mod26(sum);
        }
    }

    printf("\nRecovered Hill Cipher Key:\n");

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            printf("%d ", K[i][j]);

        printf("\n");
    }

    return 0;
}
