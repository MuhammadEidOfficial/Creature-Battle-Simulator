#include "Bitki.h"
#include <stdlib.h>

Canli BitkiOlustur(int deger) {
    Bitki this = (Bitki)malloc(sizeof(struct BITKI));
    if (this == NULL) {
        perror("Bellek ayirma islemi basarisiz oldu");
        return NULL;
    }
    this->super = CanliOlustur(deger, "B");
    this->super->bitki = this;
    this->super->gorunum = &BitkiGorunum; 
    this->yoket = &BitkiYoket;

    return this->super;
}

const char* BitkiGorunum(struct CANLI* super) {
    return "B"; 
}

void BitkiYoket(const Bitki this) {
    if (this == NULL) return;
    this->super->yoket(this->super); 
    free(this); 
}