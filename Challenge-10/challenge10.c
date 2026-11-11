#include <stdio.h>

#define ZONES 5
#define DAYS 7

void displayZoneName(int zone);
void inputData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS]);
void displayData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS]);
void calculateAverages(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS], float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES]);
void detectRiskZones(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS], int riskDays[ZONES]);
void computeGreenIndex(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES], float greenIndex[ZONES]);
void displayRanking(float greenIndex[ZONES]);
void displayRecommendations(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES], int riskDays[ZONES]);

void displayZoneName(int zone)
{
    if (zone == 0)
        printf("%-18s", "Academic Block");
    else if (zone == 1)
        printf("%-18s", "Hostel");
    else if (zone == 2)
        printf("%-18s", "Library");
    else if (zone == 3)
        printf("%-18s", "Cafeteria");
    else
        printf("%-18s", "Sports Area");
}

void inputData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS])
{
    int i, j;

    for (i = 0; i < ZONES; i++)
    {
        printf("\nEnter readings for ");
        if (i == 0) printf("Academic Block\n");
        else if (i == 1) printf("Hostel\n");
        else if (i == 2) printf("Library\n");
        else if (i == 3) printf("Cafeteria\n");
        else printf("Sports Area\n");

        for (j = 0; j < DAYS; j++)
        {
            printf("Day %d temperature (10 to 50): ", j + 1);
            scanf("%f", &temp[i][j]);
            while (temp[i][j] < 10 || temp[i][j] > 50)
            {
                printf("Invalid. Enter temperature from 10 to 50: ");
                scanf("%f", &temp[i][j]);
            }

            printf("Day %d humidity (0 to 100): ", j + 1);
            scanf("%f", &humidity[i][j]);
            while (humidity[i][j] < 0 || humidity[i][j] > 100)
            {
                printf("Invalid. Enter humidity from 0 to 100: ");
                scanf("%f", &humidity[i][j]);
            }

            printf("Day %d AQI (0 to 500): ", j + 1);
            scanf("%d", &aqi[i][j]);
            while (aqi[i][j] < 0 || aqi[i][j] > 500)
            {
                printf("Invalid. Enter AQI from 0 to 500: ");
                scanf("%d", &aqi[i][j]);
            }
        }
    }
    printf("\nAll readings saved successfully.\n");
}

void displayData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS])
{
    int i, j;

    printf("\nTEMPERATURE MATRIX (C)\n");
    printf("%-18s", "Zone/Day");
    for (j = 0; j < DAYS; j++)
        printf("%7s", j == 0 ? "D1" : j == 1 ? "D2" : j == 2 ? "D3" :
               j == 3 ? "D4" : j == 4 ? "D5" : j == 5 ? "D6" : "D7");
    printf("\n");
    for (i = 0; i < ZONES; i++)
    {
        displayZoneName(i);
        for (j = 0; j < DAYS; j++)
            printf("%7.1f", temp[i][j]);
        printf("\n");
    }

    printf("\nHUMIDITY MATRIX (%%)\n");
    printf("%-18s", "Zone/Day");
    for (j = 0; j < DAYS; j++)
        printf("%7s", j == 0 ? "D1" : j == 1 ? "D2" : j == 2 ? "D3" :
               j == 3 ? "D4" : j == 4 ? "D5" : j == 5 ? "D6" : "D7");
    printf("\n");
    for (i = 0; i < ZONES; i++)
    {
        displayZoneName(i);
        for (j = 0; j < DAYS; j++)
            printf("%7.1f", humidity[i][j]);
        printf("\n");
    }

    printf("\nAQI MATRIX\n");
    printf("%-18s", "Zone/Day");
    for (j = 0; j < DAYS; j++)
        printf("%7s", j == 0 ? "D1" : j == 1 ? "D2" : j == 2 ? "D3" :
               j == 3 ? "D4" : j == 4 ? "D5" : j == 5 ? "D6" : "D7");
    printf("\n");
    for (i = 0; i < ZONES; i++)
    {
        displayZoneName(i);
        for (j = 0; j < DAYS; j++)
            printf("%7d", aqi[i][j]);
        printf("\n");
    }
}

void calculateAverages(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS],
                       float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES])
{
    int i, j;
    float sumTemp, sumHumidity, sumAQI;

    for (i = 0; i < ZONES; i++)
    {
        sumTemp = 0;
        sumHumidity = 0;
        sumAQI = 0;

        for (j = 0; j < DAYS; j++)
        {
            sumTemp = sumTemp + temp[i][j];
            sumHumidity = sumHumidity + humidity[i][j];
            sumAQI = sumAQI + aqi[i][j];
        }

        avgTemp[i] = sumTemp / DAYS;
        avgHumidity[i] = sumHumidity / DAYS;
        avgAQI[i] = sumAQI / DAYS;
    }
}

void detectRiskZones(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS],
                     int riskDays[ZONES])
{
    int i, j;

    printf("\nRISK DAY REPORT\n");
    for (i = 0; i < ZONES; i++)
    {
        riskDays[i] = 0;
        printf("\n");
        displayZoneName(i);
        printf("Risk days: ");

        for (j = 0; j < DAYS; j++)
        {
            if (aqi[i][j] > 150 || temp[i][j] > 35 || humidity[i][j] > 80)
            {
                riskDays[i]++;
                printf("D%d ", j + 1);
            }
        }

        if (riskDays[i] == 0)
            printf("None");
        printf("\nTotal risk days: %d\n", riskDays[i]);
    }
}

