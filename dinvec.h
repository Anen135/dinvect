#ifndef VECTOR_H
#define VECTOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    void *data;        
    size_t size;       
    size_t capacity;   
    size_t elem_size;
    unsigned short is_dynamic : 1; // Я не знаю зачем это, пусть будет.
    void (*free_func)(void *);
} Vector;

void vector_resize(Vector *vector, size_t new_capacity);
void vector_push(Vector *vector, void *value);
void* vector_get(Vector *vector, size_t index);
void vector_free(Vector *vector);
void vector_remove(Vector *vector, size_t index);
Vector* construct_vector(size_t elem_size, size_t capacity, void (*free_func)(void *));



#endif