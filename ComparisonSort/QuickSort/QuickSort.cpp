/*******************************************************************************
*
* FileName : QuickSort.cpp
* Comment  : 三种方法实现快速排序
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/06/03
*
*******************************************************************************/
#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

//方法1采用最出名的双向填坑方法，以第一个元素为“主元”将数组分割，然后递归排序
void QuickSort_1(int array[],int l,int r)
{
	if(l<r)
	{
		int i=l,j=r;
		int v=array[l]; 
		while (i<j)
		{
			//从右到左
			while(j>i && array[j]>= v)
				j--;
			if(j>i)
				array[i++]=array[j];
			//从左到右
			while(i<j && array[i]<v)
				i++;
			if(i<j)
				array[j--]=array[i];
		}
		array[i]=v; // 注意不要忘了这一行 
		//递归排序分割后的左右子数组
		if(i-1>l)
			QuickSort_1(array,l,i-1);
		if(i+1<r)
			QuickSort_1(array,i+1,r);
	}
}
//方法2采用单向循环的方法，以最后一个元素为“主元”
void QuickSort_2(int array[],int l,int r)
{
	if(l<r)
	{
		int i=l-1,j=l; //注意i的初始值为l-1
		int v=array[r]; 
		int tmp=0;
		//从左到右遍历数组进行分割 
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
		//将“主元”换到中间位置达到分割目的
		i++;
		tmp=array[i];
		array[i]=array[r];
		array[r]=tmp;
		//递归调用
		if(i-1>l)
			QuickSort_2(array,l,i-1);
		if(i+1<r)
			QuickSort_2(array,i+1,r);
	}
}
//方法3采用三数取中方法，先将左中右三个位置中按大小处于中间位置的元素
//换到最左边，以这个中间大小的元素值为“主元”，这种方法主要是考虑“主元”
//对排序效率的影响
void QuickSort_3(int array[],int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		int tmp=0;
		//下边的3个if功能就是取出中间大小的元素放到最左边
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
		//以新的最左边的元素作为“主元”
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
