#define DARC_IMPL
#include "dar.h"

void test_push(void) {
	// TODO: This doesn't pass
	dar array = dar_new(sizeof(int));
	for (int i = 0; i < 16; i++) {
		dar_push(&array, &i);
		int* xs = *array.data;
	}
	dar_del(&array);
}

int main(void) {
	test_push();
	return 0;
}
