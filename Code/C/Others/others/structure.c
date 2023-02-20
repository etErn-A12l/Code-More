#include<stdio.h>
main()
{
	struct record
	{
		int roll;
		char name[20][20];
		int marks;
	}
	student;
	printf("Enter the name: ");
	scanf("%s",&student.name);
	printf("Enter the roll number: ");
	scanf("%d",&student.roll);
	printf("Enter the marks: ");
	scanf("%d",&student.marks);
	printf("The Student Info:\n");
	printf("Name:%s\nRoll No.:%d\nMarks:%d out of 700",student.name,student.roll,student.marks);
}
