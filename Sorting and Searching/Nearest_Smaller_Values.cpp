#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define output(arr) for(auto &it: arr) cerr<<it<<" "; cerr<<nl;
// #define cerr if(false)cerr

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,x; cin >> n;

    vector<int> keep;
    map<int,int> mp;
    keep.push_back(0); mp[0]=0;

    for (int i = 1; i <= n; i++)
    {
        cin>> x;
        while(keep.back()>=x)keep.pop_back();

        cout<<mp[keep.back()]<<" ";

        mp[x]=i;
        keep.push_back(x);
    }
    cout<<nl;
}