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
	for (int i = 0; i < n; i++)
	{
		scanf("%d+%d", &a, &b);
		printf("%d\n", a + b);
	}
}