#include <stdio.h>

int main()
{
    printf("CBC Error Propagation Demonstration\n");
    printf("-----------------------------------\n");

    printf("\nPart (a):\n");
    printf("If C1 is corrupted in CBC mode:\n");

    printf("P1 becomes completely corrupted.\n");
    printf("P2 has a corresponding bit error.\n");
    printf("P3 and later blocks are not affected.\n");

    printf("\nPart (b):\n");
    printf("If a bit error occurs in the source P1:\n");

    printf("C1 is completely changed because encryption is performed\n");
    printf("on the modified plaintext block.\n");

    printf("The error affects C1 and causes subsequent CBC processing\n");
    printf("to produce changed ciphertext blocks.\n");

    printf("\nSummary:\n");
    printf("Corrupted C1 -> P1 corrupted + corresponding bit error in P2\n");
    printf("Blocks after P2 -> unaffected\n");

    return 0;
}
