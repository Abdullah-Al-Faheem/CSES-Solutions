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

    vector<pair<int,char>>arr;

    int a,b;
    for (int i = 1; i <= n; i++)
    {
        cin>> a>> b;
        arr.push_back({a,'b'});
        arr.push_back({b,'e'});
    }
    sort(all(arr));

    int cnt = 0, ans = 0;

    for (auto it: arr)
    {
        if(it.second=='b') cnt++; // begin
        else cnt--; // end

        ans = max(ans, cnt);
    }

    cout<<ans<<nl;
}