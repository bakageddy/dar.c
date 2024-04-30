#ifndef DARC_H
#define DARC_H

#ifndef DARC_INITIAL_CAPACITY
#define DARC_INITIAL_CAPACITY 16
#endif // !DARC_INITIAL_CAPACITY

#ifndef DARC_MINIMUM_CAPACITY
#define DARC_MINIMUM_CAPACITY 8
#endif // !DARC_MINIMUM_CAPACITY

#include <stddef.h>
// #define OPTION_IMPL
// #include "option.h"

typedef struct {
	void **data;
	size_t size;
	size_t len;
	size_t cap;
} dar; 

dar dar_new(size_t size);
int dar_push(dar *dar, void *elem);
void dar_del(dar *dar);

#define DARC_IMPL
#ifdef DARC_IMPL
#include <stdlib.h>
#include <assert.h>

dar dar_new(size_t size) {
	assert(size != 0);
	void *data = calloc(DARC_INITIAL_CAPACITY, sizeof(void *));
	assert(data != NULL);
	return (dar) {
		.data = (void **) data,
		.size = size,
		.len = 0,
		.cap = DARC_INITIAL_CAPACITY,
	};
}

int dar_grow(dar *dar) {
	void *res = realloc(dar -> data, sizeof(void*) * dar -> cap * 2);
	if (res == NULL) {
		return -1;
	}
	dar -> data = &res;
	dar -> cap *= 2;
	return 0;
}

int dar_push(dar *dar, void *elem) {
	if (dar -> cap == 0 || dar -> size == 0) return -1;
	if (dar -> len == dar -> cap) {
		if (dar_grow(dar) < 0) {
			return -1;
		}
	}
	dar -> data[dar -> len * sizeof(void *)] = elem;
	dar -> len += 1;
	return 0;
}

void dar_del(dar *dar) {
	free(dar -> data);
	dar -> cap = 0;
	dar -> len = 0;
	dar -> data = NULL;
}

#endif // !DARC_IMPL

#endif // !DARC_H
