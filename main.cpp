#include <stdio.h>
#include "sort_heap.h"
#include "sort_shell.h"
#include "sort_quick.h"
#include "sort_merge.h"
#include "sort_insert.h"
#include "sort_select.h"
#include "sort_bubble.h"

int main(int argc, char* argv[])
{
	const int size = 10000;
	data_t src[size] = {0};
	data_t tmp[size] = {0};

	init_datas(src, size);
	//print_datas(src, size);

#define SORT_TEST(pfn) \
	memcpy(tmp, src, sizeof(data_t) * size);\
	sort_test(tmp, size, #pfn, pfn)

	SORT_TEST(sort_heap);
	SORT_TEST(sort_quick);
	SORT_TEST(sort_merge);
	SORT_TEST(sort_shell);
	SORT_TEST(sort_insert);
	SORT_TEST(sort_select);
	SORT_TEST(sort_bubble);

	//print_datas(tmp, size);
	
	while (getchar() != 'q');
	return 0;
}