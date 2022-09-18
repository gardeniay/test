#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,d,x;
	scanf("%lf %lf %lf %lf %lf",&x,&a,&b,&c,&d);
	printf("%.7lf",a*pow(x,3)+b*pow(x,2)+c*x+d);
}
