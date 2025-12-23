#ifndef USER_H
#define USER_H

typedef struct {
    char *username;
} User;

extern User user;

void clear_input_buffer();
void user_login();
void welcome_player();

#endif