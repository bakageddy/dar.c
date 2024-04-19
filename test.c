#define DARC_IMPL
#include "dar.h"

int main(void) {
	dar array = dar_new(sizeof(int));
	dar_del(&array);
	return 0;
}
