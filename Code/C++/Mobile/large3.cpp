#include <iostream>
using namespace std;
int main()
{
	int size,temp,i,j;
	cout<<"Enter the amount of numbers you want to check: ";
	cin>>size;
	int arr[size];
	for(i=0;i<size;i++)
	{
		cout<<"Enter the "<<" "<<(i+1)<<"th element: ";
		cin>>arr[i];
	}
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	cout<<"The largest and the 2nd largest value is "<<" "<<arr[size-1]<<" and "<<" "<<arr[size-2];
	return 0;
}
