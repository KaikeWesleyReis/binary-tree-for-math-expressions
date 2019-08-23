#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treebin.h"

//BINARY TREE FOR MATH EXPRESSION BASED ON PILE DATA STRUCTURE
//AUTHOR: Kaike W.Reis

//GLOBAL VAR
extern node *raiz;
extern node *pilha[100];
extern int topo;
extern int indices[100]; 
extern int ref; 
extern char elementos[100];

//FUNCTIONS
node* arvoreLibera(node *raiz){ //RELEASE TREE
	if(raiz != NULL){
		arvoreLibera(raiz->esq);
		arvoreLibera(raiz->dir);
		free(raiz);
	}
	return NULL;
}
void insere(char conteudo) { // INSERT NODE
	node *aux = (node*) malloc(sizeof(node));
	node *atual;
	node *pai;
	aux->info = conteudo;
	aux->esq = NULL;
	aux->dir = NULL;
	int algarismo = conteudo - 48;

   if(raiz == NULL) {// IF TREE EMPTY, INSERT ROOT
    	raiz = aux;
    	pilha[topo] = raiz;
    	topo++;
   } 
   else {
   		atual = raiz;
   		pai = NULL;
   		while(1){
   			pai = atual;
   			//printf("(p)%c=>",atual->info);
   			if(topo < 0){
   				printf("Erro na Expressao: Pilha invalida!\n");
   				break;
			   }

			if(conteudo=='+'||conteudo=='-'||conteudo=='*'||conteudo=='/'){
				pilha[topo-1]->info = aux->info;
				return;								
			}
			else if(conteudo==')'){
				//pilha[topo] = NULL;//Remove o endereco do topo
				topo--;
				return;			
			}
			//WAY DECISION 
			if(pai->info == '('){//WAY DECISION: TO THE LEFT
				atual = atual->esq;
				if(atual == NULL){
					pai->esq = aux;
					//printf("(e)%c=>",pai->esq->info);
					if(conteudo == '('){
						pilha[topo] = pai->esq;
						topo++;
						return;
					}
					else{
						return;
					}
				}	
			}
			else if(pai->info=='+'||pai->info=='-'||pai->info=='*'||pai->info=='/'){//WAY DECISION: TO THE RIGHT
				atual = atual->dir;
				if(atual == NULL){
					pai->dir = aux;
					//printf("(d)%c=>",pai->dir->info);
					if(conteudo == '('){
						pilha[topo] = pai->dir;
						topo++;
						return;
					}
					else{
						return;
					}
				}					
			}
			else{
				break;
			}				
		}
	}
}
void pre_ordem(node* raiz) {//PRE ORDER
   if(raiz != NULL) {
      printf("%c ",raiz->info);
      pre_ordem(raiz->esq);
      pre_ordem(raiz->dir);
   }
}
void simetrica(node* raiz) {//SIMETRY
   if(raiz != NULL) {
      simetrica(raiz->esq);
      printf("%c ",raiz->info);          
      simetrica(raiz->dir);
   }
}
void pos_ordem(node* raiz) {//POST ORDER
   if(raiz != NULL) {
      pos_ordem(raiz->esq);
      pos_ordem(raiz->dir);
      printf("%c ", raiz->info);
   }
}
int resultado(node* raiz){//EXPRESSION RESULTS CALC - RECURSIVE
	int alg = raiz->info - 48;
	if(alg >= 0 && alg <= 9){
		return alg;
	}
	else{
		if(raiz->info=='+'){
			return resultado(raiz->esq) + resultado(raiz->dir); //OP +
		}
		else if(raiz->info=='-'){
			return resultado(raiz->esq) - resultado(raiz->dir); //OP -
		}
		else if(raiz->info=='*'){
			return resultado(raiz->esq) * resultado(raiz->dir); //OP *
		}
		else if(raiz->info=='/'){
			return resultado(raiz->esq) / resultado(raiz->dir); //OP DIVIDE
		}
		else if(!(alg >= 0 && alg <= 9)){
			return 0;
		}
	}
}
void folhas(node *raiz){// TREE LEAFS
	if(raiz->esq == NULL && raiz->dir == NULL){
		return;
	}
	if(raiz->info == '+'||raiz->info == '-'||raiz->info == '*'||raiz->info == '/'){
		int algarismo;
		algarismo = raiz->esq->info - 48;
		if(algarismo >= 0 && algarismo <= 9){
			printf("%c(%c) ",raiz->esq->info,raiz->info);
			algarismo = raiz->dir->info - 48;
			if(algarismo >= 0 && algarismo <= 9){
				printf("%c(%c) ",raiz->dir->info,raiz->info);
			}
		}
		else{
			algarismo = raiz->dir->info - 48;
			if(algarismo >= 0 && algarismo <= 9){
				printf("%c(%c) ",raiz->dir->info,raiz->info);
				algarismo = raiz->esq->info - 48;
				if(algarismo >= 0 && algarismo <= 9){
					printf("%c(%c)",raiz->esq->info,raiz->info);
				}
			}
		}
	}
	//ACTIVATE RECURSIVITY
	if(raiz->esq != NULL){
		folhas(raiz->esq);
	}
	if(raiz->dir != NULL){
		folhas(raiz->dir);
	}
}
int quantidade(node *raiz){//TREE NODE QUANTITY
	if(raiz == NULL) return 0;
	return quantidade(raiz->esq) + quantidade(raiz->dir) + 1;
}
void niveis (node *raiz,int level) {//TREE LEVELS
	if(raiz == NULL) return;
	else{
		indices[ref] = level;
		elementos[ref] = raiz->info;
		ref++;
	}
	if(raiz->esq != NULL){
		niveis(raiz->esq,level+1);
	}
	if(raiz->dir != NULL){
		niveis(raiz->dir,level+1);
	}
}
int altura(node *raiz){//TREE HEIGTH
	int x,y;
	if(raiz == NULL) return 0;//EMPTY TREE!
	x = altura(raiz->esq);
	y = altura(raiz->dir);
	if(x > y) return x+1;
	else return y+1;
}
