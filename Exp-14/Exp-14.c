#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char plaintext[100];
    int key[100];
    char ciphertext[100];

    int i, len = 0;

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter key values:\n");

    /* Read key values */
    for (i = 0; i < 13; i++)
        scanf("%d", &key[i]);

    /* Encrypt */
    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (isalpha(plaintext[i]))
        {
            int p = tolower(plaintext[i]) - 'a';

            ciphertext[len] =
                ((p + key[len]) % 26) + 'a';

            len++;
        }
    }

    ciphertext[len] = '\0';

    printf("\nCiphertext: %s\n", ciphertext);

    return 0;
}
