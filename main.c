#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tests.h"
#include "menu.h"
#include "my_array.h"


int main(){
	int t;
	Array* array = malloc(sizeof(Array));
	array->buffer_size = get_int(NULL, 0, 0);
	array_create(array, sizeof(int), array->buffer_size);
	{
		array = new_array();

	}



	return 0;
}
