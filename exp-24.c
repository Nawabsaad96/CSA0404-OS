#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char line[200], pattern[50];

    printf("Enter pattern to search: ");
    scanf("%s", pattern);

    fp = fopen("sample.txt", "r");

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, pattern)) {
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}
