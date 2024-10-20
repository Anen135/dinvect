#include "dinvec.h" 

typedef struct {
    int id;
    char name[50];
} Person;

int main() {
    Vector vector_struct;
    Vector vector_int;
    vector_init(&vector_struct, sizeof(Person), 4); // Вектор для хранения структур 
    vector_init(&vector_int, sizeof(int), 4); // Вектор для хранения целых чисел

    // Создаем несколько структур
    Person p1 = {1, "Alice"};
    Person p2 = {2, "Bob"};
    int i1 = 1;
    int i2 = 2;

    vector_push(&vector_struct, &p1);
    vector_push(&vector_struct, &p2);
    vector_push(&vector_int, &i1);
    vector_push(&vector_int, &i2);

    // Тест сохранения данных
    p1.id = 10;
    strcpy(p1.name, "AliceUpdated");
    i1 = 10;

    // Вывод
    for (size_t i = 0; i < vector_struct.size; i++) {
        Person *p = (Person*)vector_get(&vector_struct, i);
        printf("ID: %d, Name: %s\n", p->id, p->name);
    }

    for (size_t i = 0; i < vector_int.size; i++) {
        int *p = (int*)vector_get(&vector_int, i);
        printf("Value: %d\n", *p);
    }

    vector_free(&vector_struct); // Освобождение памяти
    vector_free(&vector_int);

    return 0;
}
