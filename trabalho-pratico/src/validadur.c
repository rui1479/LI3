#include "../include/validadur.h"

int campos_positivos (char *line){
    return (strlen(line)>0);
}

int testa_data (char *line){
   int dateINT[3], i;

    if (sscanf(line, "%d/%d/%d", &dateINT[0], &dateINT[1], &dateINT[2]) == 3 ){
        if ((dateINT[0] > 0 && dateINT[0] < 32) && (dateINT[1] > 0 && dateINT[1] < 13) && (dateINT[2] > 1800 && dateINT[2] < 2500 )){
            return 1;
        }   
        else {
            return 0;
        }
    } 
    else {
        return 0;
    }
}

int testa_as_cc (char *line){
    
    int valido = 0;
    int n = strlen(line);

    if(line[0] == 'a' || line [0] == 'A'){
        char ac[6];

        for (size_t i = 0; i <= n; ++i) {
            ac[i] = tolower((unsigned char) line[i]);
        }

        if(strcmp(ac,"active") == 0){
            valido = 1;
        }
    }

    if(line[0] == 'i' || line [0] == 'I'){
        char ac[8];

        for (size_t i = 0; i <= n; ++i) {
            ac[i] = tolower((unsigned char) line[i]);
        }

        if(strcmp(ac,"inactive") == 0){
            valido = 1;
        }
    }

    if(line[0] == 'g' || line [0] == 'G'){
        char cc[5];

        for (size_t i = 0; i <= n; ++i) {
            cc[i] = tolower((unsigned char) line[i]);
        }

        if(strcmp(cc,"green") == 0){
            valido = 1;
        }
    }

    if(line[0] == 'b' || line [0] == 'B'){
        char cc[5];

        for (size_t i = 0; i <= n; ++i) {
            cc[i] = tolower((unsigned char) line[i]);
        }

        if(strcmp(cc,"basic") == 0){
            valido = 1;
        }
    }

    if(line[0] == 'p' || line [0] == 'P'){
        char cc[7];

        for (size_t i = 0; i <= n; ++i) {
            cc[i] = tolower((unsigned char) line[i]);
        }

        if(strcmp(cc,"premium") == 0){
            valido = 1;
        }
    }

    return valido;
}

int testa_distance(char *line){
    char* aux;
    char* restante;

    long resp = strtol(line,&restante,10);

    if (resp > 0 && strlen(restante) == 0){
        return 1;
    }
    
    return 0;
}

int testa_digito(char *numero){
    int valido = 1;
    
    for (int i = 1; *numero ;i++){
        if (!isdigit(numero[i])) valido = 0;
    }

    return valido;
}

int testa_score(char *line){
    char* aux;
    char* restante;

    long resp = strtol(line,&restante,10);

    if((resp > 0 && strlen(restante) == 0) || (resp > 0 && restante[0] == '.' && testa_digito(restante))){
        return 1;
    }
}

int testa_tip(char *line){
    char* aux;
    char* restante;

    long resp = strtol(line,&restante,10);

    if(resp > 0 && strlen(restante) == 0 || resp > 0 && restante[0] == '.' && isdigit(restante[1])){
        return 1;
    }
}

int testdriver (Driver a){
    return (campos_positivos(get_id_driver(a)) && campos_positivos(get_name_driver(a)) &&
            testa_data(get_birth_driver(a)) && campos_positivos(get_gender_driver(a)) && 
            testa_as_cc(get_car_class_driver(a)) && campos_positivos(get_license_plate_driver(a)) &&
            campos_positivos(get_city_driver(a)) && testa_data(get_account_creation_driver(a)) && 
            testa_as_cc(get_account_status_driver(a)));
}

int testuser (User a){
    return (campos_positivos(get_username_user(a)) && campos_positivos(get_name_user(a)) &&
            campos_positivos(get_gender_user(a)) && testa_data(get_birth_date_user(a)) &&
            testa_data(get_account_creation_user(a)) && campos_positivos(get_pay_method_user(a)) && 
            testa_as_cc(get_account_status_user(a)));
}

int testrides (Rides a){
    return (campos_positivos(get_id_Rides(a)) && testa_data(get_date_Rides(a)) &&
            campos_positivos(get_driver_Rides(a)) && campos_positivos(get_user_Rides(a)) &&
            campos_positivos(get_city_Rides(a)) && testa_distance(get_distance_Rides(a)) &&
            testa_score(get_score_user_Rides(a)) && testa_score(get_score_driver_Rides(a)));
}