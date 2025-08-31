#ifndef IMPL_A_H
#define IMPL_A_H

#include "object.h"

typedef struct ImplA {
    int secret;
} ImplA;

void ImplA_init(void* self);
void ImplA_process(void* self, int input);
void ImplA_destroy(void* self);

#endif // IMPL_A_H
