#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
// #define int long long
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define output(arr) for(auto &it: arr) cerr<<it<<" "; cerr<<nl;
// #define cerr if(false)cerr

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k, x; cin >> n>>k; 

    vector<pair<int,int>>arr;
    for (int i = 1; i <= n; i++)
    {
        cin>> x; arr.push_back({x,i});
    }
    sort(all(arr));

    bool f = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int gap = k-arr[i].first-arr[j].first ;
            
            auto it = lower_bound(arr.begin()+j+1, arr.end(), make_pair(gap, -1));

            if(it!=arr.end() and it->first == gap)
            {
                cout<< arr[i].second<<" "<<arr[j].second<<" "<<it->second<<nl;
                f = true;
                break;
            }
        }
        if(f)break;
    }

    if(!f) cout<<"IMPOSSIBLE"<<nl;
}