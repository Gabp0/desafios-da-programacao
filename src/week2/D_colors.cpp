#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
using ull = unsigned long long;
using ull = long long;
using ld = long double;
long long pinf = 9223372036854775807;
long long minf = -9223372036854775807;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ull n;
    cin >> n;
    vector<pair<ull, ull>> v(n);
    for (auto &x : v)
    {
        cin >> x.xx >> x.yy;
    }

    for (ull i = 1; i < n; i++)
    {
        ull j = i;
        while ((j > 0) && (v[j].xx < v[j - 1].xx))
        {
            if (v[j].yy == v[j - 1].yy)
            {
                cout << "NO"
                     << "\n";
                return 0;
            }
            pair<ull, ull> t = v[j];
            v[j] = v[j - 1];
            v[j - 1] = t;
            j--;
        }
    }

    cout << "YES"
         << "\n";
}