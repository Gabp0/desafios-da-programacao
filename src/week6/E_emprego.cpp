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

ll n;
vector<ll> sm;
void add(ll i, ll delta)
{
    for (; i < n + 1; i += i & (-i))
        sm[i] += delta;
}
int get(ll i)
{
    ll ans = 0;
    for (; i > 0; i -= i & (-i))
        ans += sm[i];
    return ans;
}

double a;

double calc(double v2, vector<ll> v)
{
    double ans = 0.0;
    
    for (ll i = n - 1; i >= 0; --i)
    {
        if (v2 >= (double)v[i])
            return ans;

        ans += (double)v[i] - v2;
    }
    return ans;
}
double bs(vector<ll> v)
{
    double b = 0.0;
    double e = v[n - 1];
    double mid;

    while (b <= e)
    {
        mid = (b + e) / 2.0;
        double c = calc(mid, v);

        cout << "c: " << c << " a: " << a << " mid: " << mid << " res: " << fabs(c - (double)a) << endl;

        if (fabs(c - (double)a) < 1e-5)
        {
            return mid;
        }

        if (c < a)
            e = mid;
        else
            b = mid;
    }
    return 0;
}

int main()
{
    while (cin >> n >> a)
    {
        if (n == 0 && a == 0)
        {
            return 0;
        }

        vector<ll> v(n);
        sm = vector<ll>(n + 1, 0);
        ll sum = 0;
        for (ll i = 0; i < n; ++i)
        {
            cin >> v[i];
            sum += v[i];
            add(i + 1, v[i]);
        }

        if (sum < a)
        {
            cout << "-.-\n";
        }
        else if (sum == a)
        {

            cout << ":D\n";
        }
        else
        {
            sort(v.begin(), v.end());
            cout << fixed << setprecision(4) << bs(v) << "\n";
        }
    }
}