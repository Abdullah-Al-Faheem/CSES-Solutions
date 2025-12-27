#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define output(arr) for(auto &it: arr) cerr<<it<<" "; cerr<<nl;
#define cerr if(false)cerr

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;  cin>>n>>k;
    int x, a, b, c;
    cin>> x>> a>> b>> c;

    int l, r; 
    l = x, r = x;

    int sum = 0;

    for (int i = 1; i <= k; i++) 
    {
        sum+= r;

        r = (r*a+b)%c;
    }

    int xr = sum;

    int cnt = n-k;
    while(cnt--)
    {
        sum+= r;
        sum-= l;

        l = (l*a+b)%c;
        r = (r*a + b)%c;

        dbug(sum)
        xr^= sum;
    }


    cout<< xr<<nl;
}