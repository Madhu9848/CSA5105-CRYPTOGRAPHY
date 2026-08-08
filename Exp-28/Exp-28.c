#include <stdio.h>

int main()
{
    int totalLanes = 25;
    int capacityLanes = 9;

    int messageLanes = totalLanes - capacityLanes;

    printf("SHA-3 Lane Calculation\n");
    printf("----------------------\n");

    printf("Total lanes           : %d\n", totalLanes);
    printf("Message block size     : 1024 bits\n");
    printf("Lane size              : 64 bits\n");
    printf("Capacity               : %d bits\n",
           capacityLanes * 64);

    printf("Capacity lanes         : %d\n",
           capacityLanes);

    printf("Message lanes          : %d\n",
           messageLanes);

    printf("\nWithout permutation, the original zero\n");
    printf("capacity lanes remain zero.\n");

    printf("Therefore all capacity lanes will NOT\n");
    printf("become nonzero under the given assumption.\n");

    return 0;
}
