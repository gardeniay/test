#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef double dou;

int n, m, ans;
int flag_a, flag_b;
int chess_a[1005], chess_b[1005];

int findnum_a(int a[], int b, int num)
{
    for (int k = b + 1; k <= n; k++)
    {
        if (chess_a[k] == num)
        {
            return k;
        }
    }
    return -1;
}

int findnum_b(int a[], int b, int num)
{
    for (int k = b + 1; k <= n; k++)
    {
        if (chess_b[k] == num)
        {
            return k;
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &chess_a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &chess_b[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        vector<int> a, b;
        for (int j = 1; j <= n; j++)
        {
            a.push_back(chess_a[j]);
            if (chess_a[j] == i && flag_a == 0)
            {
                if (findnum_a(chess_a, j, i) > 0)
                {
                    j = findnum_a(chess_a, j, i) - 1;
                }
            }
        }
        for (int j = 1; j <= n; j++)
        {
            b.push_back(chess_b[j]);
            if (chess_b[j] == i && flag_b == 0)
            {
                if (findnum_b(chess_b, j, i) > 0)
                {
                    j = findnum_b(chess_b, j, i) - 1;
                }
            }
        }
        if (a == b) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
