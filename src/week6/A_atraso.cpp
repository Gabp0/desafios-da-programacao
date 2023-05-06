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

ll swaps = 0;
ll h;
vector<cord> a;
void merge_sort(int l, int r)
{
    if (r - l == 1)
    {
        return;
    }
    int mi = l + (r - l) / 2;
    merge_sort(l, mi);
    merge_sort(mi, r);
    vector<cord> aux(r - l);
    int i = l, j = mi;
    for (int k = 0; k < r - l; k++)
    {
        if (i < mi && j < r)
        {
            if (!(a[i].xx < a[j].xx))
            {
                if (a[j].yy > h - 1)
                {
                    swaps += mi - i;
                }
                // cout << "swapping " << a[i] << " and " << a[j] << " s = " << swaps << "\n";
            }
            if (a[i].xx < a[j].xx)
            {
                aux[k] = a[i++];
            }
            else
            {
                aux[k] = a[j++];
            }
        }
        else if (i < mi)
        {
            aux[k] = a[i++];
        }
        else
        {
            aux[k] = a[j++];
        }
    }
    copy(aux.begin(), aux.end(), a.begin() + l);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll n;
    cin >> n >> h;
    a = vector<cord>(n);

    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i].xx;
        a[i].yy = i;
    }
    merge_sort(0, n);

    cout << swaps << "\n";
}