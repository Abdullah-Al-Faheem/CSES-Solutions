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

const int M = 1e7+3;
int arr[M], pref[M], suff[M];

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n>>k; 
    int x, a, b, c; cin>> x>> a>> b>> c;

    for (int i = 1; i <= n; i++) 
    {
        arr[i] = pref[i]= suff[i] = x;

        if((i-1)%k) pref[i] = min(pref[i], pref[i-1]);

        x = (x*a+b)%c;
    }

    for (int i = n; i >=1; i--) if(i%k) suff[i] = min(suff[i], suff[i+1]);

    int xr = 0;
    for (int i = k; i <= n; i++) xr^= min(pref[i], suff[i-k+1]);

    cout<<xr<<nl;
}