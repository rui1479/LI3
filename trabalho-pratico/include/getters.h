#ifndef GETTERS_H
#define GETTERS_H

#include "../include/catalogos.h"
#include <string.h>
#include <time.h>

typedef struct aux_driver* AUX_DRIVER;

typedef struct aux_user* AUX_USER;

typedef struct aux_q7* AUX_Q7;

typedef struct aux_q8* AUX_Q8;

typedef struct aux_q9* AUX_Q9;

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
double get_preco_medio_data(Catalogos catalogo, char* data_inicial, char* data_final);
double get_distancia_media_city(Catalogos catalogo, char* city, char* data_inicial, char* data_final);

GList* auxquerie2 (Catalogos catalogo);
GList* auxquerie3 (Catalogos catalogo);
GList* auxquerie7 (Catalogos catalogo,char* city);
// GList* auxquerie8 (Catalogos catalogo,char* gender);
GList* auxquerie9 (Catalogos catalogo,char* data_inicial, char* data_final);

#endif