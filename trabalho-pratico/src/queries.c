#include "../include/queries.h"

void query1_users(CatUser catalogoUsers, CatRides catalogoRides, CatDriver catalogoDrivers, char *username, int linha){
    char* novousername = strsep(&username,"\n");
    User user = g_hash_table_lookup(catalogoUsers->user, novousername);
    if(strcmp("active",get_account_status_user(user))==0){
        char buffer[128];
        sprintf(buffer, "Resultados/command%d_output.txt", linha);
        FILE *query1txt_user = fopen(buffer, "w");
        char *nome = get_name_list_user(catalogoUsers, username);
        char *gender = get_gender_list_user(catalogoUsers, username);
        int idade = get_idade_list_User(catalogoUsers, username);
        double avaliacao_media = get_avaliacao_media_user(catalogoRides, username);
        int numero_viagens = get_numero_viagens_user(catalogoRides, username);
        double total_gasto = get_total_gasto(catalogoRides,catalogoUsers, catalogoDrivers, username);
        fprintf(query1txt_user, "%s;%s;%i;%.3f;%i;%.3f\n", nome, gender, idade, avaliacao_media, numero_viagens, total_gasto);
        fclose(query1txt_user);        
    }
    else{
        char buffer[128];
        sprintf(buffer, "Resultados/command%d_output.txt", linha);
        FILE *query1txt_user = fopen(buffer, "w");
        fprintf(query1txt_user, "\n");
        fclose(query1txt_user);
    }
}
void query1_drivers(CatDriver catalogoDrivers, CatRides catalogoRides, char *id, int linha){
    char* novoid = strsep(&id,"\n");
    Driver drivers = g_hash_table_lookup(catalogoDrivers->Driver, novoid);
    if(strcmp("active",get_account_status_driver(drivers))==0){
        char buffer[128];
        sprintf(buffer, "Resultados/command%d_output.txt", linha);
        FILE *query1txt_driver = fopen(buffer, "w");
        char *nome = get_name_list_driver(catalogoDrivers,id);
        char *gender = get_gender_list_driver(catalogoDrivers,id);
        int idade = get_idade_list_driver(catalogoDrivers,id);
        double avaliacao_media = get_avaliacao_media(catalogoRides,id);
        int numero_viagens = get_numero_viagens(catalogoRides,id);
        double total_euferido = get_total_euferido(catalogoRides,catalogoDrivers,id);
        fprintf(query1txt_driver, "%s;%s;%i;%.3f;%i;%.3f\n", nome, gender, idade, avaliacao_media, numero_viagens, total_euferido);
        fclose(query1txt_driver);        
    }
    else{
        char buffer[128];
        sprintf(buffer, "Resultados/command%d_output.txt", linha);
        FILE *query1txt_driver = fopen(buffer, "w");
        fprintf(query1txt_driver, "\n");
        fclose(query1txt_driver);
    }
}

void query4 (CatDriver catalogoDrivers, CatRides catalogoRides, char* city, int linha){
    char buffer[128];
    sprintf(buffer, "Resultados/command%d_output.txt", linha);
    FILE *query4txt_driver = fopen(buffer, "w");
    double preco_medio = get_preco_medio_city(catalogoRides,catalogoDrivers, city);
    fprintf(query4txt_driver, "%.3f\n", preco_medio);
    fclose(query4txt_driver);
}

