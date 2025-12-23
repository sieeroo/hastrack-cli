#include "hastrack.h"
#include "feature.h"
#include "user.h"

void save_data() {
    FILE *fileuser = fopen("savedatauser.txt", "w");
    if (!fileuser) {
        printf("Error, cannot save data!\n");
        return;
    }

    fprintf(fileuser, "User:%s\n", user.username);
    fprintf(fileuser, "ActivityCount:%d\n", activityCount);

    for (int i = 0; i < activityCount; i++) {
        fprintf(fileuser, "Activity:%s\n", features[i].activityname);
        fprintf(fileuser, "TargetDate:%s\n", features[i].targetdate);
        fprintf(fileuser, "Description:%s\n", features[i].taskdescription);
        fprintf(fileuser, "Progress:%d\n", features[i].percentageprogress);
        fprintf(fileuser, "Status:%s\n", features[i].changestatus);
        fprintf(fileuser, "Time:%s\n", features[i].time);
        fprintf(fileuser, "StatusBit:%d\n", features[i].statusbit);
    }

    fclose(fileuser);
    printf("Data saved successfully!\n");
}

void load_data() {
    FILE *f = fopen("savedatauser.txt", "r");
    if (f == NULL) {
        printf("SOrry, no saved data found. Starting new program...\n");
        return;
    }

    char buffer[1024];
    int idx = -1;

    while (fgets(buffer, sizeof(buffer), f)) {
        buffer[strcspn(buffer, "\n")] = 0;

        if (strncmp(buffer, "User:", 5) == 0) {
            if(strlen(buffer + 5) < 50) {
                strcpy(user.username, buffer + 5);
            }
        }
        else if (strncmp(buffer, "ActivityCount:", 14) == 0) {
            activityCount = atoi(buffer + 14);
        }
        else if (strncmp(buffer, "Activity:", 9) == 0) {
            idx++;
            if (idx >= MAX_ACTIVITIES) break;
            strcpy(features[idx].activityname, buffer + 9);
        }
        else if (strncmp(buffer, "TargetDate:", 11) == 0) {
            strcpy(features[idx].targetdate, buffer + 11);
        }
        else if (strncmp(buffer, "Description:", 12) == 0) {
            strcpy(features[idx].taskdescription, buffer + 12);
        }
        else if (strncmp(buffer, "Progress:", 9) == 0) {
            features[idx].percentageprogress = atoi(buffer + 9);
        }
        else if (strncmp(buffer, "Status:", 7) == 0) {
            strcpy(features[idx].changestatus, buffer + 7);
        }
        else if (strncmp(buffer, "Time:", 5) == 0) {
            strcpy(features[idx].time, buffer + 5);
        }
        else if (strncmp(buffer, "StatusBit:", 10) == 0) {
            features[idx].statusbit = atoi(buffer + 10);
        }
    }

    fclose(f);
    printf("Data loaded successfully! %d activities found...\n", activityCount);
}