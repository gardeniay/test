#include<stdio.h>
int main()
{
	int x,a,y,b;
	float z; 
	scanf("%d %d %d %d",&x,&a,&y,&b);
	z=(b*y-a*x)/(b-a);
	printf("%.2f",z);

}
