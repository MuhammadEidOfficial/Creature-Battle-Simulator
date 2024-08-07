#ifndef HABITAT_H
#define HABITAT_H

#include "Canli.h"
#include <stdio.h>


struct HABITAT {
    Canli kazanan;
    Canli** grid;
    int satir;
    int sutun;
    int eksenX;
    int eksenY;

    void (*islemlerYap)(struct HABITAT*);
    void (*yazdir)(struct HABITAT*, int);
    void (*yoket)(struct HABITAT*);
};

typedef struct HABITAT* Habitat;

Habitat HabitatOlustur(Canli**, int, int);
void HabitatIslemlerYap(struct HABITAT*);
void HabitatYazdir(struct HABITAT*, int);
void HabitatYoket(struct HABITAT*);

#endif