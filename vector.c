#include "vector.h"

vector* vectorInit(const size_t DATA_TYPE) {
    vector *x = malloc(sizeof(vector));
    if(allocationValidation(x) == false) {
        return NULL;
    }

    x->data = malloc(INITIALSIZE * DATA_TYPE);
    if(allocationValidation(x->data) == false) {
        free(x);
        return NULL;
    }
    x->capacity = INITIALSIZE;
    x->size = 0;
    x->data_type = DATA_TYPE;
    return x;
}

void push(vector *x, const void *SIZE) {
    if(x->size == x->capacity) {
        x->capacity *= 2;
        void *temp = realloc(x->data, x->capacity * x->data_type);
        printf("Re-allocated\n");
        if(allocationValidation(temp) == false) {
            return;
        }
        x->data = temp;
    }
    void *element = malloc(x->data_type);
    memcpy(element, SIZE, x->data_type);
    x->data[x->size] = element;
    x->size++;
}

void pop(vector *x) {
    if(x->size == 0) {
        perror("No values left!");
        return;
    }
    x->size--;
    if(x->size < x->capacity/RESIZESIZE) {
        x->capacity = ceil(x->capacity/RESIZEAMOUNT);
        void *temp = realloc(x->data, x->capacity * x->data_type);
        if(allocationValidation(temp) == false) {
            return;
        }
        x->data = temp;
    }
}

void* read(vector *x, const size_t INDEX) {
    if(INDEX > x->size) {
        perror("Invalid index\n");
        return NULL;
    }
    void *temp = x->data[INDEX];
    return temp;
}

void freeVector(vector *x) {
    if(x == NULL) {
        perror("Vector already deleted!");
        return;
    }
    free(x->data);
    free(x);
}

bool allocationValidation(void *x) {
    if(x == NULL) {
        perror("Memory allocation failed\n");
        return false;
    }
    return true;
}
