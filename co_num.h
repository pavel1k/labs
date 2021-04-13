#pragma once
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

typedef struct complex {
    float realPart;
    float complexPart;

    size_t size;
} complex;

complex* new_complex(float realPart, float complexPart);

void* complex_add(void* num1, void* num2, void* res);
void* complex_sub(void* num1, void* num2, void* res);
void* complex_mult(void* num1, void* num2, void* res);

void complex_print(void* num);
int complex_is_same(void* num1, void* num2);