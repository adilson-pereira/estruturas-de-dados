#include"lista.h"
struct desc{
	Nodo *inicio;
	Nodo *ultimo;
	int tamanho;
};
struct nodo{
  int valor;
	descritor *D;
	Nodo *prox;
};
Nodo *inicializa(){
	return NULL;
}
Nodo * insere_inicio(Nodo *list, int val){
  if(list == NULL){
		list = (Nodo *)malloc(sizeof(Nodo));
		descritor *desc = (descritor *)malloc(sizeof(descritor));
		list -> valor = val;
		desc -> inicio = list;
		desc -> ultimo = list;
		list -> D = desc;
		list -> D -> tamanho= 1;
		list -> prox = list;
		return(list);
	}
	else{
		Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
		novo->valor = val;
		novo->prox = list->D->inicio;
		novo->D = list->D;
		novo->D->inicio = novo;
		novo->D->ultimo->prox = novo;
		novo->D->tamanho += 1;
		return(novo);
	}
}
void insere_final(Nodo *list, int val){
	Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
	novo->valor = val;
	list->D->ultimo->prox = novo; // Fiz o ultimo elo apontar pro novo elo
  novo->prox = list->D->inicio; // Novo elo aponta pro inicio
  list->D->ultimo = novo; // Descritor ultimo aponta pro novo elo
  novo->D = list->D; // Fiz o descritor do novo elo apontar pro descritor
  novo->D->tamanho += 1;
}
void print_list(Nodo *lista){
  if (lista == NULL){
    printf("Lista vazia!\n");
  }
  else{
    Nodo *aux = lista -> D -> inicio;
    do{
      printf("%d\n",aux->valor);
      aux = aux -> prox;
    }while(aux != aux -> D -> inicio);
  }
}
void insere_pos(Nodo *list, int val, int pos){
	if(pos >= list->D->tamanho){
		printf("\nPosição Inválida!\n");
	}else if(pos == 0){
		printf("\nPara inserir na posição zero, selecione no menu a opção 1.\n");
	}
	else if(pos == list -> D -> tamanho -1){
		printf("\nPara inserir na ultima posição, selecione no menu a opção 3.\n");
	}
	else{
		Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
		novo->valor = val;
		Nodo *aux = list->D->inicio;
		int i = 1;
		while(i<pos){
			aux = aux->prox;
			i++;
		}
		novo->prox = aux->prox;
		aux->prox = novo;
		novo->D = aux->D;
		novo->D->tamanho += 1;
	}
}
Nodo *remove_pos(Nodo *list,int pos){
	if(pos >= list->D->tamanho || pos < 0){
		printf("\nPosição Inválida!\n");
	}
	
	if(pos == 0){
		Nodo *aux = list->D->inicio; // Copiei a posição 0 para uma variável auxiliar
		list -> D -> inicio = list -> D -> inicio -> prox; //Fiz o inicio apontar pra posição 1
		list -> D -> ultimo -> prox = list -> D -> inicio;
		free(aux);
		list -> D -> tamanho -= 1;
		list = list -> D -> inicio;
		printf("\nElemento na posição %d foi removido com sucesso!\n",pos);
		return(list);
	}
	if(pos == list -> D -> tamanho -1){
		Nodo *aux = list -> D -> inicio;
		int i = 0;
		while (i < (pos -1)){
			aux = aux -> prox;
			i++;
		}
		list -> D -> ultimo = aux;
		aux = aux -> prox;
		list -> D -> ultimo -> prox = list -> D -> inicio;
		free(aux);
		list -> D -> tamanho -= 1;
		list = list -> D -> inicio;
		printf("\nElemento na posição %d foi removido com sucesso!\n",pos);
		return(list);
	}
	else{
		Nodo *aux = list->D->inicio;
		int i = 1;
		while(i<pos){
			aux = aux->prox;
			i++;
		}
		Nodo *aux2 = aux -> prox; //aux 2 vai ser destruido
		Nodo *auxprox = aux2 -> prox;
		aux -> prox = auxprox;
		free(aux2);
		aux->D->tamanho -= 1;
		list = aux->D->inicio;
		printf("\nElemento na posição %d foi removido com sucesso!\n",pos);
		return(list);
	}
	
}
Nodo *destroi_lista(Nodo *list) {
    Nodo *atual = list->D->inicio;
    Nodo *proximo;
    while (atual != list -> D -> ultimo) {
        proximo = atual -> prox;
        free(atual);
        atual = proximo;
    };
    return(NULL);
} 

void run(){
	int teste=1,t=0,valor=0,pos=0;
	Nodo *lista = inicializa();
	while (teste == 1){
		printf("\n ### MENU ###\n\n");
		printf("1-INSERIR NO INICIO DA LISTA\n");
		printf("2-INSERIR EM UMA POSICAO\n");
		printf("3-INSERIR NO FIM DA LISTA\n");
		printf("4-REMOVER ELEMENTO EM UMA POSIÇÃO\n");
		printf("5-CONSULTA A LISTA\n");
		printf("6-SAIR\n");
		printf("\nSELECIONE UMA OPÇÃO E TECLE <ENTER>: ");
		scanf("%d",&t);
		
		if (t==1){
			printf("DIGITE O VALOR: ");
			scanf("%d",&valor);
			lista = insere_inicio(lista,valor);
		}
		else{
			if (t==2){	
				printf("DIGITE O VALOR,POSICAO: ");
				scanf("%d,%d",&valor,&pos);
				insere_pos(lista,valor,pos);
			}
			else{
				if (t==3){
					printf("DIGITE O VALOR: ");
					scanf("%d",&valor);
					insere_final(lista,valor);
				}
				else{
					if (t==4){
						printf("DIGITE A POSICAO A SER REMOVIDA: ");
						scanf("%d",&valor);
						lista = remove_pos(lista,valor);
					}
					else{
						if (t==5){
							printf("\nIMPRIMINDO LISTA\n");
							printf("==========================\n");
							print_list(lista);
							printf("==========================\n");
						}
						else{
							lista = destroi_lista(lista);
							teste=0;
							printf("\nGood Bye :)\n");
						}
					}
				}
			}
		}
	}
}
