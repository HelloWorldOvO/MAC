#include <stdio.h>
#include <fcntl.h>

#define FILE "str.txt"


int main(){
    int fd;
    int ret;
    fd = open(FILE, O_RDWR);
    ret = flock(fd, LOCK_EX);

    printf("hello\n");

    getchar();
    ret = flock(fd, LOCK_UN);


    return 0;
}