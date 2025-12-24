#ifndef HASTRACK_H
#define HASTRACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ACTIVITIES 20 

#define STATUS_NOT_STARTED 1
#define STATUS_IN_PROGRESS 2
#define STATUS_DONE 4

enum menuOptions {
    eToDoList = 1,
    eViewActivity,
    eRecent,
    eExit
};

enum activityMenuOptions {
    eSeeDetail = 1,
    eChangeStatus,
    eBack
};


#endif
