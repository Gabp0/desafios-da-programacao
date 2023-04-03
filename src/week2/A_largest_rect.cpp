#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
using ull = unsigned long long;
using ll = long long;
using ld = long double;
long long pinf = 9223372036854775807;
long long minf = -9223372036854775807;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll n;
    cin >> n;

    vector<ll> v(n);
    for (auto &x : v)
    {
        cin >> x;
    }

    stack<ll> s;
    ll max = minf;
    ll ca;

    for (size_t i = 0; i < n; i++)
    {
        while (!s.empty() && v[s.top()] >= v[i])
        {
            ca = s.top();
            s.pop();

            if (s.empty())
            {
                ca = v[ca] * i;
            }
            else
            {
                ca = v[ca] * (i - s.top() - 1);
            }

            if (ca > max)
            {
                max = ca;
            }
        }

        s.push(i);
    }

    while (!s.empty())
    {
        ca = s.top();
        s.pop();

        if (s.empty())
        {
            ca = v[ca] * n;
        }
        else
        {
            ca = v[ca] * (n - s.top() - 1);
        }

        if (ca > max)
        {
            max = ca;
        }
    }
    
    cout << max << endl;
}