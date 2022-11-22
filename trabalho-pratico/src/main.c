#include "../include/parse.h"
#include <string.h>
#define MAXL 1024000

/**
 * Função main do programa.
*/

int main(int argc, char* argv[]){
    printf("1\n");
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    char *usersfile = malloc(strlen(argv[1])+strlen("users.csv")+1000);
        strcpy(usersfile,argv[1]);
        strcat(usersfile,"/users.csv");
    printf("%s\n",usersfile);

    char *driversfile= malloc(strlen(argv[1])+strlen("drivers.csv")+1000);
        strcpy(driversfile,argv[1]);
        strcat(driversfile,"/drivers.csv");
    printf("%s\n",driversfile);

    char *ridesfile = malloc(strlen(argv[1])+strlen("rides.csv")+1000);
        strcpy(ridesfile,argv[1]);
        strcat(ridesfile,"/rides.csv");
    printf("%s\n",driversfile);

    FILE* fileUser = fopen(usersfile,"r");
    FILE* fileDriver = fopen(driversfile,"r");
    FILE* fileRides = fopen(ridesfile,"r");
    FILE* f = fopen(argv[2],"r");

    printf("3\n");
    CatUser catalogoUsers = parseUser(fileUser);
    printf("51\n");
    CatRides catalogoRides = parseRides(fileRides);
    printf("61\n");
    CatDriver catalogoDrivers = parseDrivers(fileDriver);
    printf("4\n");

    char buff[MAXL];
    int i = 1;
    int j = 0;

    while(fgets(buff, MAXL, f)){
        char *string = g_strdup(buff);
        char *query;
        char *arg1;
        char *arg2;
        char *arg3;
        char *arg4;
        if((query = (char*)g_strdup(strsep(&string, " ")))!= NULL){
            if((arg1 = (char*)strsep(&string, " ")) != NULL){
                if((arg2 = (char*)strsep(&string, " ")) != NULL){
                    if((arg3 = (char*)strsep(&string, " ")) != NULL){
                        if((arg4 = (char*)strsep(&string, " ")) != NULL){
                        }
                        else{ // queries com 3 argumentos apenas temos a 6
                            //query6();
                        }
                    }
                    else{ // queries com 2 argumentos
                        if(atoi(query) == 5){ // então é a query 5
                            //query5();
                        }
                        else if(atoi(query) == 7){// então é a 7
                            //query7();
                        }
                        else if(atoi(query) == 8){// então é a 8
                            //query8();
                        }
                        else if(atoi(query) == 9){// então é a 9
                            //query9();
                    }
                }
                }
                else{ // queries com 1 argumentos
                    if(atoi(query) == 1){ // então é a query 1
                        printf("%s",arg1);
                        printf("%i",j);
                        printf("\n");
                        if(isdigit(arg1[j])){
                            query1_drivers(catalogoDrivers,catalogoRides, arg1,i);
                        }
                        else{
                            printf("6\n");
                            query1_users(catalogoUsers,catalogoRides, catalogoDrivers, arg1,i);
                        }
                    }
                    else if(atoi(query) == 2){ // então é a query 2
                        //query2();
                    }
                    else if(atoi(query) == 3){ // então é a query 3
                        //query3();
                    }
                    else if(atoi(query) == 4){ // então é a query 4
                             printf("7\n");
                             query4(catalogoDrivers,catalogoRides,arg1,i);
                    }
                }
            }
        }
        i++;
    }

    free(catalogoUsers);
    free(catalogoRides);
    free(catalogoDrivers);


    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Demorou %.2f segundos!\n", cpu_time_used);

    return 0;
}