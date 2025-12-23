#include "hastrack.h"
#include "user.h"
#include "feature.h"
#include "handlefile.h"

void main_menu() {
    int userChoice;

    while (1) {
        welcome_player();
        printf("Menu Options:\n");
        printf("1. To Do List\n");
        printf("2. View Activity\n");
        printf("3. View Recent\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        
        if (scanf("%d", &userChoice) != 1) {
            printf("Sorry, input invalid! please enter a number..\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        if (userChoice < eToDoList || userChoice > eExit) {
            printf("Sorry, input invalid! choose 1-4..\n");
            continue;
        }

        if (userChoice == eToDoList) {
            to_do_list();
        }
        else if (userChoice == eViewActivity) { 
            view_activity();
        }
        else if (userChoice == eRecent) {
            show_stack_view();
        }
        else if (userChoice == eExit) {
            save_data();
            printf("\nThank you for using 'HASTRACK'!\n");
            printf("Goodbye, %s!\n", user.username);
            return;
        }
    }
}