void computeGreenIndex(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES],
                       float greenIndex[ZONES])
{
    int i;
    float aqiScore, tempScore, humidityScore;
    float tempDifference, humidityDifference;

    for (i = 0; i < ZONES; i++)
    {
        aqiScore = 100 - (avgAQI[i] / 5);

        if (avgTemp[i] >= 25)
            tempDifference = avgTemp[i] - 25;
        else
            tempDifference = 25 - avgTemp[i];
        tempScore = 100 - (4 * tempDifference);

        if (avgHumidity[i] >= 50)
            humidityDifference = avgHumidity[i] - 50;
        else
            humidityDifference = 50 - avgHumidity[i];
        humidityScore = 100 - (2 * humidityDifference);

        if (aqiScore < 0) aqiScore = 0;
        if (tempScore < 0) tempScore = 0;
        if (humidityScore < 0) humidityScore = 0;

        greenIndex[i] = 0.4 * aqiScore + 0.3 * tempScore + 0.3 * humidityScore;
    }

    printf("\nGREEN INDEX\n");
    for (i = 0; i < ZONES; i++)
    {
        displayZoneName(i);
        printf("%.2f\n", greenIndex[i]);
    }
}

void displayRanking(float greenIndex[ZONES])
{
    int i, j, position = 0, rank, count;
    int used[ZONES] = {0};
    float highest;

    printf("\nZONE RANKING (HIGHEST TO LOWEST)\n");
    while (position < ZONES)
    {
        highest = -1;
        for (i = 0; i < ZONES; i++)
            if (used[i] == 0 && greenIndex[i] > highest)
                highest = greenIndex[i];

        rank = position + 1;
        count = 0;
        for (j = 0; j < ZONES; j++)
        {
            if (used[j] == 0 && greenIndex[j] == highest)
            {
                printf("Rank %d: ", rank);
                if (j == 0) printf("Academic Block");
                else if (j == 1) printf("Hostel");
                else if (j == 2) printf("Library");
                else if (j == 3) printf("Cafeteria");
                else printf("Sports Area");
                printf(" (%.2f)\n", greenIndex[j]);
                used[j] = 1;
                count++;
            }
        }
        position += count;
    }
}

void displayRecommendations(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES],
                            int riskDays[ZONES])
{
    int i;

    printf("\nECO-FRIENDLY RECOMMENDATIONS\n");
    for (i = 0; i < ZONES; i++)
    {
        printf("\n");
        displayZoneName(i);
        printf("\n");

        if (avgAQI[i] > 150)
            printf("- Reduce vehicle emissions and control dust in this zone.\n");
        else
            printf("- Continue monitoring air quality.\n");

        if (avgTemp[i] > 35)
            printf("- Increase shade and plant more trees.\n");

        if (avgHumidity[i] > 80)
            printf("- Improve ventilation and check for damp areas.\n");

        if (riskDays[i] > 0)
            printf("- Review the reported risk days and take corrective action.\n");
        else
            printf("- No risk days recorded; maintain current eco-friendly practices.\n");
    }
}

int main()
{
    float temp[ZONES][DAYS], humidity[ZONES][DAYS];
    int aqi[ZONES][DAYS];
    float avgTemp[ZONES], avgHumidity[ZONES], avgAQI[ZONES];
    float greenIndex[ZONES];
    int riskDays[ZONES];
    int choice, dataReady = 0;

    do
    {
        printf("\n===== ECOGUARD CAMPUS ENVIRONMENT MONITOR =====\n");
        printf("1. Input / Update Data\n");
        printf("2. Display Data\n");
        printf("3. Zone-wise Averages\n");
        printf("4. Detect Risk Days\n");
        printf("5. Green Index and Ranking\n");
        printf("6. Recommendations\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            inputData(temp, humidity, aqi);
            dataReady = 1;
        }
        else if (choice >= 2 && choice <= 6 && dataReady == 0)
        {
            printf("\nPlease enter the readings first using option 1.\n");
        }
        else if (choice == 2)
        {
            displayData(temp, humidity, aqi);
        }
        else if (choice == 3)
        {
            int i;
            calculateAverages(temp, humidity, aqi, avgTemp, avgHumidity, avgAQI);
            printf("\nZONE-WISE 7-DAY AVERAGES\n");
            printf("%-18s %12s %12s %12s\n", "Zone", "Temperature", "Humidity", "AQI");
            for (i = 0; i < ZONES; i++)
            {
                displayZoneName(i);
                printf("%12.2f %12.2f %12.2f\n", avgTemp[i], avgHumidity[i], avgAQI[i]);
            }
        }
        else if (choice == 4)
        {
            detectRiskZones(temp, humidity, aqi, riskDays);
        }
        else if (choice == 5)
        {
            calculateAverages(temp, humidity, aqi, avgTemp, avgHumidity, avgAQI);
            computeGreenIndex(avgTemp, avgHumidity, avgAQI, greenIndex);
            displayRanking(greenIndex);
        }
        else if (choice == 6)
        {
            calculateAverages(temp, humidity, aqi, avgTemp, avgHumidity, avgAQI);
            detectRiskZones(temp, humidity, aqi, riskDays);
            displayRecommendations(avgTemp, avgHumidity, avgAQI, riskDays);
        }
        else if (choice == 7)
        {
            printf("\nThank you for using ECOGUARD.\n");
        }
        else
        {
            printf("\nInvalid choice. Please select 1 to 7.\n");
        }

    } while (choice != 7);

    return 0;
}
