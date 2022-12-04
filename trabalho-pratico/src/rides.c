#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/rides.h"


struct rides {
    char *id;
    char *date;
    char *driver;
    char *user;
    char *city;
    char *distance;
    char *score_user;
    char *score_driver;
    char *tip;
    char *comment;
};


char* get_id_Rides(Rides r) {
  if(r)
    return g_strdup(r->id);
  return NULL;
}

char* get_date_Rides(Rides r) {
  if(r)
    return g_strdup(r->date);
  return NULL;
}

char* get_driver_Rides(Rides r) {
  if(r)
    return g_strdup(r->driver);
  return NULL;
}

char* get_user_Rides(Rides r) {
  if(r)
    return g_strdup(r->user);
  return NULL;
}

char* get_city_Rides(Rides r) {
  if(r)
    return g_strdup(r->city);
  return NULL;
}

char* get_distance_Rides(Rides r) {
  if(r)
    return g_strdup(r->distance);
  return NULL;
}

char* get_score_user_Rides(Rides r) {
  if(r)
    return g_strdup(r->score_user);
  return NULL;
}

char* get_score_driver_Rides(Rides r) {
  if(r)
    return g_strdup(r->score_driver);
  return NULL;
}

char* get_tip_Rides(Rides r) {
  if(r)
    return g_strdup(r->tip);
  return NULL;
}

char* get_comment_Rides(Rides r) {
  if(r)
    return g_strdup(r->comment);
  return NULL;
}

void set_catRides(CatRides r, GHashTable* u, GHashTable* a, GHashTable* x){
  r->RidesUser=u;
  r->RidesDriver=a;
  r->Rides = x;
}

GHashTable* get_catalogo_ridesuser(CatRides c){
  return c->RidesUser;
}

GHashTable* get_catalogo_ridesdriver(CatRides c){
  return c->RidesDriver;
}

GHashTable* get_catalogo_rides(CatRides c){
  return c->Rides;
}


Rides build_Rides(char *line) {

    Rides r = malloc(sizeof(struct rides));

    r -> id = strdup(strsep(&line, ";\n"));
    r -> date = strdup(strsep(&line, ";\n"));
    r -> driver = strdup(strsep(&line, ";\n"));
    r -> user = strdup(strsep(&line, ";\n"));    
    r -> city = strdup(strsep(&line, ";\n"));
    r -> distance = strdup(strsep(&line, ";\n"));
    r -> score_user = strdup(strsep(&line, ";\n"));
    r -> score_driver = strdup(strsep(&line, ";\n"));
    r -> tip = strdup(strsep(&line, ";\n"));
    r -> comment = strdup(strsep(&line, ";\n"));

    return r;

}