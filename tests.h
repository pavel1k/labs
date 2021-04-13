#pragma once
#ifndef TEST_H
#define TEST_H


typedef enum {
	OK,
	ERROR
} Error;


typedef struct {
	Error(*function)();
	const char* name;
} test_function;

int test();
void sqr(int* val);
#endif // TEST_H
