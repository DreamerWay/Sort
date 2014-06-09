/*******************************************************************************
*
* FileName : HeapSort.cpp
* Comment  : ������
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/06/06
*
*******************************************************************************/
#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

//�±ߵĽ����������õ��ǲ��ö������ݽ���������
void Swap(int &a, int &b)
{
	if (a != b) //����ж���Ҫ�Ƿ�ֹ��a==bʱ���ʹa��b��Ϊ0
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}
}
//��positionλ����Ԫ�ؿ�ʼ������ʹ������󶥶ѣ��ݹ���������ӽڵ�
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
			break; //���break����Ҫ����Ҫ���ϱ�i=max_position�ŵ�if���
		
	}
}

void HeapSort(int array[],int len)
{
	int k=0;
	//ֻ��Ҫ��len-1�δ󶥶ѣ����Ѷ������ֵ���Ͻ�������ߵ�len-1λ���������
	for(int i=0;i<len-1;i++)
	{
		k=len-1-i;//k�����ô󶥶Ѻ���Ҫ����������λ��
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
