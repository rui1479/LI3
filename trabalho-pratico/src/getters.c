#include "../include/getters.h"
#define ANO "09/10/2022"


//-------------------------------------------------------------------------USERS----------------------------------------------------------------------------------------------------------------

char* get_name_list_user(CatUser catalogos, char* username){
  char* novousername = strsep(&username,"\n");
  User user = g_hash_table_lookup(catalogos->user, novousername);
  char* name = g_strdup(get_name_user(user));
  return name;
} 

char* get_gender_list_user(CatUser catalogos, char* username){
  char* novousername = strsep(&username,"\n");
  User user = g_hash_table_lookup(catalogos->user, novousername);
  char* gender = g_strdup(get_gender_user(user));
  return gender;
}

int get_idade_list_User(CatUser catalogos, char* username){
  char* novousername = strsep(&username,"\n");
  int idade = 0;
  User user = g_hash_table_lookup(catalogos->user, novousername);
  if(user){
    char* birth_day = g_strdup(get_birth_date_user(user));
    Data nascimento = build_data(birth_day);
    Data ref = build_data(g_strdup(ANO));
    int ano_nascimento = get_ano(nascimento);
    int ano_ref = get_ano(ref);
    int mes_nascimento = get_mes(nascimento);
    int mes_ref = get_mes(ref);
    int dia_nascimento = get_dia(nascimento);
    int dia_ref = get_dia(ref);

    idade = (ano_ref) - (ano_nascimento);

    if(mes_nascimento>mes_ref||(mes_nascimento==mes_ref&&dia_nascimento>dia_ref)){
      idade = idade - 1;
    }
  }
  return idade;
}

// void get_status(CatUser catalogos, char* username){
//   char* novousername = strsep(&username,"\n");
//   User user = g_hash_table_lookup(catalogos->user, novousername);
//   if(strcmp("active",get_account_status_user(user))==0){
//     printf("1");
//   }
//   else printf("0");
// }

//-------------------------------------------------------------------------DRIVERS----------------------------------------------------------------------------------------------------------------

char* get_name_list_driver(CatDriver catalogos, char* id){
  char* novoid = strsep(&id,"\n");
  Driver drivers = g_hash_table_lookup(catalogos->Driver, novoid);
  char* name = g_strdup(get_name_driver(drivers));
  return name;
}        

char* get_gender_list_driver(CatDriver catalogos, char* id){
  char* novoid = strsep(&id,"\n");
  Driver driver = g_hash_table_lookup(catalogos->Driver, novoid);
  char* gender = g_strdup(get_gender_driver(driver));
  return gender;
}

int get_idade_list_driver(CatDriver catalogos, char* id){
  char* novoid = strsep(&id,"\n");
  int idade = 0;
  Driver driver = g_hash_table_lookup(catalogos->Driver, novoid);
  if(driver){
    char* birth_day = g_strdup(get_birth_driver(driver));
    Data nascimento = build_data(birth_day);
    Data ref = build_data(g_strdup(ANO));
    int ano_nascimento = get_ano(nascimento);
    int ano_ref = get_ano(ref);
    int mes_nascimento = get_mes(nascimento);
    int mes_ref = get_mes(ref);
    int dia_nascimento = get_dia(nascimento);
    int dia_ref = get_dia(ref);

    idade = (ano_ref) - (ano_nascimento);

    if(mes_nascimento>mes_ref||(mes_nascimento==mes_ref&&dia_nascimento>dia_ref)){
      idade = idade - 1;
    }
  }
  return idade;
}

//-------------------------------------------------------------------------RIDES-DRIVER----------------------------------------------------------------------------------------------------------------

double get_avaliacao_media(CatRides catalogos, char* id){
  char* novoid = strsep(&id,"\n");
  double total;
  float score;
  int contador=0;
  gpointer key, value;
  GHashTableIter iter;
  g_hash_table_iter_init(&iter, catalogos->Rides); 
  while(g_hash_table_iter_next(&iter, &key, &value)){
    Rides ride = value;
    if(atoi(novoid) == atoi(get_driver_Rides(ride))){
      score += atof(get_score_driver_Rides(ride));
      contador++;
    }
  }

  total = (double)score/contador;

  return total;
}

int get_numero_viagens(CatRides catalogos, char *id){
  char* novoid = strsep(&id,"\n");
  int contador=0;
  gpointer key, value;
  GHashTableIter iter;
  g_hash_table_iter_init(&iter, catalogos->Rides); 
  while(g_hash_table_iter_next(&iter, &key, &value)){
    Rides ride = value;
    if(atoi(novoid) == atoi(get_driver_Rides(ride))){
      contador++;
    }
  }
  return contador;
}

