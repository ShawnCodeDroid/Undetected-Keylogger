#include <stdio.h>

void junkC() {
    volatile int junk = 0;

    for (int i = 0; i < 100; i++) {
        junk += i;
        if (junk % 7 == 3) {
            junk -= 2;
        }
    }
}