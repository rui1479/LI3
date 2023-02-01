#include "../include/getters.h"
#define ANO "9/10/2022"

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
};                      

struct aux_q8{
    char *gender;
    char *id;
    char *nome;
    char *username;
    char *nome_user;
    char *viagem;
    Data conta_driver;
    Data conta_user;
};


struct aux_q9{
    char *id;
    Data data_viagem;
    char *distancia;
    char *cidade;
    char *tip;
};

//-------------------------------------------------------------------------FUNÇÕES AUXILIARES----------------------------------------------------------------------------------------------------------------

char* get_id_auxdriver (AUX_DRIVER a){
    if (a){
        return g_strdup(a->id);
    }
    return NULL;
}

char* get_nome_auxdriver (AUX_DRIVER a){
    if (a){
        return g_strdup(a->nome);
    }
    return NULL;
}

double get_avaliacao_auxdriver (AUX_DRIVER a){
    if (a){
        return a->avaliacao;
    }
    return 0;
}

int get_contador_auxdriver (AUX_DRIVER a){
    if (a){
        return a->contador;
    }
    return 0;
}

char* get_user_auxuser (AUX_USER a){
    if (a){
        return g_strdup(a->username);
    }
    return NULL;
}

char* get_nome_auxuser (AUX_USER a){
    if (a){
        return g_strdup(a->nome);
    }
    return NULL;
}

int get_distancia_auxuser (AUX_USER a){
    if (a){
        return a->distotal;
    }
    return 0;
}


char* get_id_auxq7 (AUX_Q7 a){
    if (a){
        return g_strdup(a->id);
    }
    return NULL;
}

char* get_nome_auxq7 (AUX_Q7 a){
    if (a){
        return g_strdup(a->nome);
    }
    return NULL;
}

double get_avaliacao_auxq7 (AUX_Q7 a){
    if (a){
        return a->avaliacao;
    }
    return 0;
}

int get_contador_auxq7 (AUX_Q7 a){
    if (a){
        return a->contador;
    }
    return 0;
}
           

char* get_gender_auxq8 (AUX_Q8 a){
    if (a){
        return g_strdup(a->gender);
    }
    return NULL;
}

char* get_id_auxq8 (AUX_Q8 a){
    if (a){
        return g_strdup(a->id);
    }
    return NULL;
}

char* get_nome_auxq8 (AUX_Q8 a){
    if (a){
        return g_strdup(a->nome);
    }
    return NULL;
}

char* get_username_auxq8 (AUX_Q8 a){
    if (a){
        return g_strdup(a->username);
    }
    return NULL;
}

char* get_nome_user_auxq8 (AUX_Q8 a){
    if (a){
        return g_strdup(a->nome_user);
    }
    return NULL;
}

char* get_viagem_auxq8 (AUX_Q8 a){
    if (a){
        return g_strdup(a->viagem);
    }
    return NULL;
}

Data get_contaD_auxq8 (AUX_Q8 a){
    if (a){
        return (a->conta_driver);
    }
    return NULL;
} 

Data get_contaU_auxq8 (AUX_Q8 a){
    if (a){
        return (a->conta_user);
    }
    return NULL;
} 


char* get_id_auxq9 (AUX_Q9 a){
    if (a){
        return g_strdup(a->id);
    }
    return NULL;
}

char* get_distancia_auxq9 (AUX_Q9 a){
    if (a){
        return g_strdup(a->distancia);
    }
    return NULL;
}

char* get_cidade_auxq9 (AUX_Q9 a){
    if (a){
        return g_strdup(a->cidade);
    }
    return NULL;
}

char* get_tip_auxq9 (AUX_Q9 a){
    if (a){
        return g_strdup(a->tip);
    }
    return NULL;
}

Data get_data_auxq9 (AUX_Q9 a){
    if (a){
        return (a->data_viagem);
    }
    return NULL;
}


