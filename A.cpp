#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef double dou;

ll ans[5][5];
ll len[5];

int main()
{
	for (int i = 1; i < 4; i++)
	{
		scanf("%lld %lld", &ans[i][1], &ans[i][2]);
	}
	len[1] = pow(ans[3][1] - ans[1][1], 2) + pow(ans[3][2] - ans[1][2], 2);//AC
	len[2] = pow(ans[2][1] - ans[1][1], 2) + pow(ans[2][2] - ans[1][2], 2);//AB
	len[3] = pow(ans[3][1] - ans[2][1], 2) + pow(ans[3][2] - ans[2][2], 2);//CB
	if (len[2] >= len[1] + len[3])
	{
		printf("Longlive Friendship!\n");
	}
	else
	{
		printf("Rush B!\n");
	}
	return 0;
}