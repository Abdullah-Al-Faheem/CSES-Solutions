#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define output(arr) for(auto &it: arr) cerr<<it<<" "; cerr<<nl;
// #define cerr if(false)cerr

int target, n;

const int M = 503, mod = 1e9+7;

int power(int a, int b) 
{
    if (b==0) return 1;
    if (b&1) return (long long)a *power(a, b-1) % mod;
    return power((long long)a*a %mod , b/2);
}
int modInverse(int A) {return power(A, mod - 2);}

int dp[M][M*M];

int calc(int at, int sum)
{
    if(at==n+1)
    {
        if(sum==target) return 1;
        else return 0;
    }
    if(dp[at][sum]!=-1) return dp[at][sum];

    int cnt = 0;

    // nebo
    cnt+= calc(at+1, sum+at);
    cnt%=mod;
    
    // nebo na
    cnt+= calc(at+1, sum);
    cnt%=mod;

    return dp[at][sum]=cnt;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n;

    int sum= n*(n+1)/2;
    if(sum&1){cout<<0<<nl; return 0;}
    target=sum/2;

    memset(dp,-1,sizeof dp);

    cout<<((long long)calc(1,0)*modInverse(2))%mod<<nl;
}