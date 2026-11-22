#include <stdio.h>
#include <stdlib.h>

#define ZONES 5
#define DAYS 7

/* ---------- prototypes (required) ---------- */
void inputWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]);
void displayWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]);
void calculateZoneStats(int *zoneUsage, int *total, float *average,
                        int *peakUsage, int *peakDay);
void detectWaterAlerts(int *zoneUsage, int dailyTarget, int *overLimitDays,
                       int *totalExcess, int *spikeDays, int *alertDays);
void generateAuditReport(int usage[ZONES][DAYS], int dailyTarget[ZONES],
                         int excessByZone[ZONES], int overLimitByZone[ZONES],
                         int spikeByZone[ZONES], int alertByZone[ZONES]);
void rankZones(int excessByZone[ZONES]);
void displayConservationActions(int overLimitByZone[ZONES],
                                int spikeByZone[ZONES],
                                int excessByZone[ZONES]);

/* ---------- helpers ---------- */
const char *zoneName(int z)
{
    switch (z) {
        case 0: return "Academic Block";
        case 1: return "Hostel";
        case 2: return "Library";
        case 3: return "Cafeteria";
        default: return "Sports Complex";
    }
}

/* Reads an int in [lo, hi]; re-prompts on invalid or non-numeric input. */
int readInRange(const char *prompt, int lo, int hi)
{
    int value, ok, c;
    while (1) {
        printf("%s", prompt);
        ok = scanf("%d", &value);
        if (ok == EOF) {
            printf("\nInput ended unexpectedly. Exiting.\n");
            exit(0);
        }
        if (ok != 1) {
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("  Invalid input. Enter a whole number.\n");
            continue;
        }
        if (value < lo || value > hi) {
            printf("  Invalid value. Allowed range: %d to %d.\n", lo, hi);
            continue;
        }
        return value;
    }
}

/* Prints the (1-based) days on which a spike occurred, using pointers. */
void printSpikeDays(int *zoneUsage)
{
    int day, found = 0;
    for (day = 1; day < DAYS; day++) {
        if (*(zoneUsage + day) * 100 > *(zoneUsage + day - 1) * 140) {
            printf("%sDay %d", found ? ", " : "", day + 1);
            found = 1;
        }
    }
    if (!found) printf("none");
}

/* ---------- required functions ---------- */
void inputWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES])
{
    int z, d;
    char prompt[100];
    for (z = 0; z < ZONES; z++) {
        printf("\n--- Zone %d: %s ---\n", z + 1, zoneName(z));
        dailyTarget[z] = readInRange("Daily target (100-50000 L): ", 100, 50000);
        for (d = 0; d < DAYS; d++) {
            sprintf(prompt, "Day %d reading (0-50000 L): ", d + 1);
            usage[z][d] = readInRange(prompt, 0, 50000);
        }
    }
}

void displayWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES])
{
    int z, d;
    printf("\n%-16s", "Zone");
    for (d = 1; d <= DAYS; d++) printf("%8s%d", "Day", d);
    printf("%10s\n", "Target");
    for (z = 0; z < ZONES; z++) {
        printf("%d.%-14s", z + 1, zoneName(z));
        for (d = 0; d < DAYS; d++) printf("%9d", usage[z][d]);
        printf("%10d\n", dailyTarget[z]);
    }
    printf("(All values in litres)\n");
}

void calculateZoneStats(int *zoneUsage, int *total, float *average,
                        int *peakUsage, int *peakDay)
{
    int day, sum = 0, peak = *zoneUsage, pDay = 1;
    for (day = 0; day < DAYS; day++) {
        int v = *(zoneUsage + day);
        sum += v;
        if (v > peak) {
            peak = v;
            pDay = day + 1;
        }
    }
    *total = sum;
    *average = (float)sum / DAYS;
    *peakUsage = peak;
    *peakDay = pDay;
}

void detectWaterAlerts(int *zoneUsage, int dailyTarget, int *overLimitDays,
                       int *totalExcess, int *spikeDays, int *alertDays)
{
    int day, over = 0, excess = 0, spikes = 0, alerts = 0;
    for (day = 0; day < DAYS; day++) {
        int cur = *(zoneUsage + day);
        int isOver = cur > dailyTarget;
        int isSpike = 0;
        if (day > 0) {
            int prev = *(zoneUsage + day - 1);
            isSpike = (cur * 100 > prev * 140);
        }
        if (isOver) {
            over++;
            excess += cur - dailyTarget;
        }
        if (isSpike) spikes++;
        if (isOver || isSpike) alerts++;
    }
    *overLimitDays = over;
    *totalExcess = excess;
    *spikeDays = spikes;
    *alertDays = alerts;
}

