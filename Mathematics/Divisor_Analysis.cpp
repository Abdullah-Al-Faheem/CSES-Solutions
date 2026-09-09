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
#define dbug(x) cout << #x<<" -> "<<x << nl;
#define input(arr) for(auto &it:arr) cin>>it
#define output(arr) for(auto &it: arr) cout<<it<<" "; cout<<nl
#define vec2d(name,n,m,val) vector<vector<int>>(name)((n),vector<int>((m),(val)))
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
const int mod = 1e9+7;
 
int gcdExtended(int a, int b, int* x, int* y)
{
    // Base Case
    if (a == 0) 
    {
        *x = 0, *y = 1;
        return b;
    }
    // To store results of recursive call
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}
 
// when M and A are coprime or gcd(A, M)==1:
int modInverse(int A, int M) 
{
    int x, y;
    int g = gcdExtended(A, M, &x, &y);
    if (g != 1) {cout << "Inverse doesn't exist\n"; return -1;}
    else 
    {
        // m is added to handle negative x
        int res = (x % M + M) % M;
        return res;
    }
}
 
int power (int x, int n)
{
    if(n==0) return 1; // base case
 
    int res = power(x, n/2);
    
    // odd power
    if(n&1) return ( (res*res)%mod * (x%mod) ) % mod;    
    // even power
    else return (res* res)% mod;   
}
 
int32_t main()
{
    fast_io;
    
    int t; cin >> t;
    int a,b;
    
    int sum, mul, cnt, cnt2;
    cnt = cnt2 = sum = mul = 1;

    while(t--)
    {
        cin >> a>> b;
        
        sum *= ( power(a,b+1) -1 ) * modInverse(a-1, mod) %mod;
        sum%= mod;
        
        int tmp = power(a, (b*(b+1))/2);
        
        mul = (power(mul, b+1) * power(tmp, cnt2))%mod;
        
        cnt = cnt * (b+1)%mod;
        cnt2 = cnt2 * (b+1)%(mod-1);
    }

    cout << cnt<<" "<<sum<<" "<<mul<<nl;
    
}