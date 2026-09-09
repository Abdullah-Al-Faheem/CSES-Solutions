#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long
#define pi acos(-1.0)
#define int long long
#define NO cout<<"NO\n"
#define YES cout<<"YES\n"
#define sqrt(x) sqrtl(x)
#define double long double
#define rall(x) x.rbegin(), x.rend()
#define all(x) (x).begin(), (x).end()
#define fix(n) fixed<<setprecision(n) 
#define mem(a,b) memset(a,b,sizeof(a))
#define dbug(x) cout << #x<<" -> "<<x << nl
#define input(arr) for(auto &it:arr) cin>>it
#define output(arr) for(auto &it: arr) cout<<it<<" "; cout<<nl
#define vec2d(name,n,m,val) vector<vector<int>>(name)((n),vector<int>((m),(val)))
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int MOD = 1e9+7;

// call by power(x, n) to calculate (x^n)%MOD
int power (int x, int n)
{
    if(n==0) return 1; // base case

    int res = power(x, n/2);
    
    // odd power
    if(n&1) return ( (res*res)%MOD * (x%MOD) ) % MOD;    
    // even power
    else return (res* res)% MOD;   
}

int32_t main()
{
    fast_io;
    int tc, test = 0; cin >> tc;
    while(tc--)
    {
        //cout<<"Case "<< ++test <<": ";
        int a, b;
        cin>> a>> b;
        
        b = b%(MOD-1);

        cout << power(a,b)<<nl;
    }
}