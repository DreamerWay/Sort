/*******************************************************************************
*
* FileName : RadixSort.cpp
* Comment  : �������򣨵�λ�棩
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/06/09
*
*******************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//��������˼�����http://www.cnblogs.com/sun/archive/2008/06/26/1230095.html

//����������Ԫ�����λ��
int MaxBit(int array[],int len)
{
	int d=1;
	int* p_tmp=new int[len];
	for(int i=0;i<len;i++)
	{
		p_tmp[i]=array[i];
	}
	for(i=0;i<len;i++)
	{
		int p=1;
		while(p_tmp[i]/10 != 0)
		{
			p++;
			p_tmp[i]/=10;
		}
		if(p>d)
			d=p;
	}
	delete [] p_tmp;
	return d;
}

//
void RadixSort(int array[],int len)
{
	int maxbit=MaxBit(array,len);

	int* p_countArray=new int[10]; //ÿһλ��ΧΪ0~9�����Դ�СΪ10
	int* p_sortArray=new int[len]; //����ĳһ���ź����Ԫ��
	int i=0,j=0,k=0;
	int radix=1;
	//�ڲ�����һ��CountingSort����
	for(i=0;i<maxbit;i++)
	{
		for(j=0;j<10;j++)
			p_countArray[j]=0;
		for(j=0;j<len;j++)
		{
			k=(array[j]/radix)%10;
			p_countArray[k]++;
		}
		for(j=1;j<10;j++)
			p_countArray[j]+=p_countArray[j-1];
		for(j=len-1;j>=0;j--)
		{
			k=(array[j]/radix)%10;
			p_countArray[k]--;
			p_sortArray[p_countArray[k]]=array[j];
		}
		//��һ���ź�������鸴�ƻ�ԭ����
		for(j=0;j<len;j++)
			array[j]=p_sortArray[j];

		radix*=10; //����ʮ���Ӷ�ȡ����λ���ֲ�����
	}

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
	RadixSort(test1,10);
	Print(test1,10);
	
	return 0;
}