#include<stdio.h>
#include<stdlib.h>

typedef struct nodo Nodo;
typedef struct desc descritor;

/* RETORNA UM PONTEIRO NULO */
Nodo *inicializa();
/* INSERE UM NODO NO INICIO, CASO ESTEJA NULA, CRIA E RETORNA O PRIMEIRO NODO */
Nodo * insere_inicio(Nodo *list, int val);
/* INSERE UM NODO NO FINAL DA LISTA */
void insere_final(Nodo *list, int val);
/* IMPRIME OS VALORES DA LISTA EM ORDEM DO POSICIONAMENTO DOS NODOS */
void print_list(Nodo *lista);
/* INSERE UM NODO EM UMA POSIÇÃO */
void insere_pos(Nodo *list, int val, int pos);
/* REMOVE O NODO DA POSIÇÃO INSERIDA */
Nodo *remove_pos(Nodo *list,int pos);
/* DESTROI A LISTA E SAI DO PROGRAMA */
Nodo *destroi_lista(Nodo *list);
/* INICIA O PROGRAMA/MENU */
void run();
