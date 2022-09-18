#include <stdio.h>
int main()
{
	FILE *fp;
	char letter;
	fp=fopen("rupsha.txt","w");
	if(fp==NULL)
	{
		printf("\ncannot open file");
		exit(1);
	}
	printf("\nEnter name and press Enter to end");
	do
	{
		letter=getchar();
		if(letter=='\n')
		break;
		fputc(letter,fp);
	}while(1);
	fclose(fp);
	return 0;
}
