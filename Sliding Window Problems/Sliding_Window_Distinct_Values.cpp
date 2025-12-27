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
    int n, k; cin >> n>>k;

    vector<int> arr(n+3);
    for (int i = 1; i <= n; i++) cin>> arr[i];

    map<int,int> mp;

    for (int i = 1; i <k; i++) mp[arr[i]]++;

    int cnt= mp.size();

    for (int i = k; i <= n; i++)
    {
        // in
        if(mp[arr[i]]==0) cnt++;
        mp[arr[i]]++;


        cout<<cnt<<" ";

        // out
        int val = arr[i-k+1];
        mp[val]--;
        if(mp[val]==0) cnt--;
    }

}