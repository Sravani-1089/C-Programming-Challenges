#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,f,choice;
    float a,b,c,d,root1,root2;

    while(1)
    {
        printf("\n1.linear equation\n");
        printf("2.factorial\n");
        printf("3.quadratic equation\n");
        printf("4.exit\n");

        printf("enter your choice(1-4): ");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("enter a and b: ");
            scanf("%f,%f",&a,&b);

            if(a !=0)
                printf("\nx = %.2f\n",-b/a);
            else if(b==0)
                printf("infinite solutions\n");
            else
                printf("no solution\n");
        }
        else if(choice ==2)
        {
            printf("enter n(0 to 12): ");
            scanf("%d",&n);
            if(n<0 || n>12)
                printf("invalid number");
            else
            {
                f=1;
                for(i=1;i<=n;i++)
                    f=f*i;
                printf("factorial of %d=%d\n",n,f);
            }
        }
        else if(choice==3)
        {
            printf("enter a,b and c: ");
            scanf("%f %f %f",&a,&b,&c);
            printf("a=%.2f,b=%.2f,c=%.2f\n",a,b,c);

            if(a!=0)
            {
                d=b*b-4*a*c;

                if(d<0)
                    printf("\nno real roots\n");
                else if(d==0)
                {
                    root1 = -b/(2*a);
                    printf("\nequal roots = %.2f\n",root1);
                }
                else
                {
                    root1 = (-b+sqrt(d))/(2*a);
                    root2 = (-b-sqrt(d))/(2*a);

                    printf("root1 = %.2f\n",root1);
                    printf("root2 = %.2f\n",root2);
                }
            }
            else
                printf("not a quadratic equation\n");
        }
        else if (choice==4)
        {
            printf("program ended\n");
            break;
        }
        else
            printf("invalid choice\n");
    }
    return 0;
}
