#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char al[5]={'A','B','C','D','E'};
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<al[j]<<" ";
        }
        cout<<endl;
    }
}