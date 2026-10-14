
#include <stdio.h>

int main()
{
    float amount, smallTotal = 0, mediumTotal = 0, largeTotal = 0, total = 0, average;
    int smallCount = 0, mediumCount = 0, largeCount = 0, validCount = 0;

    printf("Enter expense (0 to stop): ");
    scanf("%f", &amount);

    while (amount != 0)
    {
        if (amount < 0)
        {
            printf("Invalid expense!\n");
        }
        else if (amount < 100)
        {
            validCount++;
            total += amount;
            smallCount++;
            smallTotal += amount;
        }
        else if (amount < 500)
        {
            validCount++;
            total += amount;
            mediumCount++;
            mediumTotal += amount;
        }
        else
        {
            validCount++;
            total += amount;
            largeCount++;
            largeTotal += amount;
        }

        printf("Enter expense (0 to stop): ");
        scanf("%f", &amount);
    }

    printf("\nValid expenses: %d\n", validCount);
    printf("Total expenses: %.2f\n", total);
    printf("Small count: %d, Total: %.2f\n", smallCount, smallTotal);
    printf("Medium count: %d, Total: %.2f\n", mediumCount, mediumTotal);
    printf("Large count: %d, Total: %.2f\n", largeCount, largeTotal);

    if (validCount > 0)
    {
        average = total / validCount;
        printf("Average expense: %.2f\n", average);
    }
    else
    {
        printf("No valid expenses entered.\n");
    }

    return 0;
}
