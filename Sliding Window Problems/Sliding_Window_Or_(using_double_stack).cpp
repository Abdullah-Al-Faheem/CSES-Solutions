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

    stack<pair<int,int>> stIn,stOut;

    for (int i = 1; i < k; i++)
    {
        if(stIn.empty()) stIn.push({x,x});
        else stIn.push({x, x| stIn.top().second });
        
        x = (x*a+b)%c;
    }
    
    int xr = 0;

    for (int i = k; i <= n; i++) 
    {
        // in
        if(stIn.empty()) stIn.push({x,x});
        else stIn.push({x, x| stIn.top().second });
        
        // output 
        if(stIn.empty()) xr ^= stOut.top().second;
        else if(stOut.empty()) xr ^= stIn.top().second;
        else xr^= stIn.top().second| stOut.top().second;
        
        // out
        if(stOut.empty())
        {
            while(!stIn.empty()) // transfer from in-stack to out-stack
            {
                int val = stIn.top().first; stIn.pop();

                if(stOut.empty()) stOut.push({val,val});
                else stOut.push({val, val| stOut.top().second });
            }
        }
        stOut.pop();
        
        x = (x*a+b)%c;
    }


    cout<<xr<<nl;
}