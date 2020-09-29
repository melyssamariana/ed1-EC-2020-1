#include <stdio.h>
#include <malloc.h>
#include <math.h>
 

typedef struct auxiliar {
  char * nome;
  struct auxiliar * prox;
  struct auxiliar * anterior;
}
REGISTRO;
 
typedef REGISTRO * PONT;
int pontos = 0;
PONT * criaLista() {
  PONT * li = (PONT * ) malloc(sizeof(PONT));
  if (li != NULL)
    *
    li = NULL;
  return li;
}
 
int excluir(PONT * roda, char * nome, char * sentido) {
  REGISTRO * auxiliar;
  REGISTRO * anterior;
  int passos = 0;
 
  if (strstr(sentido, "-") == NULL) {
    auxiliar = (*roda);
    anterior = ( * roda);
    while (strstr((auxiliar) -> nome, nome) == NULL && passos < 2) {
      (auxiliar) = (auxiliar) -> prox;
      if (strstr((auxiliar) -> nome, nome) == NULL) {
        (anterior) = (anterior) -> prox;
      }
      passos++;
    }
    if (strstr((auxiliar) -> nome, nome) != NULL) {
      if (auxiliar == (*roda)->prox){
        (*roda)->prox = auxiliar->prox;
      } else {
      anterior -> prox = auxiliar -> prox;
      auxiliar -> prox -> anterior = anterior;
      free(auxiliar);
      }

      pontos++;
    }
 
  } else {
    auxiliar = ( * roda);
    anterior = ( * roda);
    while (strstr((auxiliar) -> nome, nome) == NULL && passos < 2) {
      (auxiliar) = (auxiliar) -> anterior;
       
      if (strstr((auxiliar) -> nome, nome) == NULL) {
        (anterior) = (anterior) -> anterior;
      }
      passos++;

    }
    if (strstr((auxiliar) -> nome, nome) != NULL) {
      anterior -> anterior = auxiliar -> anterior;
      auxiliar -> anterior -> prox = anterior;
      free(auxiliar);
      pontos++;
    }
  }
  return 1;
}
 
int inserir(PONT * li, char * nome) {
  REGISTRO * no;
  no = (REGISTRO * ) malloc(sizeof(REGISTRO));
  no -> nome = nome;
  no -> prox = * li;
  REGISTRO * auxiliar;
  REGISTRO * anterior;
  auxiliar = * li;
  anterior = * li;
  while (auxiliar -> prox != * li) {
    (auxiliar) = (auxiliar) -> prox;
    if ((auxiliar) -> prox != * li) {
      (anterior) = (anterior) -> prox;
    }
  }
  no -> anterior = auxiliar;
  auxiliar -> prox = no;
  ( * li) -> anterior = no;
  return 1;
}
 
int inserirVovo(PONT * li, char * nome) {
  if (li == NULL)
    return 0;
  REGISTRO * no;
  no = (REGISTRO * ) malloc(sizeof(REGISTRO));
  if (no == NULL)
    return 0;
  no -> nome = nome;
  no -> prox = no;
  no -> anterior = no;
  if (( * li) == NULL) { 
    * li = no;
  } else {
    REGISTRO * auxiliar;
    auxiliar = * li;
    while (auxiliar -> prox != NULL) {
      auxiliar = auxiliar -> prox;
    }
    auxiliar -> prox = no;
  }
  return 1;
}
 
int main(void) {
  int contador = 0, i = 0;
  char * operacao;
  char * nome;
  char * sentido;
  PONT * lista = criaLista();
 
  inserirVovo(lista, "Arlete"); 
 
  for (;;) {
    nome = (char * ) malloc(30 * sizeof(char));
    scanf("%s", nome);
    if (strstr(nome, "FIM") != NULL) {
      break;
    } else {
      inserir(lista, nome);
      contador++;
    }
 
  }
 
  for (i = 0; i < contador; i++) {
    nome = (char * ) malloc(30 * sizeof(char));
    sentido = (char * ) malloc(30 * sizeof(char));
    scanf("%s", nome);
    scanf("%s", sentido);
    excluir(lista, nome, sentido);
  }
 
  printf("%d", pontos);
  return 0;
 
}