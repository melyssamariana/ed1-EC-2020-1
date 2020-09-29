#include <stdio.h>
#include <malloc.h>
#include <math.h> 


typedef struct aux {
  int reg;
  struct aux* prox;
} anao;

typedef struct elemn {
  int reg;
  int qntdCor;
  int qntdAnao;
  int foto;
  struct elemn* prox;
} lista;

typedef struct el {
  int reg;
  int qntdCor;
  struct el* prox;
} foto;


typedef foto* pont3;
typedef lista* pont2;
typedef anao* pont1;


pont1* lista1 (){
    pont1 *li = (pont1 *)malloc(sizeof(pont1));
    if (li != NULL)
        *li = NULL;
    return li;
}

pont2* lista2 (){
    pont2 *li = (pont2 *)malloc(sizeof(pont2));
    if (li != NULL)
        *li = NULL;
    return li;
}

pont3* lista3 (){
    pont3 *li = (pont3 *)malloc(sizeof(pont3));
    if (li != NULL)
        *li = NULL;
    return li;
}

int quantosAnaos(pont1 *filaAnoes, int referencia1, int referencia2){
    if(filaAnoes == NULL) return 0;
    int posicao1, posicao2, quantidade,contador = 1;
    anao (*aux) = *filaAnoes;
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

void inserirAnao(pont1 *filaAnoes, int numeroReferencia, int numeroAnao){ 
    anao (*aux) = *filaAnoes;  
    anao *anon = (anao *)malloc(sizeof(anao));
    anon->reg = numeroAnao;
    while ((aux)->reg != numeroReferencia && (aux) != NULL){
      (aux) = (aux)->prox;
    }
    anon->prox = (aux)->prox;
    (aux)->prox = anon;
}


void mostraLista(pont1 *filaAnoes){
    printf("\nlista");
    anao (*aux) = *filaAnoes;
    while ((aux) != NULL){
      printf(" %d",(aux)->reg);
      (aux) = (aux)->prox;
    }
    printf("\n");
}

void mostraListaRegistros(pont2 *filaAnoes){
    int linha = 1;
    printf("\nlista");
    lista (*aux) = *filaAnoes;
    while ((aux) != NULL){
      printf(" \n%d - |COR: %d | QntdAnao: %d | Foto: %d | QntdCor: %d |",linha,(aux)->reg,aux->qntdAnao,aux->foto,aux->qntdCor);
      (aux) = (aux)->prox;
      linha ++;
    }
    printf("\n");
}

void mostraResultado(pont2 *cores, int foto, pont3 *fot){    
    int min = 0, flag = 0;

    lista (*aux) = *cores;
    while ((aux) != NULL){
      if (aux->foto == foto){

        if(aux->qntdCor > aux->qntdAnao/2){

           
          printf("bonita %d",aux->reg);
          flag = 1;
        }
      }
      aux = aux->prox;
    }

    if (flag == 0){
      printf("feia");
    }
    printf("\n");
}


void inserirFinalCor(pont2 *li, int cor, int qntd, int foto, int qntdAnao)
{
    lista *no; 
    no = (lista *)malloc(sizeof(lista));
    no->reg = cor; 
    no->prox = NULL; 
    no->foto = foto; 
    no->qntdCor = qntd; 
    no->qntdAnao = qntdAnao;
    if ((*li) == NULL)
    { 
        *li = no;
    }
    else
    {
        lista *aux; 
        aux = *li; 
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no; 
    }

}


void verificarFoto(pont1 *filaAnoes, pont2 *listaCor, int posicao1, int posicao2, int numeroCores, int foto){

    anao (*aux);
    int contador = 0, i,aparece = 0,contadorAnao = 0;
    
    for (i = 1; i <= numeroCores; i++ ){
      aparece = 0; contador = 1;contadorAnao = 0;
      aux = *filaAnoes;
      while ((aux) != NULL){
        if (contador <= posicao2 && (contador >= posicao1)){
          contadorAnao++;
          if (aux->reg == i){
            aparece++;
          }
        }
        aux = aux->prox;
        contador++;
      }
      inserirFinalCor(listaCor,i,aparece, foto,contadorAnao);

    }
}

void inserirFinal(pont1 *li, int registro)
{
    anao *no;
    no = (anao *)malloc(sizeof(anao));
    no->reg = registro;
    no->prox = NULL;
    if ((*li) == NULL)
    { 
        *li = no;

    }
    else
    {
        anao *aux;
        aux = *li;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no;
    }
}





int main(void) {
  char operacao;
  int casoTeste = 0, contador = 0;
  int anao = 0, referencia = 0, numeroAnaos;
  int numeroCores, cor,nFotos,posicao1,posicao2,i;
  pont1 *lista = lista1(); 
  pont2 *cores = lista2(); 
  pont3 *foto = lista3();

  scanf("%d",&casoTeste);

  for (i = 0; i < casoTeste; i++){
  lista = lista1();
  cores = lista2();
  foto = lista3();

  scanf("%d %d",&numeroAnaos,&numeroCores);


  for (contador = 0; contador < numeroAnaos; contador ++){
    scanf("%d",&cor);
    inserirFinal(lista, cor);
  }

  scanf("%d",&nFotos);

  for (contador = 1; contador <= nFotos; contador ++){
    scanf("%d %d",&posicao1,&posicao2);
    verificarFoto(lista, cores, posicao1,posicao2,numeroCores, contador);
  }

  for (contador = 1; contador <= nFotos; contador ++){
      mostraResultado(cores,contador,foto);
  }
  }


 
  return 0;
}


