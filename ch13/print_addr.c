#include <stdlib.h>
#include <stdio.h>


int  main(int argc, char *argv[]) {
    printf("location of code:  %p\n", (void *) main);
    printf("location of heap:  %p\n", (void *) malloc(64));
    int  x  = 1;
    printf("location of stack:  %p\n", (void *)&x);
    return 0;
}