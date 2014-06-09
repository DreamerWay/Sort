/*******************************************************************************
*
* FileName : CountingSort
* Comment  : ��������
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/06/06
*
*******************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//���������˼���:http://www.cnblogs.com/developerY/p/3166462.html

const int MAX_VALUE=20; //������������Ԫ��ֵ��Χ�޶�Ϊ0~20

void CountingSort(int array[],int len)
{
	int count_len=MAX_VALUE+1;
	int * p_countArray=new int[count_len]; //������һ�����飬��СΪԪ�أ����ֵ+1��
	for(int i=0;i<count_len;i++) //����������������Ԫ�س�ʼ��Ϊ0
		p_countArray[i]=0;

	for(i=0;i<len;i++) //�������������е�Ԫ�ط��뵽�������У�����Ԫ��ֵ�ȼ�Ϊλ�õ�ԭ��
	{
		p_countArray[array[i]]++;
	}

	for(i=1;i<count_len;i++) //ȷ�����ȸ�λ�������ݴ�����ݸ���=��λ��ֵ����ǰһλ��ֵ
		p_countArray[i]+=p_countArray[i-1];

	int* p_sortArray=new int[len]; //������һ����ʱ���������õ�Ԫ�ص�����
	for(i=len-1;i>=0;i--) //���������Ϊ�˱�֤�ȶ���
	{
		p_countArray[array[i]]--; //��һ��ԭ������p_sortArray�д�0λ�ÿ�ʼ���Ԫ�أ�������ԭ������һ��
		p_sortArray[p_countArray[array[i]]]=array[i];
	}

	for(i=0;i<len;i++) //��������ɺ�����鸴�ƻ�ԭ����
		array[i]=p_sortArray[i];
	
	//�ͷ�������Ŀռ�
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
