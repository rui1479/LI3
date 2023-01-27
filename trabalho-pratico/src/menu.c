#include "../include/menu.h"

struct aux_q7{
    char *id;
    char *nome;
    double avaliacao;
    int contador;
};

struct aux_q8{
    char *gender;
    char *id;
    char *nome;
    char *username;
    char *nome_user;
    char *viagem;
    Data conta_driver;
    Data conta_user;
};

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
    char* menu;
    printf("\n-----------------------------------------------------------------------------------------------\n");
    printf("|1| Voltar ao menu principal \n|0| Sair \n");
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("Opção desejada: ");
    scanf("%s", menu);

    if (atoi(menu) == 0){
        printf("Obrigado!\n");
        return 0;
    }

    else if (atoi(menu) == 1){
        return 1;
    }
    
    else if (!isdigit(menu[0])){
        printf("\nOpção invalida.\n");
        printSubMenu();
    }

    else{
        printf("\nOpção invalida.\n");
        printSubMenu();
    }
}

void printQuerie1_U(Catalogos catalogo, char* id){
    char* novousername = strsep(&id,"\n");
    User user = g_hash_table_lookup(catalogo->user, novousername);
    if(user){
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
    if(drivers){
        char *nome = get_name_list_driver(catalogo,novoid);
        char *gender = get_gender_list_driver(catalogo,novoid);
        int idade = get_idade_list_driver(catalogo,novoid);
        double avaliacao_media = get_avaliacao_media(catalogo,novoid);
        int numero_viagens = get_numero_viagens(catalogo,novoid);
        double total_euferido = get_total_euferido(catalogo,novoid);
        printf("\n--------------------------------------- QUERY 1 -----------------------------------------------\n");
        printf("%s;%s;%i;%.3f;%i;%.3f\n", nome, gender, idade, avaliacao_media, numero_viagens, total_euferido);
        printf("-------------------------------------------------------------------------------------------------\n");
    }
    else {
        printf("\n--------------------------------------- QUERY 1 -----------------------------------------------\n");
        printf("Este driver não existe.\n");
        printf("-------------------------------------------------------------------------------------------------\n");
    }
}

void printQuerie2(Catalogos catalogo, char* n){
    GList* sorted = auxquerie2(catalogo);
    printf("\n--------------------------------------- QUERY 2 -----------------------------------------------\n");
    for (size_t i = 0; i < atoi(n); i++) {
        AUX_DRIVER driver = g_list_nth_data(sorted, i);
        printf("%s;%s;%.3f\n", get_id_auxdriver(driver),get_nome_auxdriver(driver),(get_avaliacao_auxdriver(driver)/get_contador_auxdriver(driver)));
    }
    printf("-----------------------------------------------------------------------------------------------------\n");

}

void printQuerie3(Catalogos catalogo, char* n){
    GList* sorted = auxquerie3(catalogo);
    printf("\n--------------------------------------- QUERY 3 -----------------------------------------------\n");
    for (size_t i = 0; i < atoi(n); i++) {
        AUX_USER user = g_list_nth_data(sorted, i);
        printf("%s;%s;%i\n", get_user_auxuser(user), get_nome_auxuser(user), get_distancia_auxuser(user));
    }
    printf("-----------------------------------------------------------------------------------------------------\n");
}

void printQuerie4(Catalogos catalogo, char* city){
    double preco_medio = get_preco_medio_city(catalogo, city);
    printf("\n------------------------------------------- QUERY 4 -----------------------------------------------\n");
    printf("O preço medio nesta cidade é: %.3f\n", preco_medio);
    printf("-----------------------------------------------------------------------------------------------------\n");
}

void printQuerie5(Catalogos catalogo, char* data_inicial, char* data_final){
    double preco_medio_data = get_preco_medio_data(catalogo, data_inicial, data_final);
    printf("\n------------------------------------------- QUERY 5 -----------------------------------------------\n");
    printf("O preço medio no intervalo de tempo inserido é: %.3f\n", preco_medio_data);
    printf("-----------------------------------------------------------------------------------------------------\n");
}
void printQuerie6(Catalogos catalogo, char* city, char* data_inicial, char* data_final){
    double distancia_media = get_distancia_media_city(catalogo,city,data_inicial,data_final);
    printf("\n------------------------------------------- QUERY 6 -----------------------------------------------\n");
    printf("A distancia media da cidade %s no intervalo de tempo inserido é: %.3f\n", city, distancia_media);
    printf("-----------------------------------------------------------------------------------------------------\n");
}

void printQuerie7(Catalogos catalogo, char* n, char* city){
    GList* sorted = auxquerie7(catalogo, city);
    printf("\n--------------------------------------- QUERY 7 -----------------------------------------------\n");
    for (size_t i = 0; i < atoi(n); i++) {
        AUX_Q7 driver = g_list_nth_data(sorted, i);
        printf("%s;%s;%.3f\n", driver->id,driver->nome,(driver->avaliacao)/(driver->contador));
    }
    printf("-----------------------------------------------------------------------------------------------------\n");

}

// void printQuerie8(Catalogos catalogo, char* gender, char* x){
//     GList* sorted = auxquerie8(catalogo, gender);
//     printf("\n--------------------------------------- QUERY 8 -----------------------------------------------\n");
//     int tamanho = g_list_length(sorted);
//     for (size_t i = 0; i < tamanho; i++) {
//         AUX_Q9 ride = g_list_nth_data(sorted, i);
//         printf( "%s;%s;%s;%s\n", ride->id, driver->nome, ride->username, user->nome_user);
//     }
//     printf("-----------------------------------------------------------------------------------------------------\n");
// }

void printQuerie9(Catalogos catalogo, char* data_inicial, char* data_final){
    GList* sorted = auxquerie9(catalogo,data_inicial,data_final);
    printf("\n--------------------------------------- QUERY 9 -----------------------------------------------\n");
    int tamanho = g_list_length(sorted);
    for (size_t i = 0; i < tamanho; i++) {
        AUX_Q9 ride = g_list_nth_data(sorted, i);
        Data aux = get_data_auxq9(ride);
        printf("%s;%i/%i/%i;%s;%s,%.3f\n", get_id_auxq9(ride), get_dia(aux), get_mes(aux), get_ano(aux), get_distancia_auxq9(ride), get_cidade_auxq9(ride),atof(get_tip_auxq9(ride)));
    }
    printf("-----------------------------------------------------------------------------------------------------\n");
}