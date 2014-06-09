/*******************************************************************************
*
* FileName : MergeSort.cpp
* Comment  : �鲢����
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/06/05
*
*******************************************************************************/
#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

//�鲢����ĺ���˼���ǽ�ԭʼ����һ��Ϊ������������������֮�󣬽�������ϲ���ԭʼ
//����������ɣ�������̵ݹ�ִ�У���ԭʼ���鲻�Ϸָ�����������

//��������ʵ�ַ�����merge()�ϲ���������ʱ������ʱ���飬���ǹ����new������ǳ���ʱ
//�±ߵ�ʵ�ַ�����MergeSort()��newһ����ʱ���飬����Ĳ�����������һ����ʱ����
void merge(int array[],int l,int mid,int r,int tmp[])
{
	int i=l,j=mid+1;
	int k=0;
	while(i<=mid && j<=r)
	{
		if(array[i]<array[j])
			tmp[k++]=array[i++];
		else
			tmp[k++]=array[j++];
	}
	
	while(i<=mid)
		tmp[k++]=array[i++];
	while(j<=r)
		tmp[k++]=array[j++];
	//��tmp������õ�Ԫ�طŵ�ԭ��Ԫ���������еĶ�Ӧλ��
	for(i=0;i<k;i++)
	{
		array[l+i]=tmp[i];
	}
}

void mergesort(int array[],int l,int r,int tmp[])
{
	if(l>=r) return;
	int mid=(l+r)/2;
	mergesort(array,l,mid,tmp);
	mergesort(array,mid+1,r,tmp);
	merge(array,l,mid,r,tmp);
}

void MergeSort(int array[],int len)
{
	int *p=new int[len];
	mergesort(array,0,len-1,p);
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
	MergeSort(test1,10);
	Print(test1,10);
	
	return 0;
}
