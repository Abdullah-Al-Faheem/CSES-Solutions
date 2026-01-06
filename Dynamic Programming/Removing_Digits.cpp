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

const int M = 1e6+9, inf = 1e9;

int dp[M];
int n;

int fun(int at)
{
    if(at == 0) return 0;
    if(at<0) return inf;
    if(dp[at]) return dp[at];

    int cnt = inf;

    int tmp = at;

    while(tmp)
    {
        int rem = tmp%10; tmp/=10;

        if(rem) cnt = min(cnt, fun(at-rem));
    }

    return dp[at] = cnt+1;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n;

    cout << fun(n)<<nl;
}