////////////////////////////////////////////////////////
//													  //
//             T.C. SAKARYA ÜNİVERSİTESİ              //
//      BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ     //
//           BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ           //
//    PROGRAMLAMA DİLLERİNİN PRENSİPLERİ ÖDEV RAPORU  //
//                      2.ÖDEV                        //
//                                                    //
//            Muhammed İyd - B211210569               //
//                1.Öğretim B grup                    //
//                                                    //
//         muhamad.iyd1@ogr.sakarya.edu.tr            //
//     Programın yazıldığı tarih: <08.05.2024>        //
//													  //
////////////////////////////////////////////////////////


#include "Bitki.h"
#include <stdio.h>
#include <stdlib.h>
#include "Canli.h"
#include "Bocek.h"
#include "Pire.h"
#include "Sinek.h"
#include "Habitat.h"
#include <conio.h>

Canli** dosyaOkuVeDoldur(char* dosyaAdi, int *rows, int *cols);

int main() {

    int rows, cols;
    Canli** canlilar = dosyaOkuVeDoldur("Veri.txt", &rows, &cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
          printf("%s " ,canlilar[i][j]->gorunum(canlilar[i][j]));
        
        printf("\n");
    }

    printf("%s", "\n\n\nLutfen herhangi bir tusa basiniz:");
    getch();
    Habitat program = HabitatOlustur(canlilar, rows, cols);
    program->islemlerYap(program);
    program->yoket(program);

    return 0;
}


Canli** dosyaOkuVeDoldur(char* dosyaAdi, int *rows, int *cols) {
    FILE *file;
    int temp;
    *rows = 0;
    *cols = 0;

    
    file = fopen(dosyaAdi, "r");
    if (file == NULL) {
        perror("Dosya acilirken hata olustu");
        return NULL; 
    }

    char ch;
    while (!feof(file)) {
        if (fscanf(file, "%d", &temp) == 1) {
            if (*rows == 0) (*cols)++;
        }
        ch = fgetc(file);
        if (ch == '\n') (*rows)++;
    }
    if (ch != '\n') { 
        (*rows)++;
    }

    rewind(file);
  
    Canli** creatures = (Canli**) malloc((*rows) * sizeof(Canli*));
    for (int i = 0; i < (*rows); i++) {
        creatures[i] = (Canli*) malloc((*cols) * sizeof(Canli));
    }

    for (int i = 0; i < (*rows); i++) {
        for (int j = 0; j < (*cols); j++) {
            fscanf(file, "%d", &temp);
            if (temp >= 1 && temp <= 9) {
                creatures[i][j] = BitkiOlustur(temp);
            } else if (temp >= 10 && temp <= 20) {
                creatures[i][j] = BocekOlustur(temp);
            } else if (temp >= 21 && temp <= 50) {
                creatures[i][j] = SinekOlustur(temp);
            } else if (temp >= 51 && temp <= 99) {
                creatures[i][j] = PireOlustur(temp);
            } else {
                creatures[i][j] = NULL;
            }
        }
    }

    fclose(file);
    return creatures;
}