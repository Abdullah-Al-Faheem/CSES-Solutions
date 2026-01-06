#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define output(arr) for(auto &it: arr) cerr<<it<<" "; cerr<<nl;
#define vec2d(name,n,m,val) vector<vector<int>>(name)((n),vector<int>((m),(val)))
#define cerr if(false)cerr

const int mod = 1e9+7;

const int MX = 1e6+3;

int dp[MX];

int calc(int n) 
{
    if(n==0) return 1;

    if(dp[n]) return dp[n];

    int cnt = 0;

    for (int i = 1; i <= 6; i++)
    {
        if(n-i >= 0) cnt+= calc(n-i);
        cnt%= mod;
    }

    dp[n] = cnt;
    return dp[n];
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;

    cout << calc(n)<<nl;

    for (int i = 1; i <= n; i++)
    {
        cerr<<i<<" -> "<< dp[i]<<nl;
    }
}