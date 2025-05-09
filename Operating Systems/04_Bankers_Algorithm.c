#include <stdio.h>

void printArr(int arr[5][3], int processes, int resources, char *label)
{
    int r, i, j;

    printf("%s:\n", label);
    printf("Process  | ");
    for (r = 0; r < resources; r++)
    {
        printf("Resource %d | ", r + 1);
    }
    printf("\n");

    for (i = 0; i < processes; i++)
    {
        printf("P%d       | ", i);
        for (j = 0; j < resources; j++)
        {
            printf("%d          | ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printAvailable(int available[3])
{
    int i;
    printf("Available Resources:\n");
    printf("Resource  | ");
    for (i = 0; i < 3; i++)
    {
        printf("Resource %d    | ", i + 1);
    }
    printf("\n");
    printf("          | ");
    for (i = 0; i < 3; i++)
    {
        printf("%d             | ", available[i]);
    }
    printf("\n\n");
}

int calc_safe_state(int processes, int resources, int allocation[5][3], int maxNeed[5][3], int available[3], int safeSequence[5])
{
    int work[3];
    int finish[5] = {0};
    int count = 0;
    int i, p, r, found, canFinish;

    for (i = 0; i < resources; i++)
    {
        work[i] = available[i];
    }

    while (count < processes)
    {
        found = 0;

        for (p = 0; p < processes; p++)
        {
            if (!finish[p])
            {
                canFinish = 1;

                for (r = 0; r < resources; r++)
                {
                    if (maxNeed[p][r] - allocation[p][r] > work[r])
                    {
                        canFinish = 0;
                        break;
                    }
                }

                if (canFinish)
                {
                    for (r = 0; r < resources; r++)
                    {
                        work[r] += allocation[p][r];
                    }

                    finish[p] = 1;
                    safeSequence[count++] = p;
                    found = 1;
                }
            }
        }

        if (!found)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int allocation[5][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int max_need[5][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int available[3] = {3, 3, 2};
    int safe_sequence[5];
    int i, j;

    // Print the tables
    printArr(allocation, 5, 3, "Allocation Matrix");
    printArr(max_need, 5, 3, "Max Need Matrix");
    printAvailable(available);

    // Calculate safe state
    int isSafe = calc_safe_state(5, 3, allocation, max_need, available, safe_sequence);

    if (isSafe)
    {
        printf("Safe sequence: ");
        for (i = 0; i < 5; i++)
        {
            printf("P%d ", safe_sequence[i]);
        }
        printf("\n");
    }
    else
    {
        printf("System is in an unsafe state.\n");
    }

    return 0;
}
