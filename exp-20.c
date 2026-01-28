#include <stdio.h>
#include <string.h>

int main() {
    char user[10][20], files[10][10][20];
    int users, filesCount[10];
    int i, j;

    printf("Enter number of users: ");
    scanf("%d", &users);

    for(i = 0; i < users; i++) {
        printf("\nEnter user name: ");
        scanf("%s", user[i]);

        printf("Enter number of files for %s: ", user[i]);
        scanf("%d", &filesCount[i]);

        printf("Enter file names:\n");
        for(j = 0; j < filesCount[i]; j++) {
            scanf("%s", files[i][j]);
        }
    }

    printf("\nTwo Level Directory Structure:\n");
    for(i = 0; i < users; i++) {
        printf("\nUser Directory: %s\n", user[i]);
        for(j = 0; j < filesCount[i]; j++) {
            printf("  %s\n", files[i][j]);
        }
    }

    return 0;
}
