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
    
    int total = 0, curr;

    int mx = n*n;
    int mid = (n*n + 1)/2;

    for (int i = 1; i <= mx; i++)
    {
        curr=0;
        for (int j = 1; j*j <= i; j++)
        {
            if(i%j == 0 and j<=n and i/j<=n) 
            {
                curr++;
                if (i/j != j) curr++;
            }
        }

        cerr<<i<<": "<<curr<<nl;
        total+= curr;

        if(total>= mid)
        {
            cout<<i<<nl;
            break;
        }
    }

}