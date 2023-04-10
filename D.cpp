#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef double dou;

ll t, n,tmp;
ll nums[100005];
ll ans_delay[100005];
ll ans_crossing[100005][5];
set<ll>ans_best;

ll binarySearch(ll a,ll b, ll nums[])
{
	ll left = 1, right = b, mid;
	while (left <= right)
	{
		mid = (left + right)/2;
		if ((ans_crossing[a][1] + ans_delay[nums[mid]]) *ans_crossing[a][2] <= nums[mid] * ans_crossing[a][3])
		{
			ans_best.insert(mid);
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	if (ans_best.size() > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int main()
{
	scanf("%lld %lld", &t, &n);
	for (ll i = 1; i <= n; i++)
	{
		nums[i]=i;
	}
	for (ll i = 1; i <= n; i++)
	{
		scanf("%lld", &ans_delay[i]);
	}
	for (ll i = 1; i <= t; i++)
	{
		scanf("%lld %lld %lld", &ans_crossing[i][1], &ans_crossing[i][2], &ans_crossing[i][3]);
	}
	for (ll i = 1; i <= t; i++)
	{
		ans_best.clear();
		tmp = binarySearch(i, n, nums);
		if (tmp == -1)
		{
			printf("-1\n");
		}
		else
		{
			printf("%lld\n", *ans_best.begin());
		}
	}
	return 0;
}