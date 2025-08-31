#include <stdlib.h>
#include "object.h"
#include "impl_a.h"
#include "impl_b.h"

static VTable vtableA = { ImplA_init, ImplA_process, ImplA_destroy };
static VTable vtableB = { ImplB_init, ImplB_process, ImplB_destroy };

Object* create_object(int type) {
    Object* obj = malloc(sizeof(Object));

    if (!obj) {
        exit(1);
    }

    switch (type) {
    case 0: {
        ImplA* a = malloc(sizeof(ImplA));

        if (!a) {
            exit(1);
        }

        obj->vtable = &vtableA;
        obj->data = a;
        break;
    }
    case 1: {
        ImplB* b = malloc(sizeof(ImplB));

        if (!b) {
            exit(1);
        }

        obj->vtable = &vtableB;
        obj->data = b;
        break;
    }
    default:
        free(obj);
        return NULL;
    }
    obj->vtable->init(obj->data);

    return obj;
}

void destroy_object(Object* obj) {
    if (!obj) {
        return;
    }

    obj->vtable->destroy(obj->data);
    free(obj->data);
    free(obj);
}