#ifndef GETTERS_H
#define GETTERS_H

#include "../include/parse.h"

char* get_name_list_user(CatUser catalogos, char* username);
char* get_gender_list_user(CatUser catalogos, char* username);
int get_idade_list_User(CatUser catalogos, char* username);
double get_avaliacao_media_user(CatRides catalogos, char* username);
int get_numero_viagens_user(CatRides catalogos, char *username);
double get_total_gasto(CatRides catalogosrides, CatUser catalogosusers, CatDriver catalogodrivers, char *username);

char* get_name_list_driver(CatDriver catalogos, char* id);
char* get_gender_list_driver(CatDriver catalogos, char* id);
int get_idade_list_driver(CatDriver catalogos, char* id);
double get_avaliacao_media(CatRides catalogos, char* id);
int get_numero_viagens(CatRides catalogos, char *id);
double get_total_euferido(CatRides catalogosrides, CatDriver catalogosdrivers, char *id);

double get_preco_medio_city(CatRides catalogosrides, CatDriver catalogodrivers, char *city);


#endif