#include<stdio.h>

int arr[] = {12,13,14,15,16,17,18,19,20,21,22,23};

int binarySearch(int left, int right, int data)
{
    int mid = (left + right) / 2;
    if(left > right)
    {
        printf("Index out of range !");
        return -1;
    }
    else if (arr[mid] == data)
    {
        printf("Data found at %dth Index",mid);
        return mid;
    }
    else if(arr[mid] > data)
        return binarySearch(left,mid-1,data);
    else
        return binarySearch(mid+1,right,data);
}

int main(int argc, char const *argv[])
{
    binarySearch(0,11,23);
    return 0;
}
