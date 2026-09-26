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

const int M = 503;
int dp[M][M];

int calc(int a, int b)
{
    if(a==b)return 0;
    if(dp[a][b]!=-1)return dp[a][b];

    int cnt =LLONG_MAX;

    // cut a
    for (int i = 1; i < a; i++)
    {
        cnt = min(cnt, 1+ calc(i,b)+calc(a-i,b) );
    }

    // cut b
    for (int i = 1; i < b; i++)
    {
        cnt = min(cnt, 1+ calc(a,i)+calc(a,b-i) );
    }

    cerr<<a<<" "<<b<<" -> "<<cnt<<nl;

    return dp[a][b]=cnt;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int a, b; cin>>a>>b;
    
    memset(dp, -1, sizeof dp);

    int ans = calc(a,b);

    cout<<ans<<nl;
}