int sort_function_driver(gconstpointer a, gconstpointer b) {
    struct aux_driver *driver1 = (struct aux_driver *)a;
    struct aux_driver *driver2 = (struct aux_driver *)b;

    double avaliacao1 = driver1->avaliacao / driver1->contador;
    double avaliacao2 = driver2->avaliacao / driver2->contador;

    Data d1 = driver1->viagem_recente;
    Data d2 = driver2->viagem_recente;

     if (avaliacao1 != avaliacao2)
        return (avaliacao2 > avaliacao1) ? 1 : -1;

    if (get_ano(d1) != get_ano(d2))
        return get_ano(d2) - get_ano(d1);

    if (get_mes(d1) != get_mes(d2))
        return get_mes(d2) - get_mes(d1);

    if (get_dia(d1) != get_dia(d2))
        return get_dia(d2) - get_dia(d1);

    return strcmp(driver1->id, driver2->id);
 }

int sort_function_user(gconstpointer a, gconstpointer b){
    struct aux_user *user1 = (struct aux_user *)a;
    struct aux_user *user2 = (struct aux_user *)b;

    Data u1 = user1->viagem_recente;
    Data u2 = user2->viagem_recente;

    if (user1->distotal != user2->distotal)
        return user2->distotal - user1->distotal;

    if (get_ano(u1) != get_ano(u2))
        return get_ano(u2) - get_ano(u1);

    if (get_mes(u1) != get_ano(u2))
        return get_ano(u2) - get_ano(u1);

    if (get_dia(u1) != get_dia(u2))
        return get_dia(u2) - get_dia(u1);

    return g_strcmp0(user1->username, user2->username);
}

int sort_function_q7(gconstpointer a, gconstpointer b){
    struct aux_q7 *q7_a = (struct aux_q7 *) a;
    struct aux_q7 *q7_b = (struct aux_q7 *) b;
    double rating_a = q7_a->avaliacao / q7_a->contador;
    double rating_b = q7_b->avaliacao / q7_b->contador;
    if (rating_a == rating_b)
        return g_strcmp0(q7_b->id, q7_a->id);
    else
        return (rating_b > rating_a) ? 1 : -1;
}

int sort_function_q8(gconstpointer a, gconstpointer b){
    struct aux_q8 *q8_a = (struct aux_q8 *) a;
    struct aux_q8 *q8_b = (struct aux_q8 *) b;

    Data q1 = q8_a->conta_driver;
    Data q2 = q8_b->conta_driver;
    Data q3 = q8_a->conta_user;
    Data q4 = q8_b->conta_user;

    if (get_ano(q1) == get_ano(q2)){
        if (get_mes(q1) == get_mes(q2)){
            if (get_dia(q1) == get_dia(q2)){ 
                if (get_ano(q3) == get_ano(q4)){
                    if (get_mes(q3) == get_mes(q4)){
                       if (get_dia(q3) == get_dia(q4)){
                        return g_strcmp0(q8_a->viagem, q8_b->viagem);
                       }
                        else
                            return get_dia(q3) - get_dia(q4); 
                    }
                     else
                        return get_mes(q3) - get_mes(q4);
                }
                 else
                    return get_ano(q3) - get_ano(q4);
            }        
             else
                return get_dia(q1) - get_dia(q2); 
        }
         else
             return get_mes(q1) - get_mes(q2);
    }
    else
        return get_ano(q1) - get_ano(q2); 
}

int sort_function_q9(gconstpointer a, gconstpointer b){
    struct aux_q9 *viagem_a = (struct aux_q9 *) a;
    struct aux_q9 *viagem_b = (struct aux_q9 *) b;

    int dist_a = atoi(viagem_a->distancia);
    int dist_b = atoi(viagem_b->distancia);

    Data v1 = viagem_a->data_viagem;
    Data v2 = viagem_b->data_viagem;

    if (dist_a == dist_b){
        if (get_ano(v1) == get_ano(v2)){
            if (get_mes(v1) == get_mes(v2)){
                if (get_dia(v1) == get_dia(v2))
                    return g_strcmp0(viagem_b->id, viagem_a->id);
                else
                    return get_dia(v2) - get_dia(v1);
            }
            else
                return get_mes(v2) - get_mes(v1);
        }
        else
            return get_ano(v2) - get_ano(v1);
    }
    else
        return dist_b - dist_a;
}

