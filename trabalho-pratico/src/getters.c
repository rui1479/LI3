#include "../include/getters.h"
#define ANO "09/10/2022"

//-------------------------------------------------------------------------STRUCTS----------------------------------------------------------------------------------------------------------------

struct aux_driver{
    char *id;
    char* nome;
    double avaliacao;
    int contador;
    Data viagem_recente;
};

struct aux_user{
    char *username;
    char *nome;
    int distotal;
    Data viagem_recente;
};

struct aux_q7{
    char *id;
    char *nome;
    double avaliacao;
    int contador;
    char *city;
};

struct aux_q8{
    char *gender;
    char *id;
    char *nome;
    char *username;
    char *nome_user;
};

struct aux_q9{
    char *id;
    Data data_viagem;
    char *distancia;
    char *cidade;
    char *tip;
};

struct data{
    int dia;
    int mes;
    int ano;
};

typedef struct data* Data;

//-------------------------------------------------------------------------FUNÇÕES AUXILIARES----------------------------------------------------------------------------------------------------------------


// int sort_function_driver(gconstpointer a, gconstpointer b){
//     struct aux_driver *da = (struct aux_driver *)a;
//     struct aux_driver *db = (struct aux_driver *)b;

//     double avaliacao_a = da->avaliacao / da->contador;
//     double avaliacao_b = db->avaliacao / db->contador;

//     Data data_a = da->viagem_recente;
//     Data data_b = db->viagem_recente;

//     if (avaliacao_a < avaliacao_b) return 1;
//     else if (avaliacao_a > avaliacao_b) return -1;
//     else if (compara_datas(data_a,data_b)) return 1;
//     else if (!compara_datas(data_a,data_b)) return -1;
//     else return strcmp(da->id, db->id);
// }

gint sort_function_driver(gconstpointer a, gconstpointer b) {
    struct aux_driver *driver1 = (struct aux_driver *)a;
    struct aux_driver *driver2 = (struct aux_driver *)b;

    double avaliacao1 = driver1->avaliacao / driver1->contador;
    double avaliacao2 = driver2->avaliacao / driver2->contador;

    if (avaliacao1 != avaliacao2)
        return (avaliacao2 > avaliacao1) ? 1 : -1;

    if (driver1->viagem_recente->ano != driver2->viagem_recente->ano)
        return driver2->viagem_recente->ano - driver1->viagem_recente->ano;

    if (driver1->viagem_recente->mes != driver2->viagem_recente->mes)
        return driver2->viagem_recente->mes - driver1->viagem_recente->mes;

    if (driver1->viagem_recente->dia != driver2->viagem_recente->dia)
        return driver2->viagem_recente->dia - driver1->viagem_recente->dia;

    return strcmp(driver1->id, driver2->id);
}

int sort_function_user(gconstpointer a, gconstpointer b){
    struct aux_user *user1 = (struct aux_user *)a;
    struct aux_user *user2 = (struct aux_user *)b;

    if (user1->distotal != user2->distotal)
        return user2->distotal - user1->distotal;

    if (user1->viagem_recente->ano != user2->viagem_recente->ano)
        return user2->viagem_recente->ano - user1->viagem_recente->ano;

    if (user1->viagem_recente->mes != user2->viagem_recente->mes)
        return user2->viagem_recente->mes - user1->viagem_recente->mes;

    if (user1->viagem_recente->dia != user2->viagem_recente->dia)
        return user2->viagem_recente->dia - user1->viagem_recente->dia;

    return g_strcmp0(user1->username, user2->username);
}

// int sort_function_q7(gconstpointer a, gconstpointer b){
//     struct aux_q7 *da = (struct aux_q7 *)a;
//     struct aux_q7 *db = (struct aux_q7 *)b;

//     double avaliacao_a = da->avaliacao / da->contador;
//     double avaliacao_b = db->avaliacao / db->contador;

//     char *id_a = na->id;
//     char *id_b = nb->id;

//     if (avaliacao_a < avaliacao_b) return 1;
//     else if (avaliacao_a > avaliacao_b) return -1;
//     else if (strcmp(atof(na),atof(nb))==0) return 1;
//     else if (!strcmp(atof(na),atof(nb))==0) return -1;
//     else return strcmp(na->id, nb->id);
// }

