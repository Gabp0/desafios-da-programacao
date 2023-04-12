#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
#define cord pair<ll, ll>
#define PN cout << "\n"
using ull = unsigned long long;
using ll = long long;
using ld = long double;
long long pinf = 9223372036854775807;
long long minf = -9223372036854775807;

vector<ll> s(13);
vector<ll> pos(13, pinf);
vector<bool> chosen(12);
ll n, c, t;
vector<cord> rest(132);

bool checkR(ll k)
{
    for (ll i = 0; i < c; i++)
    {
        ll fi = pos[rest[i].xx];
        ll se = pos[rest[i].yy];
        if ((fi != pinf) && (se != pinf) && (fi > se))
        {
            return false;
        }
    }
    return true;
}

void gen(int k)
{

    if (k == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        PN;
        return;
    }
    for (int i = 1; i <= n; i++)
    {

        if (!chosen[i])
        {
            chosen[i] = 1;
            s[k] = i;
            pos[i] = k;
            if (checkR(k + 1))
            {
                gen(k + 1);
            }
            chosen[i] = 0;
            pos[i] = pinf;
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    cin >> n >> c;
    for (ll i = 0; i < c; i++)
    {
        cin >> rest[i].xx >> rest[i].yy;
    }

    t = 0;
    gen(0);
}