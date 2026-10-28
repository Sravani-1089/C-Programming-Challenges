#include <stdio.h>

int main()
{
    int a[15], n, i, j, count;
    int missing = 0, duplicate = 0;
    int missingCount = 0, duplicateCount = 0;
    int pairs = 0, target, targetCount = 0;
    int valid = 1, R = 4;

    printf("Enter N (5 to 15): ");
    scanf("%d", &n);

    while (n < 5 || n > 15)
    {
        printf("Invalid N. Enter again (5 to 15): ");
        scanf("%d", &n);
    }

    printf("Enter %d ticket IDs:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);

        while (a[i] < 1 || a[i] > n)
        {
            printf("Invalid ID. Enter again (1 to %d): ", n);
            scanf("%d", &a[i]);
        }
    }

    printf("Original sequence: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    for (i = 1; i <= n; i++)
    {
        count = 0;

        for (j = 0; j < n; j++)
        {
            if (a[j] == i)
                count++;
        }

        if (count == 0)
        {
            missing = i;
            missingCount++;
        }
        else if (count > 1)
        {
            duplicate = i;
            duplicateCount++;

            if (count != 2)
                valid = 0;
        }
    }

    if (missingCount != 1 || duplicateCount != 1)
        valid = 0;

    if (valid == 0)
    {
        printf("\nInvalid scan log\n");
    }
    else
    {
        target = (R % n) + 1;

        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                    pairs++;
            }
        }

        printf("\nMissing ID = %d", missing);
        printf("\nDuplicate ID = %d", duplicate);
        printf("\nOut-of-order pairs = %d", pairs);
        printf("\nTarget ID = %d", target);

        for (i = 0; i < n; i++)
        {
            if (a[i] == target)
            {
                printf("\nTarget position: %d", i + 1);
                targetCount++;
            }
        }

        printf("\nTarget count = %d\n", targetCount);
    }

    return 0;
}
