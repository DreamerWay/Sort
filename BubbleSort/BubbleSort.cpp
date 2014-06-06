/*******************************************************************************
*
* FileName : BubbleSort.cpp
* Comment  : 冒泡排序
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/06/04
*
*******************************************************************************/
#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

void BubbleSort_1(int array[],int len)
{
	int i=0,j=0;
	int tmp=0;
	for(i=0;i<len;i++)
		for(j=1;j<len-i;j++) //注意len-i,每一趟将最大值滚到最右边
		{
			if(array[j-1]>array[j])
			{
				tmp=array[j-1];
				array[j-1]=array[j];
				array[j]=tmp;
			}
		}
}

void BubbleSort_2(int array[],int len)
{
	int i=0,j=0;
	int tmp=0;
	int flag=false; //添加flag,主要是为了防止出现已经都有序情况下算法还去做无用功
	for(i=0;i<len;i++)
	{
		for(j=1;j<len-i;j++)
		{
			if(array[j-1]>array[j])
			{
				tmp=array[j-1];
				array[j-1]=array[j];
				array[j]=tmp;
				flag=true;
			}
		}
		if(flag==false)
			break;
	}
}

void BubbleSort_3(int array[],int len)
{
	int i=0,j=0;
	int tmp=0;
	int true_len=len;
	//该实现方法主要是考虑这样一种情况
	//如果数组靠右边的一部分已经有序，只需要找到最后无序的位置，第二遍遍历到这个位置即可
	while(true_len>0)
	{
		i=true_len;
		true_len=0;
		for(j=1;j<i;j++)
		{
			if(array[j-1]>array[j])
			{
				tmp=array[j-1];
				array[j-1]=array[j];
				array[j]=tmp;
				true_len=j;
			}
		}
	}
}
//上边冒泡排序算法需要在每次遍历的时候进行很多次交换操作，影响效率
//进行一趟遍历的最终目的是找出最大的那个数并放到最右边的位置
//我们可以在遍历的时候用一个“指针”始终指向最大值位置，一趟遍历结束后
//再进行一次交换，将最大值换到最右边，这事实上就是选择排序
void SelectSort(int array[],int len)
{
	int i=0,j=0;
	int tmp=0;
	int p_max=0;
	for(i=0;i<len;i++)
	{
		p_max=len-i-1;
		for(j=0;j<len-i-1;j++)
		{
			if(array[j]>array[p_max])
				p_max=j;
		}
		if(p_max!=len-i-1)
		{
			tmp=array[p_max];
			array[p_max]=array[len-i-1];
			array[len-i-1]=tmp;
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
	BubbleSort_1(test1,10);
	Print(test1,10);

	int test2[10]={0};
	srand((unsigned)time(NULL)+1);  
	for(i = 0; i < 10;i++ )  
		test2[i]=rand()%20;
	
	Print(test2,10);
	BubbleSort_2(test2,10);
	Print(test2,10);

	int test3[10]={0};
	srand((unsigned)time(NULL)+2);  
	for(i = 0; i < 10;i++ )  
		test3[i]=rand()%20;
	
	Print(test3,10);
	BubbleSort_3(test3,10);
	Print(test3,10);

	int test4[10]={0};
	srand((unsigned)time(NULL)+3);  
	for(i = 0; i < 10;i++ )  
		test4[i]=rand()%20;
	
	Print(test4,10);
	SelectSort(test4,10);
	Print(test4,10);
	return 0;
}