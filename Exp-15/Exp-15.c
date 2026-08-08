#include <stdio.h>
#include <string.h>
#include <ctype.h>

void decrypt(char cipher[], int shift)
{
    int i;

    for (i = 0; cipher[i] != '\0'; i++)
    {
        if (isalpha(cipher[i]))
        {
            char c = tolower(cipher[i]);

            c = ((c - 'a' - shift + 26) % 26) + 'a';

            printf("%c", c);
        }
        else
        {
            printf("%c", cipher[i]);
        }
    }

    printf("\n");
}

int main()
{
    char cipher[500];
    int frequency[26] = {0};

    int i, maxIndex = 0;
    int top;

    printf("Enter ciphertext:\n");
    fgets(cipher, sizeof(cipher), stdin);

    /* Frequency calculation */
    for (i = 0; cipher[i] != '\0'; i++)
    {
        if (isalpha(cipher[i]))
        {
            int index = tolower(cipher[i]) - 'a';
            frequency[index]++;
        }
    }

    for (i = 1; i < 26; i++)
    {
        if (frequency[i] > frequency[maxIndex])
            maxIndex = i;
    }

    /*
       Assume most frequent ciphertext letter
       corresponds approximately to E.
    */

    int estimatedShift = (maxIndex - ('e' - 'a') + 26) % 26;

    printf("\nMost frequent letter: %c\n",
           maxIndex + 'a');

    printf("Estimated shift: %d\n", estimatedShift);

    printf("\nTop 10 possible plaintexts:\n");

    for (top = 0; top < 10; top++)
    {
        int shift = (estimatedShift + top) % 26;

        printf("\n%d. ", top + 1);

        decrypt(cipher, shift);
    }

    return 0;
}