gint sort_function_q9(gconstpointer a, gconstpointer b){
    struct aux_q9 *viagem_a = (struct aux_q9 *) a;
    struct aux_q9 *viagem_b = (struct aux_q9 *) b;

    int dist_a = atoi(viagem_a->distancia);
    int dist_b = atoi(viagem_b->distancia);

    if (dist_a == dist_b){
        if (viagem_a->data_viagem->ano == viagem_b->data_viagem->ano){
            if (viagem_a->data_viagem->mes == viagem_b->data_viagem->mes){
                if (viagem_a->data_viagem->dia == viagem_b->data_viagem->dia)
                    return g_strcmp0(viagem_b->id, viagem_a->id);
                else
                    return viagem_b->data_viagem->dia - viagem_a->data_viagem->dia;
            }
            else
                return viagem_b->data_viagem->mes - viagem_a->data_viagem->mes;
        }
        else
            return viagem_b->data_viagem->ano - viagem_a->data_viagem->ano;
    }
    else
        return dist_b - dist_a;
}

//-------------------------------------------------------------------------USERS----------------------------------------------------------------------------------------------------------------

char* get_name_list_user(Catalogos catalogos, char* username){
  char* novousername = strsep(&username,"\n");
  User user = g_hash_table_lookup(catalogos->user, novousername);
  char* name = g_strdup(get_name_user(user));
  return name;
} 

char* get_gender_list_user(Catalogos catalogos, char* username){
  char* novousername = strsep(&username,"\n");
  User user = g_hash_table_lookup(catalogos->user, novousername);
  char* gender = g_strdup(get_gender_user(user));
  return gender;
}

