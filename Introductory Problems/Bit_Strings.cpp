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

const int MOD = 1e9+7;

// call by power(x, n) to calculate (x^n)%MOD
int power (int x, int n)
{
    if(n==0) return 1; // base case

    int res = power(x, n/2);
    
    // odd power
    if(n&1) return ( (res*res)%MOD * (x%MOD) ) %MOD;    
    // even power
    else return (res* res)%MOD;   
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;

    cout<< power(2,n)<<nl;
}