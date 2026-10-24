
#include <stdio.h>

int main() {
    int a[12], n, i, j, k, temp;
    int sum = 0, min, max, second, found;
    int peaks = 0, run = 1, longest = 1;
    int r, d, count = 0;

    
        printf("Enter N: ");
        scanf("%d", &n);
     while (n < 5 || n > 12);

    for (i = 0; i < n; i++) {
        do {
            printf("Enter reading: ");
            scanf("%d", &a[i]);
        } while (a[i] < 0 || a[i] > 1000);
    }

    min = max = a[0];

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
        sum = sum + a[i];

        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }

    printf("\nSum = %d", sum);
    printf("\nAverage = %.2f", (float)sum / n);
    printf("\nMinimum = %d", min);
    printf("\nMaximum = %d\n", max);

    found = 0;

    for (i = 0; i < n; i++) {
        if (a[i] < max) {
            if (found == 0 || a[i] > second) {
                second = a[i];
                found = 1;
            }
        }
    }

    if (found == 1)
        printf("Second largest = %d\n", second);
    else
        printf("No second largest\n");

    for (i = 1; i < n - 1; i++) {
        if (a[i] > a[i-1] && a[i] > a[i+1])
            peaks++;
    }
    printf("Peaks = %d\n", peaks);

    for (i = 1; i < n; i++) {
        if (a[i] > a[i-1])
            run++;
        else
            run = 1;

        if (run > longest)
            longest = run;
    }
    printf("Longest run = %d\n", longest);

    printf("Enter K: ");
    scanf("%d", &k);
    k = ((k % n) + n) % n;

    for (j = 0; j < k; j++) {
        temp = a[n-1];

        for (i = n-1; i > 0; i--)
            a[i] = a[i-1];

        a[0] = temp;
    }

    printf("Rotated array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    
    printf("\nEnter last two digits: ");
    scanf("%d", &r);
    d = (r % 9) + 1;

    for (i = 0; i < n; i++) {
        if (a[i] % d == 0)
            count++;
    }

    printf("\nD = %d", d);
    printf("\nDivisible count = %d\n", count);

    return 0;
}
