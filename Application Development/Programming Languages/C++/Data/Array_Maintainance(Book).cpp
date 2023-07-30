# include<bits/stdc++.h>
using namespace std;

class array
{
    private: 
        int arr[5];
    public:
        void insert(int num,int loc);
        void del(int loc);
        void reverse();
        void display();
        void search(int num);
};

void array :: insert(int num, int loc)
{
    //shifts elements to right
    int i;
    for(i=4;i>=loc;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[i]=num;
}

void array :: del(int loc)
{
    //skip to the desired position
    
}