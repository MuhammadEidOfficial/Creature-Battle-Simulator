#include "Canli.h"
#include "string.h"

Canli CanliOlustur(int deger, char* harf) {
    Canli this;
    this = (Canli)malloc(sizeof(struct CANLI));
    if (this == NULL) {
        perror("Bellek ayirma islemi basarisiz oldu");
        return NULL;
    }
    this->deger = deger;
    this->harf = harf;

    this->bitki = NULL;
    this->bocek = NULL;
    this->pire = NULL;
    this->sinek = NULL;

    this->gorunum = &CanliGorunum;
    this->yoket = &CanliYoket;

    return this;
}

const char* CanliGorunum(struct CANLI* this) {
    return this->harf;
}

void CanliYoket(struct CANLI* this) {
    if (this == NULL) return;
    free(this);
}