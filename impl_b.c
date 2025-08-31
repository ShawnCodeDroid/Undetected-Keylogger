#include <stdio.h>
#include <stdlib.h>
#include "impl_b.h"

void ImplB_init(void* self) {
    ImplB* obj = (ImplB*)self;

    obj->code = rand() % 50 + 50;
}

void ImplB_process(void* self, int input) {
    ImplB* obj = (ImplB*)self;
}

void ImplB_destroy(void* self) {
    ImplB* obj = (ImplB*)self;

    obj->code = 0;
}