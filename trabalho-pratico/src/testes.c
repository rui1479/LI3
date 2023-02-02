#include <stdio.h>
#include "testes/testaqueries.c"

int main (int argc, char* argv[]){

        if (argc != 2) {
            printf("Erro!");
        }

        char *usersfile = malloc(strlen(argv[1])+strlen("users.csv")+10000);
            strcpy(usersfile,argv[1]);
            strcat(usersfile,"/users.csv");

        char *driversfile= malloc(strlen(argv[1])+strlen("drivers.csv")+10000);
            strcpy(driversfile,argv[1]);
            strcat(driversfile,"/drivers.csv");

        char *ridesfile = malloc(strlen(argv[1])+strlen("rides.csv")+10000);
            strcpy(ridesfile,argv[1]);
            strcat(ridesfile,"/rides.csv");
        
        FILE* fileUser = fopen(usersfile,"r");
        FILE* fileDriver = fopen(driversfile,"r");
        FILE* fileRides = fopen(ridesfile,"r");
        
        Catalogos catalogos = carregaCatalogos(fileUser,fileDriver,fileRides);

        testequery1(catalogos);
        testequery2(catalogos);
        testequery3(catalogos);
        testequery4(catalogos);
        testequery5(catalogos);
        testequery6(catalogos);
        testequery7(catalogos);
        testequery8(catalogos);
        testequery9(catalogos);

    return 0;
}