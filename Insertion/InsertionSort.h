#pragma once
template<class Type>
class CInsertionSort
{
public:
	CInsertionSort();
	~CInsertionSort();
public:
	void sorting(Type arr[], int length);
	void aptimizeSorting(Type arr[], int length);
	void binaryAptinizeSorting(Type arr[], int length);
	void swap(Type& a, Type& b);
};

