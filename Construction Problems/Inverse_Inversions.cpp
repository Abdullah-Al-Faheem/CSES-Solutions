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
    
    int n,k; cin>>n>>k;

    vector<int> ans(n+3,0);

    int cnt = n-1, val = n;

    while(k)
    {
        if(k>= cnt)
        {
            ans[n-cnt] = val;
            k-=cnt;
        }
        else
        {
            ans[n-k] = val;
            k=0;
        }
        
        val--, cnt--;
    }   

    val =1;
    for (int i = 1; i <= n; i++) cout<< (ans[i]? ans[i]: val++)<<" "; 
    cout<<nl;
}