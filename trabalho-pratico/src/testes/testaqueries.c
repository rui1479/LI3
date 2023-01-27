#include <stdio.h>
#include "../../include/catalogos.h"
#include "../../include/validadur.h"

#define ANO_I "01/01/2021"
#define ANO_F "01/01/2022"
#define ANO_I_Q6 "01/01/2020"
#define ANO_F_Q6 "01/01/2021"
#define ANO_I_Q9 "24/12/2021"
#define ANO_F_Q9 "25/12/2021"

void testequery1(Catalogos catalogo){
    clock_t start, end;
    double cpu_time_used;
    
    // iniciar relógio
    start = clock();

    char *novousername = "SaCruz110";

    // Fazer a query
    FILE *query1txt = fopen("src/testes/saida/testeQuery1.txt", "w");
    char *nome = get_name_list_user(catalogo, novousername);
    char *gender = get_gender_list_user(catalogo, novousername);
    int idade = get_idade_list_User(catalogo, novousername);
    double avaliacao_media = get_avaliacao_media_user(catalogo, novousername);
    int numero_viagens = get_numero_viagens_user(catalogo, novousername);
    double total_gasto = get_total_gasto(catalogo, novousername);
    fprintf(query1txt, "%s;%s;%i;%.3f;%i;%.3f\n", nome, gender, idade, avaliacao_media, numero_viagens, total_gasto);
    fclose(query1txt);

    // terminar relógio
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nQuery 1\nCPU Time: %.2f s!\n", cpu_time_used );

    // verificar se os resultados são os esperados
    FILE *respostaQuery1 = fopen("src/testes/saida/testeQuery1.txt", "r");
    FILE *respostaEsperada = fopen("src/testes/valido/query1_output.txt", "r");

    if (respostaQuery1 == NULL || respostaEsperada == NULL){
        printf("Error : Files not open! \n");
        exit(0);
    }

    int valido = compareFiles(respostaQuery1, respostaEsperada);
    fclose(respostaQuery1);
    fclose(respostaEsperada);

    if (valido == 1) printf("Output correto!\n");
    else printf("Erro no output produzido!\n");
}

void testequery2(Catalogos catalogo){
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();

    char *N = "10";

    GList* querie2 = auxquerie2(catalogo);
    FILE *query2txt = fopen("src/testes/saida/testeQuery2.txt", "w");

    for (size_t i = 0; i < atoi(N); i++) {
        AUX_DRIVER driver = g_list_nth_data(querie2, i);
        fprintf(query2txt, "%s;%s;%.3f\n", get_id_auxdriver(driver),get_nome_auxdriver(driver),(get_avaliacao_auxdriver(driver)/get_contador_auxdriver(driver)));
    }
    fclose(query2txt);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nQuery 2\nCPU Time: %.2f s!\n", cpu_time_used );

    FILE *respostaQuery2 = fopen("src/testes/saida/testeQuery2.txt", "r");
    FILE *respostaEsperada = fopen("src/testes/valido/query2_output.txt", "r");

    if (respostaQuery2 == NULL || respostaEsperada == NULL){
        printf("Error : Files not open! \n");
        exit(0);
    }

    int valido = compareFiles(respostaQuery2, respostaEsperada);
    fclose(respostaQuery2);
    fclose(respostaEsperada);

    if (valido == 1) printf("Output correto!\n");
    else printf("Erro no output produzido!\n");
}

void testequery3(Catalogos catalogo){
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    char *N = "10";

    GList* querie3 = auxquerie3(catalogo);
    FILE *query3txt = fopen("src/testes/saida/testeQuery3.txt", "w");

    for (size_t i = 0; i < atoi(N); i++) {
        AUX_USER user = g_list_nth_data(querie3, i);
        fprintf(query3txt, "%s;%s;%i\n", get_user_auxuser(user), get_nome_auxuser(user), get_distancia_auxuser(user));
    }
    fclose(query3txt);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nQuery 3\nCPU Time: %.2f s!\n", cpu_time_used );

    FILE *respostaQuery3 = fopen("src/testes/saida/testeQuery3.txt", "r");
    FILE *respostaEsperada = fopen("src/testes/valido/query3_output.txt", "r");

    if (respostaQuery3 == NULL || respostaEsperada == NULL){
        printf("Error : Files not open! \n");
        exit(0);
    }

    int valido = compareFiles(respostaQuery3, respostaEsperada);
    fclose(respostaQuery3);
    fclose(respostaEsperada);

    if (valido == 1) printf("Output correto!\n");
    else printf("Erro no output produzido!\n");

}

