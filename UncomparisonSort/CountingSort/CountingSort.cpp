/*******************************************************************************
*
* FileName : CountingSort
* Comment  : 计数排序
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/06/06
*
*******************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//计数排序的思想见:http://www.cnblogs.com/developerY/p/3166462.html

const int MAX_VALUE=20; //待排序数组中元素值范围限定为0~20

void CountingSort(int array[],int len)
{
	int count_len=MAX_VALUE+1;
	int * p_countArray=new int[count_len]; //新申请一个数组，大小为元素（最大值+1）
	for(int i=0;i<count_len;i++) //将新申请的数组各个元素初始化为0
		p_countArray[i]=0;

	for(i=0;i<len;i++) //将待排序数组中的元素放入到新数组中，按照元素值等价为位置的原则
	{
		p_countArray[array[i]]++;
	}

	for(i=1;i<count_len;i++) //确定不比该位置上数据大的数据个数=该位置值加上前一位置值
		p_countArray[i]+=p_countArray[i-1];

	int* p_sortArray=new int[len]; //新申请一个临时存放已排序好的元素的数组
	for(i=len-1;i>=0;i--) //倒序遍历是为了保证稳定性
	{
		p_countArray[array[i]]--; //减一的原因是在p_sortArray中从0位置开始存放元素，保持与原来数组一致
		p_sortArray[p_countArray[array[i]]]=array[i];
	}

	for(i=0;i<len;i++) //将排序完成后的数组复制回原数组
		array[i]=p_sortArray[i];
	
	//释放新申请的空间
	delete [] p_countArray;
	delete [] p_sortArray;
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
	CountingSort(test1,10);
	Print(test1,10);
	
	return 0;
}
