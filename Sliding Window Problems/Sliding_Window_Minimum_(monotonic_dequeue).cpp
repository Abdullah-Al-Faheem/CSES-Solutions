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
    
    int n, k;  cin>>n>>k;
    int x, a, b, c;
    cin>> x>> a>> b>> c;

    int l, r; 
    l = x, r = x;

    deque<int> dq;

    for (int i = 1; i <= k; i++) 
    {
        // sum+= r;
        while(!dq.empty() and dq.back() > r) dq.pop_back();
        dq.push_back(r);

        r = (r*a+b)%c;
    }

    int xr = dq.front();

    int cnt = n-k;

    while(cnt--)
    {
        // sum+= r; 
        while(!dq.empty() and dq.back() > r) dq.pop_back();
        dq.push_back(r);
        
        // sum-=l;
        if(dq.front()==l) dq.pop_front();

        l = (l*a+b)%c;
        r = (r*a + b)%c;

        xr^= dq.front();
    }


    cout<< xr<<nl;
}
