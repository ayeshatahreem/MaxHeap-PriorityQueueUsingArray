/*Write C++ code for MAX-Heap (priority queue) class using Array for storage of heap with following member functions:  
1.Constructor  
2.Destructor 
3.Insert,   Time Complexity O(lgN) 
4.Delete-MAX  Time Complexity O(lgN) 
5.Print-Heap  
6.Max-Heapify  Time Complexity O(N) 
7.Heap-Sort  Time Complexity O(N lg N) 

You can take Maximum Size of Heap as input from User at run time. */
#include <iostream>
#include "maxHeap.h"
using namespace std;

int main()
{
	heap obj;
	int arr[100];
	int size = 0;
	cout << "Enter size of elements to be inserted at maximum heap : ";
	cin >> size;
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter element " <<i+1<<": ";
		cin >> arr[i];
	}
	obj.createHeap(arr, size);
	//obj.heapSort(arr, size);
	cout << endl;
	cout << "Array after Heapify is: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	obj.heapSort(arr, size);
	cout << "Array after heap sort is: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	int element = 0;
	cout << "Enter element to be inserted : ";
	cin >> element;
	size++;
	obj.insertElement(arr, element,size);
	cout << endl;
	cout << "After insertion of an element, the new array comes out to be as: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}