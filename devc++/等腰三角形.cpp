#include<stdio.h>
#include<math.h>
int main()
{
	int a, b, c;
	float d;
	scanf("%d %d %d",&a,&b,&c);
	d =(a / 2)* pow((c * c - (a * a / 4)), 1.0 / 2);
	printf("%.2f", d);
}
