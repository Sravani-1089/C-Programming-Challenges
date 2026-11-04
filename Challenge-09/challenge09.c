#include <stdio.h>
#define ROWS 5
#define COLS 8

void initializeSeats(int seats[ROWS][COLS]);
void displaySeats(int seats[ROWS][COLS]);
int bookSeat(int seats[ROWS][COLS], int row, int col);
int cancelSeat(int seats[ROWS][COLS], int row, int col);
int reserveGroup(int seats[ROWS][COLS], int groupSize);
void displayReport(int seats[ROWS][COLS]);

int main()
{
    int seats[ROWS][COLS], choice, row, col, groupSize;
    initializeSeats(seats);

    while (1)
    {
        printf("\n--- SEATSMART ---\n");
        printf("1. Display Seats\n2. Book Seat\n");
        printf("3. Cancel Booking\n4. Group Reservation\n");
        printf("5. Occupancy Report\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            displaySeats(seats);

        else if (choice == 2 || choice == 3)
        {
            printf("Enter row and seat: ");
            scanf("%d%d", &row, &col);

            if (choice == 2)
            {
                if (bookSeat(seats, row, col))
                    printf("Booking successful!\n");
                else
                    printf("Booking failed!\n");
            }
            else
            {
                if (cancelSeat(seats, row, col))
                    printf("Cancellation successful!\n");
                else
                    printf("Cancellation failed!\n");
            }
            displaySeats(seats);
        }

        else if (choice == 4)
        {
            printf("Enter group size: ");
            scanf("%d", &groupSize);

            if (reserveGroup(seats, groupSize))
                printf("Group booking successful!\n");
            else
                printf("Group booking failed!\n");

            displaySeats(seats);
        }

        else if (choice == 5)
            displayReport(seats);

        else if (choice == 6)
        {
            printf("Thank you!\n");
            break;
        }
        else
            printf("Invalid choice!\n");
    }
    return 0;
}

void initializeSeats(int seats[ROWS][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            seats[i][j] = 0;
}

void displaySeats(int seats[ROWS][COLS])
{
    int i, j;
    printf("\n0 = Available, 1 = Booked\n");

    for (i = 0; i < ROWS; i++)
    {
        printf("Row %d: ", i + 1);
        for (j = 0; j < COLS; j++)
            printf("%d ", seats[i][j]);
        printf("\n");
    }
}

int bookSeat(int seats[ROWS][COLS], int row, int col)
{
    int result = 0;

    if (row >= 1 && row <= ROWS && col >= 1 && col <= COLS)
        if (seats[row-1][col-1] == 0)
        {
            seats[row-1][col-1] = 1;
            result = 1;
        }
    return result;
}

int cancelSeat(int seats[ROWS][COLS], int row, int col)
{
    int result = 0;

    if (row >= 1 && row <= ROWS && col >= 1 && col <= COLS)
        if (seats[row-1][col-1] == 1)
        {
            seats[row-1][col-1] = 0;
            result = 1;
        }
    return result;
}

int reserveGroup(int seats[ROWS][COLS], int groupSize)
{
    int i, j, k, count, result = 0;

    if (groupSize >= 2 && groupSize <= COLS)
        for (i = 0; i < ROWS && result == 0; i++)
            for (j = 0; j <= COLS-groupSize && result == 0; j++)
            {
                count = 0;
                for (k = 0; k < groupSize; k++)
                    if (seats[i][j+k] == 0)
                        count++;

                if (count == groupSize)
                {
                    for (k = 0; k < groupSize; k++)
                        seats[i][j+k] = 1;

                    printf("Allocated Row: %d\n", i+1);
                    printf("First Seat: %d\n", j+1);
                    result = 1;
                }
            }
    return result;
}

void displayReport(int seats[ROWS][COLS])
{
    int i, j, booked = 0, available, busiest = 0;
    int rowCount[ROWS] = {0};
    float percentage;

    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            if (seats[i][j] == 1)
            {
                booked++;
                rowCount[i]++;
            }

    available = ROWS * COLS - booked;
    percentage = booked / (float)(ROWS * COLS) * 100;

    printf("\nBooked Seats: %d\n", booked);
    printf("Available Seats: %d\n", available);
    printf("Occupancy: %.2f%%\n", percentage);

    for (i = 0; i < ROWS; i++)
        if (rowCount[i] > busiest)
            busiest = rowCount[i];

    printf("Busiest Row(s): ");
    for (i = 0; i < ROWS; i++)
        if (rowCount[i] == busiest)
            printf("%d ", i+1);
    printf("\n");
}
