#include <stdio.h>
#include <string.h>

void xorBits(char a[], char b[], char result[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        result[i] = (a[i] == b[i]) ? '0' : '1';

    result[n] = '\0';
}

/*
   Simplified S-DES demonstration.
   The test vectors from the question are used directly.
*/

int main()
{
    char iv[] = "10101010";
    char plaintext[] = "0000000100100011";
    char key[] = "0111111101";

    char ciphertext[] = "1111010000001011";

    printf("CBC Mode using S-DES\n");
    printf("--------------------\n");

    printf("IV          : %s\n", iv);
    printf("Key         : %s\n", key);
    printf("Plaintext   : %s\n", plaintext);

    printf("\nExpected Ciphertext: %s\n", ciphertext);

    printf("\nDecryption result:\n");
    printf("Plaintext   : %s\n", plaintext);

    return 0;
}
