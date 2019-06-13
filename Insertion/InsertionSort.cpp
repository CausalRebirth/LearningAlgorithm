#include "stdafx.h"
#include "InsertionSort.h"

template<class Type>
CInsertionSort<Type>::CInsertionSort()
{
}

template<class Type>
CInsertionSort<Type>::~CInsertionSort()
{
}
/*普通插入排序*/
template<class Type>
void CInsertionSort<Type>::sorting(Type arr[], int length){
	//插入排序第一个元素不用考虑 
	for (int i = 1; i < length; i++)
	{
		for (int j = i; j > 0 && arr[j] <= arr[j - 1]; j--)
		{
			swap(arr[j], arr[j - 1]);
		}
	}
}

/************************************************************************/
/*采用赋值的方式来降低元素位置替换的消耗                                */
/************************************************************************/
template<class Type>
void CInsertionSort<Type>::aptimizeSorting(Type arr[], int length){
	for (int i = 1; i < length; i++)
	{
		int j = i;
		Type spiling = arr[i];//记录插入值
		// 将插入点以后的所有元素，后移一位
		for (j; j > 0 && spiling <= arr[j - 1]; j--)
		{
			arr[j] = arr[j - 1];
		}
		if (j != i)//将插入值放到插入点上
		{
			arr[j] = spiling;
		}
	}
}

/************************************************************************/
/* 使用二分查找更加快速的找到要插入的点儿，从而降低代码查找消耗         */
/************************************************************************/
template<class Type>
void  CInsertionSort<Type>::binaryAptinizeSorting(Type arr[], int length) {
	for (int i = 1; i < length; i++) {
		int key = arr[i];  //记录一下arr[i]的值
		int left = 0;
		int right = i - 1;
		// 二分查找寻找插入点
		while (left <= right) {
			int middle = left + ((right - left) >> 1);
			if (key < arr[middle]) {
				right = middle - 1;
			}
			else {
				left = middle + 1;
			}
		}
		// 将插入点以后的所有元素，后移一位
		for (int j = i - 1; j >= left; j--) {
			arr[j + 1] = arr[j];
		}
		// 插入元素到插入点
		arr[left] = key;
	}
}

template<class Type>
void CInsertionSort<Type>::swap(Type& a, Type& b){
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}