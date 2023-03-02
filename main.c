#include <stdio.h>
#include <stdlib.h>


typedef struct nofila {
    int dado;
    struct nofila *prox;
}no;

typedef struct cabeca {
    no* inicio;
    no* final;
    int tamanho;
}TFilaEncCab;


void criarFila(TFilaEncCab *fila){  
    fila->inicio = fila->final = NULL;
    fila->tamanho = 0;
}


void enfileirar(TFilaEncCab *fila, int num){
    no *novo = malloc(sizeof(no));
    if(novo){
        novo->dado = num;
        novo->prox = NULL;
        if(fila->inicio == NULL) {  
            fila->inicio = fila->final = novo;   
        } else{
            fila->final->prox = novo;  
            fila->final = novo;
        }
        fila->tamanho++;
    } else
        printf("Erro ao alocar memoria"); 
}
 
void exibirFilas(TFilaEncCab *fila){
    no *aux = fila->inicio; 
  	printf("\nNúmero(s) da fila = [ ");
   // printf("\nNúmeros da fila:\n");
    while(aux){ 
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
     printf("]");
}

// verifica se existe igualdade entre as filas adicionadas pelo usuário
int checarIgualdade(TFilaEncCab f1, TFilaEncCab f2){
    no *aux1 = f1.inicio;
    no *aux2 = f2.inicio;

    if(f1.tamanho != f2.tamanho)
        return 0;
    while(aux1 && aux2){
        if(aux1->dado != aux2->dado){
            return 0;
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    return 1; 
}


int main() {
    TFilaEncCab fila1, fila2;
    criarFila(&fila1);
    criarFila(&fila2);

    int escolha = 1, dado;

    printf("\nPreencha a primeira fila:\n");
    do {
        printf("\n[1] Adicionar novo valor\n[0] Nao adicionar novo valor\n\n");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                printf("\nDigite o valor a ser inserido:\n");
                scanf("%d", &dado);
                enfileirar(&fila1, dado);
                break;
            case 0:
                break;
            default:
                printf("\nEntrada inválida\n");
        }
    } while(escolha);

    printf("\nPreencha a segunda fila:\n");
    do {
        printf("\n[1] Adicionar novo valor\n[0] Nao adicionar novo valor\n\n");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                printf("\nDigite o valor a ser inserido:\n");
                scanf("%d", &dado);
                enfileirar(&fila2, dado);
                break;
            case 0:
                break;
            default:
                printf("\nEntrada inválida\n");
        }
    } while(escolha);

    exibirFilas(&fila1);
    printf("\n");
    exibirFilas(&fila2);
    printf("\n");
    if(checarIgualdade(fila1, fila2))
        printf("\nAs filas são iguais!\n");
    else
        printf("\nAs filas são diferentes!\n");

    return 0;
}