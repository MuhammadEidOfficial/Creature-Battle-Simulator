#include "Habitat.h"
#include "Pire.h"
#include "Sinek.h"
#include "Bitki.h"
#include "Bocek.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <windows.h>

Habitat HabitatOlustur(Canli** canlilar, int satir, int sutun) {
    Habitat this;
    this = (Habitat)malloc(sizeof(struct HABITAT));
    this->grid = canlilar;
    this->satir = satir;
    this->sutun = sutun;
    this->kazanan = NULL;
    this->eksenX = 0;
    this->eksenY = 0;

    this->islemlerYap = &HabitatIslemlerYap;
    this->yazdir = &HabitatYazdir;
    this->yoket = &HabitatYoket;

    return this;
}

void HabitatYazdir(struct HABITAT* this, int isFinish) {
     
    if(isFinish) {
        printf("Kazanan: %s : (%d, %d)", this->kazanan->harf, this->eksenX, this->eksenY);
        return;
    }

   // Sleep(1000);

    system("cls");
    for (int i = 0; i < this->satir; i++) {
        for (int j = 0; j < this->sutun; j++) {
            if (this->grid[i][j] == NULL)
                printf("%s ", "X");
            else 
                printf("%s ", this->grid[i][j]->gorunum(this->grid[i][j]));
        }
        printf("\n");
    }
    printf("\n");
}