//-------------------------------------------------------------------------USERS----------------------------------------------------------------------------------------------------------------

char* get_name_list_user(Catalogos catalogos, char* username){
  char* novousername = strsep(&username,"\n");
  User user = g_hash_table_lookup(get_catalogo_user(catalogos), novousername);
  char* name = g_strdup(get_name_user(user));
  return name;
} 

char* get_gender_list_user(Catalogos catalogos, char* username){
  char* novousername = strsep(&username,"\n");
  User user = g_hash_table_lookup(get_catalogo_user(catalogos), novousername);
  char* gender = g_strdup(get_gender_user(user));
  return gender;
}

int get_idade_list_User(Catalogos catalogos, char* username){
  char* novousername = strsep(&username,"\n");
  int idade = 0;
  User user = g_hash_table_lookup(get_catalogo_user(catalogos), novousername);
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
  Driver drivers = g_hash_table_lookup(get_catalogo_driver(catalogos), novoid);
  char* name = g_strdup(get_name_driver(drivers));
  return name;
}        

char* get_gender_list_driver(Catalogos catalogos, char* id){
  char* novoid = strsep(&id,"\n");
  Driver driver = g_hash_table_lookup(get_catalogo_driver(catalogos), novoid);
  char* gender = g_strdup(get_gender_driver(driver));
  return gender;
}

