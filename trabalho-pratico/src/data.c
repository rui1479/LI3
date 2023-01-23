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

int compara_datas(Data a, Data b){
    return (get_ano(a) > get_ano(b) || get_ano(a) == get_ano(b) && get_mes(a) > get_mes(b) || get_ano(a) == get_ano(b) && get_mes(a) == get_mes(b) && get_dia(a) > get_dia(b) || get_ano(a) == get_ano(b) && get_mes(a) == get_mes(b) && get_dia(a) == get_dia(b));
}

Data build_data(char *line){

    Data a = malloc(sizeof(struct data));

    a->dia = atoi(strsep(&line, "/\n"));
    a->mes = atoi(strsep(&line, "/\n"));
    a->ano = atoi(strsep(&line, "/\n"));

    return a;
}

void print_data(Data a) {
    printf("%i | %i | %i \n",
        a -> dia,
        a -> mes,
        a -> ano);
}
