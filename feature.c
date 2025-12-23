#include "hastrack.h"
#include "feature.h"
#include "user.h"
#include "handlefile.h"

Feature *features;
int activityCount = 0;

void update_progress(int *progress) {
    int temp;
    while(1) {
        if(scanf("%d", &temp) != 1) {
            printf("Invalid input! Enter number 0-100: ");
            clear_input_buffer();
            continue;
        }
        if(temp >= 0 && temp <= 100) {
            *progress = temp;
            clear_input_buffer();
            return;
        }
        printf("Progress must be 0-100! Try again : ");
        clear_input_buffer();
    }
}

void to_do_list() {
    printf("\n==============================================\n");
    printf("=               To Do List Menu              =\n");
    printf("==============================================\n");

    if (activityCount >= MAX_ACTIVITIES) {
        printf("Sorry, maximum activities reached!\n");
        return;
    }

    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(features[activityCount].time, 30, "%d-%m-%Y %H:%M", timeinfo);

    printf("Enter your task (input 0, back to menu): ");
    fgets(features[activityCount].activityname, 100, stdin);
    features[activityCount].activityname[strcspn(features[activityCount].activityname, "\n")] = 0;

    if (strcmp(features[activityCount].activityname, "0") == 0) {
        printf(">> Returning to menu...\n");
        return;
    }

    printf("Description: ");
    fgets(features[activityCount].taskdescription, 1000, stdin);
    features[activityCount].taskdescription[strcspn(features[activityCount].taskdescription, "\n")] = 0;

    printf("Target date: ");
    fgets(features[activityCount].targetdate, 20, stdin);
    features[activityCount].targetdate[strcspn(features[activityCount].targetdate, "\n")] = 0;

    features[activityCount].percentageprogress = 0;
    features[activityCount].statusbit = STATUS_NOT_STARTED;
    strcpy(features[activityCount].changestatus, "Not Started");

    activityCount++;
    save_data();
}

void view_activity() {
    if (activityCount == 0) {
        printf("Sorry, no activities found. Add some activities from To Do List Menu...\n");
        return;
    }
    
    printf("\n==============================================\n");
    printf("=                Activity Menu               =\n");
    printf("==============================================\n");
    
    printf("%-5s %-25s %-15s\n", "No.", "Activity Name", "Target Date");
    printf("-----------------------------------------------\n");
    
    for (int i = 0; i < activityCount; i++) {
        printf("%-5d %-25s %-15s\n", i + 1,
               features[i].activityname,
               features[i].targetdate);
    }

    activity_menu();
}

void activity_menu() {
    int userChoiceActivityMenu;
    int activityNumber;
    int index;

    while(1) {
        printf("\nMenu Options :\n");
        printf("1. View Task Details\n");
        printf("2. Change Status\n");
        printf("3. Back\n");
        printf("Your option : ");

        if(scanf("%d", &userChoiceActivityMenu) != 1) {
            printf("Invalid input! please enter a number!\n");
            clear_input_buffer();
            continue;
        }
        
        if (userChoiceActivityMenu == eBack) {
            printf(">> Returning to menu...\n");
            return;
        }

        printf("Activity number: ");
        if(scanf("%d", &activityNumber) != 1) {
            printf("Invalid input!\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        if (activityNumber < 1 || activityNumber > activityCount) {
            printf("Sorry, activity not found...\n");
            continue;
        }
        
        index = activityNumber - 1;

        switch (userChoiceActivityMenu) {
            case eSeeDetail: 
                printf("-----------------\n");
                printf("Activity Details:\n");
                printf("-----------------\n");
                printf("Activity Name       : %s\n", features[index].activityname);
                printf("Target Date         : %s\n", features[index].targetdate);
                printf("Description         : %s\n", features[index].taskdescription);
                printf("Progress            : %d%%\n", features[index].percentageprogress);
                printf("Status              : %s\n", features[index].changestatus);
                break;
            
            case eChangeStatus:
                printf("-----------------\n");
                printf("  Change Status\n");
                printf("-----------------\n");
                printf("\nCurrent Status: %s\n", features[index].changestatus);
                printf("New Status Options:\n");
                printf("1. Not Started\n");
                printf("2. In Progress\n");
                printf("3. Done\n");
                printf("Choose status (input 0, back to menu): ");
                
                int statusChoice;
                if (scanf("%d", &statusChoice) != 1) {
                    printf("Input isn't valid, only number\n");
                    clear_input_buffer();
                    continue;
                }

                if (statusChoice == 0) {
                    printf(">> Returning to menu...\n");
                    return;
                }
            
                clear_input_buffer();

                features[index].statusbit = 0;

                switch (statusChoice) {
                    case 1:
                        features[index].statusbit = STATUS_NOT_STARTED;
                        features[index].percentageprogress = 0;
                        strcpy(features[index].changestatus, "Not Started");
                        break;
                    case 2:
                        features[index].statusbit = STATUS_IN_PROGRESS;
                        strcpy(features[index].changestatus, "In Progress");
                        printf("Progress (0-100): ");
                        update_progress(&features[index].percentageprogress); 
                        break;
                    case 3:
                        features[index].statusbit = STATUS_DONE;
                        features[index].percentageprogress = 100;
                        strcpy(features[index].changestatus, "Done");
                        printf("Task completed!\n");
                        break;
                    default:
                        printf("Invalid choice! Status not changed.\n");
                        continue;
                }
                printf("Status updated successfully!\n");
                save_data();
                break;
                
            default:
                printf("Invalid option! Please choose 1-3.\n");
                break;
        }
    }
}

void show_stack_view() {
    printf("\n==============================================\n");
    printf("=                Stack Activity              =\n");
    printf("==============================================\n");
    if (activityCount == 0) {
        printf("No activities..\n");
        return;
    }

    printf("\n");
    printf("%-5s %-28s %-6s\n", "No.", "Activity Name", "Added");
    
    for (int i = activityCount - 1; i >= 0; i--) {
        printf("[%d]   %-25s %-6s\n", i + 1, features[i].activityname, features[i].time);
    }
    printf("---------------------------------------\n");
}