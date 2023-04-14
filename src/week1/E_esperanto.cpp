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
    string word;

    cin >> n >> ws;
    cin >> word >> ws;

    if (word.back() == 's')
    {
        cout << word.at(n - 2) << word.at(n - 1) << "\n";
    }
    else
    {
        cout << word.back() << "\n";
    }
}