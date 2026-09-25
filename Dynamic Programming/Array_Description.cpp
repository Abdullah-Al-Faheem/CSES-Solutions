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

const int mod = 1e9+7;

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m; cin>>n>>m;
    
    vector<int>arr(n+3); 
    for (int i = 1; i <= n; i++) cin>>arr[i];
    
    int dp[2][m+3];
    memset(dp,0,sizeof dp);
    
    if(arr[1]==0) for (int j = 1; j <= m; j++)dp[1][j]=1;
    else dp[1][arr[1]]=1;

    for (int i = 2; i <= n; i++)
    {
        int prev= (i-1)%2;

        for (int j = 1; j <= m; j++)
        {
            if(j==arr[i] or arr[i]==0){}
            else {dp[i%2][j]=0; continue;}
            
            dp[i%2][j]= (dp[prev][j-1] + dp[prev][j]+ dp[prev][j+1])%mod;
        }
    }
    
    int cnt = 0;
    for (int j = 1; j <= m; j++) cnt= (cnt + dp[n%2][j])%mod;
    cout<<cnt<<nl;
}