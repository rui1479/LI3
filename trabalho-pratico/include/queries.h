#ifndef QUERIES_H
#define QUERIES_H

#include "../include/catalogos.h"

void query1_users(Catalogos catalogo, char *username, int linha);
void query1_drivers(Catalogos catalogo, char *id, int linha);
void query4(Catalogos catalogo, char* city, int linha);
//void query5 (CatDriver catalogoDrivers, CatRides catalogoRides, char* data_inicial, char* data_final, int linha);

#endif