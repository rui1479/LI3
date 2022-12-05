#include "../include/queries.h"

void query1_users(Catalogos catalogo, char *username, int linha){
    char* novousername = strsep(&username,"\n");
    User user = g_hash_table_lookup(catalogo->user, novousername);
    if(strcmp("active",get_account_status_user(user))==0){
        char buffer[128];
        sprintf(buffer, "Resultados/command%d_output.txt", linha);
        FILE *query1txt_user = fopen(buffer, "w");
        char *nome = get_name_list_user(catalogo, novousername);
        char *gender = get_gender_list_user(catalogo, novousername);
        int idade = get_idade_list_User(catalogo, novousername);
        double avaliacao_media = get_avaliacao_media_user(catalogo, novousername);
        int numero_viagens = get_numero_viagens_user(catalogo, novousername);
        double total_gasto = get_total_gasto(catalogo, novousername);
        fprintf(query1txt_user, "%s;%s;%i;%.3f;%i;%.3f\n", nome, gender, idade, avaliacao_media, numero_viagens, total_gasto);
        fclose(query1txt_user);        
    }
    else{
        char buffer[128];
        sprintf(buffer, "Resultados/command%d_output.txt", linha);
        FILE *query1txt_user = fopen(buffer, "w");
        fclose(query1txt_user);
    }
}

void query1_drivers(Catalogos catalogo, char *id, int linha){
    char* novoid = strsep(&id,"\n");
    Driver drivers = g_hash_table_lookup(catalogo->Driver, novoid);
    if(strcmp("active",get_account_status_driver(drivers))==0){
        char buffer[128];
        sprintf(buffer, "Resultados/command%d_output.txt", linha);
        FILE *query1txt_driver = fopen(buffer, "w");
        char *nome = get_name_list_driver(catalogo,novoid);
        char *gender = get_gender_list_driver(catalogo,novoid);
        int idade = get_idade_list_driver(catalogo,novoid);
        double avaliacao_media = get_avaliacao_media(catalogo,novoid);
        int numero_viagens = get_numero_viagens(catalogo,novoid);
        double total_euferido = get_total_euferido(catalogo,novoid);
        fprintf(query1txt_driver, "%s;%s;%i;%.3f;%i;%.3f\n", nome, gender, idade, avaliacao_media, numero_viagens, total_euferido);
        fclose(query1txt_driver);        
    }
    else{
        char buffer[128];
        sprintf(buffer, "Resultados/command%d_output.txt", linha);
        FILE *query1txt_driver = fopen(buffer, "w");
        fclose(query1txt_driver);
    }
}

void query4 (Catalogos catalogo, char* city, int linha){
    char buffer[128];
    sprintf(buffer, "Resultados/command%d_output.txt", linha);
    FILE *query4txt = fopen(buffer, "w");
    double preco_medio = get_preco_medio_city(catalogo, city);
    fprintf(query4txt, "%.3f\n", preco_medio);
    fclose(query4txt);
}

// void query5 (CatDriver catalogoDrivers, CatRides catalogoRides, char* data_inicial, char* data_final, int linha){
//     char* novadatai = strsep(&data_inicial,"\n");
//     char* novadataf = strsep(&data_final,"\n");
//     char buffer[128];
//     sprintf(buffer, "Resultados/command%d_output.txt", linha);
//     FILE *query5txt = fopen(buffer, "w");
//     double preco_medio_data = get_preco_medio_data(catalogoDrivers, catalogoRides, novadatai, novadataf);
//     fprintf(query5txt, "%.3f\n",preco_medio_data);
//     fclose(query5txt);
// }