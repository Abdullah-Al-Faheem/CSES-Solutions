#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define output(arr) for(auto &it: arr) cerr<<it<<" "; cerr<<nl;
#define cerr if(false)cerr

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;

    map<int,int> mp;

    int l = 0, x, mx = 0;

    for (int i = 1; i <= n; i++)
    {
        cin>> x;
        if(mp[x]>l) l = mp[x];
        else mx = max(mx, i-l);
        
        mp[x]= i;
        
        dbug(mx)
        dbug(l)
        dbug(i)
        cerr<<nl;
    }

    cout<<mx<<nl;
}