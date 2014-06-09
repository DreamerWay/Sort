/*******************************************************************************
*
* FileName : InsertSort.cpp
* Comment  : ��������
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/06/05
*
*******************************************************************************/
#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;
//��������˼��:ÿ�ν�һ��������ļ�¼������ؼ��ִ�С���뵽ǰ���Ѿ��ź�����������е��ʵ�
//λ�ã�ֱ��ȫ����¼�������Ϊֹ
void InsertSort_1(int array[],int len)
{
	int i=0,j=0;
	int v=0;
	//ѭ��������ڶ���Ԫ�ؿ�ʼ����Ϊarray[0]��Ϊ��������򲿷� 
	for(i=1;i<len;i++)
	{
		v=array[i]; //vΪ�������Ԫ��
		//��v��������Ԫ�شӴ�С�Ƚϣ�Ѱ��vӦ�����λ�� 
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
//��ʵ�ַ�����Ѱ�Ҳ���λ�õĹ����У�˳���ý���������������Ԫ�ؽ���
//���������λ��
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
