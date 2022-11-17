#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1

void debug(char* message) {
    if(DEBUG)
        printf("%s", message);
}