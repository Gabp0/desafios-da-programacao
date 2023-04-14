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
    list<ull> tape;
    auto h = tape.begin();
    ull n;
    cin >> n;
    char op;
    ull q, t, d;
    while (n--)
    {
        cin >> op;
        if (op == 'm')
        {
            cin >> d;
            if (d > 0)
            {
                while (d--)
                {
                    h++;
                }
            }
            else
            {
                while (d++)
                {
                    h--;
                }
            }
        }
        else if (op == 'i')
        {

            cin >> q >> t;

            while (q--)
            {
                tape.insert(h, t);
                h--;
            }
        }
        else if (op == 'd')
        {

            tape.erase(h++);
        }

        else if (op == 'q')
        {
            cout << *h << "\n";
        }
    }
}