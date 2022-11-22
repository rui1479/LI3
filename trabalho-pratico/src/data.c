#include "../include/data.h"

struct data{
    int dia;
    int mes;
    int ano;
};

int get_dia (Data a){
        return a->dia;
}

int get_mes (Data a){
        return a->mes;
}

int get_ano (Data a){
    return a->ano;
}

Data build_data(char *line){

    Data a = malloc(sizeof(struct data));

    a->dia = atoi(strsep(&line, "/\n"));
    a->mes = atoi(strsep(&line, "/\n"));
    a->ano = atoi(strsep(&line, "/\n"));

    return a;
}