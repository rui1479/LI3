#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data* Data;

int get_dia (Data a);
int get_mes (Data a);
int get_ano (Data a);

Data build_data(char *line);

#endif