#ifndef Rides_H
#define Rides_H

#include <glib.h>
#include <gmodule.h>

typedef struct rides* Rides;
typedef struct catalog_rides* CatRides;

char* get_id_Rides(Rides r);
char* get_date_Rides(Rides r);
char* get_driver_Rides(Rides r);
char* get_user_Rides(Rides r);
char* get_city_Rides(Rides r);
char* get_distance_Rides(Rides r);
char* get_score_user_Rides(Rides r);
char* get_score_driver_Rides(Rides r);
char* get_tip_Rides(Rides r);
char* get_comment_Rides(Rides r);

void set_catRides(CatRides r, GHashTable* u, GHashTable* a, GHashTable* x);

GHashTable* get_catalogo_rides(CatRides c);
GHashTable* get_catalogo_ridesdriver(CatRides c);
GHashTable* get_catalogo_ridesuser(CatRides c);

struct catalog_rides {
    GHashTable* Rides;
    GHashTable* RidesUser;
    GHashTable* RidesDriver;
};

Rides build_Rides(char *line);

#endif