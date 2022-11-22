#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <ctype.h>

#include "../include/drivers.h"
#include "../include/rides.h"
#include "../include/user.h"
#include "../include/queries.h"
#include "../include/getters.h"
#include "../include/data.h"

CatUser parseUser();
CatRides parseRides();
CatDriver parseDrivers();


#endif