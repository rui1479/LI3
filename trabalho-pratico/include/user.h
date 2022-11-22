#ifndef USERS_H
#define USERS_H

#include <glib.h>
#include <gmodule.h>

typedef struct user* User;
typedef struct catalog_user* CatUser;

char* get_username_user(User a);
char* get_name_user(User a);
char* get_gender_user(User a) ;
char* get_birth_date_user(User a);
char* get_account_creation_user(User a);
char* get_pay_method_user(User a);
char* get_account_status_user(User a);

void set_catUser(CatUser c, GHashTable* u);

GHashTable* get_catalogo_users(CatUser c);

struct catalog_user {
    GHashTable* user;
};


User build_user(char *line);

#endif