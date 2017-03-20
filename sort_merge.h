#pragma once
#include "sort_util.h"

void merge(data_t* tmp, data_t* datas, int l, int m, int r)
{
	int n = l;
	int i = l;
	int j = m + 1;

	while (i <= m && j <= r)
	{
		if (datas[i] < datas[j])
		{
			tmp[n++] = datas[i++];
		}
		else
		{
			tmp[n++] = datas[j++];
		}
	}

	while (i <= m)
	{
		tmp[n++] = datas[i++];
	}

	while (j <= r)
	{
		tmp[n++] = datas[j++];
	}

	for (int i = 0; i <= r; i++)
	{
		datas[i] = tmp[i];
	}
}

void split_merge(data_t* tmp, data_t* datas, int l, int r)
{
    if (l < r)
	{
		int m = (l + r) / 2;
		split_merge(tmp, datas, l, m);
		split_merge(tmp, datas, m + 1, r);
		merge(tmp, datas, l, m, r);
	}
}

void sort_merge(data_t* datas, int size)
{
	data_t* tmp = new data_t[size];
	split_merge(tmp, datas, 0, size - 1);
	delete[] tmp;
}