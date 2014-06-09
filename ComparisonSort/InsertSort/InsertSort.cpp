/*******************************************************************************
*
* FileName : InsertSort.cpp
* Comment  : 插入排序
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/06/05
*
*******************************************************************************/
#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;
//插入排序思想:每次将一个待排序的记录，按其关键字大小插入到前面已经排好序的子序列中的适当
//位置，直到全部记录插入完成为止
void InsertSort_1(int array[],int len)
{
	int i=0,j=0;
	int v=0;
	//循环从数组第二个元素开始，因为array[0]作为最初已排序部分 
	for(i=1;i<len;i++)
	{
		v=array[i]; //v为待排序的元素
		//将v与已排序元素从大到小比较，寻找v应插入的位置 
		for(j=i-1;j>=0;j--)
		{
			if(array[j]>v)
				array[j+1]=array[j];
			else
				break;
		}
		array[j+1]=v;
	}
}
//该实现方法在寻找插入位置的过程中，顺便用交换操作将待排序元素交换
//到待插入的位置
void InsertSort_2(int array[],int len)
{
	int i=0,j=0;
	int v=0;
	int tmp=0;
	for(i=1;i<len;i++)
	{
		v=array[i];
		for(j=i-1;j>=0;j--)
		{
			if(array[j]>v)
			{
				tmp=array[j];
				array[j]=array[j+1];
				array[j+1]=tmp;
			}
		}
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
	InsertSort_1(test1,10);
	Print(test1,10);

	int test2[10]={0};
	srand((unsigned)time(NULL)+1);  
	for(i = 0; i < 10;i++ )  
		test2[i]=rand()%20;

	Print(test2,10);
	InsertSort_2(test2,10);
	Print(test2,10);
	
	return 0;
}
