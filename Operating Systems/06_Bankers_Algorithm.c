#include <stdio.h>

int main()
{
    int processes, resources, i, j;
    int allocation[10][10], max_need[10][10], need[10][10], available[10], safe_sequence[10];
    int work[10], finish[10] = {0};

    // Input processes and resources
    printf("Enter number of processes: ");
    scanf("%d", &processes);
    printf("Enter number of resources: ");
    scanf("%d", &resources);

    // Input Allocation Matrix
    printf("Enter Allocation Matrix (%d x %d):\n", processes, resources);
    for (i = 0; i < processes; i++)
        for (j = 0; j < resources; j++)
        {
            printf("Allocation[P%d][R%d]: ", i, j);
            scanf("%d", &allocation[i][j]);
        }

    // Input Max Need Matrix
    printf("Enter Max Need Matrix (%d x %d):\n", processes, resources);
    for (i = 0; i < processes; i++)
        for (j = 0; j < resources; j++)
        {
            printf("MaxNeed[P%d][R%d]: ", i, j);
            scanf("%d", &max_need[i][j]);
        }

    // Input Available Resources
    printf("Enter Available Resources (%d values):\n", resources);
    for (i = 0; i < resources; i++)
    {
        printf("Available[R%d]: ", i);
        scanf("%d", &available[i]);
    }

    // Calculate Need Matrix = Max - Allocation
    for (i = 0; i < processes; i++)
        for (j = 0; j < resources; j++)
            need[i][j] = max_need[i][j] - allocation[i][j];

    // Print Combined Table
    printf("\n%-10s %-20s %-20s %-20s\n", "Process", "Allocation", "Max", "Need");
    for (i = 0; i < processes; i++)
    {
        printf("P%-9d", i);
        for (j = 0; j < resources; j++)
            printf("%d ", allocation[i][j]);
        printf("        ");
        for (j = 0; j < resources; j++)
            printf("%d ", max_need[i][j]);
        printf("        ");
        for (j = 0; j < resources; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    // Print Available Resources
    printf("\nAvailable Resources: ");
    for (i = 0; i < resources; i++)
        printf("R%d=%d ", i, available[i]);
    printf("\n");

    // Begin Banker's Algorithm to find Safe Sequence
    for (i = 0; i < resources; i++)
        work[i] = available[i];

    int count = 0, found, p, r;
    while (count < processes)
    {
        found = 0;
        for (p = 0; p < processes; p++)
        {
            if (!finish[p])
            {
                int canAllocate = 1;
                for (r = 0; r < resources; r++)
                {
                    if (need[p][r] > work[r])
                    {
                        canAllocate = 0;
                        break;
                    }
                }
                if (canAllocate)
                {
                    for (r = 0; r < resources; r++)
                        work[r] += allocation[p][r];
                    safe_sequence[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }
        if (!found)
        {
            printf("\nSystem is in an UNSAFE state.\n");
            return 0;
        }
    }

    // Print Safe Sequence
    printf("\nSystem is in a SAFE state.\nSafe sequence: ");
    for (i = 0; i < processes; i++)
        printf("P%d ", safe_sequence[i]);
    printf("\n");

    return 0;
}