int get_idade_list_User(Catalogos catalogos, char* username){
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

// void get_status(Catalogos catalogos, char* username){
//   char* novousername = strsep(&username,"\n");
//   User user = g_hash_table_lookup(catalogos->user, novousername);
//   if(strcmp("active",get_account_status_user(user))==0){
//     printf("1");
//   }
//   else printf("0");
// }

//-------------------------------------------------------------------------DRIVERS----------------------------------------------------------------------------------------------------------------

char* get_name_list_driver(Catalogos catalogos, char* id){
  char* novoid = strsep(&id,"\n");
  Driver drivers = g_hash_table_lookup(catalogos->Driver, novoid);
  char* name = g_strdup(get_name_driver(drivers));
  return name;
}        

char* get_gender_list_driver(Catalogos catalogos, char* id){
  char* novoid = strsep(&id,"\n");
  Driver driver = g_hash_table_lookup(catalogos->Driver, novoid);
  char* gender = g_strdup(get_gender_driver(driver));
  return gender;
}

int get_idade_list_driver(Catalogos catalogos, char* id){
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

double get_avaliacao_media(Catalogos catalogos, char* id){
  char* novoid = strsep(&id,"\n");
  double total;
  double score;
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

int get_numero_viagens(Catalogos catalogos, char *id){
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

double get_total_euferido(Catalogos catalogos, char *id){
  char* novoid = strsep(&id,"\n");
  Driver drivers = g_hash_table_lookup(catalogos->Driver, novoid);
  char* car_class = g_strdup(get_car_class_driver(drivers));

  double km=0;
  float tip = 0;
  double total = 0;

  gpointer key, value;
  GHashTableIter iter;
  g_hash_table_iter_init(&iter, catalogos->Rides); 
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

double get_avaliacao_media_user(Catalogos catalogos, char* username){
  char* novousername = strsep(&username,"\n");
  double total;
  double score;
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

int get_numero_viagens_user(Catalogos catalogos, char *username){
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

double get_total_gasto(Catalogos catalogos, char *username){
  char* novousername = strsep(&username,"\n");

  double km=0;
  float tip = 0;
  double total = 0;

  gpointer key, value;
  GHashTableIter iter;
  g_hash_table_iter_init(&iter, catalogos->Rides); 
  while(g_hash_table_iter_next(&iter, &key, &value)){
    Rides ride = value;

    char* id = get_driver_Rides(ride);

    Driver drivers = g_hash_table_lookup(catalogos->Driver, id);
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

double get_preco_medio_city(Catalogos catalogos, char *city){
  char* novacity = strsep(&city,"\n");

  double km=0;
  double total = 0;
  int contador=0;

  gpointer key, value;
  GHashTableIter iter;
  g_hash_table_iter_init(&iter, catalogos->Rides); 
  while(g_hash_table_iter_next(&iter, &key, &value)){
    Rides ride = value;

    char* id = get_driver_Rides(ride);

    Driver drivers = g_hash_table_lookup(catalogos->Driver, id);
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

double get_preco_medio_data(Catalogos catalogo, char* data_inicial, char* data_final){

  Data inicial = build_data(data_inicial);
  Data final = build_data(data_final);


  int contador = 0;
  int km = 0;
  double total = 0;

   gpointer key, value;
   GHashTableIter iter;

   g_hash_table_iter_init(&iter, catalogo->Rides); 
   while(g_hash_table_iter_next(&iter, &key, &value)){
     Rides ride = value;
     char* id = get_driver_Rides(ride);

     Driver drivers = g_hash_table_lookup(catalogo->Driver, id);
     char* car_class = g_strdup(get_car_class_driver(drivers));
     char* data_ref = get_date_Rides(ride);

    Data data_a_comparar = build_data(data_ref);
    
     if(compara_datas(data_a_comparar,inicial) && compara_datas(final,data_a_comparar)){
        contador++;
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
    }
  }
  total = total / contador;
return total;
}

double get_distancia_media_city(Catalogos catalogo, char* city, char* data_inicial, char* data_final){
  Data inicial = build_data(data_inicial);
  Data final = build_data(data_final);

  int contador = 0;
  int km = 0;
  double total = 0;

   gpointer key, value;
   GHashTableIter iter;
   g_hash_table_iter_init(&iter, catalogo->Rides); 
   while(g_hash_table_iter_next(&iter, &key, &value)){
     Rides ride = value;
     char* data_ref = get_date_Rides(ride);

    Data data_a_comparar = build_data(data_ref);
    
     if(compara_datas(data_a_comparar,inicial) && compara_datas(final,data_a_comparar) && strcmp(city,get_city_Rides(ride)) == 0){
      km += atoi(get_distance_Rides(ride));
      contador++;
     }
  }
  printf("%i\n",km);
  printf("%i",contador);
  total = (double)km / contador;

  return total;
}

GList* auxquerie2 (Catalogos catalogo){
  GHashTable* map = g_hash_table_new(g_str_hash, g_str_equal);
    gpointer keyQuery2, valueQuery2;
    GHashTableIter iterQuery2;

    g_hash_table_iter_init(&iterQuery2,catalogo->Rides);
    while(g_hash_table_iter_next(&iterQuery2, &keyQuery2, &valueQuery2)) {
        Rides ride = valueQuery2;
        Driver driver = g_hash_table_lookup(catalogo->Driver,get_driver_Rides(ride));
        if(strcmp(get_account_status_driver(driver),"active")==0){
            if(!g_hash_table_contains(map,get_driver_Rides(ride))){
              AUX_DRIVER elem = malloc(sizeof(struct aux_driver));
              elem->id = get_driver_Rides(ride);
              Driver drivers = g_hash_table_lookup(catalogo->Driver, elem->id);
              elem->nome = get_name_driver(drivers);
              elem->avaliacao = atof(get_score_driver_Rides(ride));
              elem->contador = 1;
              elem->viagem_recente = build_data(get_date_Rides(ride));
              g_hash_table_insert(map, elem->id, elem);
            }
        else {
            AUX_DRIVER elem = g_hash_table_lookup(map,get_driver_Rides(ride));
            elem->avaliacao = elem->avaliacao + atof(get_score_driver_Rides(ride));
            Data acomparar = build_data(get_date_Rides(ride));
            elem->viagem_recente = compara_datas(elem->viagem_recente,acomparar) ? elem->viagem_recente : acomparar;
            elem->contador++;
            g_hash_table_insert(map, elem->id, elem);
          }
        }
    }
    
    GList* list = g_hash_table_get_values(map);
    GList* sorted = g_list_sort(list, sort_function_driver);

    g_list_free(list);
    g_hash_table_destroy(map);

    return sorted;
}

GList* auxquerie3 (Catalogos catalogo){
    GHashTable* map = g_hash_table_new(g_str_hash, g_str_equal);
    gpointer keyQuery3, valueQuery3;
    GHashTableIter iterQuery3;

    g_hash_table_iter_init(&iterQuery3,catalogo->Rides);
    while(g_hash_table_iter_next(&iterQuery3, &keyQuery3, &valueQuery3)) {
        Rides ride = valueQuery3;
        User users = g_hash_table_lookup(catalogo->user, get_user_Rides(ride));
        if(strcmp(get_account_status_user(users),"active") == 0){
          if(!g_hash_table_contains(map,get_user_Rides(ride))){
            AUX_USER elem = malloc(sizeof(struct aux_user));
            elem->username = get_user_Rides(ride);
            User user = g_hash_table_lookup(catalogo->user, elem->username);
            elem->nome = get_name_user(user);
            elem->distotal = atoi(get_distance_Rides(ride));
            elem->viagem_recente = build_data(get_date_Rides(ride));
            g_hash_table_insert(map, elem->username, elem);
        }
        else {
            AUX_USER elem = g_hash_table_lookup(map,get_user_Rides(ride));
            elem->distotal = elem->distotal + atoi(get_distance_Rides(ride));
            Data acomparar = build_data(get_date_Rides(ride));
            elem->viagem_recente = compara_datas(elem->viagem_recente,acomparar) ? elem->viagem_recente : acomparar;
            g_hash_table_insert(map, elem->username, elem);
          }
        }
    }
    
    GList* list = g_hash_table_get_values(map);
    GList* sorted = g_list_sort(list, sort_function_user);

    //g_list_free(list);
    //g_list_free(sorted);
    //g_hash_table_destroy(map);

    return sorted;
}

// GList* auxquerie7 (Catalogos catalogo, char* city){
//   GHashTable* map = g_hash_table_new(g_str_hash, g_str_equal);
//   gpointer keyQuery7, valueQuery7;
//   GHashTableIter iterQuery7;

//   char* novacity = strsep(&city,"\n");

//   g_hash_table_iter_init(&iterQuery7,catalogo->Rides);
//   while(g_hash_table_iter_next(&iterQuery7, &keyQuery7, &valueQuery7)) {
//       Rides ride = valueQuery7;
//       if(strcmp(novacity,get_city_Rides(ride)) == 0){
//         if(!g_hash_table_contains(map,get_driver_Rides(ride))){
//             AUX_Q7 elem = malloc(sizeof(struct aux_q7));
//             elem->id = get_driver_Rides(ride);
//             Driver drivers = g_hash_table_lookup(catalogo->Driver, elem->id);
//             elem->nome = get_name_driver(drivers);
//             elem->avaliacao = atof(get_score_driver_Rides(ride));
//             elem->contador = 1;
//             elem->id = get_driver_Rides(ride);
//             g_hash_table_insert(map, elem->id, elem);
//         }
//         else {
//             AUX_Q7 elem = g_hash_table_lookup(map,get_driver_Rides(ride));
//             elem->avaliacao = elem->avaliacao + atof(get_score_driver_Rides(ride));
//             elem->contador++;
//             g_hash_table_insert(map, elem->id, elem);
//         }
//       }
//     }
    
//     GList* list = g_hash_table_get_values(map);
//     GList* sorted = g_list_sort(list, sort_function_q7); (Não esquecer de mudar o return e a função de sort)

//     g_list_free(list);
//     g_hash_table_destroy(map);

//     return list;
// }

//  GList* auxquerie8 (Catalogos catalogo,char* gender){
//     GHashTable* map = g_hash_table_new(g_str_hash, g_str_equal);
//     gpointer keyQuery8, valueQuery8;
//     GHashTableIter iterQuery8;

//     char* novogender = strsep(&gender,"\n");

//     g_hash_table_iter_init(&iterQuery8,catalogo->Rides);
//     while(g_hash_table_iter_next(&iterQuery8, &keyQuery8, &valueQuery8)) {
//         Rides ride = valueQuery8;
      
//         AUX_Q8 elem = malloc(sizeof(struct aux_q8)); 
//         elem->id = get_driver_Rides(ride);
//         Driver drivers = g_hash_table_lookup(catalogo->Driver, elem->id);
//         elem->username = get_user_Rides(ride);
//         User user = g_hash_table_lookup(catalogo->user, elem->username);
//         if(strcmp(get_gender_driver(drivers),get_gender_user(user))==0 && strcmp(novogender,get_gender_driver(drivers)) == 0 ){
//           elem->nome = get_name_driver(drivers);
//           elem->nome_user = get_name_user(user);
//           g_hash_table_insert(map, elem->id, elem);
//         }
//       }
    
//     GList* list = g_hash_table_get_values(map);
//     GList* sorted = g_list_sort(list, sort_function_q9);

//     return sorted;
// }


 GList* auxquerie9 (Catalogos catalogo,char* data_inicial, char* data_final){
    GHashTable* map = g_hash_table_new(g_str_hash, g_str_equal);
    gpointer keyQuery9, valueQuery9;
    GHashTableIter iterQuery9;

    Data inicial = build_data(data_inicial);
    Data final = build_data(data_final);

    g_hash_table_iter_init(&iterQuery9,catalogo->Rides);
    while(g_hash_table_iter_next(&iterQuery9, &keyQuery9, &valueQuery9)) {
        Rides ride = valueQuery9;
        Data data_a_comparar = build_data(get_date_Rides(ride));
        if(compara_datas(data_a_comparar,inicial) && compara_datas(final,data_a_comparar)){
            AUX_Q9 elem = malloc(sizeof(struct aux_q9));
            elem->id = get_id_Rides(ride);
            elem->data_viagem = build_data(get_date_Rides(ride));
            elem->distancia = get_distance_Rides(ride);
            elem->cidade = get_city_Rides(ride);
            elem->tip = get_tip_Rides(ride);
            g_hash_table_insert(map, elem->id, elem);
        }
    }
    GList* list = g_hash_table_get_values(map);
    GList* sorted = g_list_sort(list, sort_function_q9);

    return sorted;
}
