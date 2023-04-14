#include <bits/stdc++.h>
using namespace std;

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
    string rna;

    cin >> n >> ws;
    cin >> rna >> ws;

    ull s = rna.find("AAAAAAA");
    ull e = rna.rfind("AAAAAAA");
    if ((e == string::npos) | (s == string::npos))
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << (e - s + 7) << endl;
    }
}