#include <stdio.h>
#include <malloc.h>
#include <math.h> 
 
 
typedef struct aux {
  int reg;
  struct aux* prox;
} REGISTRO;
 
typedef REGISTRO* ponteiro;
 
 
ponteiro* criaLista (){
    ponteiro *li = (ponteiro *)malloc(sizeof(ponteiro));
    if (li != NULL)
        *li = NULL;
    return li;
}
 
 
int qntdInim(ponteiro *ListaInimigos, int referencia1, int referencia2){
    if(ListaInimigos == NULL) return 0;
    int posicao1, posicao2, quantidade,contador = 1;
    REGISTRO (*aux) = *ListaInimigos;
    while ((aux) != NULL){
      if ((aux)->reg == referencia1){
        posicao1 = contador;
      } else{
      if ((aux)->reg == referencia2){
        posicao2 = contador;
      }}
      contador++;
      (aux) = (aux)->prox;
      
    }
    quantidade = abs((posicao2 - posicao1)) - 1;
    return quantidade;  
  
}
 
 
 
int addInim(ponteiro *ListaInimigos, int numeroReferencia, int numeroInimigo){
    if(ListaInimigos == NULL) return 0; 
    REGISTRO (*aux) = *ListaInimigos;  
    REGISTRO *inimigo = (REGISTRO *)malloc(sizeof(REGISTRO));
    inimigo->reg = numeroInimigo;
    while ((aux)->reg != numeroReferencia && (aux) != NULL){
      (aux) = (aux)->prox;
    }
    inimigo->prox = (aux)->prox;
    (aux)->prox = inimigo;
    return 1; 
}
 
 
int mostrar(ponteiro *ListaInimigos){
    if(ListaInimigos == NULL) return 0; 
    printf("\nlista");
    REGISTRO (*aux) = *ListaInimigos;
    while ((aux) != NULL){
      printf(" %d",(aux)->reg);
      (aux) = (aux)->prox;
    }
    printf("\n");
    return 1;  
}
 
 
int inserirUltimo(ponteiro *li, int registro)
{
    if (li == NULL)
        return 0;
    REGISTRO *no;
    no = (REGISTRO *)malloc(sizeof(REGISTRO));
    if (no == NULL)
        return 0;
    no->reg = registro;
    no->prox = NULL;
    if ((*li) == NULL)
    { 
        *li = no;
    }
    else
    {
        REGISTRO *aux;
        aux = *li;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int excluirInim(ponteiro* ListaInimigos, int numeroInimigo){
    REGISTRO (*aux) = *ListaInimigos;
    REGISTRO (*anterior) = *ListaInimigos;
      while ((aux)->reg != numeroInimigo && (aux) != NULL){
        (aux) = (aux)->prox;
        if ((aux)->reg != numeroInimigo){
          (anterior) = (anterior)->prox;
        }
      }
    (anterior)->prox = (aux)->prox;
    free(aux);
    return 1;  
}
 
 
 
int main(void) {
  char operacao;
  int Ninimigos = 0, contador = 0,inimigo = 0, referencia = 0;
  ponteiro *lista = criaLista(); 
 
  scanf("%d",&Ninimigos);
 
  for (contador = 0; contador < Ninimigos; contador ++){
    scanf("%d",&inimigo);
    inserirUltimo(lista, inimigo);
  }
 
  do {
 
  scanf("%c",&operacao);
 
  if (operacao == 'C'){
    int referencia1,referencia2,quantidade;
    scanf("%d %d",&referencia1,&referencia2);
    quantidade = qntdInim(lista, referencia1, referencia2);
    printf("quantidade %d\n",quantidade);
  } 
 
  if (operacao == 'I'){
    scanf("%d %d",&inimigo,&referencia);
    addInim(lista, referencia, inimigo);
    printf("inserido %d\n",inimigo);
  }
 
  if (operacao == 'R'){
    scanf("%d",&inimigo);
    excluirInim(lista, inimigo);
    printf("removido %d\n",inimigo);
  }
 
  if (operacao == 'M'){
    mostrar(lista);
  }
  
  if(operacao == 'F'){
    printf("fim");
    return 0;
  }
 
  } while (1);
 
  return 0;
}