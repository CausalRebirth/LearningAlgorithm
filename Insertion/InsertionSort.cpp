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
/*��ͨ��������*/
template<class Type>
void CInsertionSort<Type>::sorting(Type arr[], int length){
	//���������һ��Ԫ�ز��ÿ��� 
	for (int i = 1; i < length; i++)
	{
		for (int j = i; j > 0 && arr[j] <= arr[j - 1]; j--)
		{
			swap(arr[j], arr[j - 1]);
		}
	}
}

/************************************************************************/
/*���ø�ֵ�ķ�ʽ������Ԫ��λ���滻������                                */
/************************************************************************/
template<class Type>
void CInsertionSort<Type>::aptimizeSorting(Type arr[], int length){
	for (int i = 1; i < length; i++)
	{
		int j = i;
		Type spiling = arr[i];//��¼����ֵ
		// ��������Ժ������Ԫ�أ�����һλ
		for (j; j > 0 && spiling <= arr[j - 1]; j--)
		{
			arr[j] = arr[j - 1];
		}
		if (j != i)//������ֵ�ŵ��������
		{
			arr[j] = spiling;
		}
	}
}

/************************************************************************/
/* ʹ�ö��ֲ��Ҹ��ӿ��ٵ��ҵ�Ҫ����ĵ�����Ӷ����ʹ����������         */
/************************************************************************/
template<class Type>
void  CInsertionSort<Type>::binaryAptinizeSorting(Type arr[], int length) {
	for (int i = 1; i < length; i++) {
		int key = arr[i];  //��¼һ��arr[i]��ֵ
		int left = 0;
		int right = i - 1;
		// ���ֲ���Ѱ�Ҳ����
		while (left <= right) {
			int middle = left + ((right - left) >> 1);
			if (key < arr[middle]) {
				right = middle - 1;
			}
			else {
				left = middle + 1;
			}
		}
		// ��������Ժ������Ԫ�أ�����һλ
		for (int j = i - 1; j >= left; j--) {
			arr[j + 1] = arr[j];
		}
		// ����Ԫ�ص������
		arr[left] = key;
	}
}

template<class Type>
void CInsertionSort<Type>::swap(Type& a, Type& b){
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}