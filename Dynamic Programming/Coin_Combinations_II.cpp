#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define output(arr) for(auto &it: arr) cerr<<it<<" "; cerr<<nl;
// #define cerr if(false)cerr

const int mod = 1e9+7;

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, x;
    cin>>n>>x;
    int arr[n+3];
    for (int i = 1; i <= n; i++) cin>>arr[i];

    vector<int>cnt(x+3,0);
    cnt[0]=1;

    for (int i = 1; i <= n; i++)
    {
        int val = arr[i];

        for (int j = 1; j <= x; j++)
        {
            if(j- val>=0) 
            {
                cnt[j]+= cnt[j- val];
                cnt[j]%=mod;
            }
        }
    }

    cout<<cnt[x]<<nl;
}