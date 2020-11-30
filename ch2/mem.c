#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"


int main(int argc, char *argv[]) {
    int *p = malloc(sizeof(int));
    assert(p != NULL);

    printf("(%d) memory address of p: %08x\n", getpid(), (
            unsigned) p);

    *p = 0;
    while(1) {
        Spin(1);
        (*p)++;
        printf("(%d) p: %d\n", getpid(), *p);
    }
}