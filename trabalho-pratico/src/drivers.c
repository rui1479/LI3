#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/drivers.h"

struct driver{
    char *id;
    char *name;
    char *birth;
    char *gender;
    char *car_class;
    char *license_plate;
    char *city;
    char *account_creation;
    char *account_status;
};

char* get_id_driver (Driver a){
    if (a){
        return g_strdup(a->id);
    }
    return NULL;
}

char* get_name_driver (Driver a){
    if (a){
        return g_strdup(a->name);
    }
    return NULL;
}

char* get_birth_driver (Driver a){
    if (a){
        return g_strdup(a->birth);
    }
    return NULL;
}

char* get_gender_driver (Driver a){
    if (a){
        return g_strdup(a->gender);
    }
    return NULL;
}

char* get_car_class_driver (Driver a){
    if (a){
        return g_strdup(a->car_class);
    }
    return NULL;
}

char* get_license_plate_driver (Driver a){
    if (a){
        return g_strdup(a->license_plate);
    }
    return NULL;
}

char* get_city_driver (Driver a){
    if (a){
        return g_strdup(a->city);
    }
    return NULL;
}

char* get_account_creation_driver (Driver a){
    if (a){
        return g_strdup(a->account_creation);
    }
    return NULL;
}

char* get_account_status_driver (Driver a){
    if (a){
        return g_strdup(a->account_status);
    }
    return NULL;
}

Driver build_Driver(char *line){

        Driver a = malloc(sizeof(struct driver));

        a->id = strdup((strsep(&line, ";\n")));
        a->name = strdup(strsep(&line, ";\n"));
        a->birth = strdup(strsep(&line, ";\n"));
        a->gender = strdup(strsep(&line, ";\n"));
        a->car_class = strdup(strsep(&line, ";\n"));
        a->license_plate = strdup(strsep(&line, ";\n"));
        a->city = strdup(strsep(&line, ";\n"));
        a->account_creation = strdup(strsep(&line, ";\n"));
        a->account_status = strdup(strsep(&line, ";\n"));
        
    return a;

}

// void print_driver(Driver a) {
//     printf("%s | %s | %s | %s | %s | %s | %s | %s | %s \n",
//         a -> id,
//         a -> name,
//         a -> birth,
//         a -> gender,
//         a -> car_class,
//         a -> license_plate,
//         a -> city,
//         a -> account_creation,
//         a -> account_status);
// }
