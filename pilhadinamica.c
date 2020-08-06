#include <stdio.h>
#include <stdlib.h>

typedef struct Rno{
	int valor;
	struct Rno *ant;
}no;

typedef struct{
	no *topo;
}pilha;

void inicia(pilha *p);
void empilha(pilha *p, int e);
int desempilha (pilha *p);
int tamanho (pilha p);
int busca(pilha p, int e);
void mostra(pilha p);

int main(int argc, char const *argv[]){
	pilha p;
	inicia(&p);
	int opc, e;
	printf("1 - Empilha\n2 - Desempilha\n3 - Tamanho\n4 - Busca\n5 - Mostra\n");
	scanf("%d", &opc);
	do{
	switch(opc){
		case 1:
		system("cls");
		printf("Digite o valor para empilhar: ");
		scanf("%d", &e);
		empilha(&p, e);
		printf("Numero empilhado!\n");
		break;
		case 2:
			desempilha(&p);
			system("cls");
			printf("Numero desempilhado!\n");
			break;
		case 3:
			system("cls");
			printf("O tamanho eh: %d\n", tamanho(p));
			break;
		case 4:
			system("cls");
			printf("Digite o valor para buscar: ");
			scanf("%d", &e);
			system("cls");
			if(busca(p, e))
				printf("Valor encontrado!\n");
			else 
				printf("Valor nao encontrado!\n");
			break;
		case 5:
		mostra(p);
		break;
	}
	printf("1 - Empilha\n2 - Desempilha\n3 - Tamanho\n4 - Busca\n5 - Mostra\n");
	scanf("%d", &opc);
	}while(opc >= 1 || opc <= 5);

	return 0;
}

void inicia(pilha *p){
	p->topo = NULL;
}

void empilha(pilha *p, int e){
	no *aux = malloc(sizeof(no));
	aux->valor = e;
	aux->ant = p->topo;
	p->topo = aux;
}

int desempilha(pilha *p){
	no *aux;
	int auxValor;
	if (p->topo == NULL){
		printf("Pilha vazia\n");
		return -1;
	}
	else{
		aux = p->topo;
		p->topo = p->topo->ant;
		auxValor = aux->valor;
		free(aux);
	}
}

int tamanho(pilha p){
	int cont = 0;
	while(p.topo != NULL){
		cont++;
		p.topo = p.topo->ant;
	}
	return cont;
}

int busca(pilha p, int e){
	while(p.topo != NULL){
		if(p.topo->valor == e){
			return 1;
		}
		p.topo = p.topo->ant;
	}
	return 0;
}

void mostra(pilha p){
	system("cls");
	printf("Pilha:\n");
	no *aux = p.topo;
	while(aux != NULL){
		printf("%d\n", aux->valor);
		aux = aux->ant;
	}
	printf("\n");
}
