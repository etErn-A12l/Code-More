#include <stdio.h>
int main()
{
	int a=6373,*v;
	v=&a;
	printf("Address of a=%u\n",v);
	printf("Address of a=%u\n",&a);
	return 0;
}
