#include "Pire.h"
  

Canli PireOlustur(int deger) {
    Pire this = (Pire)malloc(sizeof(struct PIRE));
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
    this->super->super = CanliOlustur(deger, "P");
    this->super->super->pire = this;
    this->super->super->gorunum = &PireGorunum; 
    this->yoket = &PireYoket;

    return (Canli)this->super->super;
}


const char* PireGorunum(struct CANLI* canli) {
    return "P";
}

void PireYoket(const Pire this) {
    if (this == NULL) return;
    this->super->super->yoket(this->super->super);
    free(this);
}

