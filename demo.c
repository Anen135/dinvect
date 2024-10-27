#include "dinvec.c"

// Макрос для генерации функции очистки
#define DEFINE_FREE_FUNC(type, ...)             \
    void free_##type(void *ptr) {                        \
        type *obj = (type *)ptr;                         \
        void *fields[] = {__VA_ARGS__};                  \
        for (size_t i = 0; i < sizeof(fields) / sizeof(fields[0]); i++) { \
            free(fields[i]);                             \
        }                                                \
    }

typedef struct {
    int id;
    char name[50];
    int *age;  
} Person;

// Генерация функции free_Person для очистки age
DEFINE_FREE_FUNC(Person, obj->age)

int main() {
    Vector *vector_struct = construct_vector(sizeof(Person), 4, free_Person);
    Vector *vector_int = construct_vector(sizeof(int), 4, NULL);
    vector_struct->is_dynamic = 1;

    // Динамические поля для структуры
    Person p1 = {1, "Alice", (int *)malloc(sizeof(int))};
    *p1.age = 25;
    Person p2 = {2, "Bob", (int *)malloc(sizeof(int))};
    *p2.age = 30;
    Person p3 = {3, "Charlie", (int *)malloc(sizeof(int))};
    *p3.age = 35;


    vector_push(vector_struct, &p1);
    vector_push(vector_struct, &p2);
    vector_push(vector_struct, &p3);

    int i1 = 1;
    int i2 = 2;
    int i3 = 3;
    vector_push(vector_int, &i1);
    vector_push(vector_int, &i2);
    vector_push(vector_int, &i3);
    i1 = 10; // Тест на сохранение значений

    // Тест переполнения вектора
    vector_push(vector_int, &i1);
    vector_push(vector_int, &i2);
    vector_push(vector_int, &i3);
    printf("vector int capacity:  %d\n", (int)vector_int->capacity);

    // Тест удаления элемента
    vector_remove(vector_struct, 1);
    vector_remove(vector_int, 1);

    // Вывод
    for (size_t i = 0; i < vector_struct->size; i++) {
        Person *p = (Person*)vector_get(vector_struct, i);
        printf("ID: %d, Name: %s, Age: %d\n", p->id, p->name, *p->age);
    }

    for (size_t i = 0; i < vector_int->size; i++) {
        int *p = (int*)vector_get(vector_int, i);
        printf("Value: %d\n", *p);
    }

    // Освобождение памяти
    vector_free(vector_struct);
    vector_free(vector_int);

    return 0;
}
