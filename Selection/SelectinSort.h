#pragma once
/************************************************************************/
/*  ѡ��������һ��ֱ�۵������㷨.����ԭ����ÿһ�δӴ�������ѡ����С������
һ��Ԫ��,��������е���ʼλ��,ֱ��ȫ�������������Ԫ������.ѡ�������ǲ���
�������򷽷�*/
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

