#ifndef CANLI_H
#define CANLI_H

#include "Canli.h"
#include <stdio.h>
#include <stdlib.h>

// Kullanilan diger turler icin ileri bildirimler....
struct BITKI;
struct BOCEK;
struct PIRE;
struct SINEK;

struct CANLI {
    char* harf;
    int deger;
    struct BITKI* bitki;
    struct BOCEK* bocek;
    struct PIRE* pire;
    struct SINEK* sinek;
    
    
    const char* (*gorunum)(struct CANLI*);
    void (*yoket)(struct CANLI*);
};

typedef struct CANLI* Canli;

Canli CanliOlustur(int, char*);
const char* CanliGorunum(struct CANLI*); 
void CanliYoket(struct CANLI*);

#endif
