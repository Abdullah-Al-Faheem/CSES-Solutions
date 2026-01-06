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
// #define cerr if(false)cerr

const int inf = 1e9;

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x;
    cin>> n>>x;
    vector<int> arr(n+3);
    for (int i = 1; i <= n; i++) cin>> arr[i];

    vec2d(dp, 2, x+3, inf);
    dp[0][0] = 0;

    int curr = 1;

    for (int at = 1; at <= n; at++)
    {
        for (int val = 0; val<= x; val++)
        {
            dp[curr][val] = dp[curr-1][val];
            if(arr[at] <= val) dp[curr][val] = min(dp[curr][val], 1 + dp[curr][val-arr[at]]);
        }

        for (int val = 0; val<= x; val++) dp[curr-1][val] = dp[curr][val];
    }

    cout << (dp[curr][x] == inf ? -1: dp[curr][x] )<<nl;
}