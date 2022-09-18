#include <stdio.h>
#include <math.h>
double area(int,int,int,int,int,int);
void pointcheck(double a,double a1,double a2,double a3);
int main()
{
	//delclaring variables
	int x1,x2,x3,y1,y2,y3,x,y;
	double ab,bc,ca,pa,pb,pc,r,r1,r2,r3;
	//collecting co-ordinates of points from user
	printf("Enter the co-ordintes of the first point of triangle (x1,y1): ");
	scanf("%d%d",&x1,&y1);
	printf("Enter the co-ordinates of the second point of triangle (x2,y2): ");
	scanf("%d%d",&x2,&y2);
	printf("Enter the co-ordinates of the third point of triangle(x3,y3): ");
	scanf("%d%d",&x3,&y3);
	printf("Enter the co-ordinates of the other point: ");
	scanf("%d%d",&x,&y);
	//calculating areas of individual triangles
	r=area(x1,y1,x2,y2,x3,y3);
	r1=area(x,y,x1,y1,x2,y2);
	r2=area(x,y,x2,y2,x3,y3);
	r3=area(x,y,x1,y1,x3,y3);
	//checking the location of the other point
	pointcheck(r,r1,r2,r3);
	return 0;
}
double area(int a,int b,int c,int d,int e,int f)
{
	double x;
	x=(a*(d-f)+c*(f-b)+e*(b-d))/2;
	return x;
}
void pointcheck(double a,double a1,double a2,double a3)
{
	if(a==(a1+a2+a3))
	{
		printf("The point lies in the triangle");
	}
	else
	{
		printf("\n\nThe point lies outside of the triangle");
	}
}
	
	
