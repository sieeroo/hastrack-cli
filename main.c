#include "hastrack.h"
#include "user.h"
#include "feature.h"
#include "handlefile.h"
#include "menu.h"

int main() {
    user.username = malloc(50 * sizeof(char));
    features = malloc(MAX_ACTIVITIES * sizeof(Feature));

    if (!user.username || !features) {
        printf("Memory allocation failed\n");
        return 1;
    }

    user.username[0] = '\0';
    
    user_login();
    main_menu();

    // Cleanup
    free(user.username);
    free(features);
    
    return 0;
}