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

const int M = 5e3+3;
int arr[M];

int dp[M][M];
bool status[M][M];

int calc(int l, int r, bool ok)
{
    if(l==r) 
    {
        if(ok)return arr[l];
        else return 0;
    }

    if(status[l][r]) return dp[l][r];

    int a, b, ans;
    
    if(ok)
    {
        // first theke nebo
        a = arr[l]+ calc(l+1,r, ok^1);
        // last theke nebo 
        b = arr[r]+calc(l,r-1,ok^1);
        
        ans = max(a,b);
    }
    else
    {
        // first theke nebe
        a = calc(l+1,r, ok^1);
        // last theke nebe
        b = calc(l,r-1,ok^1);

        ans = min(a,b);
    }

    status[l][r]=true;
    return dp[l][r]=ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin>>arr[i];

    cout<<calc(1,n,true)<<nl;
}