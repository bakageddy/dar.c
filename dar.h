#ifndef DARC_H
#define DARC_H

#ifndef DARC_INITIAL_CAPACITY
#define DARC_INITIAL_CAPACITY 16
#endif // !DARC_INITIAL_CAPACITY

#include <stddef.h>
#define OPTION_IMPL
#include "option.h"

typedef struct {
	void *data;
	size_t size;
	size_t len;
	size_t cap;
} dar; 

dar dar_new(size_t size);
void dar_del(dar *dar);

#ifdef DARC_IMPL
#include <stdlib.h>
#include <assert.h>

dar dar_new(size_t size) {
	void *data = malloc(size * DARC_INITIAL_CAPACITY);
	assert(data != NULL);
	return (dar) {
		.data = data,
		.size = size,
		.len = 0,
		.cap = DARC_INITIAL_CAPACITY,
	};
}

void dar_del(dar *dar) {
	free(dar -> data);
	dar -> cap = 0;
	dar -> len = 0;
	dar -> data = NULL;
}

#endif // !DARC_IMPL

#endif // !DARC_H
