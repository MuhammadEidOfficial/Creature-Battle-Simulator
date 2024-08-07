#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI {
    Canli super;

    void (*yoket)(struct BITKI*);
};

typedef struct BITKI* Bitki;

Canli BitkiOlustur(int deger);
const char* BitkiGorunum(struct CANLI*);
void BitkiYoket(const Bitki);

#endif