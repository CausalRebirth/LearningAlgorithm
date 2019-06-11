#ifndef SortingBubbling_h__
#define SortingBubbling_h__

#pragma once
template<class Data>
class CSortingBubbling
{
public:
	CSortingBubbling();
	~CSortingBubbling();
public:
	void sorting(Data arr[], int length);
	void BubbleSort(Data arr[], int len);
	void swap(Data& a, Data& b);
};
#endif // SortingBubbling_h__

