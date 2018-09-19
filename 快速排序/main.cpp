#include<iostream>
#include<assert.h>
using namespace std;


void PrintArray(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl; 
}


//ע��:����Ľ����һ������ 

//����ֵΪ������ 
int P(int a[],int left,int right)
{
	assert(a);
	int tmp=a[left];//ȡ����һ��ֵ��Ϊ��׼��ͬʱleft���λ�������Ϊ��״̬ 
	//��׼�Ǵ����ȡ�����Դ��ұ߿�ʼ 
	while(left<right)
	{
		while(left<right&&a[right]>tmp)//ͣ�µ�ʱ��������С��tmp�����������ŵ���� 
		right--;
		a[left]=a[right];//�ŵ���ߵĿ�״̬��leftλ����
		while(left<right&&a[left]<=tmp)
		left++;
		a[right]=a[left];//�ŵ��ұߵĿ�״̬��rightλ���� 
	 } 
	 a[right]=tmp;
	
	 return right;//���������� 
}


void QuckSort(int a[],int left,int right)
{
	assert(a);
	if(left<right)
	{
			int index  = P(a,left,right);
			QuckSort(a,index+1,right);
		    QuckSort(a,left,index-1);
	}
	
		
}


int main()
{
	int a[]={9,8,7,6,5,5,3,2,1,0};
	int len=sizeof(a)/sizeof(a[0]);
		PrintArray(a,len);
	QuckSort(a,0,len-1);
	
	PrintArray(a,len);
	return 0;
 } 
