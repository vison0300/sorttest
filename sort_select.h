#pragma once
#include "sort_util.h"

void sort_select(data_t* datas, int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;

		for (int j = i + 1; j < size; j++)
		{
			if (datas[j] < datas[min])
			{
				min = j;
			}
		}

		if (min > i)
		{
			swap(&datas[i], &datas[min]);
		}
	}
}