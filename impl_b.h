#ifndef IMPL_B_H
#define IMPL_B_H

#include "object.h"

typedef struct ImplB {
    int code;
} ImplB;

void ImplB_init(void* self);
void ImplB_process(void* self, int input);
void ImplB_destroy(void* self);

#endif // IMPL_B_H