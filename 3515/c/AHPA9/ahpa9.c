#include <stdio.h>
#include <stdlib.h>

struct fuelPump {
    char name[8];
    int capacity;
    int fuel;
};

void carArrived(struct fuelPump *pump);
void refillRequest(struct fuelPump *pump);

int main(void) {
    struct fuelPump pump1 = {"Pump #1", 100, 100};
    struct fuelPump pump2 = {"Pump #2", 75, 75};
    struct fuelPump pump3 = {"Pump #3", 50, 50};
    struct fuelPump pump4 = {"Pump #4", 150, 150};
    struct fuelPump pumps[4] = {pump1, pump2, pump3, pump4};

    for (;;) {
        int pumpSelected;
        char whichPump[3];
        printf("Welcome to 8/12! Please select a pump (1-4): ");
        pumpSelected = strtol(fgets(whichPump, 3, stdin), nullptr, 10);
        switch (pumpSelected) {
            case 1:
                carArrived(&pumps[0]);
                break;
            case 2:
                carArrived(&pumps[1]);
                break;
            case 3:
                carArrived(&pumps[2]);
                break;
            case 4:
                carArrived(&pumps[3]);
                break;
            default:
                printf(".....Pump #%d does not exist\n\n", pumpSelected);
        }

        for (int i = 0; i < 4; i++) {
            printf("%s:\n\tCapacity: %d\n\tFuel Remaining: %d\n\n", pumps[i].name, pumps[i].capacity, pumps[i].fuel);
        }
        for (int i = 0; i < 4; i++) {
            if (pumps[i].fuel < 20) {
                printf("%s is low, pending refill\n", pumps[i].name);
                refillRequest(&pumps[i]);
            }
        }
        char leave[3];
        int leaveLoop;
        printf("Leave 8/12? (Y/N): ");
        fgets(leave, sizeof leave, stdin);
        for (;;) {
            if (leave[0] == 'Y' || leave[0] == 'y') {
                printf("Please come back soon!\n");
                leaveLoop = 1;
                break;
            }
            else if (leave[0] == 'N' || leave[0] == 'n') {
                leaveLoop = 0;
                break;
            }
            else {
                printf("Y OR N\n");
            }
        }
        if (leaveLoop == 1) {
            break;
        }
    }
}

void carArrived(struct fuelPump *pump) {
    printf("Thank you for using %s!\n10 Gallons removed from %s\n\n", pump->name, pump->name);
    pump->fuel -= 10;
}

void refillRequest(struct fuelPump *pump) {
    printf("%s has been refilled!\n\n", pump->name);
    pump->fuel = pump->capacity;
}