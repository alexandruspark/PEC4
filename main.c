#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAXFILENAME 11+1
#define MAXMODELNAME 40+1

typedef struct {
    char model[MAXMODELNAME];
    int power;
    float consumption;
    int price;
} tCar;


int main() {

    char filename[MAXFILENAME];
    char filename2[MAXFILENAME];
    tCar car1, car2;

    int powerPriceRelation;
    int powerPriceRelation2;
    int bestCar;
    //int i;
    
    FILE* fileToRead;
    FILE* fileToRead2;
    
    // ENTRADA DE DATOS
    // pregunta por el nombre de fichero
    printf("INPUT\n");
    printf("FILENAME1?\n");    
    scanf("%12s", filename);
    printf("FILENAME2?\n");    
    scanf("%12s", filename2);

    // abre el fichero
    fileToRead = fopen(filename, "r");
    fileToRead2 = fopen(filename2, "r");
    
    // leer datos del archivo

    fscanf(fileToRead, "%40s", &car1.model);
    fscanf(fileToRead2, "%40s", &car2.model);    
    fscanf(fileToRead, "%d", &car1.power);
    fscanf(fileToRead2, "%d", &car2.power);
    fscanf(fileToRead, "%f", &car1.consumption);
    fscanf(fileToRead2, "%f", &car2.consumption);
    fscanf(fileToRead, "%d", &car1.price);
    fscanf(fileToRead2, "%d", &car2.price);       

    
    
    fclose(fileToRead);
    fclose(fileToRead2);
    
    // PROCESO DE DATOS
    // ver si los tipos de equipamiento estan por debajo del stock
    
    powerPriceRelation = (float)car1.power / (float)car2.price;
    powerPriceRelation2 = (float)car1.power / (float)car2.price;
    bestCar = 1;
    
    //si el consumo es menor
    
    if (car1.consumption < car2.consumption) {
        bestCar = 1;
    } else {
        if (car1.consumption > car2.consumption) {
            bestCar = 2;
        } else {
            // si el consumo es igual
            if (powerPriceRelation > powerPriceRelation2) {
                bestCar = 1;
            } else {
                if (powerPriceRelation < powerPriceRelation2) {
                    bestCar = 2;
                } else {
                    //si el ratio es igual= orden alfabetico
                    if (strcmp(car1.model, car2.model) <= 0) {
                        bestCar = 1;
                    } else {
                        bestCar = 2;
                    }
                }
            }
        }
    }

            
        
        
    printf("OUTPUT\n");

    if (bestCar == 1) {
        printf("THE BEST CAR IS %s\n", car1.model);
    } else {
        printf("THE BEST CAR IS %s\n", car2.model);
    }
    
    
        return 0;
}