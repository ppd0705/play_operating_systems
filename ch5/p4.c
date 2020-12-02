#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int)getpid());


    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        close(STDOUT_FILENO);
        open("./p4.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
        printf("hi\n");
        char *myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("p3.c");
        myargs[0] = NULL;
        execvp(myargs[0], myargs);
        printf("this should't print out");
    } else {
        int wc = wait(NULL);
        printf("hello, I am parent of %d (pid:%d)\n", wc, (int)(getpid()));
    }
    return 0;
}