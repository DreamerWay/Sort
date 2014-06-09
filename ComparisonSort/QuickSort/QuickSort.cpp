/*******************************************************************************
*
* FileName : QuickSort.cpp
* Comment  : ���ַ���ʵ�ֿ�������
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/06/03
*
*******************************************************************************/
#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

//����1�����������˫����ӷ������Ե�һ��Ԫ��Ϊ����Ԫ��������ָȻ��ݹ�����
void QuickSort_1(int array[],int l,int r)
{
	if(l<r)
	{
		int i=l,j=r;
		int v=array[l]; 
		while (i<j)
		{
			//���ҵ���
			while(j>i && array[j]>= v)
				j--;
			if(j>i)
				array[i++]=array[j];
			//������
			while(i<j && array[i]<v)
				i++;
			if(i<j)
				array[j--]=array[i];
		}
		array[i]=v; // ע�ⲻҪ������һ�� 
		//�ݹ�����ָ�������������
		if(i-1>l)
			QuickSort_1(array,l,i-1);
		if(i+1<r)
			QuickSort_1(array,i+1,r);
	}
}
//����2���õ���ѭ���ķ����������һ��Ԫ��Ϊ����Ԫ��
void QuickSort_2(int array[],int l,int r)
{
	if(l<r)
	{
		int i=l-1,j=l; //ע��i�ĳ�ʼֵΪl-1
		int v=array[r]; 
		int tmp=0;
		//�����ұ���������зָ� 
		for(j=l;j<r;j++)
		{
			if(array[j]<=v)
			{
				i++;
				tmp=array[i];
				array[i]=array[j];
				array[j]=tmp;
			}
		}
		//������Ԫ�������м�λ�ôﵽ�ָ�Ŀ��
		i++;
		tmp=array[i];
		array[i]=array[r];
		array[r]=tmp;
		//�ݹ����
		if(i-1>l)
			QuickSort_2(array,l,i-1);
		if(i+1<r)
			QuickSort_2(array,i+1,r);
	}
}
//����3��������ȡ�з������Ƚ�����������λ���а���С�����м�λ�õ�Ԫ��
//��������ߣ�������м��С��Ԫ��ֵΪ����Ԫ�������ַ�����Ҫ�ǿ��ǡ���Ԫ��
//������Ч�ʵ�Ӱ��
void QuickSort_3(int array[],int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		int tmp=0;
		//�±ߵ�3��if���ܾ���ȡ���м��С��Ԫ�طŵ������
		if(array[l]<array[m])
		{
			tmp=array[l];
			array[l]=array[m];
			array[m]=tmp;
		}
		if(array[r]<array[m])
		{
			tmp=array[r];
			array[r]=array[m];
			array[m]=tmp;
		}
		if(array[r]<array[l])
		{
			tmp=array[r];
			array[r]=array[l];
			array[l]=tmp;
		}
		//���µ�����ߵ�Ԫ����Ϊ����Ԫ��
		int i=l,j=r;
		int v=array[l];
		while(i<j)
		{
			while(j>i && array[j]>=v)
				j--;
			if(j>i)
				array[i++]=array[j];

			while(i<j && array[i]<v)
				i++;
			if(i<j)
				array[j--]=array[i];
		}
		array[i]=v;
		if(i-1>l)
			QuickSort_3(array,l,i-1);
		if(i+1<r)
			QuickSort_3(array,i+1,r);
	}
}
void Print(int array[],int length)
{
	//print the array in the form:1->2->3->0
	for(int i=0;i<length;i++)
	{
		if(i<length-1)
			cout<<array[i]<<"->";
		else
			cout<<array[i]<<endl;
	}
}

int main()
{

	int test1[10]={0};
	srand((unsigned)time(NULL));  
	for(int i = 0; i < 10;i++ )  
		test1[i]=rand()%20;
	
	Print(test1,10);
	QuickSort_1(test1,0,9);
	Print(test1,10);
	
	int test2[10]={0};
	srand((unsigned)time(NULL)+1);  
	for(i = 0; i < 10;i++ )  
		test2[i]=rand()%20;
	
	Print(test2,10);
	QuickSort_2(test2,0,9);
	Print(test2,10);
	
	int test3[10]={0};
	srand((unsigned)time(NULL)+2);  
	for(i = 0; i < 10;i++ )  
		test3[i]=rand()%20;
	
	Print(test3,10);
	QuickSort_3(test3,0,9);
	Print(test3,10);

	return 0;
}