int get_idade_list_driver(Catalogos catalogos, char* id){
  char* novoid = strsep(&id,"\n");
  int idade = 0;
  Driver driver = g_hash_table_lookup(get_catalogo_driver(catalogos), novoid);
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
  g_hash_table_iter_init(&iter, get_catalogo_rides(catalogos)); 
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
  g_hash_table_iter_init(&iter, get_catalogo_rides(catalogos)); 
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
  Driver drivers = g_hash_table_lookup(get_catalogo_driver(catalogos), novoid);
  char* car_class = g_strdup(get_car_class_driver(drivers));

  double km=0;
  float tip = 0;
  double total = 0;

  gpointer key, value;
  GHashTableIter iter;
  g_hash_table_iter_init(&iter, get_catalogo_rides(catalogos)); 
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
  g_hash_table_iter_init(&iter, get_catalogo_rides(catalogos)); 
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
  g_hash_table_iter_init(&iter, get_catalogo_rides(catalogos)); 
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
  g_hash_table_iter_init(&iter, get_catalogo_rides(catalogos)); 
  while(g_hash_table_iter_next(&iter, &key, &value)){
    Rides ride = value;

    char* id = get_driver_Rides(ride);

    Driver drivers = g_hash_table_lookup(get_catalogo_driver(catalogos), id);
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
  g_hash_table_iter_init(&iter, get_catalogo_rides(catalogos)); 
  while(g_hash_table_iter_next(&iter, &key, &value)){
    Rides ride = value;

    char* id = get_driver_Rides(ride);

    Driver drivers = g_hash_table_lookup(get_catalogo_driver(catalogos), id);
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

  char* novadatai = strsep(&data_inicial,"\n");
  char* novadataf = strsep(&data_final,"\n");

  Data inicial = build_data(novadatai);
  Data final = build_data(novadataf);


  int contador = 0;
  int km = 0;
  double total = 0;

   gpointer key, value;
   GHashTableIter iter;

   g_hash_table_iter_init(&iter, get_catalogo_rides(catalogo)); 
   while(g_hash_table_iter_next(&iter, &key, &value)){
     Rides ride = value;
     char* id = get_driver_Rides(ride);

     Driver drivers = g_hash_table_lookup(get_catalogo_driver(catalogo), id);
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
   g_hash_table_iter_init(&iter, get_catalogo_rides(catalogo)); 
   while(g_hash_table_iter_next(&iter, &key, &value)){
     Rides ride = value;
     char* data_ref = get_date_Rides(ride);

    Data data_a_comparar = build_data(data_ref);
    
     if(compara_datas(data_a_comparar,inicial) && compara_datas(final,data_a_comparar) && strcmp(city,get_city_Rides(ride)) == 0){
      km += atoi(get_distance_Rides(ride));
      contador++;
     }
  }

  total = (double)km / contador;

  return total;
}

GList* auxquerie2 (Catalogos catalogo){
  GHashTable* map = g_hash_table_new(g_str_hash, g_str_equal);
    gpointer keyQuery2, valueQuery2;
    GHashTableIter iterQuery2;

    g_hash_table_iter_init(&iterQuery2,get_catalogo_rides(catalogo));
    while(g_hash_table_iter_next(&iterQuery2, &keyQuery2, &valueQuery2)) {
        Rides ride = valueQuery2;
        Driver driver = g_hash_table_lookup(get_catalogo_driver(catalogo),get_driver_Rides(ride));
        if(strcmp(get_account_status_driver(driver),"active")==0){
            if(!g_hash_table_contains(map,get_driver_Rides(ride))){
              AUX_DRIVER elem = malloc(sizeof(struct aux_driver));
              elem->id = get_driver_Rides(ride);
              Driver drivers = g_hash_table_lookup(get_catalogo_driver(catalogo), elem->id);
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

    g_hash_table_iter_init(&iterQuery3,get_catalogo_rides(catalogo));
    while(g_hash_table_iter_next(&iterQuery3, &keyQuery3, &valueQuery3)) {
        Rides ride = valueQuery3;
        User users = g_hash_table_lookup(get_catalogo_user(catalogo), get_user_Rides(ride));
        if(strcmp(get_account_status_user(users),"active") == 0){
          if(!g_hash_table_contains(map,get_user_Rides(ride))){
            AUX_USER elem = malloc(sizeof(struct aux_user));
            elem->username = get_user_Rides(ride);
            User user = g_hash_table_lookup(get_catalogo_user(catalogo), elem->username);
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

GList* auxquerie7 (Catalogos catalogo, char* city){
  GHashTable* map = g_hash_table_new(g_str_hash, g_str_equal);
  gpointer keyQuery7, valueQuery7;
  GHashTableIter iterQuery7;

  char* novacity = strsep(&city,"\n");

  g_hash_table_iter_init(&iterQuery7,get_catalogo_rides(catalogo));
  while(g_hash_table_iter_next(&iterQuery7, &keyQuery7, &valueQuery7)) {
      Rides ride = valueQuery7;
      if(strcmp(novacity,get_city_Rides(ride)) == 0){
        if(!g_hash_table_contains(map,get_driver_Rides(ride))){
            AUX_Q7 elem = malloc(sizeof(struct aux_q7));
            elem->id = get_driver_Rides(ride);
            Driver drivers = g_hash_table_lookup(get_catalogo_driver(catalogo), elem->id);
            elem->nome = get_name_driver(drivers);
            elem->avaliacao = atof(get_score_driver_Rides(ride));
            elem->contador = 1;
            elem->id = get_driver_Rides(ride);
            g_hash_table_insert(map, elem->id, elem);
        }
        else {
            AUX_Q7 elem = g_hash_table_lookup(map,get_driver_Rides(ride));
            elem->avaliacao = elem->avaliacao + atof(get_score_driver_Rides(ride));
            elem->contador++;
            g_hash_table_insert(map, elem->id, elem);
        }
      }
    }
    
    GList* list = g_hash_table_get_values(map);
    GList* sorted = g_list_sort (list, sort_function_q7); //(Não esquecer de mudar o return e a função de sort)

    // g_list_free(list);
    // g_hash_table_destroy(map);

    return sorted;
}

GList* auxquerie8 (Catalogos catalogo,char* gender, char *x){
    // GHashTable* map = g_hash_table_new(g_str_hash, g_str_equal);
    // gpointer keyQuery8, valueQuery8;
    // GHashTableIter iterQuery8;

    // Data atual = build_data(g_strdup(ANO));
    // int ano_ref = (get_ano(atual) - atoi(x));
    // int mes_ref = get_mes(atual);
    // int dia_ref = get_dia(atual);

    // char* novogender = strsep(&gender,"\n");

    // g_hash_table_iter_init(&iterQuery8,get_catalogo_rides(catalogo));
    // while(g_hash_table_iter_next(&iterQuery8, &keyQuery8, &valueQuery8)) {
    //      Rides ride = valueQuery8;

    //      char *id_driver = g_strdup(get_driver_Rides(ride));
    //      Driver drivers = g_hash_table_lookup(get_catalogo_driver(catalogos), id_driver);
    //      char* account_driver = g_strdup(get_account_creation_driver(drivers));
    //      Data data_driver = build_data(account_driver);
    //      int ano_driver = get_ano(data_driver);
    //      int mes_driver = get_mes(data_driver);
    //      int dia_driver = get_dia(data_driver);

    //      char *id_user = g_strdup(get_user_Rides(ride));
    //      User user = g_hash_table_lookup(get_catalogo_user(catalogos), id_user);
    //      char* account_user = g_strdup(get_account_creation_user(user));
    //      Data data_user = build_data(account_user);
    //      int ano_user = get_ano(data_user);
    //      int mes_user = get_mes(data_user);
    //      int dia_user = get_dia(data_user);


    //      if(ano_ref > ano_driver || ano_ref == ano_driver && mes_ref > mes_driver || ano_ref == ano_driver && mes_ref == mes_driver && dia_ref > dia_driver || ano_ref == ano_driver && mes_ref == mes_driver && dia_ref == dia_driver){
    //       if(ano_ref > ano_user || ano_ref == ano_user && mes_ref > mes_user || ano_ref == ano_user && mes_ref == mes_user && dia_ref > dia_user || ano_ref == ano_user && mes_ref == mes_user && dia_ref == dia_user){
    //         AUX_Q8 elem = malloc(sizeof(struct aux_q8)); 
    //         elem->id = get_driver_Rides(ride);
    //         elem->username = get_user_Rides(ride);
    //         User user = g_hash_table_lookup(get_catalogo_user(catalogos), elem->username);
    //         if(strcmp(get_gender_driver(drivers),get_gender_user(user))==0 && strcmp(novogender,get_gender_driver(drivers)) == 0 ){
    //           elem->nome = get_name_driver(drivers);
    //           elem->nome_user = get_name_user(user);
    //           elem->conta_driver=build_data(get_account_creation_driver(drivers));
    //           elem->conta_user = build_data(get_account_creation_user(user));
    //           elem->viagem=get_id_Rides(ride);
    //           g_hash_table_insert(map, elem->id, elem);
    //           }
    //       }   
    //     }
    //   }
    
    // GList* list = g_hash_table_get_values(map);
    // GList* sorted = g_list_sort(list, sort_function_q8);

    // return sorted;
}


 GList* auxquerie9 (Catalogos catalogo,char* data_inicial, char* data_final){
    GHashTable* map = g_hash_table_new(g_str_hash, g_str_equal);
    gpointer keyQuery9, valueQuery9;
    GHashTableIter iterQuery9;

    Data inicial = build_data(data_inicial);
    Data final = build_data(data_final);

    g_hash_table_iter_init(&iterQuery9,get_catalogo_rides(catalogo));
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

