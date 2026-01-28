#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    struct stat fileStat;
    struct dirent *de;
    DIR *dr;

    stat("sample.txt", &fileStat);
    printf("File Size: %ld bytes\n", fileStat.st_size);

    int fd = open("sample.txt", O_RDONLY);
    printf("File Descriptor: %d\n", fd);

    lseek(fd, 5, SEEK_SET);

    dr = opendir(".");
    printf("\nDirectory contents:\n");
    while ((de = readdir(dr)) != NULL) {
        printf("%s\n", de->d_name);
    }

    closedir(dr);
    close(fd);
    return 0;
}
