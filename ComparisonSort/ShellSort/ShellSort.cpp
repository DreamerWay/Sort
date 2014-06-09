/*******************************************************************************
*
* FileName : ShellSort.cpp
* Comment  : œ£∂˚≈≈–Ú£®ø«≈≈–Ú£©
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/06/05
*
*******************************************************************************/
#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

void ShellSort(int array[],int len)
{
	int i=0,j=0,k=0,gap=0,v=0;
	for(gap=len/2;gap>0;gap/=2)
	{
		for(i=0;i<gap;i++)
		{
			for(j=i+gap;j<len;j+=gap)
			{
				v=array[j];
				for(k=j-gap;k>=0;k-=gap)
				{
					if(array[k]>v)
						array[k+gap]=array[k];
					else
						break;
					array[k]=v;
				}
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
	ShellSort(test1,10);
	Print(test1,10);
	
	return 0;
}