#include <stdio.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main()
{
    int n = 3599;
    int e = 31;

    int p = 0, q = 0;
    int phi;
    int d;

    /* Find p and q */
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            p = i;
            q = n / i;
            break;
        }
    }

    printf("p = %d\n", p);
    printf("q = %d\n", q);

    phi = (p - 1) * (q - 1);

    printf("Phi(n) = %d\n", phi);

    /* Find d */
    for (d = 1; d < phi; d++)
    {
        if ((e * d) % phi == 1)
            break;
    }

    printf("Public key  = (%d, %d)\n", e, n);
    printf("Private key = (%d, %d)\n", d, n);

    return 0;
}