void testequery4(Catalogos catalogo){
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();

    char *city = "Braga";

    FILE *query4txt = fopen("src/testes/saida/testeQuery4.txt", "w");
    double preco_medio = get_preco_medio_city(catalogo, city);
    fprintf(query4txt, "%.3f\n", preco_medio);
    fclose(query4txt);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nQuery 4\nCPU Time: %.2f s!\n", cpu_time_used );

    FILE *respostaQuery4 = fopen("src/testes/saida/testeQuery4.txt", "r");
    FILE *respostaEsperada = fopen("src/testes/valido/query4_output.txt", "r");

    if (respostaQuery4 == NULL || respostaEsperada == NULL){
        printf("Error : Files not open! \n");
        exit(0);
    }
    int valido = compareFiles(respostaQuery4, respostaEsperada);
    fclose(respostaQuery4);
    fclose(respostaEsperada);

    if (valido == 1) printf("Output correto!\n");
    else printf("Erro no output produzido!\n");
}

void testequery5(Catalogos catalogo){
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();

    FILE *query5txt = fopen("src/testes/saida/testeQuery5.txt", "w");
    double preco_medio_data = get_preco_medio_data(catalogo, g_strdup(ANO_I), g_strdup(ANO_F));
    fprintf(query5txt, "%.3f\n",preco_medio_data);
    fclose(query5txt);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nQuery 5\nCPU Time: %.2f s!\n", cpu_time_used );

    FILE *respostaQuery5 = fopen("src/testes/saida/testeQuery5.txt", "r");
    FILE *respostaEsperada = fopen("src/testes/valido/query5_output.txt", "r");

    if (respostaQuery5 == NULL || respostaEsperada == NULL){
        printf("Error : Files not open! \n");
        exit(0);
    }

    int valido = compareFiles(respostaQuery5, respostaEsperada);
    fclose(respostaQuery5);
    fclose(respostaEsperada);

    if (valido == 1) printf("Output correto!\n");
    else printf("Erro no output produzido!\n");

}

void testequery6(Catalogos catalogo){
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();

    char *city = "Braga";

    FILE *query6txt = fopen("src/testes/saida/testeQuery6.txt", "w");
    double distancia_media = get_distancia_media_city(catalogo,g_strdup(city),g_strdup(ANO_I_Q6),g_strdup(ANO_F_Q6));
    fprintf(query6txt, "%.3f\n",distancia_media);
    fclose(query6txt);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nQuery 6\nCPU Time: %.2f s!\n", cpu_time_used );

    FILE *respostaQuery6 = fopen("src/testes/saida/testeQuery5.txt", "r");
    FILE *respostaEsperada = fopen("src/testes/valido/query5_output.txt", "r");

    if (respostaQuery6 == NULL || respostaEsperada == NULL){
        printf("Error : Files not open! \n");
        exit(0);
    }

    int valido = compareFiles(respostaQuery6, respostaEsperada);
    fclose(respostaQuery6);
    fclose(respostaEsperada);

    if (valido == 1) printf("Output correto!\n");
    else printf("Erro no output produzido!\n");

}

// void testequery7(Catalogos catalogo){

// }

// void testequery8(Catalogos catalogo){

// }

void testequery9(Catalogos catalogo){
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();

    GList* querie9 = auxquerie9(catalogo,g_strdup(ANO_I_Q9),g_strdup(ANO_F_Q9));
    FILE *query9txt = fopen("src/testes/saida/testeQuery9.txt", "w");

    int tamanho = g_list_length(querie9);
    for (size_t i = 0; i < tamanho; i++) {
        AUX_Q9 ride = g_list_nth_data(querie9, i);
        Data aux = get_data_auxq9(ride);
        fprintf(query9txt, "%s;%i/%i/%i;%s;%s,%.3f\n", get_id_auxq9(ride), get_dia(aux), get_mes(aux), get_ano(aux), get_distancia_auxq9(ride), get_cidade_auxq9(ride),atof(get_tip_auxq9(ride)));
    }
    fclose(query9txt);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nQuery 9\nCPU Time: %.2f s!\n", cpu_time_used );

    FILE *respostaQuery9 = fopen("src/testes/saida/testeQuery3.txt", "r");
    FILE *respostaEsperada = fopen("src/testes/valido/query3_output.txt", "r");

    if (respostaQuery9 == NULL || respostaEsperada == NULL){
        printf("Error : Files not open! \n");
        exit(0);
    }

    int valido = compareFiles(respostaQuery9, respostaEsperada);
    fclose(respostaQuery9);
    fclose(respostaEsperada);

    if (valido == 1) printf("Output correto!\n");
    else printf("Erro no output produzido!\n");

}