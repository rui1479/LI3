#include "../include/catalogos.h"
#define ANO "09/10/2022"

// -----------------------------------------------------------------------Parse User -----------------------------------------------------------------------------------------

CatUser parseUser(FILE* fileUser){
    CatUser catalogoUser = malloc(sizeof(CatUser));
    GHashTable* user = g_hash_table_new(g_str_hash, g_str_equal);

    int max_length = 1024000;
    char buff[max_length];

    if(fileUser == NULL){
        printf("Erro a processar Users!\n");
        return 0;
    }

    while(fgets(buff, max_length, fileUser)){
        User a = build_user(buff);
        if(testuser(a)){
            g_hash_table_insert(user, get_username_user(a), a); // key é o username
        }
    }

    catalogoUser->user = user;

    fclose(fileUser);

    return catalogoUser;
}

// -------------------------------------------------------------------------Parse Rides -----------------------------------------------------------------------------------------

CatRides parseRides(FILE* fileRides){
    CatRides catalogoRides = malloc(sizeof(CatRides));
    GHashTable* rides = g_hash_table_new(g_str_hash, g_str_equal);
    GHashTable* ridesuser = g_hash_table_new(g_str_hash, g_str_equal);
    GHashTable* ridesdriver = g_hash_table_new(g_str_hash, g_str_equal);
    
    int max_length = 1024000;
    char buff[max_length];

    if(fileRides == NULL){
        printf("Erro a processar Rides!\n");
        return 0;
    }

    while(fgets(buff, max_length, fileRides)){
        Rides r = build_Rides(buff);
        if(testrides(r)){
        g_hash_table_insert(rides, get_id_Rides(r), r); // key é o id do rides
        g_hash_table_insert(ridesuser, get_user_Rides(r), r); // key é o user do rides
        g_hash_table_insert(ridesdriver, get_driver_Rides(r), r);  // key é o driver do rides
        }
    } 

    catalogoRides->Rides = rides;
    catalogoRides->RidesDriver = ridesdriver;
    catalogoRides->RidesUser;

    fclose(fileRides);

    return catalogoRides;
}

// --------------------------------------------------------------------------Parse Drivers -----------------------------------------------------------------------------------------

CatDriver parseDrivers(FILE* fileDriver){
    CatDriver catalogoDriver = malloc(sizeof(CatDriver));
    GHashTable* driver = g_hash_table_new(g_str_hash, g_str_equal);

    int max_length = 1024000;
    char buff[max_length];

    if(fileDriver == NULL){
        printf("Erro a processar Drivers!\n");
        return 0;
    }

    while(fgets(buff, max_length, fileDriver)){
        Driver d = build_Driver(buff);
        if(testdriver(d)){
            g_hash_table_insert(driver, get_id_driver(d), d);
        }
    }

    catalogoDriver->Driver = driver;

    fclose(fileDriver);

    return catalogoDriver;
}
// ------------------------------------------------------------------------Carregar Catalogos -----------------------------------------------------------------------------------------

Catalogos carregaCatalogos(FILE* user,FILE* driver, FILE* rides){
    Catalogos cat = malloc(sizeof(Catalogos) * 10);
    printf("\n A carregar Users ...\n");
    CatUser catalogoUsers = parseUser(user);
    printf("\n A carregar Drivers ...\n");
    CatDriver catalogoDrivers = parseDrivers(driver);
    printf("\n A carregar Rides ...\n");
    CatRides catalogoRides = parseRides(rides);
    cat->Driver = catalogoDrivers->Driver;
    cat->user = catalogoUsers->user;
    cat->RidesDriver = catalogoRides->RidesDriver;
    cat->Rides = catalogoRides->Rides;
    cat->RidesUser = catalogoRides->RidesUser;
    return cat;
}

// ------------------------------------------------------------------------Getters Hash Table -----------------------------------------------------------------------------------------

GHashTable* get_catalogo_drivers(CatDriver c){
    return c->Driver;
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

GHashTable* get_catalogo_users(CatUser c){
  return c->user;
}

