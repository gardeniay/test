#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef double dou;

ll n, m, k, ans;

bool check(ll a)
{
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += min(m, a / i);
	}
	return sum < k;
}

int main()
{
	scanf("%lld %lld %lld", &n, &m, &k);
	ll l = 1, h = n * m, mid;
	while (l < h)
	{
		mid = (l + h) / 2;
		if (check(mid))
		{
			l = mid + 1;
		}
		else
		{
			h = mid;
		}
	}
	printf("%lld\n", l);
}