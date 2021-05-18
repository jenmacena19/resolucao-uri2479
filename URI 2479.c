#include <stdio.h>
#include <stdlib.h>
#include <string.h> 	//estudante: Jeniffer Macena

typedef struct criancaNoel{
	char sinal;
	char nome[21]; 
}kids;

//cabecalho do metodo de ordenacao Cocktail-Sort
void cocktailSort(kids v[], int n);

int main(){
	
	int n,i, bons=0,ruins=0;
	
	//ler quantidade de casos de teste
	scanf("%d",&n);
	kids crianca[n],aux;
	
	//ler para o mesmo caso de teste o campo 'sinal' e 'nome'
	for(i=0; i<n; i++){
		scanf(" %c",&crianca[i].sinal);
		scanf("%s",crianca[i].nome);
	}
	 
	for(i=0;i<n;i++){
		if(crianca[i].sinal=='+'){ //verificando no campo 'sinal' do vetor de struct crianca se foi boa ou ruim
			bons++;
		}else{
			ruins++;
		}
	}
	
	//ordenando elementos no vetor de struct "kids"
	cocktailSort(crianca, n);

	//imprimindo elementos do vetor ja ordenados somente pelo campo 'nome'
	for(i= 0; i<n; i++){
		printf("%s\n",crianca[i].nome);
	}
	
	printf("Se comportaram: %d | Nao se comportaram: %d\n",bons,ruins);
	
	return 0;
	
}

void cocktailSort(kids v[], int n){
	int fim, inicio, troca, i;
	kids aux;
	fim = 0;
	inicio = n - 1;
	troca = 0;
	
	while (troca == 0 && fim < inicio){
		// se nao tiver troca ou ponteiro que sobe ultrapassar o que desce, está ordenado
		troca = 1;
		//percorrer da direita para esquerda
		
		for(i = fim; i < inicio; i++ ){//dir->esquerda: verifica se o prox é maior
			if(strcmp(v[i].nome, v[i+1].nome)>0){
				aux = v[i];
				v[i] = v[i+1];
				v[i+1]= aux;
				troca = 0;
			}
		}
		
		//diminui o "inicio" pq o elemento com maior valor, está na direita (atual posição inicio_
		inicio--;
		
		//percorrer da esquerda p direita
		for(i=inicio; i> fim; i--){
			if(strcmp(v[i].nome, v[i-1].nome) < 0){
				aux = v[i];
				v[i] = v[i-1];
				v[i-1] = aux;
				troca = 0;
			}
		}
		//aumenta o "fim" pq o menor valor ja esta na posicao inicial (fim)
		fim++;	
	}
}