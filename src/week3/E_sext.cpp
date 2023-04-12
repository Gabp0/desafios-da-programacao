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

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll n;
    cin >> n >> ws;
    vector<ll> s(n);
    for (auto &i : s)
    {
        cin >> i;
    }
    sort(s.begin(), s.end());

    // f = (a*b + c)/d - e
    // e = (a*b + c)/d - f
    // d = (a*b + c)/(e + f)
    // c = (e + f)*(a*b)/d - a*b
    // b = (e + f)*(a*b)/d - a*c
    // a = (e + f)*(a*b)/d - b*c]

    vector<ll> ab;
    for (auto a : s)
    {
        for (auto b : s)
        {
            ab.push_back(a * b);
        }
    }

    vector<cord> abc;
    for (auto i : ab)
    {
        for (auto b : s)
        {
            ll v = i + b;
            auto fi = find(abc.begin(), abc.end(), v);
            if (fi == abc.end())
            {
                abc.push_back({v, 1});
            }
            else
            {
                ll pos = fi - abc.begin();
                abc[pos] = {v, abc[pos].yy + 1};
            }
        }
    }

    ll ss = 0;
    for (auto d : s)
    {
        if (d == 0)
        {
            continue;
        }

        for (auto e : s)
        {
            for (auto f : s)
            {
                auto it = find_if(abc.begin(), abc.end(), [](const cord &s)
                                  { return s.xx == ((d * f) + (d * e)); });
                if (find(abc.begin(), abc.end(), ((d * f) + (d * e)), ) != abc.end())

                    for (auto i : abc)
                    {
                        if (i.xx == ((d * f) + (d * e)))
                        {
                            ss += i.yy;
                        }
                    }
            }
        }
    }

    cout << ss << endl;
}