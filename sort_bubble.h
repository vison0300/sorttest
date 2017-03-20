#pragma once
#include "sort_util.h"

void sort_bubble(data_t* datas, int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (datas[j] > datas[j + 1])
			{
				swap(&datas[j], &datas[j + 1]);
			}
		}
	}
}