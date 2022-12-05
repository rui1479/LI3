#ifndef GETTERS_H
#define GETTERS_H

#include "../include/catalogos.h"

char* get_name_list_user(Catalogos catalogos, char* username);
char* get_gender_list_user(Catalogos catalogos, char* username);
int get_idade_list_User(Catalogos catalogos, char* username);
double get_avaliacao_media_user(Catalogos catalogos, char* username);
int get_numero_viagens_user(Catalogos catalogos, char *username);
double get_total_gasto(Catalogos catalogos, char *username);

char* get_name_list_driver(Catalogos catalogos, char* id);
char* get_gender_list_driver(Catalogos catalogos, char* id);
int get_idade_list_driver(Catalogos catalogos, char* id);
double get_avaliacao_media(Catalogos catalogos, char* id);
int get_numero_viagens(Catalogos catalogos, char *id);
double get_total_euferido(Catalogos catalogos, char *id);

double get_preco_medio_city(Catalogos catalogos, char *city);
//double get_preco_medio_data(Catalogos catalogodrivers, Catalogos catalogorides, char* data_inicial, char* data_final);


#endif