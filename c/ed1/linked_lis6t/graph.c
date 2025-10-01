#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct _no {
   int id; /*Identificador armazenado no nó. */
   struct _no *next; /*Próximo nó na lista encadeada. */
} List;

/*Estrutura de Grafo por lista de adjacências: */
typedef struct {
   int E; /*Quantidade de arestas.*/
   int V; /*Quantidade de vértices.*/
   List **list; /*Listas de adjacências (uma por vértice).*/
} Graph;

/*Libera a memória de uma lista encadeada.*/
void free_list (List *l) {
  while (l != NULL) {
    List *t = l->next; 
    free (l); 
    l = t; 
  }
}

/*Cria um grafo com {V} listas de adjacência.*/
Graph* create (int V) {
  Graph *G = (Graph *)malloc(sizeof(Graph));
  G->E = 0;
  G->V = V;
  G->list = (List **)malloc(G->V * sizeof(List *));
  int i;
  /*Uma lista de adjacência por vértice:*/ 
  for (i = 0; i < G->V; i++) 
    G->list[i] = NULL; 
  return G;
}

/*Libera memória de um grafo representado por lista de adjacências.*/
void destroy (Graph *G) {
  int i;	
  for (i = 0; i < G->V; i++) 
    free_list (G->list[i]);	   
  free (G->list);
  free (G);
}

/*Imprime um grafo representado por lista de adjacências.*/
void print (Graph *G) {
  int i;	
  for (i = 0; i < G->V; i++) {
    List *v = G->list[i];
    List *tmp = v;
    printf("%d -> ", i);
    for (tmp = v; tmp != NULL; tmp = tmp->next) {
      printf ("%d ", tmp->id);     
    }
    printf("\n");
  }	
}

/*Adiciona aresta {v} no final da lista de {u} */
void add_edge (int u, int v, Graph *G) {
    // Criar novo nó
    List *new = (List *)malloc(sizeof(List));
    new->id = v;
    new->next = NULL;

    // Se a lista de u estiver vazia, vira o primeiro
    if (G->list[u] == NULL) {
        G->list[u] = new;
    } else {
        // Senão, percorre até o fim da lista
        List *tmp = G->list[u];
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new;
    }

    // Esta func foi feita pelo ChatGPT. Estava com dificuldades com a syntax dessa estrutura entao pedi uma ajuda... (faltei no dia)

    // Atualiza número de arestas
    G->E++;
}



/* Remove aresta {v} da lista de {u} em {G} */
void remove_edge (int u, int v, Graph *G) {
  List *lista = G->list[u];
  List *hind = NULL;
  // Se for vazia
  if (lista->next == NULL)
    return;

  // Enquanto nao encontrar V ou o Final
  while((lista->id != v) && (lista->next != NULL)) {
    hind = lista;
    lista = lista->next;
  }

  if (hind == NULL) {
      G->list[u] = lista->next;
    } else {
      hind->next = lista->next;
    }

  free(lista);
  G->E--;
}

/* Função binária que retorna TRUE se {u} é amigo de {v}: */
int friend (int u, int v, Graph *G) {
  List *lista = G->list[u];

  while((lista->id != v) && (lista->next != NULL)) {
    lista = lista->next;
  }

  if (lista->id == v) { // se for o ultimo elemento
    return 1;
  }
  return 0;
  
}

/*Função principal.*/
int main () {

   /*Número de vértices*/	
   int V = 5; 

   /*Construindo o grafo mostrado na lista de exercícios:*/
   Graph *G = create (V);

   /*Inserção de arestas (adicionando amizades):*/
   /*Amizades do {0}*/
   add_edge (0, 1, G);
   add_edge (0, 4, G);
   /*Amizades do {1}*/
   add_edge (1, 0, G);
   add_edge (1, 4, G);
   add_edge (1, 2, G);
   add_edge (1, 3, G);
   /*Amizades do {2}*/
   add_edge (2, 1, G);
   add_edge (2, 3, G);
   /*Amizades do {3}*/
   add_edge (3, 1, G);
   add_edge (3, 4, G);
   add_edge (3, 2, G);
   /*Amizades do {4}*/
   add_edge (4, 3, G);
   add_edge (4, 0, G);
   add_edge (4, 1, G);
   printf("Grafo apos solicitacoes de amizade:\n");
   print (G);
   printf("# vertices = %d, # arestas = %d\n\n", G->V, G->E);

   /*Remoção de arestas (fazendo um unfollow)*/
 
   printf("Grafo apos unfollow de [{1} p/ {3}], [{2} p/ {1}] e [{4} p/ {0}]:\n");
   remove_edge (1,3,G);
   remove_edge (2,1,G);
   remove_edge (4,0,G);
   print (G);
   printf("# vertices = %d, # arestas = %d\n\n", G->V, G->E);

   printf("O usuario {1} e amigo de {2}: %d\n", friend (1,2,G));
   printf("O usuario {1} e amigo de {3}: %d\n", friend (1,3,G));
   printf("O usuario {2} e amigo de {1}: %d\n", friend (2,1,G));

   destroy (G);      

   return 0;
}
