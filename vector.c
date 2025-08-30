#include "vector.h"

vector* vectorInit(const size_t DATA_TYPE) {
    vector *x = malloc(sizeof(vector));
    if(allocationValidation(x) == false) {
        return NULL;
    }

    x->data = malloc(INITIALSIZE * sizeof(void*));
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
    void *element = malloc(x->data_type); // Because the original data wasen't dynamicly allocated.
    if(allocationValidation(element) == false) {
        return;
    }
    memcpy(element, SIZE, x->data_type);
    
    if(x->size == x->capacity) {
        x->capacity *= 2;
        void *temp = realloc(x->data, x->capacity * sizeof(void*));
    
        if(allocationValidation(temp) == false) {
            return;
        }
        x->data = temp;
    }
    x->data[x->size] = element;
    x->size++;
}

void pop(vector *x) {
    if(x->size == 0) {
        perror("No values left!");
        return;
    }

    x->size--;
    x->data[x->size] = NULL;

    if(x->size < x->capacity/RESIZESIZE) {
        x->capacity = ceil(x->capacity/RESIZEAMOUNT);
        void *temp = realloc(x->data, x->capacity * sizeof(void*));
        if(allocationValidation(temp) == false) {
            return;
        }
        x->data = temp;
    }
}

void* read(vector *x, const size_t INDEX) {
    if(INDEX >= x->size) {
        perror("Invalid index\n");
        return NULL;
    }
    return x->data[INDEX];
}

void freeVector(vector *x) {
    if(x == NULL) {
        perror("Vector already deleted!");
        return;
    }
    for(size_t i = 0; i < x->size; i++) {
        free(x->data[i]);
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
