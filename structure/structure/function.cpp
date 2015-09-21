
#include "function.h"

int* addNum(Example* e) {
	int* temp2 = new int(e->a + e->b);
	//int temp = e->a + e->b;
	return temp2;
}