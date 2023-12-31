#include "../include/catalogos.h"
#define ANO "09/10/2022"

// -----------------------------------------------------------------------STRUCTS --------------------------------------------------------------------------------------------

struct catalog_driver {
    GHashTable* Driver;
};

struct catalog_rides {
    GHashTable* Rides;
};

struct catalog_user {
    GHashTable* user;
};

struct catalogos {
    GHashTable* Driver;
    GHashTable* Rides;
    GHashTable* user;
};

GHashTable* get_catalogo_user (Catalogos a){
    return a->user;
};

GHashTable* get_catalogo_driver (Catalogos a){
    return a->Driver;
};

GHashTable* get_catalogo_rides (Catalogos a){
    return a->Rides;
};

// -----------------------------------------------------------------------Parse User -----------------------------------------------------------------------------------------

CatUser parseUser(FILE* fileUser){
    CatUser catalogoUser = malloc(sizeof(CatUser)*10);
    GHashTable* user = g_hash_table_new(g_str_hash, g_str_equal);

    int max_length = 200;
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
    //printf("Users: %i\n",g_hash_table_size(catalogoUser->user));

    fclose(fileUser);

    return catalogoUser;
}

// -------------------------------------------------------------------------Parse Rides -----------------------------------------------------------------------------------------

CatRides parseRides(FILE* fileRides){
    CatRides catalogoRides = malloc(sizeof(CatRides)*100);
    GHashTable* rides = g_hash_table_new(g_str_hash, g_str_equal);
    
    int max_length = 200;
    char buff[max_length];

    if(fileRides == NULL){
        printf("Erro a processar Rides!\n");
        return 0;
    }

    while(fgets(buff, max_length, fileRides)){
        Rides r = build_Rides(buff);
        if(testrides(r)){
        g_hash_table_insert(rides, get_id_Rides(r), r); // key é o id do rides
        }
    } 

    catalogoRides->Rides = rides;

    //printf("Rides: %i\n",g_hash_table_size(catalogoRides->Rides));

    fclose(fileRides);
    return catalogoRides;
}

// --------------------------------------------------------------------------Parse Drivers -----------------------------------------------------------------------------------------

CatDriver parseDrivers(FILE* fileDriver){
    CatDriver catalogoDriver = malloc(sizeof(CatDriver) * 10);
    GHashTable* driver = g_hash_table_new(g_str_hash, g_str_equal);

    int max_length = 200;
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
    //printf("Drivers: %i\n",g_hash_table_size(catalogoDriver->Driver));
    return catalogoDriver;
}
// ------------------------------------------------------------------------Carregar Catalogos -----------------------------------------------------------------------------------------

Catalogos carregaCatalogos(FILE* user,FILE* driver, FILE* rides){
    Catalogos cat = malloc(sizeof(Catalogos) * 1000);
    printf("\n A carregar Users ...\n");
    CatUser catalogoUsers = parseUser(user);
    printf("\n A carregar Drivers ...\n");
    CatDriver catalogoDrivers = parseDrivers(driver);
    printf("\n A carregar Rides ...\n");
    CatRides catalogoRides = parseRides(rides);
    cat->Driver = catalogoDrivers->Driver;
    cat->user = catalogoUsers->user;
    cat->Rides = catalogoRides->Rides;
    return cat;
}
