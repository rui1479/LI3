#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/user.h"

struct user {
    char *username; 
    char *name;
    char *gender;
    char *birth_date;
    char *account_creation;
    char *pay_method;
    char *account_status;
};


char* get_username_user(User a) {
  if(a)
    return a->username;
  return NULL;
}

char* get_name_user(User a) {
  if(a)
    return a->name;
  return NULL;
}

char* get_gender_user(User a) {
  if(a)
    return a->gender;
  return NULL;
}

char* get_birth_date_user(User a) {
  if(a)
    return a->birth_date;
  return NULL;
}

char* get_account_creation_user(User a) {
  if(a)
    return a->account_creation;
  return NULL;
}

char* get_pay_method_user(User a) {
  if(a)
    return a->pay_method;
  return NULL;
}

char* get_account_status_user(User a) {
  if(a)
    return a->account_status;
  return NULL;
}

void set_catUser(CatUser c, GHashTable* u){
  c->user = u;
}

GHashTable* get_catalogo_users(CatUser c){
  return c->user;
}

User build_user(char *line) {

    User a = malloc(sizeof(struct user));

    a -> username = strdup(strsep(&line, ";\n"));
    a -> name = strdup(strsep(&line, ";\n"));
    a -> gender = strdup(strsep(&line, ";\n"));
    a -> birth_date = strdup(strsep(&line, ";\n"));    
    a -> account_creation = strdup(strsep(&line, ";\n"));
    a -> pay_method = strdup(strsep(&line, ";\n"));
    a -> account_status = strdup(strsep(&line, ";\n"));
  
    return a;

}

// void print_user(User a) {
//     printf("%s | %s | %s | %s | %s | %s | %s | %s | %s | %s \n",
//         a -> username,
//         a -> name,
//         a -> gender,
//         a -> birth_date,
//         a -> account_creation,
//         a -> pay_method,
//         a -> account_status;  
// }
