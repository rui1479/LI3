#ifndef USERS_H
#define USERS_H

#include <glib.h>
#include <gmodule.h>

typedef struct user* User;

char* get_username_user(User a);
char* get_name_user(User a);
char* get_gender_user(User a) ;
char* get_birth_date_user(User a);
char* get_account_creation_user(User a);
char* get_pay_method_user(User a);
char* get_account_status_user(User a);

void free_user(struct user* u);

User build_user(char *line);

#endif