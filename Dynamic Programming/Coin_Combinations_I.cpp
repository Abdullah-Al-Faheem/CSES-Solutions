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

const int M = 103, mx = 1e6+3, mod = 1e9+7;
int n, total, arr[M];

vector<int> dp(mx, -1);

int calc(int sum)
{
    if(sum == 0) return 1;
    if(dp[sum]!= -1) return dp[sum];

    int &cnt = dp[sum]; cnt = 0;

    for (int i = 1; i <= n; i++) if(arr[i] <= sum) {cnt += calc(sum-arr[i]); if(cnt>=mod) cnt-=mod;}

    return cnt;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>> n>> total;
    for (int i = 1; i <= n; i++) cin>> arr[i];

    int ans = calc(total);

    cout << ans<<nl;
}