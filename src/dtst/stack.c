#include "../helper.h"
#include "dtst.h"

astk_t *astk_new(int size) {
    astk_t *stack = _malloc(sizeof(astk_t));
    stack->size = size;
    stack->top = -1;
    stack->array = _calloc(size, sizeof(int));

    return stack;
}

void astk_push(astk_t *stack, int data) {
    if (stack->top == stack->size - 1) {
        stack->size *= 2;
        stack->array = _realloc(stack->array, stack->size * sizeof(int));
    }
    stack->top++;
    stack->array[stack->top] = data;
}

int astk_pop(astk_t *stack) {
    int value = -1;
    if (stack->top > -1) {
        value = stack->array[stack->top];
        stack->top--;
    }
    return value;
}

int astk_peek(astk_t *stack) {
    return stack->array[stack->top];
}

void astk_free(astk_t *stack) {
    _free(stack->array);
    _free(stack);
}
