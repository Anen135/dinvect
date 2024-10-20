#include "dinvec.h"

void vector_init(Vector *vector, size_t elem_size, size_t capacity) {
    vector->data = malloc(elem_size * capacity); 
    vector->size = 0;
    vector->capacity = capacity;
    vector->elem_size = elem_size;
}

void vector_resize(Vector *vector, size_t new_capacity) {
    vector->data = realloc(vector->data, vector->elem_size * new_capacity); 
    vector->capacity = new_capacity;
}

void vector_push(Vector *vector, void *value) {
    if (vector->size == vector->capacity) {
        vector_resize(vector, vector->capacity * 2); 
    }
    memcpy((char*)vector->data + vector->size * vector->elem_size, value, vector->elem_size);
    vector->size++;
}

void* vector_get(Vector *vector, size_t index) {
    if (index < vector->size) {
        return (char*)vector->data + index * vector->elem_size; 
    }
    return NULL; 
}

void vector_free(Vector *vector) {
    free(vector->data); 
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
    vector->elem_size = 0;
}
