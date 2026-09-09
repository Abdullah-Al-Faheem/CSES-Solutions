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

const int mod = 1e9+7; // change here
const int M = 2e6+5; // change here
int fact[M];

// call with precalc() at the start of main()
void precalc(void) 
{
    fact[0]=1;

    for (int i = 1; i <M; i++)
    {
        fact[i]=fact[i-1]*i%mod;
    }
}

int power(int a, int b) 
{
    if (b==0) return 1;
    if (b&1) return a *power(a, b-1) % mod;
    return power(a*a %mod , b/2);
}
int modInverse(int A) {return power(A, mod - 2);}

int ncr(int n, int r)
{
    return fact[n]*modInverse(fact[n-r]*fact[r]%mod)%mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    precalc();

    int room, ppl;
    cin>>room>>ppl;

    cout<<ncr(room+ppl-1, ppl)<<nl;
}