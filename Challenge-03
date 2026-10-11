#include <stdio.h>

int main()
{
    float purchase, discount, amount, delivery, finalAmount;
    float distance;
    int customer;

    printf("Enter purchase amount: ");
    scanf("%f", &purchase);

    printf("Enter customer type (1-Student, 2-Regular): ");
    scanf("%d", &customer);

    printf("Enter delivery distance in km: ");
    scanf("%f", &distance);

    if (customer == 1)
    {
        if (purchase >= 2000)
            discount = purchase * 0.15;
        else
            discount = purchase * 0.10;
    }
    else if (customer == 2)
    {
        if (purchase >= 3000)
            discount = purchase * 0.08;
        else
            discount = 0;
    }
    else
    {
        printf("Invalid customer type!\n");
        discount = 0;
    }

    if (customer == 1 || customer == 2)
    {
        amount = purchase - discount;

        if (distance <= 5)
            delivery = 40;
        else if (distance <= 15)
            delivery = 70;
        else
            delivery = 100;

        finalAmount = amount + delivery;

        printf("\nPurchase Amount = Rs. %.2f\n", purchase);
        printf("Discount Amount = Rs. %.2f\n", discount);
        printf("Amount After Discount = Rs. %.2f\n", amount);
        printf("Delivery Charge = Rs. %.2f\n", delivery);
        printf("Final Payable Amount = Rs. %.2f\n", finalAmount);
    }

    return 0;
}
