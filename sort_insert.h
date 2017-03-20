#pragma once
#include "sort_util.h"

void sort_insert(data_t* datas, int size)
{
	data_t tmp;

	for (int i = 1; i < size; i++)
	{
		tmp = datas[i];

		for (int j = i - 1; j >= 0; j--)
		{
			if (tmp < datas[j])
			{
				datas[j + 1] = datas[j];
			}
			else
			{
				datas[j + 1] = tmp;
				break;
			}
		}
	}
}
