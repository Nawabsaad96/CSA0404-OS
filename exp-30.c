#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat st;
    stat("sample.txt", &st);
    printf("Permissions: ");
    printf((st.st_mode & S_IRUSR) ? "r" : "-");
    printf((st.st_mode & S_IWUSR) ? "w" : "-");
    printf((st.st_mode & S_IXUSR) ? "x" : "-");
    printf("\n");

    return 0;
}
