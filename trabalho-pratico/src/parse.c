#include "../include/parse.h"

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
        if(a){
            g_hash_table_insert(user, get_username_user(a), a); // key é o username
        }
    }

    set_catUser(catalogoUser, user);

    fclose(fileUser);

    return catalogoUser;
}


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
        if(r){
        g_hash_table_insert(rides, get_id_Rides(r), r); // key é o id do rides
        g_hash_table_insert(ridesuser, get_user_Rides(r), r); // key é o user do rides
        g_hash_table_insert(ridesdriver, get_driver_Rides(r), r);  // key é o driver do rides
        }
    } 

    set_catRides(catalogoRides, ridesuser, ridesdriver, rides);
    fclose(fileRides);

    return catalogoRides;
}



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
        if(d){
            g_hash_table_insert(driver, get_id_driver(d), d);
        }
    }

    set_catDriver(catalogoDriver, driver);

    fclose(fileDriver);

    return catalogoDriver;
}