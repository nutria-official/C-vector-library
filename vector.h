#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define INITIALSIZE 2
#define RESIZESIZE 4 // The proportion size at which pop() resizes the allocated memory.
#define RESIZEAMOUNT 2 // The proportion in which the vector gets resized when RESIZESIZE is reached.

typedef struct {
    void *data;
    size_t size;
    size_t capacity;
    size_t data_type; // The size of the datatype.
} vector;

vector* vectorInit(const size_t DATA_TYPE);
void push(vector *x, const void *SIZE);
void pop(vector *x);
void* read(vector *x, const size_t INDEX);
void freeVector(vector *x);
bool allocationValidation(void *x); // Function for checking if memory allocation failed or not.

#endif

