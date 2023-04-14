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
    vector<tuple<ull, char, bool>> t(n);
    for (auto &x : t)
    {
        cin >> get<0>(x);
        cin >> get<1>(x);
        get<2>(x) = false;
    }

    for (size_t i = 0; i < n; i++)
    {
        if (!get<2>(t[i]))
        {
            if (get<1>(t[i]) == 'L')
            {
                ull h = get<0>(t[i]);
                ull j = i + 1;
                while ((get<0>(t[j]) < h) && (j < n))
                {
                    j++;
                }

                if ((get<0>(t[j]) == h) && (get<1>(t[j]) == 'O') && !get<2>(t[j]))
                {
                    get<2>(t[i]) = true;
                    get<2>(t[j]) = true;
                }
                else
                {
                    std::cout << "N" << endl;
                    return 0;
                }
            }

            if (get<1>(t[i]) == 'O')
            {
                ull h = get<0>(t[i]);
                ull j = i - 1;
                while ((get<0>(t[j]) < h) && (j >= 0))
                {
                    j--;
                }

                if ((get<0>(t[j]) == h) && (get<1>(t[j]) == 'L') && !get<2>(t[j]))
                {
                    get<2>(t[i]) = true;
                    get<2>(t[j]) = true;
                }
                else
                {
                    std::cout << "N" << endl;
                    return 0;
                }
            }
        }
    }

    std::cout << "S" << endl;
}