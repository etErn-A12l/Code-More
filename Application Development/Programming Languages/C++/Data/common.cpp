#include<iostream>
using namespace std;
int main()
{
    int A[7],B[5],count=0;
    for(int i=0;i<7;i++)
    {
        cout<<"Enter the "<<" "<<(i+1)<<"th element of first array: ";
        cin>>A[i];
    }
    cout<<endl;
    cout<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<"Enter the "<<" "<<(i+1)<<"th element of second array: ";
        cin>>B[i];
    }
    cout<<endl;
    cout<<endl;
   for (int i=0;i<7;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(A[i]==B[j])
            {
                count+=1;
            }
        }
    } 
    int C[count];
    for (int i=0;i<7;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(A[i]==B[j])
            {
                C[j]=A[i];
                break;
            }
        }
    }
    cout<<"First Array: ";
    cout<<endl;
    for(int i=0;i<7;i++)
    {
        cout<<" "<<A[i];
    }
    cout<<endl;
    cout<<"2nd Array: ";
    cout<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<" "<<B[i];
    }
    cout<<endl;
    cout<<"Result Array: ";
    cout<<endl;
    for(int i=0;i<count;i++)
    {
        cout<<" "<<C[i];
    }
    return 0;
}
