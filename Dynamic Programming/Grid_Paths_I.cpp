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
 
const int mod = 1e9+7;
 
const int M = 1e3 + 3;
 
char arr[M][M];
 
vec2d(dp, M, M , -1);
 
int n; 
 
int fun(int r, int c)
{
    if(arr[r][c] == '*') return 0;
    if(r>n or c> n) return 0;
    if(dp[r][c]!= -1) return dp[r][c];
    if(r==n and c==n) return 1;
 
    int ans = fun(r, c+1); 
    ans += fun(r+1, c); 
    ans %= mod;
 
    return dp[r][c] = ans;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>> arr[i][j];
        }
    }
 
    int ans = fun(1,1);
 
    cout <<ans<< nl;
}