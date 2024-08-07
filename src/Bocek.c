#include "Bocek.h"

Canli BocekOlustur(int deger) {
    Bocek this = (Bocek)malloc(sizeof(struct BOCEK));
    if (this == NULL) {
        perror("Bellek ayirma islemi basarisiz oldu");
        return NULL;
    }
    this->super = CanliOlustur(deger, "C");
    this->super->bocek = this;
    this->super->gorunum = &BocekGorunum; 
    this->yoket = &BocekYoket;

    return this->super;
}

const char* BocekGorunum(struct CANLI* super) {
    return "C";
}

void BocekYoket(const Bocek this) {
    if (this == NULL) return;
    this->super->yoket(this->super); 
    free(this); 
}