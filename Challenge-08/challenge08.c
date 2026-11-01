#include <stdio.h>

int main()
{
    int a[6][6];
    int n, t, i, j;
    int sum, maxRow = -1, maxCol = -1;
    int maxRisk, count = 0;
    int mainD = 0, secondD = 0;
    int boundary = 0, hotspots = 0;

    printf("Enter N (3 to 6): ");
    scanf("%d", &n);

    while (n < 3 || n > 6)
    {
        printf("Invalid N. Enter again: ");
        scanf("%d", &n);
    }

    printf("Enter grid values (0 to 100):\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);

            while (a[i][j] < 0 || a[i][j] > 100)
            {
                printf("Invalid value. Enter again: ");
                scanf("%d", &a[i][j]);
            }
        }
    }

    printf("Enter threshold T (1 to 100): ");
    scanf("%d", &t);

    while (t < 1 || t > 100)
    {
        printf("Invalid T. Enter again: ");
        scanf("%d", &t);
    }

    // Row totals
    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
            sum = sum + a[i][j];

        if (sum > maxRow)
            maxRow = sum;
    }

    printf("\nHighest row total: %d", maxRow);
    printf("\nRows: ");

    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
            sum = sum + a[i][j];

        if (sum == maxRow)
            printf("%d ", i + 1);
    }

    // Column totals
    for (j = 0; j < n; j++)
    {
        sum = 0;
        for (i = 0; i < n; i++)
            sum = sum + a[i][j];

        if (sum > maxCol)
            maxCol = sum;
    }

    printf("\n\nHighest column total: %d", maxCol);
    printf("\nColumns: ");

    for (j = 0; j < n; j++)
    {
        sum = 0;
        for (i = 0; i < n; i++)
            sum = sum + a[i][j];

        if (sum == maxCol)
            printf("%d ", j + 1);
    }

    // Maximum risk and threshold count
    maxRisk = a[0][0];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] > maxRisk)
                maxRisk = a[i][j];

            if (a[i][j] >= t)
                count++;
        }
    }

    printf("\n\nHighest risk: %d", maxRisk);
    printf("\nPositions:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == maxRisk)
                printf("Row %d Column %d\n", i + 1, j + 1);
        }
    }

    printf("Cells meeting threshold: %d", count);

    // Diagonal sums
    for (i = 0; i < n; i++)
    {
        mainD = mainD + a[i][i];
        secondD = secondD + a[i][n - 1 - i];
    }

    printf("\n\nMain diagonal: %d", mainD);
    printf("\nSecondary diagonal: %d", secondD);

    if (mainD == secondD)
        printf("\nDiagonals are balanced.");
    else
        printf("\nDiagonals are not balanced.");

    // Boundary sum
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 ||
                j == 0 || j == n - 1)
            {
                boundary = boundary + a[i][j];
            }
        }
    }

    printf("\n\nBoundary sum: %d", boundary);

    // Local hotspots
    printf("\n\nLocal hotspots:\n");

    for (i = 1; i < n - 1; i++)
    {
        for (j = 1; j < n - 1; j++)
        {
            if (a[i][j] > a[i-1][j] &&
                a[i][j] > a[i+1][j] &&
                a[i][j] > a[i][j-1] &&
                a[i][j] > a[i][j+1] &&
                a[i][j] >= t)
            {
                printf("Row %d Column %d Value %d\n",
                       i + 1, j + 1, a[i][j]);

                hotspots++;
            }
        }
    }

    if (hotspots == 0)
        printf("No local hotspots found.");

    // Final decision
    printf("\n\nFinal Decision: ");

    if (hotspots > 0)
        printf("CRITICAL");
    else if (count >= n)
        printf("WARNING");
    else
        printf("NORMAL");

    return 0;
}
