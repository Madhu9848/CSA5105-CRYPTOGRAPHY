#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
    char plaintext[200];
    char text[200];
    char cipher[200];

    int key[2][2] = {
        {9, 4},
        {5, 7}
    };

    int determinant;
    int inverseDet;
    int invKey[2][2];

    int i, j, len;
    int x1, x2;
    int y1, y2;

    printf("Enter plaintext:\n");
    fgets(plaintext, sizeof(plaintext), stdin);

    /* Remove spaces and keep alphabets */
    len = 0;

    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (isalpha(plaintext[i]))
        {
            text[len++] = tolower(plaintext[i]);
        }
    }

    /* Add x if length is odd */
    if (len % 2 != 0)
        text[len++] = 'x';

    text[len] = '\0';

    /* Encryption */
    for (i = 0; i < len; i += 2)
    {
        x1 = text[i] - 'a';
        x2 = text[i + 1] - 'a';

        y1 = mod26(key[0][0] * x1 + key[0][1] * x2);
        y2 = mod26(key[1][0] * x1 + key[1][1] * x2);

        cipher[i] = y1 + 'a';
        cipher[i + 1] = y2 + 'a';
    }

    cipher[len] = '\0';

    printf("\nCiphertext: %s\n", cipher);

    /* Calculate determinant */
    determinant = key[0][0] * key[1][1]
                - key[0][1] * key[1][0];

    determinant = mod26(determinant);

    inverseDet = inverseMod26(determinant);

    if (inverseDet == -1)
    {
        printf("Inverse does not exist.\n");
        return 0;
    }

    /* Inverse matrix */
    invKey[0][0] = mod26(inverseDet * key[1][1]);
    invKey[0][1] = mod26(-inverseDet * key[0][1]);
    invKey[1][0] = mod26(-inverseDet * key[1][0]);
    invKey[1][1] = mod26(inverseDet * key[0][0]);

    printf("\nInverse Key Matrix:\n");
    printf("%d %d\n", invKey[0][0], invKey[0][1]);
    printf("%d %d\n", invKey[1][0], invKey[1][1]);

    /* Decryption */
    printf("\nDecrypted text: ");

    for (i = 0; i < len; i += 2)
    {
        x1 = cipher[i] - 'a';
        x2 = cipher[i + 1] - 'a';

        y1 = mod26(invKey[0][0] * x1 +
                   invKey[0][1] * x2);

        y2 = mod26(invKey[1][0] * x1 +
                   invKey[1][1] * x2);

        printf("%c%c", y1 + 'a', y2 + 'a');
    }

    printf("\n");

    return 0;
}
