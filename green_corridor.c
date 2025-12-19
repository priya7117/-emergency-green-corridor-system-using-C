#include <stdio.h>
#include <unistd.h>

#define JUNCTIONS 5
#define HOSPITALS 3

// 1 = Junction on ambulance route
int route[JUNCTIONS] = {1, 1, 1, 1, 1};

// 1 = Accident zone
int accident[JUNCTIONS] = {0, 1, 0, 0, 0};

// Traffic density: 1=Low, 2=Medium, 3=High
int density[JUNCTIONS] = {2, 3, 3, 1, 2};

char hospitals[HOSPITALS][40] = {
    "City Government Hospital",
    "Apollo Emergency Care",
    "LifeCare Trauma Center"
};

void countdown(int t)
{
    int i;
    printf("⏱️ Green Time Remaining: ");
    for (i = t; i > 0; i--)
    {
        printf("%d ", i);
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}

void sendHospitalAlert()
{
    int i;
    printf("\n📡 Alerting Nearby Hospitals...\n\n");
    for (i = 0; i < HOSPITALS; i++)
    {
        printf("🏥 %-25s -> ALERT SENT (ETA: 10 mins)\n", hospitals[i]);
        sleep(1);
    }
}

int main()
{
    int i, greenTime;
    int normalTime = 30;
    int emergencyTime = 0;

    printf("=============================================\n");
    printf(" SMART EMERGENCY GREEN CORRIDOR SYSTEM\n");
    printf("=============================================\n");

    printf("\n🚑 Emergency Ambulance Detected!");
    printf("\n📍 GPS Route Identified\n");

    sendHospitalAlert();

    printf("\n---------------------------------------------\n");
    printf(" Activating Green Corridor\n");
    printf("---------------------------------------------\n");

    for (i = 0; i < JUNCTIONS; i++)
    {
        if (!route[i])
            continue;

        if (accident[i])
        {
            printf("\n⚠️ Junction %d : Accident Zone – REROUTED\n", i + 1);
            continue;
        }

        if (density[i] == 1)
            greenTime = 4;
        else if (density[i] == 2)
            greenTime = 6;
        else
            greenTime = 8;

        printf("\n🟢 Junction %d : GREEN (Ambulance Direction)\n", i + 1);
        printf("🔴 Cross Roads : RED\n");

        countdown(greenTime);

        printf("✅ Ambulance Cleared Junction %d\n", i + 1);

        emergencyTime += greenTime;
        sleep(1);
    }

    printf("\n---------------------------------------------\n");
    printf("🏥 Ambulance Reached Hospital Safely!\n");

    printf("⏱️ Total Time Saved : %d seconds\n",
           normalTime - emergencyTime);

    printf("🚦 Normal Traffic Restored\n");
    printf("=============================================\n");

    return 0;
}

