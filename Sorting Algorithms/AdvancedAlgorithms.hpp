#pragma once
#include <iostream>
#include "SortingAlgorithms.h"

namespace HeapSort
{
	template <class Data, class Function>
	static void siftDown(Data arr[],int parent, const int size, Function cmp)
	{
		int child = 2 * parent + 1;
		while (child < size)
		{
			if (cmp(arr[child], arr[child + 1]))
			{
				child++;
			}

			if (cmp(arr[parent], arr[child]))
			{
				std::swap(arr[parent], arr[child]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
			{
				break;
			}
		}
	}
	template<class Data, class Function>
	static void buildHeap(Data arr[], const int size, Function cmp)
	{
		int lastParent = size / 2 - 1;
		for (int i = lastParent; i >= 0; i--)
		{
			siftDown(arr, i, size, cmp);
		}
	}
}

template<class Data, class Function>
void heapSort(Data arr[], const int size, Function cmp)
{
	HeapSort::buildHeap(arr, size,cmp);

	for (int i = size - 1; i > 0; i--)
	{
		std::swap(arr[0], arr[i]);
		HeapSort::siftDown(arr, 0, size, cmp);
	}
}

namespace QuickSort
{
	template <class Data, class Function>
	static void quickSort(Data arr[],int beg,int end, Function cmp)
	{
		while(beg < end)
		{
			int pivot = partition(arr, beg, end, cmp);
			if (pivot - beg < end - pivot)
			{
				quickSort(arr, beg, pivot - 1,cmp);
				beg = pivot + 1;
			}
			else
			{
				quickSort(arr, pivot + 1, end,cmp);
				end = pivot - 1;
			}
		}
	}

	template <class Data, class Function>
	static int partition(Data arr[], const int beg, const int end, Function cmp)
	{
		int el = arr[beg];
		int i = beg;
		int j = end + 1;

		while (true)
		{
			while (cmp(el,arr[++i]))
			{
				if (i==end)
				{
					break;
				}
			}

			while (cmp(arr[--j],el))
			{
				if (j==beg)
				{
					break;
				}
			}

			if (i>=j)
				break;

			std::swap(arr[i], arr[j]);
		}
		std::swap(arr[beg], arr[j]);
		
		return j;
	}
}

template <class Data, class Function = LTC<Data>>
void quickSort(Data arr[], const int size, Function cmp )
{
	QuickSort::quickSort(arr, 0, size - 1,cmp);
}

template<class Data, class Function=LTC<Data>>
void mergeSort(Data arr[], const int size, Function cmp)
{
	insertionSort(arr, size, cmp);
}



//TO DO 
//1. MergeSort