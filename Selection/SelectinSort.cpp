#include "stdafx.h"
#include "SelectinSort.h"
template<class Type>
CSelectinSort<Type>::CSelectinSort()
{
}


template<class Type>
CSelectinSort<Type>::~CSelectinSort()
{
}

template<class Type>
void CSelectinSort<Type>::sorting(Type arr[], int length) {
	for (int gap = 0; gap < length; gap++)
	{
		int spiling = gap;
		for (int i = gap+1;i < length;i++)
		{
			if (arr[spiling] >= arr[i])
				spiling = i;//spiling始终保持为当前找到的最小值的下标
		}
		/************************************************************************/
		/* spiling发生改变以后，把当前最小值放置在本次循环最前端                */
		/************************************************************************/
		if (spiling != gap)
			swap(arr[spiling], arr[gap]);
	}
}
/************************************************************************/
/* 但是为了效率更高，我们可以对此优化，在这种写法当中我们每一次都是找到一个最大的，那么我们完全可以一次选择出两个元素来，一个最大的，一个最小的，把最大的放到最右边（降序相反），把最小的放到最左边（降序相反）*/
/************************************************************************/
template<class Type>
void CSelectinSort<Type>::aptimizeSorting(Type arr[], int length) {
	int left = 0;
	int right = length - 1;
	while (left < right)
	{
		int max_spiling = right;//储存最大值
		int min_spiling = left;//储存最小值
		for (int i = left; i <= right; i++)
		{
			if (arr[max_spiling] < arr[i])
			{
				max_spiling = i;//max_spiling始终保持为当前找到的最大值的下标
			}
			if (arr[min_spiling] > arr[i])
			{
				min_spiling = i;//min_spiling始终保持为当前找到的最小值的下标
			}
		}
		//把最大值放置到本次循环最右侧
		if (max_spiling != right)
		swap(arr[max_spiling], arr[right]);
		//假设本次循环min_spiling走到了right，因为max_spiling已经和right交换了位置，right的值现在应该在max_spiling位置上
		if (min_spiling == right)
			min_spiling = max_spiling;
		//把最小值放置在本次循环最左侧
		if (min_spiling != left)
			swap(arr[min_spiling], arr[left]);
		left++;
		right--;
	}
}
template<class Type>
void CSelectinSort<Type>::swap(Type& a, Type& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}