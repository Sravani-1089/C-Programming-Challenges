#include <stdio.h>

int main() {
    float distance, mileage, fuel_price;
    float fuel_required, total_cost;

    printf("Enter distance (km): ");
    scanf("%f", &distance);

    printf("Enter mileage (km/litre): ");
    scanf("%f", &mileage);

    printf("Enter fuel price (Rs/litre): ");
    scanf("%f", &fuel_price);

    fuel_required = distance / mileage;
    total_cost = fuel_required * fuel_price;

    printf("Fuel required = %.2f litres\n", fuel_required);
    printf("Total fuel cost = Rs %.2f\n", total_cost);

    return 0;
}
