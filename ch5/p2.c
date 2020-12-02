#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int)getpid());


    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
    } else if (rc == 0) {
        printf("hello, I am chid (pid:%d)\n", (int)getpid());
    } else {
        int wc = wait(NULL);
        printf("hello, I am parent of %d (pid:%d)\n", wc, (int)(getpid()));
    }
    return 0;
}