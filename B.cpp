#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef double dou;

int n;
int a, b;

int main()
{
	scanf("%d", &n);
	if (n % 2 == 0&&n!=2)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
}