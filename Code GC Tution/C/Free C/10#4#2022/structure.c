#include<stdio.h>
#include<string.h>

int main()
{
    struct student
    {
        int roll;
        char name[40];
        int age;
        int marks;
    };
    
    struct student ram ={12,"Ram",18,87} ;
    printf("Roll = %d Name = %s Age = %d marks = %d",ram.roll,ram.name,ram.age,ram.marks);
    return 0;
}
