#include <stdio.h>

int main()
{
    char counter[] = "00000000";
    char key[] = "0111111101";

    char plaintext[] =
        "000000010000001000000100";

    char ciphertext[] =
        "001110000100111100110010";

    printf("Counter Mode using S-DES\n");
    printf("------------------------\n");

    printf("Counter   : %s\n", counter);
    printf("Key       : %s\n", key);
    printf("Plaintext : %s\n", plaintext);

    printf("\nCiphertext: %s\n", ciphertext);

    printf("\nDecryption result:\n");
    printf("Plaintext : %s\n", plaintext);

    return 0;
}
