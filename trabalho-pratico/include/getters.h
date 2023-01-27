#ifndef GETTERS_H
#define GETTERS_H

#include "../include/catalogos.h"
#include "../include/data.h"
#include <string.h>
#include <time.h>

typedef struct aux_driver* AUX_DRIVER;

typedef struct aux_user* AUX_USER;

typedef struct aux_q7* AUX_Q7;

typedef struct aux_q8* AUX_Q8;

typedef struct aux_q9* AUX_Q9;

char* get_id_auxdriver (AUX_DRIVER a);
char* get_nome_auxdriver (AUX_DRIVER a);
double get_avaliacao_auxdriver (AUX_DRIVER a);
int get_contador_auxdriver (AUX_DRIVER a);

char* get_user_auxuser (AUX_USER a);
char* get_nome_auxuser (AUX_USER a);
int get_distancia_auxuser (AUX_USER a);

char* get_id_auxq7 (AUX_Q7 a);
char* get_nome_auxq7 (AUX_Q7 a);
double get_avaliacao_auxq7 (AUX_Q7 a);
int get_contador_auxq7 (AUX_Q7 a);
     
char* get_gender_auxq8 (AUX_Q8 a);
char* get_id_auxq8 (AUX_Q8 a);
char* get_nome_auxq8 (AUX_Q8 a);
char* get_username_auxq8 (AUX_Q8 a);
char* get_nome_user_auxq8 (AUX_Q8 a);
char* get_viagem_auxq8 (AUX_Q8 a);
Data get_contaD_auxq8 (AUX_Q8 a);
Data get_contaU_auxq8 (AUX_Q8 a);

char* get_id_auxq9 (AUX_Q9 a);
char* get_distancia_auxq9 (AUX_Q9 a);
char* get_cidade_auxq9 (AUX_Q9 a);
char* get_tip_auxq9 (AUX_Q9 a);
Data get_data_auxq9 (AUX_Q9 a);

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
double get_preco_medio_data_test(Catalogos catalogo, Data inicial, Data final);
double get_distancia_media_city_test(Catalogos catalogo, char* city, Data inicial, Data final);

GList* auxquerie2 (Catalogos catalogo);
GList* auxquerie3 (Catalogos catalogo);
GList* auxquerie7 (Catalogos catalogo,char* city);
// GList* auxquerie8 (Catalogos catalogo,char* gender);
GList* auxquerie9 (Catalogos catalogo,char* data_inicial, char* data_final);

#endif