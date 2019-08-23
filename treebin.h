//BINARY TREE FOR MATH EXPRESSION BASED ON PILE DATA STRUCTURE
//AUTHOR: Kaike W.Reis

//TAD STRUCT
typedef struct node node;
struct node{ //STRUCTURE NODE
   char info;
   node *esq;
   node *dir;
};

//FUNCTIONS
node* arvoreLibera(node *raiz);//FREE THE TREE AFTER FINISHING THE EXPRESSION RESULTS
void insere(char conteudo);//INSERT NODE IN TREE
void pre_ordem(node* raiz);//PRE ORDER
void simetrica(node* raiz);//TREE SIMETRY
void pos_ordem(node* raiz);//POST ORDER
int resultado(node* raiz);//EXPRESSION RESULTS
void folhas(node *raiz);//TREE LEAFS
int quantidade(node *raiz);//TREE NODES
void niveis (node *raiz,int level);//TREE LEVELS
int altura(node *raiz);//TREE HEIGTH


