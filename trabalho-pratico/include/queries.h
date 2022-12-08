#ifndef QUERIES_H
#define QUERIES_H

#include "../include/catalogos.h"

void query1_users(Catalogos catalogo, char *username, int linha);
void query1_drivers(Catalogos catalogo, char *id, int linha);
void query2 (Catalogos catalogo, char* N, int linha);
void query4(Catalogos catalogo, char* city, int linha);
void query5 (Catalogos catalogo, char* data_inicial, char* data_final, int linha);
void query6 (Catalogos catalogo, char* city, char* data_inicial, char* data_final, int linha);
#endif