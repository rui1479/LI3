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

typedef struct catalog_driver* CatDriver;
typedef struct catalog_rides* CatRides;
typedef struct catalog_user* CatUser;
typedef struct catalogos* Catalogos;

GHashTable* get_catalogo_user (Catalogos a);
GHashTable* get_catalogo_driver (Catalogos a);
GHashTable* get_catalogo_rides (Catalogos a);
Catalogos carregaCatalogos(FILE* user,FILE* driver, FILE* rides);

#include "../include/queries.h"
#include "../include/getters.h"
#include "../include/menu.h"

#endif                                                                              