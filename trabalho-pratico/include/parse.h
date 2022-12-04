#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "../include/drivers.h"
#include "../include/rides.h"
#include "../include/user.h"
#include "../include/queries.h"
#include "../include/getters.h"
#include "../include/data.h"
#include "../include/validadur.h"

CatUser parseUser(FILE* fileUser);
CatRides parseRides(FILE* fileRides);
CatDriver parseDrivers(FILE* fileDriver);


#endif                                                                              