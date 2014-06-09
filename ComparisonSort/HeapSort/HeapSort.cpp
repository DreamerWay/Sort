/*******************************************************************************
*
* FileName : HeapSort.cpp
* Comment  : 堆排序
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/06/06
*
*******************************************************************************/
#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

//下边的交换函数采用的是不用额外数据交换两个数
void Swap(int &a, int &b)
{
	if (a != b) //这个判断主要是防止当a==b时结果使a与b都为0
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}
}
//从position位置上元素开始调整，使其满足大顶堆，递归调整左右子节点
void Adjust(int array[],int position,int len)
{
	int i=position;
	int max_position;
	while(i<=(len-2)/2)
	{
		max_position=2*i+1;
		if((max_position+1)<len && array[max_position+1]>array[max_position])
			max_position+=1;
		if(array[i]<array[max_position])
		{
			Swap(array[i],array[max_position]);
			i=max_position;
		}
		else
			break; //这个break很重要，不要把上边i=max_position放到if外边
		
	}
}

void HeapSort(int array[],int len)
{
	int k=0;
	//只需要建len-1次大顶堆，将堆顶的最大值不断交换到后边的len-1位置完成排序
	for(int i=0;i<len-1;i++)
	{
		k=len-1-i;//k代表建好大顶堆后需要交换的最新位置
		for(int j=(k-1)/2;j>=0;j--)
			Adjust(array,j,k+1);
		Swap(array[0],array[k]);
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
	HeapSort(test1,10);
	Print(test1,10);	
	return 0;
}
