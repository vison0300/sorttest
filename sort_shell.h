#pragma once
#include "sort_util.h"

void shell_insert(data_t* datas, int size, int d)
{
	data_t tmp;

	for (int i = d; i < size; i++)
	{
		tmp = datas[i];
		
		for (int j = i - d; j >= 0; j -= d)
		{
			if (tmp < datas[j])
			{
				datas[j + d] = datas[j];
			}
			else
			{
				datas[j + d] = tmp;
				break;
			}
		}
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
