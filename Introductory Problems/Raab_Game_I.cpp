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
        int n, a, b; cin>>n>> a>> b;

        if(a+b>n or (a*b==0 and a+b)) {cout<<"NO\n"; continue;}
        
        vector<pair<int,int>> ans;

        for (int i = 1; i <= (n-a-b); i++) ans.push_back({i,i});
        
        int i = (n-a-b)+1, j = i;

        if(b) 
        {
            j=n+1;
            int tmpB=b;
            while(tmpB--)j--;
        }

        int s = i;

        for (; i <= n; i++, j++)
        {
            if(j==n+1) j= s;
            ans.push_back({i,j});
        }

        cout<<"YES\n";
        for (auto it: ans) cout<<it.first<<" "; cout<<nl;
        for (auto it: ans) cout<<it.second<<" "; cout<<nl;
    }
}