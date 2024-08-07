#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK {
    Bocek super;

    void (*yoket)(struct SINEK*);
};

typedef struct SINEK* Sinek;

Canli SinekOlustur(int deger);
const char* SinekGorunum(struct CANLI*);
void SinekYoket(const Sinek);

#endif