#include "../include/menu.h"

void printMenuPrincipal(){
    printf("\n-------------------------------------------------------------------------------------\n");
    printf("|1|                       Resumo de um perfil registado no serviço                    |\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("|2|                        Top N condutores com maior avaliação média                 |\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("|3|                       Top N utilizadores com maior distância viajada              |\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("|4|                           Preço médio das viagens por cidade                      |\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("|5|                     Preço médio das viagens num intervalo de tempo                |\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("|6|                Preço médio das viagens numa cidade num intervalo de tempo         |\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("|7|                       Top N condutores numa determinada cidade                    |\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("|8|              Todas as viagens de um user e driver com X anos de conta ativa       |\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("|9|             Todas as viagens que um user deu gorjeta num intervalo de tempo       |\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("|0|                                       SAIR                                        |\n");
    printf("---------------------------------------------------------------------------------------\n");
}

int printSubMenu(){
    int menu;
    printf("\n-----------------------------------------------------------------------------------------------\n");
    printf("|1| Voltar ao menu principal \n|0| Sair \n");
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("Opção desejada: ");
    scanf("%d", &menu);
    if (menu == 0) printf("Obrigado!\n");
    else menu = 1;
    return menu;
}

void printQuerie1_U(Catalogos catalogo, char* id){
    char* novousername = strsep(&id,"\n");
    User user = g_hash_table_lookup(catalogo->user, novousername);
    if(strcmp("active",get_account_status_user(user))==0){
        char *nome = get_name_list_user(catalogo, novousername);
        char *gender = get_gender_list_user(catalogo, novousername);
        int idade = get_idade_list_User(catalogo, novousername);
        double avaliacao_media = get_avaliacao_media_user(catalogo, novousername);
        int numero_viagens = get_numero_viagens_user(catalogo, novousername);
        double total_gasto = get_total_gasto(catalogo, novousername);
        printf("\n------------------------------------------- QUERY 1 -------------------------------------------\n");
        printf("%s;%s;%i;%.3f;%i;%.3f\n", nome, gender, idade, avaliacao_media, numero_viagens, total_gasto);
        printf("-------------------------------------------------------------------------------------------------\n");
    }
    else{
        printf("\n------------------------------------------- QUERY 1 -------------------------------------------\n");
        printf("Este user não existe.\n");
        printf("-------------------------------------------------------------------------------------------------\n");
    }
}

void printQuerie1_D(Catalogos catalogo, char* id){
    char* novoid = strsep(&id,"\n");
    Driver drivers = g_hash_table_lookup(catalogo->Driver, novoid);
    if(strcmp("active",get_account_status_driver(drivers))==0){
        char *nome = get_name_list_driver(catalogo,novoid);
        char *gender = get_gender_list_driver(catalogo,novoid);
        int idade = get_idade_list_driver(catalogo,novoid);
        double avaliacao_media = get_avaliacao_media(catalogo,novoid);
        int numero_viagens = get_numero_viagens(catalogo,novoid);
        double total_euferido = get_total_euferido(catalogo,novoid);
        printf("\n------------------------------------------- QUERY 1 -------------------------------------------\n");
        printf("%s;%s;%i;%.3f;%i;%.3f\n", nome, gender, idade, avaliacao_media, numero_viagens, total_euferido);
        printf("-------------------------------------------------------------------------------------------------\n");
    }
    else {
        printf("\n--------------------------------------- QUERY 1 -------------------------------------------\n");
        printf("Este driver não existe.\n");
        printf("-------------------------------------------------------------------------------------------------\n");
    }
}

void printQuerie4(Catalogos catalogo, char* city){
    double preco_medio = get_preco_medio_city(catalogo, city);
    printf("\n------------------------------------------- QUERY 4 -------------------------------------------\n");
    printf("O preço medio nesta cidade é: %.3f\n", preco_medio);
    printf("-------------------------------------------------------------------------------------------------\n");
}

void printQuerie5(Catalogos catalogo, char* data_inicial, char* data_final){
    double preco_medio_data = get_preco_medio_data(catalogo, data_inicial, data_final);
    printf("\n------------------------------------------- QUERY 5 -------------------------------------------\n");
    printf("O preço medio no intervalo de tempo inserido é: %.3f\n", preco_medio_data);
    printf("-------------------------------------------------------------------------------------------------\n");
}
void printQuerie6(Catalogos catalogo, char* city, char* data_inicial, char* data_final){
    double distancia_media = get_distancia_media_city(catalogo,city,data_inicial,data_final);
    printf("\n------------------------------------------- QUERY 6 -------------------------------------------\n");
    printf("A distancia media da cidade %s no intervalo de tempo inserido é: %.3f\n", city, distancia_media);
    printf("-------------------------------------------------------------------------------------------------\n");
}