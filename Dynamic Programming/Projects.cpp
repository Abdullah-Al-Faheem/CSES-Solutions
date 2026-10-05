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

    int n; cin>>n;

    map<int, vector<pair<int,int>>>mp;

    int a, b, p;

    for (int i = 1; i <= n; i++)
    {
        cin>> a>>b>>p;
        mp[b].push_back({a,p});
    }

    map<int,int>dp;
    dp[0]=0;

    int last = 0;

    for (auto [b, vc]: mp)
    {
        for (auto [a,p]: vc) 
        {
            dp[b]=last;

            auto it =mp.upper_bound(a-1);
            
            int day =0;
            if(it!=mp.begin())
            {
                it--;
                day = it->first;
            }

            dp[b]= max(dp[b], p+ dp[day]);
            last = dp[b];
        }
    }

    cout<<last<<nl;
}