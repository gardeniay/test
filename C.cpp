#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef double dou;

int a, b, c;
string s;

int main() 
{
    for (int i = 0; i < 3; i++) 
    {
        cin >> s;
        char c1 = s[0];
        char c2 = s[2];
        if (s[1] == '>') 
        {
            if (c1 == 'A') a++;
            else if (c1 == 'B') b++;
            else c++;

            if (c2 == 'A') a--;
            else if (c2 == 'B') b--;
            else c--;
        }
        else 
        {
            if (c1 == 'A') a--;
            else if (c1 == 'B') b--;
            else c--;

            if (c2 == 'A') a++;
            else if (c2 == 'B') b++;
            else c++;
        }
    }
    if (a == b || b == c || c == a) 
    {
        cout << "Impossible";
        return 0;
    }
    char min_c;
    if (a < b && a < c) min_c = 'A';
    else if (b < c) min_c = 'B';
    else min_c = 'C';
    char max_c;
    if (a > b && a > c) max_c = 'A';
    else if (b > c) max_c = 'B';
    else max_c = 'C';
    if (min_c == 'A' && max_c == 'B')
    {
        printf("ACB");
        return 0;
    }
    else if (min_c == 'A' && max_c == 'C')
    {
        printf("ABC");
        return 0;
    }
    else if (min_c == 'B' && max_c == 'A')
    {
        printf("BCA");
        return 0;
    }
    else if (min_c == 'B' && max_c == 'C')
    {
        printf("BAC");
        return 0;
    }
    else if (min_c == 'C' && max_c == 'A')
    {
        printf("CBA");
        return 0;
    }
    else if (min_c == 'C' && max_c == 'B')
    {
        printf("CAB");
        return 0;
    }
}
