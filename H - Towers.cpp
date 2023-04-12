#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef double dou;

int n, max_wood;
int wood[1000000];
set<int>ans2;
int ans1,every_wood[1005];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &wood[i]);
		if (wood[i] > max_wood)max_wood = wood[i];
		ans2.insert(wood[i]);
		every_wood[wood[i]]++;
	}
	for (int i = 1; i <= max_wood; i++)
	{
		if (every_wood[i] > ans1)
		{
			ans1=every_wood[i];
		}
	}
	int ans3 = ans2.size();
	printf("%d %d\n", ans1, ans3);
}