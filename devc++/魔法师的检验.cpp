#include<stdio.h>
int main()
{
	int a;
	scanf("%d", a,1);
	printf("%d %d %d", (a - a % 100) / 100, (a / 10) % 10, a % 10);
}
