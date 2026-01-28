#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    write(fd, "UNIX File Management\n", 22);

    lseek(fd, 0, SEEK_SET);
    read(fd, buffer, 22);

    write(1, buffer, 22);   // stdout

    close(fd);
    return 0;
}
