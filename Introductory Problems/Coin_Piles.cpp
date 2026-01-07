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
    int tc; cin >> tc;
    while(tc--)
    {
        int a, b; cin>> a>> b;

        if(a<b) swap(a,b);
        
        if(a> 2*b){cout<<"NO\n"; continue;}
        
        while(a!=b)
        {
            int gap=  a-b;
            if(gap&1) gap++;
            
            a-= gap;
            b-= gap/2;
        }

        cout<< (a%3? "NO": "YES")<<nl;
    }
}
