#include <stdio.h>
#include <string.h>
#include <ctype.h>

char englishFreq[] = "etaoinshrdlucmfwypvbgkjqxz";

void analyze(char cipher[])
{
    int freq[26] = {0};
    int i, j;

    for (i = 0; cipher[i] != '\0'; i++)
    {
        if (isalpha(cipher[i]))
        {
            freq[tolower(cipher[i]) - 'a']++;
        }
    }

    printf("\nLetter frequencies:\n");

    for (i = 0; i < 26; i++)
    {
        printf("%c : %d\n", 'a' + i, freq[i]);
    }

    printf("\nPossible plaintext using frequency mapping:\n");

    for (i = 0; cipher[i] != '\0'; i++)
    {
        if (isalpha(cipher[i]))
        {
            int c = tolower(cipher[i]) - 'a';

            int rank = 0;

            for (j = 0; j < 26; j++)
            {
                if (freq[j] > freq[c])
                    rank++;
            }

            if (rank < 26)
                printf("%c", englishFreq[rank]);
            else
                printf("%c", cipher[i]);
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
    char cipher[1000];

    printf("Enter ciphertext:\n");
    fgets(cipher, sizeof(cipher), stdin);

    analyze(cipher);

    return 0;
}
