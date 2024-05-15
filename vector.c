#include "vector.h"

void init_vector(Vector *vec, size_t elem_size)
{
    assert(vec);
    assert(elem_size);

    vec->capacity = 1;
    vec->size = 0;
    vec->elem_size = elem_size;
    vec->data = malloc(sizeof(void*));
    vec->is_valid = 1;
}

void free_vector(Vector *vec) {
    assert(vec);
    assert(vec->is_valid);

    for (uint32_t i = 0; i < vec->size; i++)
        free(vec->data[i]);

    vec->capacity = 0;
    vec->size = 0;
    vec->data = NULL;
    vec->is_valid = 0;
}

void push_back(Vector *vec, void *datum) {
    assert(vec);
    assert(datum);
    assert(vec->is_valid);

    if (vec->capacity == vec->size) {
        vec->capacity *= 2;
        void **new_data = malloc(sizeof(void*) * vec->capacity);

        for (uint32_t i = 0; i < vec->size; i++)
            new_data[i] = vec->data[i];
        
        free(vec->data);
        vec->data = new_data;
    }

    void *datum_copy_ptr = malloc(vec->elem_size);

    memcpy(datum_copy_ptr, datum, vec->elem_size);

    vec->data[vec->size] = datum_copy_ptr;
    vec->size++;

    return;
}

void pop_back(Vector *vec) {
    assert(vec);
    assert(vec->size > 0);

    free(vec->data[vec->size]);

    vec->size--;
}

void resize(Vector *vec, size_t nsize) {
    assert(vec);

    if (nsize <= vec->size) {
        vec->size = nsize;
        return;
    }

    void **new_data = malloc(sizeof(void*) * nsize);

    for (uint32_t i = 0; i < min(nsize, vec->size); i++)
        new_data[i] = vec->data[i];
    
    for (uint32_t i = 0; i < min(nsize, vec->size); i++)
        free(vec->data[i]);

    free(vec->data);

    vec->capacity = nsize;
    vec->data = new_data;
}

void *at(Vector *vec, size_t index) {
    assert(vec);
    assert(index < vec->size);

    return vec->data[index];
}

size_t capacity(Vector *vec) { 
    assert(vec);
    return vec->capacity;
}

size_t size(Vector *vec) {
    assert(vec);
    return vec->size;
}

int main(void) {
    Vector vec;
    init_vector(&vec, sizeof(uint32_t));

    free_vector(&vec);
}
