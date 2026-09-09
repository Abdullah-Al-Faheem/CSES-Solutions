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

const int mod = 1e9+7;

int power(int a, int b) 
{
    if (b==0) return 1;
    if (b&1) return a *power(a, b-1) % mod;
    return power(a*a %mod , b/2);
}

int modInverse(int A) {return power(A, mod - 2);}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;

    int ans = 0;

    for (int i = 1; i <= n;)
    {
        int cnt = n / i;

        int l = i;
        int r = n / cnt;

        int sz = (r - l + 1) % mod;
        int sum = (l % mod + r % mod) % mod;

        int tmp = ((sum * sz) % mod * modInverse(2)) % mod;

        ans = (ans + (tmp * cnt % mod) % mod) % mod;

        i = r + 1;
    }

    cout << ans << nl;
}
