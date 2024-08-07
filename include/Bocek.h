#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK{
    Canli super;

    void (*yoket)(struct BOCEK*);
};

typedef struct BOCEK* Bocek;

Canli BocekOlustur(int deger);
const char* BocekGorunum(struct CANLI*);
void BocekYoket(const Bocek);

#endif