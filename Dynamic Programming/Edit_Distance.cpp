#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define output(arr) for(auto &it: arr) cerr<<it<<" "; cerr<<nl;
#define vec2d(name,n,m,val) vector<vector<int>>(name)((n),vector<int>((m),(val)))
// #define cerr if(false)cerr

const int inf = 5e3+2;

string a, b;

vec2d(dp, inf, inf , -1);

int fun(int atA, int atB)
{
    if(atB == b.size()) return a.size()- atA;
    if(atA == a.size()) return b.size()- atB;
    if(dp[atA][atB] != -1) return dp[atA][atB];

    int ans = inf;

    // keep
    if(a[atA] == b[atB]) ans = min(ans, 0 + fun(atA+1, atB + 1));

    // add
    ans = min(ans, 1 + fun(atA, atB+1));
    
    // remove
    ans = min(ans, 1 + fun(atA+1 , atB));
    
    // replace
    ans = min(ans, 1 + fun(atA+1 , atB+1));

    return dp[atA][atB] = ans;
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>> a>> b;

    cout << fun(0,0)<<nl;
}