#include <stdio.h>
#include <string.h>

int main()
{
    char choice;

    printf("3DES in CBC Mode\n");
    printf("-----------------\n");

    printf("\nFor SECURITY:\n");
    printf("3DES provides stronger security than DES.\n");

    printf("\nFor PERFORMANCE:\n");
    printf("3DES is slower because encryption is performed three times.\n");

    printf("\nWhich factor is important?\n");
    printf("Enter S for Security or P for Performance: ");
    scanf(" %c", &choice);

    if (choice == 'S' || choice == 's')
    {
        printf("\nChoice: 3DES\n");
        printf("Reason: Better security than single DES.\n");
    }
    else if (choice == 'P' || choice == 'p')
    {
        printf("\nChoice: Faster algorithm\n");
        printf("Reason: 3DES requires three DES operations.\n");
    }
    else
    {
        printf("\nInvalid choice.\n");
    }

    return 0;
}
