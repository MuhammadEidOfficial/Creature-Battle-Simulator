#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"


struct PIRE{
   Bocek super;
   
   void (*yoket)(struct PIRE*);
};

typedef struct PIRE* Pire;

Canli PireOlustur(int deger);
const char* PireGorunum(struct CANLI*);
void PireYoket(const Pire);

#endif