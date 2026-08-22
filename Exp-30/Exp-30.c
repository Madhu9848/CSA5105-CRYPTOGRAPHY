#include <stdio.h>

long long powerMod(long long base,
                   long long exp,
                   long long mod)
{
    long long result = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

int main()
{
    long long n, e;
    char message[100];

    printf("Enter RSA n: ");
    scanf("%lld", &n);

    printf("Enter RSA e: ");
    scanf("%lld", &e);

    getchar();

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    printf("\nEncrypted values:\n");

    for (int i = 0; message[i] != '\0'; i++)
    {
        if (message[i] >= 'A' &&
            message[i] <= 'Z')
        {
            int m = message[i] - 'A';

            printf("%lld ",
                   powerMod(m, e, n));
        }
        else if (message[i] >= 'a' &&
                 message[i] <= 'z')
        {
            int m = message[i] - 'a';

            printf("%lld ",
                   powerMod(m, e, n));
        }
    }

    printf("\n");

    printf("\nThis method is insecure because the same\n");
    printf("plaintext letter always produces the same ciphertext.\n");

    return 0;
}
