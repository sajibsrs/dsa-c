#include <stdio.h>
#include <stdlib.h>
#include "dtst.h"

stck_t *stack_new(int size) {
    stck_t *new_stack = malloc(sizeof(stck_t));
    new_stack->stack = malloc(size * sizeof(int));
    new_stack->top = -1;
    new_stack->size = size;
    return new_stack;
}

void stack_push(stck_t *s, int elm) {
    if (s->top == s->size - 1) {
        printf("Stack is full\n");
        return;
    }
    s->stack[++s->top] = elm;
}

int stack_pop(stck_t *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->stack[s->top--];
}

int stack_peek(stck_t *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->stack[s->top];
}

int stack_is_empty(stck_t *s) {
    return s->top == -1;
}
