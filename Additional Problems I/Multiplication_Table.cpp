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

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n; cin >> n;
    int at = (n*n+1)/2;

    auto calc = [&](int mid) 
    {
        int cnt =0;
        for (int i = 1; i <= n; i++)
        {
            cnt+= min(mid,i*n)/i;
        }

        return cnt;
    };
    
    int lft = 1, rgt = n*n, mid, ans = 0;
    while(lft<=rgt)
    {
        mid = lft + (rgt-lft)/2;
        
        int a = calc(mid);
        int b= calc(mid-1);

        if(at<=a and at>b){ans = mid; break;}
        else if(a<at) lft = mid+1;
        else rgt = mid-1;
    }

    cout<<ans<<nl;
}