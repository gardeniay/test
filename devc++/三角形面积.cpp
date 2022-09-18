#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,d,x,y;
	scanf("%f %f %f",&a,&b,&c);
	d=b*b-4*a*c;
	x=(-b+sqrt(d))/2*a;
	y=(-b-sqrt(d))/2*a;
	printf("x1=%.2f\nx2=%.2f\n",x,y);
}
