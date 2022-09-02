#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


int main(){
    int fd = open("./sample_text",O_RDONLY);
    char buf[100];
    int size;

    if(fd < 0){
        fprintf(stderr,"Error Opening: %s",strerror(errno));
        exit(1);
    }
    while(1){
        size = read(fd,buf,sizeof(buf));
        if(size == 0) break;
        printf("%s",buf);
    }
    close(fd);
    return EXIT_SUCCESS;
}