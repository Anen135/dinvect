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
} Vector;

void vector_init(Vector *vector, size_t elem_size, size_t capacity);
void vector_resize(Vector *vector, size_t new_capacity);
void vector_push(Vector *vector, void *value);
void* vector_get(Vector *vector, size_t index);
void vector_free(Vector *vector);
void vector_remove(Vector *vector, size_t index, void (*free_func)(void *));


#endif