void generateAuditReport(int usage[ZONES][DAYS], int dailyTarget[ZONES],
                         int excessByZone[ZONES], int overLimitByZone[ZONES],
                         int spikeByZone[ZONES], int alertByZone[ZONES])
{
    int z, total, peak, peakDay;
    float avg;
    printf("\n================ WATER AUDIT REPORT ================\n");
    for (z = 0; z < ZONES; z++) {
        calculateZoneStats(&usage[z][0], &total, &avg, &peak, &peakDay);
        detectWaterAlerts(&usage[z][0], dailyTarget[z], &overLimitByZone[z],
                          &excessByZone[z], &spikeByZone[z], &alertByZone[z]);
        printf("\nZone %d: %s (target %d L/day)\n", z + 1, zoneName(z),
               dailyTarget[z]);
        printf("  Weekly total     : %d L\n", total);
        printf("  Daily average    : %.2f L\n", avg);
        printf("  Peak consumption : %d L on Day %d\n", peak, peakDay);
        printf("  Over-limit days  : %d\n", overLimitByZone[z]);
        printf("  Total excess     : %d L\n", excessByZone[z]);
        printf("  Spike days       : %d (", spikeByZone[z]);
        printSpikeDays(&usage[z][0]);
        printf(")\n");
        printf("  Unique alert days: %d\n", alertByZone[z]);
    }
    printf("\n====================================================\n");
}

void rankZones(int excessByZone[ZONES])
{
    int order[ZONES], rank[ZONES];
    int i, j, max = excessByZone[0], tmp;

    for (i = 0; i < ZONES; i++) order[i] = i;
    /* sort zone indices by excess, highest first (stable) */
    for (i = 0; i < ZONES - 1; i++)
        for (j = 0; j < ZONES - 1 - i; j++)
            if (excessByZone[order[j]] < excessByZone[order[j + 1]]) {
                tmp = order[j]; order[j] = order[j + 1]; order[j + 1] = tmp;
            }
    /* competition ranking: ties share a rank */
    for (i = 0; i < ZONES; i++) {
        int better = 0;
        for (j = 0; j < ZONES; j++)
            if (excessByZone[j] > excessByZone[order[i]]) better++;
        rank[i] = better + 1;
        if (excessByZone[i] > max) max = excessByZone[i];
    }

    printf("\n--- Zone Ranking by Total Excess ---\n");
    printf("%-6s%-18s%s\n", "Rank", "Zone", "Excess (L)");
    for (i = 0; i < ZONES; i++)
        printf("%-6d%-18s%d\n", rank[i], zoneName(order[i]),
               excessByZone[order[i]]);

    if (max == 0) {
        printf("\nNo zone exceeded its daily target.\n");
    } else {
        printf("\nGreatest excess (%d L): ", max);
        j = 0;
        for (i = 0; i < ZONES; i++)
            if (excessByZone[i] == max)
                printf("%s%s", j++ ? ", " : "", zoneName(i));
        printf("\n");
    }
}

void displayConservationActions(int overLimitByZone[ZONES],
                                int spikeByZone[ZONES],
                                int excessByZone[ZONES])
{
    int z;
    printf("\n--- Conservation Actions ---\n");
    for (z = 0; z < ZONES; z++) {
        printf("\nZone %d: %s (excess %d L)\n", z + 1, zoneName(z),
               excessByZone[z]);
        if (spikeByZone[z] > 0)
            printf("  - Check for a leak or unexpected use around the flagged spike days (%d; see Audit Report for the days).\n",
                   spikeByZone[z]);
        if (overLimitByZone[z] >= 3)
            printf("  - PRIORITY: conduct a water audit and prepare a reduction plan.\n");
        else if (overLimitByZone[z] >= 1)
            printf("  - Monitor the over-limit days and inspect taps and valves.\n");
        if (spikeByZone[z] == 0 && overLimitByZone[z] == 0)
            printf("  - No alerts: maintain current good practices.\n");
    }
}

/* ---------- main ---------- */
int main(void)
{
    int usage[ZONES][DAYS], dailyTarget[ZONES];
    int excessByZone[ZONES] = {0}, overLimitByZone[ZONES] = {0};
    int spikeByZone[ZONES] = {0}, alertByZone[ZONES] = {0};
    int auditDone = 0, choice;

    printf("=== WATERWISE: Track. Detect. Conserve. ===\n");

    inputWaterData(usage, dailyTarget);

    do {
        printf("\n===== MENU =====\n"
               "1. Display Water Data\n"
               "2. Generate Audit Report\n"
               "3. Rank Zones by Excess\n"
               "4. Conservation Actions\n"
               "5. Exit\n");
        choice = readInRange("Enter choice: ", -2147483647, 2147483647);
        switch (choice) {
            case 1:
                displayWaterData(usage, dailyTarget);
                break;
            case 2:
                generateAuditReport(usage, dailyTarget, excessByZone,
                                    overLimitByZone, spikeByZone, alertByZone);
                auditDone = 1;
                break;
            case 3:
                if (!auditDone) printf("\nPlease generate the audit report (Option 2) first.\n");
                else rankZones(excessByZone);
                break;
            case 4:
                if (!auditDone) printf("\nPlease generate the audit report (Option 2) first.\n");
                else displayConservationActions(overLimitByZone, spikeByZone,
                                                excessByZone);
                break;
            case 5:
                printf("\nGoodbye! Save water.\n");
                break;
            default:
                printf("\nInvalid choice. Enter 1-5.\n");
        }
    } while (choice != 5);
    return 0;
}
