#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define output(arr) for(auto &it: arr) cerr<<it<<" "; cerr<<nl;
// #define cerr if(false)cerr


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, tk; cin>>n>>tk;
    
    int cost[n+3];
    int val[n+3];
    
    for (int i = 1; i <= n; i++) cin>>cost[i];
    for (int i = 1; i <= n; i++) cin>>val[i];
    
    int dp[tk+3];
    memset(dp,0,sizeof dp);
    
    // O (n*tk) 
    for (int i = 1; i <= n; i++) // at i
    {
        for (int j = tk; j >= cost[i]; j--) // with j tk
        {
            dp[j] = max(dp[j] , dp[ j-cost[i] ] + val[i]); // val with j tk
        }
    }
    
    cout<<dp[tk]<<nl;
}