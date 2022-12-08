#ifndef MENU_H
#define MENU_H

#include <glib.h>
#include <gmodule.h>

#include "../include/catalogos.h"

void printMenuPrincipal();
int printSubMenu();

void printQuerie1_U(Catalogos catalogo, char* id);
void printQuerie1_D(Catalogos catalogo, char* id);
void printQuerie4(Catalogos catalogo, char* city);
void printQuerie5(Catalogos catalogo, char* data_inicial, char* data_final);
void printQuerie6(Catalogos catalogo, char* city, char* data_inicial, char* data_final);

#endif