#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "../include/drivers.h"
#include "../include/rides.h"
#include "../include/user.h"
#include "../include/data.h"
#include "../include/validadur.h"

struct catalog_driver {
    GHashTable* Driver;
};

struct catalog_rides {
    GHashTable* Rides;
    GHashTable* RidesUser;
    GHashTable* RidesDriver;
};

struct catalog_user {
    GHashTable* user;
};

struct catalogos {
    GHashTable* Driver;
    GHashTable* Rides;
    GHashTable* RidesUser;
    GHashTable* RidesDriver;
    GHashTable* user;
};

typedef struct catalog_driver* CatDriver;
typedef struct catalog_rides* CatRides;
typedef struct catalog_user* CatUser;
typedef struct catalogos* Catalogos;

Catalogos carregaCatalogos(FILE* user,FILE* driver, FILE* rides);

#include "../include/queries.h"
#include "../include/getters.h"
#include "../include/menu.h"

#endif                                                                              