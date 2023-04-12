#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef double dou;

int n, ans[3];
int dp[10000];

int main()
{
	dp[0] = 0;
	scanf("%d %d %d %d", &n, &ans[0], &ans[1], &ans[2]);
	for (int i = 1; i <= n; i++)
	{
		dp[i] = -10000000;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i >= ans[j])
			{
				dp[i] = max(dp[i], dp[i - ans[j]] + 1);
			}
		}
	}
	printf("%d", dp[n]);
	return 0;
}