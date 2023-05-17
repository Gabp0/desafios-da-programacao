#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<ll> pr, lp(1e7 + 15);
void eulersieve /* O(n) */ (int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < int(pr.size()) && pr[j] <= lp[i] && i * pr[j] <= n; j++)
        {
            lp[i * pr[j]] = pr[j];
        }
    }
}

int main()
{
    int t;
    cin >> t;
    eulersieve(1e7 + 15);
    while (t--)
    {
        ll multi, i, k, n;
        cin >> n >> k;
        i = 0;
        multi = 1;
        for (int i = 0; i < k; i++)
        {
            multi *= pr[i];
        }
        i = k;
        while (multi < n)
        {
            if (multi / pr[i - k] * pr[i] > n)
            {
                break;
            }
            multi /= pr[i - k];
            multi *= pr[i++];
        }
        cout << multi << '\n';
    }
}