#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define endl "\n"
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) x.rbegin(), x.rend()
#define fix(n) fixed<<setprecision(n) 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
signed main()
{
    fast_io;
 
    ll x, n;
 
    cin >> x>> n;
 
    set<ll> lgt;
    multiset<ll> len;
 
    // lgt = {0, x}
 
    lgt.insert(0);
    lgt.insert(x);
 
    len.insert(x);
 
    for (int i=0; i<n; i++)
    {
        ll temp; cin >> temp;
        // lgt.insert(temp);
 
        auto it = lgt.upper_bound(temp);
 
        auto nxt = it;
        it--;
        auto pev = it;
 
        ll gap = (*nxt) - (*pev);
 
        len.erase( len.find(gap) );
 
        len.insert( (*nxt) - temp);
        len.insert( temp - (*pev));
 
        auto ans = len.end();
        ans--;
        cout << *ans<<" ";
 
        // for (auto el: len)
        // {
        //     cout << el << " ";
        // }
        // cout << endl;
 
        lgt.insert(temp);
 
    }
}