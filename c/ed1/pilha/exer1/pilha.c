#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

/* Estrutura de pilha para operações de desfazer (undo) e refazer (redo) */
typedef struct {
    int *array;
    int size;
    int peek_redo;
    int peek_undo;
} Stack;

/* Estrutura do editor de texto */
typedef struct {
    char *buffer;  /* Conteúdo atual do editor */
    int end;       /* Posição do último caractere válido no buffer */
    int size;      /* Capacidade máxima do buffer */
    Stack *s;      /* Pilha de operações para desfazer e refazer*/
} Editor;

/* Verifica se a pilha de redo está cheia */
int undo_redo_full (Stack *s) {
    return((s->peek_undo >= s->size - 1) || (s->peek_redo < 0));
}

/* Verifica se a pilha de undo está vazia */
int undo_redo_empty (Stack *s) {
    return((s->peek_redo + 1) == s->size) && (s->peek_undo == 0);
}

/* Adiciona um caractere na pilha de undo */
void push_undo (char c, Stack *s) {
    s->array[s->peek_undo] = c;
    (s->peek_undo)++;
}

/* Remove e retorna o último caractere da pilha de undo */
int pop_undo (Stack *s) {
    int param;
    param = s->array[s->peek_undo];
    s->array[s->peek_undo] = ' ';
    (s->peek_undo)--;
    return param;
}

/* Adiciona um caractere na pilha de redo */
void push_redo (char c, Stack *s) {
    s->array[s->peek_redo] = c;
    (s->peek_undo)--;
}

/* Remove e retorna o último caractere da pilha de redo */
int pop_redo (Stack *s) {
    int param = s->array[s->peek_redo];
    s->array[s->peek_redo] = ' '; // <- blank
    (s->peek_redo)++;
    return param;
}


/* Limpa todos os elementos da pilha de redo e undo */
void clear_undo_redo (Stack *s) {    
    s->peek_undo = 0;
    s->peek_redo = s->size - 1;
}

/* Cria uma pilha de caracteres com tamanho definido */
Stack* create_stack (int size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->array = (int *)malloc(size * sizeof(int));
    s->size = size;
    s->peek_undo = 0;
    s->peek_redo = size - 1;
    return s;
}

/* Inicializa o editor de texto com tamanho definido */
Editor* create_editor (int size) {
    Editor *E = (Editor *)malloc(sizeof(Editor));
    E->buffer = (char *)malloc(sizeof(char) * size);
    E->end = 0;
    E->size = size;
    E->s = create_stack(size);
    return E;
}

/* Libera memória do editor e suas pilhas */
void kill_editor (Editor *E) {
    free(E->buffer);
    free(E->s->array);
    free(E->s);
    free(E);
}

/* Exibe o conteúdo atual do editor */
void show_screen (Editor *E) {
   printf("Tela: %s\n", E->buffer);
}

/* Adiciona um caractere ao buffer do editor e atualiza pilhas */
void add_char (char c, int flag_clean_redo, Editor *E) {
    if(flag_clean_redo) {
        clear_undo_redo(E->s);
    }

    if(E->end >= E->size - 1) {
        printf("Stack Overflow");
        exit(1);
    }

    E->buffer[E->end] = c;
    (E->end)++;
}

/* Função principal de digitação, atualiza buffer e pilhas */
void digitar (char c, Editor *E) {
   printf("> digitar: %c\n", c);
   add_char(c, true, E);
   show_screen(E);
}

/* Desfaz a última operação de digitação */
void desfazer (Editor *E) {
    push_undo(E->buffer[E->end], E->s);
    E->buffer[E->end] = ' ';
    (E->end)--;
}

/* Refaz a última operação desfeita */
void refazer (Editor *E) {
    char c = pop_undo(E->s);
    push_redo(c, E->s);
    E->buffer[E->end] = c;
    (E->end)++;
}

int main () {
  /* Cria um editor com capacidade para 32 caracteres */
  Editor *E = create_editor (32); 
  digitar ('A', E);
  digitar ('B', E);
  digitar ('C', E);

  desfazer (E);
  desfazer (E);
  desfazer (E);
  digitar ('X', E);
  refazer (E);

  kill_editor (E);
  return 0;
}

