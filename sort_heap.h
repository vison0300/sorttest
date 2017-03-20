#pragma once
#include "sort_util.h"

void heap_adjust(data_t* datas, int l, int r)
{
	data_t tmp = datas[l];
	int i = l;
	int j = 2 * i + 1;

	while (j <= r)
	{
		if (j + 1 <= r && datas[j] < datas[j + 1])
		{
			j++;
		}

		if (datas[i] > datas[j])
		{
			break;
		}
		else
		{
			swap(&datas[i], &datas[j]);

			i = j;
			j = 2 * i + 1;
		}
	}
}

void sort_heap(data_t* datas, int size)
{
	for (int i = size / 2; i >= 0; i--)
	{
		heap_adjust(datas, i, size - 1);
	}

	for (int i = size - 1; i > 0; i--)
	{
		swap(&datas[0], &datas[i]);
		heap_adjust(datas, 0, i - 1);
	}
}