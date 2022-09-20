#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,d;
	scanf("%lf %lf %lf",&a,&b,&c);
	d=b*b-4*a*c;
	if(a==0){printf("0");fflush(stdin);}
	if(a!=0&&d<0){printf("-1");fflush(stdin);}
	if(a!=0&&d>=0)printf("x1=%.2lf\nx2=%.2lf\n",(-b+sqrt(d))/(2*a),(-b-sqrt(d))/(2*a));
	//if(d>=0){printf("x1=%.2lf\nx2=%.2lf\n",(-b+sqrt(d))/(2*a),(-b-sqrt(d))/(2*a));fflush(stdin);}
	return 0;
}
