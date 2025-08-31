#ifndef OBJECT_H
#define OBJECT_H

#include <stdio.h>

typedef struct {
    void (*init)(void*);
    void (*process)(void*, int);
    void (*destroy)(void*);
} VTable;

typedef struct {
    VTable* vtable;
    void* data;
} Object;

Object* create_object(int type);
void destroy_object(Object* obj);

#endif