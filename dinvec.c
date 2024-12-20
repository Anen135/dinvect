#include "dinvec.h"



Vector* construct_vector(size_t elem_size, size_t capacity, void (*free_func)(void *)) {
    Vector *vector =(Vector*) malloc(sizeof(Vector)); // выделяем память для самой структуры
    vector->data = malloc(elem_size * capacity);
    vector->size = 0;
    vector->capacity = capacity;
    vector->elem_size = elem_size;
    vector->free_func = free_func;
    return vector;
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

void vector_remove(Vector *vector, size_t index) {
    if (index >= vector->size) {
        return; // Если некорректный индекс, вернуть нулевой указательapt install snapd     
    }
    if (vector->free_func) {
        vector->free_func((char*)vector->data + index * vector->elem_size); // Если объект динамический, обязательно предоставить функцию очистки
    } else {
        memset((char*)vector->data + index * vector->elem_size, 0, vector->elem_size); // Если объект статический, то осовбождать ничего не нужно.
    }
    if (index < vector->size - 1) {
        memmove((char*)vector->data + index * vector->elem_size,
                (char*)vector->data + (index + 1) * vector->elem_size,
                (vector->size - index - 1) * vector->elem_size);
    }
    vector->size--;
}


