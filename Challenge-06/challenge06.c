#include <stdio.h>

int main()
{
    int a[12], n, i, sum=0, min, max;
    int found=0, peaks=0, second;
    int longest=1, r, d, j, k;
    int count=0, run=1, temp;
    
    printf("enter n: ");
    scanf("%d", &n);
    
    while(n < 5 || n > 12)
    {
        printf("enter n: ");
        scanf("%d", &n);
    }
    
    for(i = 0; i < n; i++)
    {
        do
        {
            printf("enter reading: ");
            scanf("%d", &a[i]);
        }
        while(a[i] < 0 || a[i] > 1000);
    }
    
    min = max = a[0];
    
    printf("Original: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        sum = sum + a[i];
        
        if(a[i] < min) min = a[i];
        if(a[i] > max) max = a[i];
    }
    
    printf("\nsum=%d", sum);
    printf("\naverage=%.2f\n", (float)sum / n);
    printf("\nminimum=%d", min);
    printf("\nmaximum=%d\n", max);
    
    for(i = 0; i < n; i++)
    {
        if(a[i] < max)
        {
            if(found == 0 || a[i] > second)
            {
                second = a[i];
                found = 1;
            }
        }
    }
    
    if(found == 1)
        printf("second largest=%d\n", second);
    else
        printf("no second largest\n");
        
    for(i = 1; i < n - 1; i++)
    {
        if(a[i] > a[i-1] && a[i] > a[i+1])
        {
            peaks++;
        }
    }
    printf("local peaks = %d\n", peaks);
    
    for(i = 1; i < n; i++)
    {
        if(a[i] > a[i-1])
        {
            run++;
            if(run > longest) longest = run;
        }
        else
        {
            run = 1;
        }
    }
    printf("longest increasing run=%d\n", longest);
    
    printf("enter k: ");
    scanf("%d", &k);
    k = ((k % n) + n) % n;
    
    for(j = 0; j < k; j++)
    {
        temp = a[n-1];
        for(i = n - 1; i > 0; i--)
        {
            a[i] = a[i-1];
        }
        a[0] = temp;
    }
    
    printf("rotated array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
    printf("\nenter last two digits: ");
    scanf("%d", &r);
    
    d = (r % 9) + 1;
    
    for(i = 0; i < n; i++)
    {
        if(a[i] % d == 0)
        {
            count++;
        }
    }
    
    printf("D=%d", d);
    printf("\ndivisible count=%d\n", count);
    
    return 0;
}
