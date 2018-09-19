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


//注意:排序的结果是一个升序 

//返回值为相遇点 
int P(int a[],int left,int right)
{
	assert(a);
	int tmp=a[left];//取出第一个值作为基准，同时left这个位置相对于为空状态 
	//基准是从左边取的所以从右边开始 
	while(left<right)
	{
		while(left<right&&a[right]>tmp)//停下的时候遇到了小于tmp的数，将它放到左边 
		right--;
		a[left]=a[right];//放到左边的空状态的left位置中
		while(left<right&&a[left]<=tmp)
		left++;
		a[right]=a[left];//放到右边的空状态的right位置中 
	 } 
	 a[right]=tmp;
	
	 return right;//返回相遇点 
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
