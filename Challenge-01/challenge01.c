#include<stdio.h>
int main()
{
  int m1,m2,m3,m4,m5;
int total;
float average,percentage;
printf("enter marks of five subjects:\n");
printf("subject1:");
scanf("%d",&m1):
printf("subject2:");
scanf("%d",&m2);
printf("subject3:");
scanf("%d",&m3);
printf("subject4:");
scanf("%d",&m4);
printf("subject5:");
scanf("%d",&m5);
total=m1+m2+m3+m4+m5;
average=total/5.0;
percentage=(total/500.0)*100;
printf("\nTotal Marks=%d\n",total);
printf("Average Marks=%.2f\n",average);
printf("Percentage=%2f%%\n",percentage);
return 0;
}
