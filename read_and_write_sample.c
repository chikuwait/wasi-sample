#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv){
    if (argc != 3){
        fprintf(stderr,"missing argments");
        exit(1);
    }

    int fd_in = open(argv[1],O_RDONLY);
    if (fd_in < 0){
        fprintf(stderr,"Error Opening Input: %s",strerror(errno));
    }

    int fd_out = open(argv[2], O_WRONLY | O_CREAT, 0660); 
    if (fd_out < 0){
        fprintf(stderr,"Error Opening Output: %s",strerror(errno));
    }
    while(1){
        char buf[1];
        int rsize = read(fd_in,buf,sizeof(buf));
        if (rsize < 0){
            break; 
        }

        int  wsize = write(fd_out,buf,(size_t)rsize);
        if (wsize < 0){
            fprintf(stderr,"Write Error: %s",strerror(errno));
            exit(1);
        }
    }

    return EXIT_SUCCESS;
}