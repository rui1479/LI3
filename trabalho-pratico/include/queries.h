#ifndef QUERIES_H
#define QUERIES_H

#include "../include/parse.h"

void query1_users(CatUser catalogoUsers, CatRides catalogoRides, CatDriver catalogoDrivers, char *username, int linha);
void query1_drivers(CatDriver catalogoDrivers, CatRides catalogoRides, char *id, int linha);

#endif