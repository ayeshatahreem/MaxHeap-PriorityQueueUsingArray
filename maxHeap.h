#ifndef Heap_H
#define Heap_H

#include <iostream>
using namespace std;

class heap
{
private:
	int arr[100];
	int capacity;
public:
	heap()
	{
		arr[0] = 0;
		capacity = 0;
	}
	heap(int size)
	{
		capacity = size;
	}
	void heapify(int arr[], int i, int p)  
	{
		int l, r, largest, swap = 0;      
		l = 2 * i + 1;							// i = 0 
		r = 2 * i + 2;
		if (l <= p && arr[l] > arr[i])
		{
			largest = l;
		}
		else
		{
			largest = i;
		}
		if (r<=p && arr[r]>arr[largest])
		{
			largest = r;
		}
		if (largest != i)
		{
			swap = arr[i];            
			arr[i] = arr[largest];
			arr[largest] = swap;
			heapify(arr, largest, p);
		}

	}
	void createHeap(int arr[], int n)
	{
		int p = n - 1;
		for (int i = n / 2 ; i >= 0; i--)
		{
			heapify(arr, i ,p);
		}
	}
	void heapSort(int arr[], int n)
	{
		int heapSize, i, swap;
		heapSize = n - 1;
		for (i = heapSize; i >= 0; i--)
		{
			swap = arr[0];
			arr[0] = arr[heapSize];
			arr[heapSize] = swap;
			heapSize--;
			heapify(arr, 0, heapSize);
		}
	}
	void bottomUp(int arr[], int n)
	{
		int parent = n / 2;
		if (arr[parent] > arr[n])
		{
			swap(arr[parent], arr[n]);
			bottomUp(arr, parent);
		}
	}
	void insertElement(int arr[], int key,int n)
	{
		arr[n-1] = key;
		bottomUp(arr, n - 1);
	}
	void bottomDown(int arr[], int i, int n)
	{
		int min = 0;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left <= n && arr[left] < arr[i])
		{
			min = left;
		}
		if (right <= n && arr[right] < arr[min])
		{
			min = right;
		}
		swap(arr[min], arr[i]);
		bottomDown(arr, min, n);
	}
	void deleteElement(int arr[], int n,int size)
	{
		if (n < 1)
		{
			return;
		}
		int temp = arr[1];
		swap(arr[1], arr[n]);
		bottomDown(arr, n-1,size);
	}
	~heap()
	{
		delete []arr;
	}
};
#endif