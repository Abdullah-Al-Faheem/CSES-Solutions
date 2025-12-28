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

    set<pair<int,int>>bg,en;

    int a,b;
    for (int i = 1; i <= n; i++)
    {
        cin>> a>> b;
        bg.insert({a,b});
        en.insert({b,a});
    }
    
    int cnt = 0;

    while(!en.empty())
    {
        cnt++;
        int r = en.begin()->first;

        while(!bg.empty() and bg.begin()->first < r)
        {
            a = bg.begin()->first;
            b = bg.begin()->second;

            bg.erase(bg.begin());
            en.erase(en.find({b,a}));
        }
    }

    cout<<cnt<<nl;
}