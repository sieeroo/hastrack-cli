#include "hastrack.h"
#include "user.h"
#include "handlefile.h"

User user;

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void welcome_player() {
    printf("\n===============================================\n");
    printf("=                ! WELCOME TO !               =\n");
    printf("=                 ' HASTRACK '                =\n");
    printf("===============================================\n");
    printf("~~ heloo, %s\n", user.username);
}

void user_login() {
    char choice;
    char temp_buffer[100];

    printf("Enter your username: ");
    fgets(temp_buffer, sizeof(temp_buffer), stdin);
    temp_buffer[strcspn(temp_buffer, "\n")] = 0;
    
    if(strlen(temp_buffer) >= 50) {
        temp_buffer[49] = '\0';
        printf("Sorry, username wil be shortened to 49 character...\n");
    }
    
    strcpy(user.username, temp_buffer);

    printf("Want to reload your previous data? (y/n): ");
    if(scanf(" %c", &choice) != 1) {
        choice = 'n';
    }
    clear_input_buffer();

    if (choice == 'y' || choice == 'Y') {
        load_data();
    }
}