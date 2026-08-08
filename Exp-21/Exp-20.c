#include <stdio.h>
#include <string.h>

void padMessage(char message[])
{
    int len = strlen(message);
    int blockSize = 8;
    int padding = blockSize - (len % blockSize);

    printf("\nOriginal message: %s", message);
    printf("\nOriginal length: %d", len);

    printf("\nPadding bytes added: %d", padding);

    printf("\nPadded message: ");

    printf("%s", message);

    for (int i = 0; i < padding; i++)
        printf("0");

    printf("\n");
}

int main()
{
    char message[100];

    printf("Enter plaintext: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    padMessage(message);

    return 0;
}
