#include <stdio.h>
#include <stdlib.h>
#include "dtst.h"

istack_t *stack_new(int size) {
    istack_t *new_stack = malloc(sizeof(istack_t));
    new_stack->stack = malloc(size * sizeof(int));
    new_stack->top = -1;
    new_stack->size = size;
    return new_stack;
}

void stack_push(istack_t *s, int elm) {
    if (s->top == s->size - 1) {
        printf("Stack is full\n");
        return;
    }
    s->stack[++s->top] = elm;
}

int stack_pop(istack_t *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->stack[s->top--];
}

int stack_peek(istack_t *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->stack[s->top];
}

int stack_is_empty(istack_t *s) {
    return s->top == -1;
}