const char* str;
const char* ikinciStr;
void HabitatIslemlerYap(struct HABITAT* this) {
    this->kazanan = this->grid[0][0];
    
    for (int i = 0; i < this->satir; i++) {
        for (int j = 0; j < this->sutun; j++) {
            // her durumlar bir kontrol yapiyor
            if (i == 0 && j == 0) {
                j = 1;
            }
            str = this->kazanan->gorunum(this->kazanan);
            ikinciStr = this->grid[i][j]->gorunum(this->grid[i][j]);
    
            if(strcmp(str, "B") == 0) {

                // yasanan durumu
                if(strcmp(ikinciStr, "P") == 0) {
                    this->grid[i][j]->pire->yoket(this->grid[i][j]->pire);
                    this->grid[i][j] = NULL;
                }
                else if(strcmp(ikinciStr, "S") == 0) {
                    this->grid[i][j]->sinek->yoket(this->grid[i][j]->sinek);
                    this->grid[i][j] = NULL;
                }

                // olum durumu
                else if(strcmp(ikinciStr, "C") == 0) {
                    this->grid[this->eksenX][this->eksenY]->bitki->yoket(this->grid[this->eksenX][this->eksenY]->bitki);
                    this->grid[this->eksenX][this->eksenY] = NULL;
                    this->eksenX = i;
                    this->eksenY = j;
                    this->kazanan = this->grid[i][j];
                }

                // ayni harf durumu
                else {
                    if(this->kazanan->deger > this->grid[i][j]->deger) {
                        this->grid[i][j]->bitki->yoket(this->grid[i][j]->bitki);
                        this->grid[i][j] = NULL;
                    }
                        
                    else if(this->kazanan->deger < this->grid[i][j]->deger) {
                        this->grid[this->eksenX][this->eksenY]->bitki->yoket(this->grid[this->eksenX][this->eksenY]->bitki);
                        this->grid[this->eksenX][this->eksenY] = NULL;
                        this->eksenX = i;
                        this->eksenY = j;
                        this->kazanan = this->grid[i][j];
                    }
                    else {
                        this->grid[i][j]->bitki->yoket(this->grid[i][j]->bitki);
                        this->grid[i][j] = NULL;
                    }    
                }
            }

            else if(strcmp(str, "C") == 0) {
                
                // yasanan durumu
                if(strcmp(ikinciStr, "B") == 0) {
                    this->grid[i][j]->bitki->yoket(this->grid[i][j]->bitki);
                    this->grid[i][j] = NULL;
                }
                else if(strcmp(ikinciStr, "P") == 0) {
                    this->grid[i][j]->pire->yoket(this->grid[i][j]->pire);
                    this->grid[i][j] = NULL;
                }

                // olum durumu
                else if (strcmp(ikinciStr, "S") == 0) {
                    this->grid[this->eksenX][this->eksenY]->bocek->yoket(this->grid[this->eksenX][this->eksenY]->bocek);
                    this->grid[this->eksenX][this->eksenY] = NULL;
                    this->eksenX = i;
                    this->eksenY = j;
                    this->kazanan = this->grid[i][j];
                }

                // ayni harf durumu
                else {
                    if(this->kazanan->deger > this->grid[i][j]->deger) {
                        this->grid[i][j]->bocek->yoket(this->grid[i][j]->bocek);
                        this->grid[i][j] = NULL;
                    }
                    else if(this->kazanan->deger < this->grid[i][j]->deger) {
                        this->grid[this->eksenX][this->eksenY]->bocek->yoket(this->grid[this->eksenX][this->eksenY]->bocek);
                        this->grid[this->eksenX][this->eksenY] = NULL;
                        this->eksenX = i;
                        this->eksenY = j;
                        this->kazanan = this->grid[i][j];
                    }
                    else {
                        this->grid[i][j]->bocek->yoket(this->grid[i][j]->bocek);
                        this->grid[i][j] = NULL;
                    }
                }
            }

            else if(strcmp(str, "S") == 0) {
                
                // yasanan durumu
                if(strcmp(ikinciStr, "P") == 0) {
                    this->grid[i][j]->pire->yoket(this->grid[i][j]->pire);
                    this->grid[i][j] = NULL; 
                }
                else if(strcmp(ikinciStr, "C") == 0) {
                    this->grid[i][j]->bocek->yoket(this->grid[i][j]->bocek);
                    this->grid[i][j] = NULL;
                }

                // olum durumu
                else if(strcmp(ikinciStr, "B") == 0) {
                    this->grid[this->eksenX][this->eksenY]->sinek->yoket(this->grid[this->eksenX][this->eksenY]->sinek);
                    this->grid[this->eksenX][this->eksenY] = NULL;
                    this->eksenX = i;
                    this->eksenY = j;
                    this->kazanan = this->grid[i][j];
                }

                // ayni harf durumu
                else {
                    if(this->kazanan->deger > this->grid[i][j]->deger) {
                        this->grid[i][j]->sinek->yoket(this->grid[i][j]->sinek);
                        this->grid[i][j] = NULL;
                    }
                    else if(this->kazanan->deger < this->grid[i][j]->deger) {
                        this->grid[this->eksenX][this->eksenY]->sinek->yoket(this->grid[this->eksenX][this->eksenY]->sinek);
                        this->grid[this->eksenX][this->eksenY] = NULL;
                        this->eksenX = i;
                        this->eksenY = j;
                        this->kazanan = this->grid[i][j];
                    }
                    else {
                        this->grid[i][j]->sinek->yoket(this->grid[i][j]->sinek);
                        this->grid[i][j] = NULL;
                    }
                }
            }
            else {
                // yasanan durumu
                if(strcmp(ikinciStr, "P") == 0) {
                    if(this->kazanan->deger > this->grid[i][j]->deger) {
                        this->grid[i][j]->pire->yoket(this->grid[i][j]->pire);
                        this->grid[i][j] = NULL;
                    }
                        
                    else if(this->kazanan->deger < this->grid[i][j]->deger) {
                        this->grid[this->eksenX][this->eksenY]->pire->yoket(this->grid[this->eksenX][this->eksenY]->pire);
                        this->grid[this->eksenX][this->eksenY] = NULL;
                        this->eksenX = i;
                        this->eksenY = j;
                        this->kazanan = this->grid[i][j];
                    }
                    else {
                        this->grid[i][j]->pire->yoket(this->grid[i][j]->pire);
                        this->grid[i][j] = NULL;
                    }    
                }
                else {
                    this->grid[this->eksenX][this->eksenY]->pire->yoket(this->grid[this->eksenX][this->eksenY]->pire);
                        this->grid[this->eksenX][this->eksenY] = NULL;
                        this->eksenX = i;
                        this->eksenY = j;
                        this->kazanan = this->grid[i][j];
                }
            }
        HabitatYazdir(this, 0);
        }
        
    }
    HabitatYazdir(this, 1);
}

void HabitatYoket(struct HABITAT* this) {
    if (this == NULL) return;
    free(this);
}