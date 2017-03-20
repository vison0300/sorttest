#pragma once
#include "sort_util.h"

void quick(data_t* datas, int l, int r)
{
	int i = l; 
	int j = r;
	data_t tmp = datas[i];

	while (i < j)
	{
		while (i < j && datas[j] >= tmp)j--;
		if (i < j)datas[i] = datas[j];

		while (i < j && datas[i] <= tmp)i++;
		if (i < j)datas[j] = datas[i];
	}

	datas[i] = tmp;

	if (l < i - 1)
	{
		quick(datas, l, i - 1);
	}
	
	if (r > i + 1)
	{
		quick(datas, i + 1, r);
	}
}

void sort_quick(data_t* datas, int size)
{
	quick(datas, 0, size - 1);
}