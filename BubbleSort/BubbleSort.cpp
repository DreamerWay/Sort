/*******************************************************************************
*
* FileName : BubbleSort.cpp
* Comment  : ð������
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
		for(j=1;j<len-i;j++) //ע��len-i,ÿһ�˽����ֵ�������ұ�
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
	int flag=false; //���flag,��Ҫ��Ϊ�˷�ֹ�����Ѿ�������������㷨��ȥ�����ù�
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
	//��ʵ�ַ�����Ҫ�ǿ�������һ�����
	//������鿿�ұߵ�һ�����Ѿ�����ֻ��Ҫ�ҵ���������λ�ã��ڶ�����������λ�ü���
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
//�ϱ�ð�������㷨��Ҫ��ÿ�α�����ʱ����кܶ�ν���������Ӱ��Ч��
//����һ�˱���������Ŀ�����ҳ������Ǹ������ŵ����ұߵ�λ��
//���ǿ����ڱ�����ʱ����һ����ָ�롱ʼ��ָ�����ֵλ�ã�һ�˱���������
//�ٽ���һ�ν����������ֵ�������ұߣ�����ʵ�Ͼ���ѡ������
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