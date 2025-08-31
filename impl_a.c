#include <stdio.h>
#include <stdlib.h>
#include "impl_a.h"

void ImplA_init(void* self) {
    ImplA* obj = (ImplA*)self;

    obj->secret = rand() % 100;
}

void ImplA_process(void* self, int input) {
    ImplA* obj = (ImplA*)self;
}

void ImplA_destroy(void* self) {
    ImplA* obj = (ImplA*)self;

    obj->secret = 0;
}