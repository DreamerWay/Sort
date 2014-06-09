/*******************************************************************************
*
* FileName : MergeSort.cpp
* Comment  : 归并排序
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/06/05
*
*******************************************************************************/
#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

//归并排序的核心思想是将原始数组一分为二，如果这两个排序好之后，将其有序合并则原始
//数组排序完成，这个过程递归执行，将原始数组不断分割，最终完成排序

//在其他的实现方法中merge()合并有序数列时分配临时数组，但是过多的new操作会非常费时
//下边的实现方法在MergeSort()中new一个临时数组，后面的操作都共用这一个临时数组
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
	//将tmp中排序好的元素放到原来元素在数组中的对应位置
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
