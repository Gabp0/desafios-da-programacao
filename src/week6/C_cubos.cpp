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

void printMulti(multiset<vector<ll>> ms)
{
    cout << "multiset: " << endl;
    for (auto i : ms)
    {
        print(i);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll n;
    cin >> n;
    multiset<ll> towers;
    multiset<ll, less<ll>>::iterator itr;

    ll x;
    while (n--)
    {
        cin >> x;

        itr = towers.upper_bound(x);
        if (itr != towers.end())
        {
            towers.erase(itr);
            towers.insert(x);
        }
        else
        {
            towers.insert(x);
        }

        // printMulti(towers);
    }

    // for (auto i : towers)
    // {
    //     print(i);
    // }
    cout << towers.size() << "\n";
}