#include<stdio.h>
#include<math.h> 
int main()
{
	float a, b, c,d,p;
	scanf("%f %f %f", &a,&b,&c);
	p=(a+b+c)/2;
	d=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("area=%.2f",d);
}
