#pragma once
#include <time.h>
#include <windows.h>

typedef int data_t;

void init_datas(data_t* datas, int size)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < size; i++)
	{
		datas[i] = rand();
	}
}

void print_datas(data_t* datas, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d,", datas[i]);
	}

	printf("\n\n");
}

void swap(data_t* p1, data_t* p2)
{
	if (p1 && p2)
	{
		data_t tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
	}
}

double getusec()
{
	LARGE_INTEGER liFreq = {0};
	LARGE_INTEGER liCount = {0};

	QueryPerformanceCounter(&liCount); 
	QueryPerformanceFrequency(&liFreq);

	return double(liCount.QuadPart) * 1e6 / liFreq.QuadPart;
}

void sort_test(data_t* datas, int size, const char* name, void (*pfnsort)(data_t*, int))
{
	printf("%s[size=%d]--------------------------------------------------\n", name, size);
	double bus = getusec();
	(*pfnsort)(datas, size);
	double eus = getusec();
	printf("%s performance time = %.3f us\n\n", name, eus - bus);
}

