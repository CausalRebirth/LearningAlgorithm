#pragma once
/************************************************************************/
/*  选择排序是一种直观的排序算法.它的原理是每一次从待排序中选出最小或最大的
一个元素,存放在序列的起始位置,直到全部待排序的数据元素排完.选择排序是不稳
定的排序方法*/
/************************************************************************/
template <class	Type>
class CSelectinSort
{
public:
	CSelectinSort();
	~CSelectinSort();
public:
	void sorting(Type arr[],int length);
	void aptimizeSorting(Type arr[],int length);
	void swap(Type& a, Type& b);
};

