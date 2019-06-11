#include "stdafx.h"
#include "SortingBubbling.h"
#include <iostream>

template<class Data>
CSortingBubbling<Data>::CSortingBubbling() {

}

template<class Data>
CSortingBubbling<Data>::~CSortingBubbling()
{
}
/************************************************************************/
/* 它是一种较简单的排序算法。它会遍历若干次要排序的数列，每次遍历时，它都会从前往后依次的比较相邻两个数的大小；如果前者比后者大，则交换它们的位置。这样，一次遍历之后，最大的元素就在数列的末尾！ 采用相同的方法再次遍历时，第二大的元素就被排列在最大元素之前。重复此操作，直到整个数列都有序为止 */
/************************************************************************/
template<class Data>
void CSortingBubbling<Data>::sorting(Data arr[], int length) {
	int max_index = length - 1;
	for (int i = 0;i < length;i++)
	{
		bool is_exchange = true;
		max_index = (length - i) > max_index ? max_index : (length - i);
		int _max_index = max_index;
		for (int j = 0;j < _max_index;j++)
		{
			if (arr[j] > arr[j+1])
			{
				is_exchange = false;
				swap(arr[j], arr[j + 1]);
				/************************************************************************/
				/* 记录最后交换，后面没有交换说明j后面的数字已经是有序的没必要没次都全部循环 */
				/************************************************************************/
				max_index = j;
			}
		}
		/************************************************************************/
		/*循环结束is_exchange为true说明本次循环发现数组已经有序不需要再次进行交换*/
		/************************************************************************/
		if (is_exchange)
			break;
	}
}
/************************************************************************/
/* 换个思路,每次找到最大值放到最后再查找最小值放到数组最前面*/
/************************************************************************/
template<class Data>
void CSortingBubbling<Data>::BubbleSort(Data arr[], int len)
{
	int i = 0;
	int j = 0;
	int n = 0;//同时找最大值的最小需要两个下标遍历
	bool flag = true;
	int pos = 0;//用来记录最后一次交换的位置
	int k = len - 1;
	for (i = 0; i < len - 1; i++)//确定排序趟数
	{
		pos = 0;
		flag = 0;
		//正向寻找最大值
		for (j = n; j < k; j++)//确定比较次数
		{
			if (arr[j] > arr[j + 1])
			{
				//交换
				swap(arr[j], arr[j + 1]);
				flag = false;//加入标记
				pos = j;//交换元素，记录最后一次交换的位置
			}
		}
		if (flag)//如果没有交换过元素，则已经有序,直接结束
			return;
		k = pos;//下一次比较到记录位置即可
				//反向寻找最小值
		for (j = k; j > n; j--)
		{
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
				flag = false;
			}
		}
		n++;
		if (flag)//如果没有交换过元素，则已经有序,直接结束
			return;
	}
}

template<class Data>
void CSortingBubbling<Data>::swap(Data& a, Data& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}