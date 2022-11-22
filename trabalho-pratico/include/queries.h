#ifndef QUERIES_H
#define QUERIES_H

#include "../include/parse.h"

void query1_users(CatUser catalogoUsers, CatRides catalogoRides, CatDriver catalogoDrivers, char *username, int linha);
void query1_drivers(CatDriver catalogoDrivers, CatRides catalogoRides, char *id, int linha);
void query4(CatDriver catalogoDrivers, CatRides catalogoRides, char* city, int linha);
void query5 (CatDriver catalogoDrivers, CatRides catalogoRides, char* data_inicial, char* data_final, int linha);

#endif