#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef double dou;

int n, best_car;
int result[150][150];
int ans[105];

void cmp(int a, int b)
{
	if (result[a][b] == -1 || result[a][b] == 0)
	{
		return;
	}
	else if (result[a][b] == 1)
	{
		ans[a]--;
		return;
	}
	else if (result[a][b] == 2)
	{
		ans[b]--;
	}
	else if (result[a][b] == 3)
	{
		ans[b]--;
		ans[a]--;
		return;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &result[i][j]);
			cmp(i,j);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == 0)best_car++;
	}
	printf("%d\n", best_car);
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == 0)printf("%d ", i);
	}
}