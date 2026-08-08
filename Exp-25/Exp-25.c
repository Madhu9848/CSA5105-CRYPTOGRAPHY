#include <stdio.h>

int gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main()
{
    long long n, plaintext;

    printf("Enter RSA modulus n: ");
    scanf("%lld", &n);

    printf("Enter plaintext block: ");
    scanf("%lld", &plaintext);

    long long g = gcd(plaintext, n);

    printf("\nGCD(plaintext, n) = %lld\n", g);

    if (g > 1 && g < n)
    {
        printf("A common factor exists.\n");
        printf("This can help factor n and break RSA.\n");
    }
    else
    {
        printf("No non-trivial common factor found.\n");
    }

    return 0;
}
