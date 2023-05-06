#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
#define cord pair<ll, ll>
#define PN cout << "\n"
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using sh = short;
using ush = unsigned short;
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

inline sh dr(string a)
{
    ll d = 0;
    for (auto i : a)
    {
        d = ((i - '0') + d) % 9;
    }
    return d;
}

inline sh dr(sh a)
{
    sh d = 0;
    while (a > 0)
    {
        d += a % 10;
        a /= 10;
    }
    return d % 9;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll n, q;
    string s;

    cin >> n;
    cin >> s;
    cin >> q;

    while (q--)
    {
        ll op;
        cin >> op;

        if ((op == 1) || (op == 2))
        {
            ll a1, b1, a2, b2;
            sh d;
            cin >> a1 >> b1 >> a2 >> b2 >> d;

            string op1, op2;
            for (ll i = a1; i <= b1; i++)
            {
                op1 += s[i - 1];
            }
            for (ll i = a2; i <= b2; i++)
            {
                op2 += s[i - 1];
            }

            // cout << "d = " << d << "\n";
            // cout << "pos = " << a1 << " " << b1 << " " << a2 << " " << b2 << "\n";
            // cout << "op1 = " << op1 << " op2 = " << op2 << "\n";

            bool ans = false;
            if (op == 1)
            {
                ans = (dr(dr(op1) + dr(op2)) == d);
            }
            else if (op == 2)
            {
                ans = (dr(dr(op1) * dr(op2)) == d);
            }

            if (ans)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else if (op == 3)
        {
            ll p;
            char d;
            cin >> p;
            cin >> d;
            s[p - 1] = d;
        }
        cerr << q << "\n";
    }
}