#include "Sinek.h"

Canli SinekOlustur(int deger) {
    Sinek this = (Sinek)malloc(sizeof(struct SINEK));
    if (this == NULL) {
        perror("Bellek ayirma islemi basarisiz oldu");
        return NULL;
    }
    this->super = (Bocek)malloc(sizeof(struct BOCEK));
    if (this->super == NULL) {
        perror("Bellek ayirma islemi basarisiz oldu");
        free(this);
        return NULL;
    }
    this->super->super = CanliOlustur(deger, "S");
    this->super->super->sinek = this;
    this->super->super->gorunum = &SinekGorunum; 
    this->yoket = &SinekYoket;

    return (Canli)this->super->super;
}

const char* SinekGorunum(struct CANLI* canli) {
    return "S";
}

void SinekYoket(const Sinek this) {
    if (this == NULL) return;
    this->super->super->yoket(this->super->super);
    free(this);
}

