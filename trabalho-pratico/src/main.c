#include "../include/catalogos.h"
#define MAXL 1024000

/**
 * Função main do programa.
*/

int main(int argc, char* argv[]){

    clock_t start, end;

    double cpu_time_used;

    start = clock();

    if(argc==1){

        char* caminho = malloc(1000);
        int menu = 1, opcao;
        char opcaoA[1];

        printf("Introduza o caminho para a pasta onde estão os ficheiros de entrada:\n");
        scanf("%s", caminho);
        
        char *usersfile = malloc(strlen("users.csv")+1000);
            strcpy(usersfile,caminho);
            strcat(usersfile,"/users.csv");

        char *driversfile= malloc(strlen("drivers.csv")+1000);
            strcpy(driversfile,caminho);
            strcat(driversfile,"/drivers.csv");

        char *ridesfile = malloc(strlen("rides.csv")+1000);
            strcpy(ridesfile,caminho);
            strcat(ridesfile,"/rides.csv");

        free(caminho);     

        // char *usersfile = "Dataset_Fase1/users.csv";
        // char *driversfile = "Dataset_Fase1/drivers.csv";
        // char *ridesfile = "Dataset_Fase1/rides.csv";

        FILE* fileUser = fopen(usersfile,"r");
        FILE* fileDriver = fopen(driversfile,"r");
        FILE* fileRides = fopen(ridesfile,"r");

        Catalogos catalogos = carregaCatalogos(fileUser,fileDriver,fileRides);

        while(menu!=0){
            printMenuPrincipal();
            printf("\nInsira a opção pretendida: ");
            scanf("%s", opcaoA);

            while (!isdigit(opcaoA[0])) {
                printf("\nOpção inválida!\n");
                printMenuPrincipal();
                printf("\nInsira a opção pretendida: ");
                scanf("%s", opcaoA);
            }

            opcao = atoi(opcaoA);

            if (opcao == 0){
                menu = 0; printf("Obrigado!\n");
            }
            else if(opcao == 1){
                char* id = malloc(sizeof(id));
                printf("\nInsira o id/username pretendido: ");
                scanf("%s",id);
                if(isdigit(id[0])){
                    printQuerie1_D(catalogos,id);
                    menu = printSubMenu();
                }
                else {
                    printQuerie1_U(catalogos,id);
                    menu = printSubMenu();
                }
            }
            else if(opcao == 2){
                char* n = malloc(sizeof(n));
                printf("\nInsira o numero de condutores que deseja listar: ");
                scanf("%s",n);
                printQuerie2(catalogos,n);
                menu = printSubMenu();
            }
            else if(opcao == 3){
                char* n = malloc(sizeof(n));
                printf("\nInsira o numero de condutores que deseja listar: ");
                scanf("%s",n);
                printQuerie3(catalogos,n);
                menu = printSubMenu();
            }
            else if(opcao == 4){
                char* city = malloc(sizeof(city));
                printf("\nInsira a cidade pretendida: ");
                scanf("%s",city);
                printQuerie4(catalogos,city);
                menu = printSubMenu();
            }
            else if(opcao == 5){
                char* data_i = malloc(sizeof(data_i));
                char* data_f = malloc(sizeof(data_f));
                printf("\nInsira a Data inicial pretendida(DD/MM/ANO): ");
                scanf("%s",data_i);
                printf("\nInsira a Data Final pretendida(DD/MM/ANO): ");
                scanf("%s",data_f);
                printQuerie5(catalogos,data_i,data_f);
                menu = printSubMenu();
            }
            else if(opcao == 6){
                char* data_i = malloc(sizeof(data_i));
                char* data_f = malloc(sizeof(data_f));
                char* city = malloc(sizeof(city));
                printf("\nInsira a cidade pretendida: ");
                scanf("%s",city);
                printf("\nInsira a Data inicial pretendida(DD/MM/ANO): ");
                scanf("%s",data_i);
                printf("\nInsira a Data Final pretendida(DD/MM/ANO): ");
                scanf("%s",data_f);
                printQuerie6(catalogos,city,data_i,data_f);
                menu = printSubMenu();
            }
            else if(opcao == 7){
                char* n = malloc(sizeof(n));
                char* city = malloc(sizeof(city)); 
                printf("\nInsira a cidade pretendida: ");
                scanf("%s",city);
                printf("\nInsira o numero de condutores que deseja listar: ");
                scanf("%s",n);
                printQuerie7(catalogos,n,city);
                menu = printSubMenu();
            }
            else if(opcao == 8){
                // char* gender = malloc(sizeof(gender));
                // char* anos = malloc(sizeof(anos)); 
                // printf("\nInsira o género pretendido: ");
                // scanf("%s",gender);
                // printf("\nInsira ,pelo menos, o numero á quanto tempo a conta foi criada: ");
                // scanf("%s",x);
                // printQuerie8(catalogos,gender, x);
                // menu = printSubMenu();
                
            }
            else if(opcao == 9){
                char* data_i = malloc(sizeof(data_i));
                char* data_f = malloc(sizeof(data_f));
                printf("\nInsira a Data inicial pretendida(DD/MM/ANO): ");
                scanf("%s",data_i);
                printf("\nInsira a Data Final pretendida(DD/MM/ANO): ");
                scanf("%s",data_f);
                printQuerie9(catalogos,data_i,data_f);
                menu = printSubMenu();
            }
            else {
                printf("\nOpção inválida!\n");
            }
        }

    }
    
    if (argc==3){
            // cria string com o path completo 
        char *usersfile = malloc(strlen(argv[1])+strlen("users.csv")+1000);
            strcpy(usersfile,argv[1]);
            strcat(usersfile,"/users.csv");

        char *driversfile= malloc(strlen(argv[1])+strlen("drivers.csv")+1000);
            strcpy(driversfile,argv[1]);
            strcat(driversfile,"/drivers.csv");

        char *ridesfile = malloc(strlen(argv[1])+strlen("rides.csv")+1000);
            strcpy(ridesfile,argv[1]);
            strcat(ridesfile,"/rides.csv");
        

        FILE* fileUser = fopen(usersfile,"r");
        FILE* fileDriver = fopen(driversfile,"r");
        FILE* fileRides = fopen(ridesfile,"r");
        FILE* f = fopen(argv[2],"r");
        
        Catalogos catalogos = carregaCatalogos(fileUser,fileDriver,fileRides);

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
                if((arg1 = (char*)g_strdup(strsep(&string, " "))) != NULL){
                    if((arg2 = (char*)g_strdup(strsep(&string, " "))) != NULL){
                        if((arg3 = (char*)strsep(&string, " ")) != NULL){
                            if((arg4 = (char*)strsep(&string, " ")) != NULL){
                            }
                            else{ // queries com 3 argumentos apenas temos a 6
                                query6(catalogos,arg1,arg2,arg3,i);
                            }
                        }
                        else{ // queries com 2 argumentos
                            if(atoi(query) == 5){ // então é a query 5
                                query5(catalogos,arg1,arg2,i);
                            }
                            else if(atoi(query) == 7){// então é a 7
                                query7(catalogos,arg1,arg2,i);
                            }
                            else if(atoi(query) == 8){// então é a 8
                                //query8();
                            }
                            else if(atoi(query) == 9){// então é a 9
                                query9(catalogos,arg1,arg2,i);
                        }
                    }
                    }
                    else{ // queries com 1 argumentos
                        if(atoi(query) == 1){ // então é a query 1
                            if(isdigit(arg1[j])){
                                query1_drivers(catalogos, arg1,i);
                            }
                            else{
                                query1_users(catalogos, arg1,i);
                            }
                        }
                        else if(atoi(query) == 2){ // então é a query 2
                                query2(catalogos, arg1, i);
                        }
                        else if(atoi(query) == 3){ // então é a query 3
                                query3(catalogos, arg1, i);
                        }
                        else if(atoi(query) == 4){ // então é a query 4
                                query4(catalogos,arg1,i);
                        }
                    }
                }
            }
            i++;
        }

        free(catalogos);
        fclose(f);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Demorou %.2f segundos!\n", cpu_time_used);

    return 0;
}