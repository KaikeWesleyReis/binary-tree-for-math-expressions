#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treebin.h"

//BINARY TREE FOR MATH EXPRESSION BASED ON PILE DATA STRUCTURE
//AUTHOR: Kaike W.Reis

//GLOBAL VAR: Var defines given the recursive nature from treebin.h
node *raiz = NULL;
node *pilha[100];
int topo = 0;
int indices[100];
int ref = 0;
char elementos[100];

//TESTED EXAMPLES
//(2+(5*((4/2)-1)));
//(2+(3*2));
//(((4*2)-(6+1))+(8/(9-7)));
	

int main(){
	// MATH EXPRESSION
	//char expressao[100];
	char expressao1[] = "(2+(5*((4/2)-1)))";
	//char expressao1[] = "(2+(3*2))";
	//char expressao1[] = "(((4*2)-(6+1))+(8/(9-7)))";
	
	//PROG VAR
	char expressao[100];
	int i; //FOR COUNT
	int k; //FOR COUNT
	int alt; //TREE HEIGTH
	int qtd; //TREE NODES COUNT
	int caso = 1; //HOW MANY CASES WILL BE ANALYZED
	int resposta; //FINAL ANSWER FROM TREE
	
	//VERIFICATION VARS
	int verifica_parenteses_aberto = 0; //VERIFY HOW MANY '(' THERE ARE
	int verifica_parenteses_closed = 0; //VERIFY HOW MANY ')' THERE ARE
	int verifica_operadores = 0; //VERIFY HOW MANY MATH OPERATIONS
	int flag = 0; //EXPRESSION IS OK!
	
	//PILE INIT
	for(i=0;i<100;i++){
		pilha[i] == NULL;
	}
	//PROG WORKS
	printf("BINARY TREE FOR MATH EXPRESSIONS\n");
	printf("AUTHOR: Kaike W.Reis\n");
	printf("--------------------------------------------------------------------------------------\nRESTRICTIONS:\n-DO NOT INSERT SPACE IN THE EXPRESSION\n-NUMBER OF () NEEDS TO BE EQUAL TO NUMBER OF OPERATORS\n-IT IS NECESSARY TO AT LEAST USE () TO CLOSE A EXPRESSION\n\n");
	while(1){
		//STEP 1: GET MATH EXPRESSION && VERIFY THE QUALITY OF IT
		printf("\n--------------------------------------------------------------------------------------\nWRITE YOUR EXPRESSION(TO END THE PROGRAM, PRESS 0): ");
		scanf("%s",expressao);
		printf("\n");
		//BREAK CONDITION
		if(strcmp(expressao,"0") == 0) break;
		//LOOP
		for(i=0;expressao[i] != '\0';i++){
			if(expressao[i] == '(') verifica_parenteses_aberto++;
			else if(expressao[i] == ')') verifica_parenteses_closed++;
			else if(expressao[i] =='+'||expressao[i] =='-'||expressao[i] =='*'||expressao[i] =='/') verifica_operadores++;	
		}
		if(verifica_parenteses_aberto == verifica_parenteses_closed){
			flag++;
		}
		else{
			printf("ERROR IN EXPRESSION - DIFFERENT NUMBER OF '(' AND ')'.\n");
		}
		if(verifica_parenteses_aberto == verifica_operadores){
			flag++;
		}
		else{
			printf("ERROR IN EXPRESSION - DIFFERENT NUMBER OF () AND OPERATIONS.\n");
		}
		if(flag == 2){ //FLAG OK
			//STEP 2: PUT THE EXPRESSION IN THE TREE
			for(i=0;expressao[i] != '\0';i++){
				insere(expressao[i]);
			}
			printf("CASE %d:\n",caso);
			//STEP 3: SHOW TREE INFO
			printf("PRE ORDER: ");
			pre_ordem(raiz);
			printf("\n");
			printf("SIMETRY: ");
			simetrica(raiz);
			printf("\n");
			printf("POST ORDER: ");
			pos_ordem(raiz);
			printf("\n");
			qtd = quantidade(raiz);
			alt = altura(raiz);
			printf("NODES: %d  || TREE HEIGTH: %d\n",qtd,alt);
			//TREE LEVELS
			niveis(raiz,0); //CALL FUNCTION TO ANALYZE LEVELS
			for(i = 0;i<alt;i++){ 
				printf("LEVEL %d: ",i);
				for(k = 0;k<qtd;k++){ 
					if(indices[k] == i){ 
						printf("%c ",elementos[k]);
					}
				}
				printf("\n");
			}
			//TREE LEAFS
			printf("LEAFS: ");
			folhas(raiz);
			printf("\n");
			
			//STEP 4: EXPRESSION RESULTS
			resposta = resultado(raiz);
			printf("EXPRESSION RESULTS: %d\n",resposta);
		}
		else{
			printf("ERROR UNKNOW IN EXPRESSION!\n");
		}
		//Reparos necessarios para o funcionamento do programa (variaveis globais) & outras definidas no main:	
		ref = 0;
		topo = 0;
		verifica_parenteses_aberto = 0;
		verifica_parenteses_closed = 0;
		verifica_operadores = 0;
		flag = 0;	
		raiz = arvoreLibera(raiz);
		caso++;
	}
	return 0;
}
