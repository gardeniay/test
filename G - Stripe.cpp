#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef double dou;

int n, ans;
int scrip[100000], s[100000];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &scrip[i]);
		s[i + 1] = s[i] + scrip[i];
	}
	for (int i = 1; i < n; i++)
	{
		if (s[i] == s[n] - s[i])ans++;
	}
	printf("%d", ans);
}