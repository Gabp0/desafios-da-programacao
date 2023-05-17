#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
#define cord pair<ll, ll>
#define PN cout << "\n"
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using s = short;
using us = unsigned short;
long long pinf = 9223372036854775807;
long long minf = -9223372036854775807;

void print(vector<ll> v, string s = "")
{
    cout << s << ": ";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> pr, lp(1e7 + 15);
void eulersieve /* O(n) */ (int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < int(pr.size()) && pr[j] <= lp[i] && i * pr[j] <= n; j++)
            lp[i * pr[j]] = pr[j];
    }
}

int main()
{
    ll t;
    cin >> t;
    eulersieve(1e7 + 15);
    while (t--)
    {
        int m = 1, i = 0, k, n;
        cin >> n >> k;
        i = 0;
        m = 1;

        for (ll i = 0; i < k; i++)
        {
            m *= pr[i];
        }

        i = k;
        while (m < n)
        {
            if ((m / (pr[i - k] * pr[i])) > n)
            {
                break;
            }

            m /= pr[i - k];
            m *= pr[i];
            i++;
        }
        cout << m << '\n';
    }
}