double get_total_euferido(CatRides catalogosrides, CatDriver catalogosdrivers, char *id){
  char* novoid = strsep(&id,"\n");
  Driver drivers = g_hash_table_lookup(catalogosdrivers->Driver, novoid);
  char* car_class = g_strdup(get_car_class_driver(drivers));

  double km=0;
  float tip = 0;
  double total = 0;

  gpointer key, value;
  GHashTableIter iter;
  g_hash_table_iter_init(&iter, catalogosrides->Rides); 
  while(g_hash_table_iter_next(&iter, &key, &value)){
    Rides ride = value;
    
    if(atoi(novoid) == atoi(get_driver_Rides(ride))){
        km = atoi(get_distance_Rides(ride));
        tip = atof(get_tip_Rides(ride));


        if(strcmp("green",car_class)==0){
          total += 4 + 0.79 * km + tip;
        }

        if(strcmp("basic",car_class)==0){
          total += 3.25 + 0.62 * km + tip;
        }
          
        if(strcmp("premium",car_class)==0){
          total += 5.20 + 0.94 * km + tip;
      }
    }
  }

  return total;
}

//-------------------------------------------------------------------------RIDES-USER----------------------------------------------------------------------------------------------------------------

double get_avaliacao_media_user(CatRides catalogos, char* username){
  char* novousername = strsep(&username,"\n");
  double total;
  float score;
  int contador=0;
  gpointer key, value;
  GHashTableIter iter;
  g_hash_table_iter_init(&iter, catalogos->Rides); 
  while(g_hash_table_iter_next(&iter, &key, &value)){
    Rides ride = value;
    if(strcmp(novousername,get_user_Rides(ride)) == 0){
      score += atof(get_score_user_Rides(ride));
      contador++;
    }
  }

  total = (double)score/contador;

  return total;
}

int get_numero_viagens_user(CatRides catalogos, char *username){
  char* novousername = strsep(&username,"\n");
  int contador=0;
  gpointer key, value;
  GHashTableIter iter;
  g_hash_table_iter_init(&iter, catalogos->Rides); 
  while(g_hash_table_iter_next(&iter, &key, &value)){
    Rides ride = value;
    if(strcmp(novousername,get_user_Rides(ride)) == 0){
      contador++;
    }
  }
  return contador;
}

double get_total_gasto(CatRides catalogosrides, CatUser catalogosusers, CatDriver catalogodrivers, char *username){
  char* novousername = strsep(&username,"\n");

  double km=0;
  float tip = 0;
  double total = 0;

  gpointer key, value;
  GHashTableIter iter;
  g_hash_table_iter_init(&iter, catalogosrides->Rides); 
  while(g_hash_table_iter_next(&iter, &key, &value)){
    Rides ride = value;

    char* id = get_driver_Rides(ride);

    Driver drivers = g_hash_table_lookup(catalogodrivers->Driver, id);
    char* car_class = g_strdup(get_car_class_driver(drivers));

    if(strcmp(novousername,get_user_Rides(ride)) == 0){
        km = atoi(get_distance_Rides(ride));
        tip = atof(get_tip_Rides(ride));


        if(strcmp("green",car_class)==0){
          total += 4 + 0.79 * km + tip;
        }

        if(strcmp("basic",car_class)==0){
          total += 3.25 + 0.62 * km + tip;
        }
          
        if(strcmp("premium",car_class)==0){
          total += 5.20 + 0.94 * km + tip;
      }
    }
  }

  return total;
}

double get_preco_medio_city(CatRides catalogosrides, CatDriver catalogodrivers, char *city){
  char* novacity = strsep(&city,"\n");

  double km=0;
  double total = 0;
  int contador=0;

  gpointer key, value;
  GHashTableIter iter;
  g_hash_table_iter_init(&iter, catalogosrides->Rides); 
  while(g_hash_table_iter_next(&iter, &key, &value)){
    Rides ride = value;
    char* id = get_driver_Rides(ride);

    Driver drivers = g_hash_table_lookup(catalogodrivers->Driver, id);
    char* car_class = g_strdup(get_car_class_driver(drivers));
    
    if(strcmp(novacity,get_city_Rides(ride)) == 0){
        km = atoi(get_distance_Rides(ride));
        if(strcmp("green",car_class)==0){
          total += 4 + 0.79 * km;
        }

        if(strcmp("basic",car_class)==0){
          total += 3.25 + 0.62 * km;
        }
          
        if(strcmp("premium",car_class)==0){
          total += 5.20 + 0.94 * km;
      }
      contador++;
    }
  }

  total = total / contador;

  return total;
}