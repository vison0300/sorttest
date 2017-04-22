#pragma once
#include "sort_util.h"

void shell_insert(data_t* datas, int size, int d)
{
	data_t tmp;

	for (int i = d; i < size; i++)
	{
		tmp = datas[i];
		int j = i - d;
		
		for (; tmp < datas[j] && j >= 0; j -= d)
		{
			datas[j + d] = datas[j];
		}
		
		datas[j + d] = tmp;
	}
}

void sort_shell(data_t* datas, int size)
{
	int d = size / 2;

	while (d > 0)
	{
		shell_insert(datas, size, d);
		d /= 2;
	}
}
