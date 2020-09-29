#include <stdio.h>
#include <malloc.h>
#include <math.h> 


typedef struct aux {
  char *nome;
  char *telefone;
  int numeroLigacoes;
  struct aux* proximo;
} REGISTRO;

typedef REGISTRO* PONT;



PONT* criaLista (){
    PONT *li = (PONT *)malloc(sizeof(PONT));
    if (li != NULL)
        *li = NULL;
    return li;
}

int excluirAgenda(PONT* agenda, char *nome){
    if (agenda == NULL)
        return 0;
    if ((*agenda) == NULL) 
        return 0;
    REGISTRO *ant, *no = *agenda;
    while (no != NULL && strcmp (no->nome, nome) != 0)
    {
        ant = no;
        no = no->proximo;
    }
    if (no == NULL) 
        return 0;

    if (no == *agenda) 
        *agenda = no->proximo;
    else
        ant->proximo = no->proximo;
    free(no);
    return 1; 
}



void trocar(REGISTRO* p1, REGISTRO* p2)
{
    char name[30], phone[30];
    int v;

    strcpy(name, p2->nome);
    strcpy(phone, p2->telefone);
    v = p2->numeroLigacoes;

    strcpy(p2->nome, p1->nome);
    strcpy(p2->telefone, p1->telefone);
    p2->numeroLigacoes = p1->numeroLigacoes;

    strcpy(p1->nome, name);
    strcpy(p1->telefone, phone);
    p1->numeroLigacoes = v;
}

void ordenar(PONT* l){
    REGISTRO* p1;
    REGISTRO* p2; 

    for(p1 = *l; p1; p1 = p1->proximo)
    {
        for(p2 = p1; p2; p2 = p2->proximo)
        {
            if(p1->numeroLigacoes < p2->numeroLigacoes)
                trocar(p1, p2);
        }
    }

}


int mostra(PONT *agenda){
    if(agenda == NULL) return 0; 
    REGISTRO (*aux) = *agenda;
    while ((aux) != NULL){
      printf("%s - %s %d\n",(aux)->nome,aux->telefone,aux->numeroLigacoes);
      (aux) = (aux)->proximo;
    }
    return 1;  
}


int aumentarNumeroLigacao(PONT *agenda, char* nome){
    if(agenda == NULL) return 0;
    REGISTRO (*aux) = *agenda;
    while ((aux) != NULL){
       if (strcmp (aux->nome, nome) == 0){
          aux->numeroLigacoes = aux->numeroLigacoes + 1;
          return 1;
       }
       (aux) = (aux)->proximo;
    }
    return 0; 
}



int inserirUltimo(PONT *li, int numeroLigacoes, char *telefone, char *nome)
{
    if (li == NULL)
        return 0;
    REGISTRO *no;
    no = (REGISTRO *)malloc(sizeof(REGISTRO));
    if (no == NULL)
        return 0;
    no->numeroLigacoes = numeroLigacoes;
    no->telefone = telefone;
    no->nome = nome;
    no->proximo = NULL;
    if ((*li) == NULL)
    { 
        *li = no;
    }
    else
    {
        REGISTRO *aux;
        aux = *li;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = no;
    }
    return 1;
}



int main(void) {
  char operacao;

  int nLigacao = 0;
  PONT *lista = criaLista(); 

  inserirUltimo(lista,300,"4523-2248","Hermanoteu");
  inserirUltimo(lista,299,"4523-4887","Ooloneia");

  do {
  scanf("%c",&operacao); 

  if (operacao == 'I'){
  char *nome,*telefone;
  telefone = (char *)malloc(15*sizeof(char)); 
  nome = (char *)malloc(30*sizeof(char)); 
    scanf("%s %s %d",nome,telefone,&nLigacao);
    inserirUltimo(lista,nLigacao,telefone,nome);
  }

  if (operacao == 'L'){
      char *nome,*telefone;
  telefone = (char *)malloc(15*sizeof(char)); 
  nome = (char *)malloc(30*sizeof(char)); 
    scanf("%s",nome);
    aumentarNumeroLigacao(lista, nome);
  }

  if (operacao == 'R'){
  char *nome,*telefone;
  nome = (char *)malloc(30*sizeof(char)); 
    scanf("%s",nome);
    excluirAgenda(lista, nome);
  }
  
  if(operacao == 'F'){
    ordenar(lista);
    mostra(lista);
    return 0;
  }

  } while (1);

  return 0;
}


