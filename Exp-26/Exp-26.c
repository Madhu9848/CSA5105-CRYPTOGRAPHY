#include <stdio.h>

int gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long t = b;
        b = a % b;
        a = t;
    }

    return a;
}

int main()
{
    long long p, q;
    long long oldE, oldD;
    long long newE, newD;
    long long phi;

    printf("Enter p: ");
    scanf("%lld", &p);

    printf("Enter q: ");
    scanf("%lld", &q);

    printf("Enter old public key e: ");
    scanf("%lld", &oldE);

    printf("Enter old private key d: ");
    scanf("%lld", &oldD);

    phi = (p - 1) * (q - 1);

    printf("\nOld key pair is compromised.\n");

    printf("Enter new public exponent e: ");
    scanf("%lld", &newE);

    if (gcd(newE, phi) != 1)
    {
        printf("Invalid new public exponent.\n");
        return 0;
    }

    for (newD = 1; newD < phi; newD++)
    {
        if ((newE * newD) % phi == 1)
            break;
    }

    printf("\nNew public key : (%lld, %lld)\n",
           newE, p * q);

    printf("New private key: (%lld, %lld)\n",
           newD, p * q);

    printf("\nSecurity warning:\n");
    printf("Reusing the same modulus is not considered safe.\n");
    printf("A new RSA modulus should be generated.\n");

    return 0;
}
