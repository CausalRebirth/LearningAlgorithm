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
				spiling = i;//spilingʼ�ձ���Ϊ��ǰ�ҵ�����Сֵ���±�
		}
		/************************************************************************/
		/* spiling�����ı��Ժ󣬰ѵ�ǰ��Сֵ�����ڱ���ѭ����ǰ��                */
		/************************************************************************/
		if (spiling != gap)
			swap(arr[spiling], arr[gap]);
	}
}
/************************************************************************/
/* ����Ϊ��Ч�ʸ��ߣ����ǿ��ԶԴ��Ż���������д����������ÿһ�ζ����ҵ�һ�����ģ���ô������ȫ����һ��ѡ�������Ԫ������һ�����ģ�һ����С�ģ������ķŵ����ұߣ������෴��������С�ķŵ�����ߣ������෴��*/
/************************************************************************/
template<class Type>
void CSelectinSort<Type>::aptimizeSorting(Type arr[], int length) {
	int left = 0;
	int right = length - 1;
	while (left < right)
	{
		int max_spiling = right;//�������ֵ
		int min_spiling = left;//������Сֵ
		for (int i = left; i <= right; i++)
		{
			if (arr[max_spiling] < arr[i])
			{
				max_spiling = i;//max_spilingʼ�ձ���Ϊ��ǰ�ҵ������ֵ���±�
			}
			if (arr[min_spiling] > arr[i])
			{
				min_spiling = i;//min_spilingʼ�ձ���Ϊ��ǰ�ҵ�����Сֵ���±�
			}
		}
		//�����ֵ���õ�����ѭ�����Ҳ�
		if (max_spiling != right)
		swap(arr[max_spiling], arr[right]);
		//���豾��ѭ��min_spiling�ߵ���right����Ϊmax_spiling�Ѿ���right������λ�ã�right��ֵ����Ӧ����max_spilingλ����
		if (min_spiling == right)
			min_spiling = max_spiling;
		//����Сֵ�����ڱ���ѭ�������
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