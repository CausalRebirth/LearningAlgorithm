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
/* ����һ�ֽϼ򵥵������㷨������������ɴ�Ҫ��������У�ÿ�α���ʱ���������ǰ�������εıȽ������������Ĵ�С�����ǰ�߱Ⱥ��ߴ��򽻻����ǵ�λ�á�������һ�α���֮������Ԫ�ؾ������е�ĩβ�� ������ͬ�ķ����ٴα���ʱ���ڶ����Ԫ�ؾͱ����������Ԫ��֮ǰ���ظ��˲�����ֱ���������ж�����Ϊֹ */
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
				/* ��¼��󽻻�������û�н���˵��j����������Ѿ��������û��Ҫû�ζ�ȫ��ѭ�� */
				/************************************************************************/
				max_index = j;
			}
		}
		/************************************************************************/
		/*ѭ������is_exchangeΪtrue˵������ѭ�����������Ѿ�������Ҫ�ٴν��н���*/
		/************************************************************************/
		if (is_exchange)
			break;
	}
}
/************************************************************************/
/* ����˼·,ÿ���ҵ����ֵ�ŵ�����ٲ�����Сֵ�ŵ�������ǰ��*/
/************************************************************************/
template<class Data>
void CSortingBubbling<Data>::BubbleSort(Data arr[], int len)
{
	int i = 0;
	int j = 0;
	int n = 0;//ͬʱ�����ֵ����С��Ҫ�����±����
	bool flag = true;
	int pos = 0;//������¼���һ�ν�����λ��
	int k = len - 1;
	for (i = 0; i < len - 1; i++)//ȷ����������
	{
		pos = 0;
		flag = 0;
		//����Ѱ�����ֵ
		for (j = n; j < k; j++)//ȷ���Ƚϴ���
		{
			if (arr[j] > arr[j + 1])
			{
				//����
				swap(arr[j], arr[j + 1]);
				flag = false;//������
				pos = j;//����Ԫ�أ���¼���һ�ν�����λ��
			}
		}
		if (flag)//���û�н�����Ԫ�أ����Ѿ�����,ֱ�ӽ���
			return;
		k = pos;//��һ�αȽϵ���¼λ�ü���
				//����Ѱ����Сֵ
		for (j = k; j > n; j--)
		{
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
				flag = false;
			}
		}
		n++;
		if (flag)//���û�н�����Ԫ�أ����Ѿ�����,ֱ�ӽ���
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