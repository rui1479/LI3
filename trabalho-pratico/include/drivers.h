#ifndef DRIVERS_H
#define DRIVERS_H

#include <glib.h>
#include <gmodule.h>

typedef struct driver* Driver;
typedef struct catalog_driver* CatDriver;

char* get_id_driver (Driver a);
char* get_name_driver (Driver a);
char* get_birth_driver (Driver a);
char* get_gender_driver (Driver a);
char* get_car_class_driver (Driver a);
char* get_license_plate_driver (Driver a);
char* get_city_driver (Driver a);
char* get_account_creation_driver (Driver a);
char* get_account_status_driver (Driver a);

Driver build_Driver(char *line);

GHashTable* get_catalogo_drivers(CatDriver c);

void set_catDriver(CatDriver a, GHashTable* u);

struct catalog_driver {
    GHashTable* Driver;
};

#endif