#include <stdio.h>
#include "threads/palloc.h"

extern enum palloc_allocator pallocator;

void test_FF(void)
{
	void *a = palloc_get_multiple(0, 9);
	void *b = palloc_get_multiple(0, 20);
	palloc_free_multiple(a, 9);

	void *c = palloc_get_multiple(0, 8);

	palloc_get_status(0);
}

void test_NF(void)
{
	test_FF();
}

void test_BF(void)
{
	void *a = palloc_get_multiple(0, 15);
	void *b = palloc_get_multiple(0, 1);
	void *c = palloc_get_multiple(0, 8);
	void *d = palloc_get_multiple(0, 1);
	
	palloc_free_multiple(a, 15);
	palloc_free_multiple(c, 8);

	palloc_get_status(0);

	void *e = palloc_get_multiple(0, 7);

	palloc_get_status(0);

}

void test_Buddy(void)
{
	void *a = palloc_get_multiple(0, 16);
	void *b = palloc_get_multiple(0, 16);
	void *c = palloc_get_multiple(0, 32);

	palloc_get_status(0);

	palloc_free_multiple(b, 16);
	void *d = palloc_get_multiple(0, 32);

	palloc_get_status(0);
}
void alloctest(void)
{
	printf("implement page allocation test!!!\n\n");

	switch(pallocator) {
	case ALLOCATOR_FF:
		printf("Test First fit is complete!!\n");
		test_FF();
		break;
	case ALLOCATOR_NF:
		printf("Test Next fit is copmlete!!\n");
		test_NF();
		break;
	case ALLOCATOR_BF:
		printf("Test Best fit is complete!!\n");
		test_BF();
		break;
	case ALLOCATOR_BUDDY:
		printf("Test Buddy System is copmlete!!\n");
		test_Buddy();
		break;
	}
}
