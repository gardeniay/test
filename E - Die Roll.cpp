#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef double dou;

int n, m, up_ans, down_ans = 6, flag;

int main()
{
	scanf("%d %d", &n, &m);
	flag = max(n, m);
	if (flag == 1)
	{
		printf("1/1\n");
		return 0;
	}
	else
	{
		up_ans = 7 - flag;
		for (int i = 2; i < 6; i++)
		{
			if (up_ans % i == 0 && down_ans % i == 0)
			{
				up_ans /= i;
				down_ans /= i;
				break;
			}
		}
		printf("%d/%d\n", up_ans, down_ans);
		return 0;
	}
}