#ifndef FEATURE_H
#define FEATURE_H

typedef struct {
    char activityname[100];
    char targetdate[20];
    int percentageprogress;
    char changestatus[20];
    char taskdescription[1000];
    int statusbit;
    char time[30];
} Feature;

// External declarations
extern Feature *features;
extern int activityCount;

// Function prototypes
void to_do_list();
void view_activity();
void activity_menu();
void show_stack_view();
void update_progress(int *progress); 

#endif