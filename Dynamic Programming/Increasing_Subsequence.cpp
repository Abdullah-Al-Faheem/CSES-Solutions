#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define output(arr) for(auto &it: arr) cerr<<it<<" "; cerr<<nl;
#define vec2d(name,n,m,val) vector<vector<int>>(name)((n),vector<int>((m),(val)))
// #define cerr if(false)cerr

// returns longest increasing subsequence size
int LIS(const vector<int> &arr, int n) // O(nlogn)
{
    int cnt = 0;

    vector<int> temp; // fake LIS

    for (int i = 1; i <= n; i++)
    {
        if(temp.empty() or arr[i]> temp.back()) {temp.push_back(arr[i]); cnt++;}
        else 
        {
            auto it = lower_bound(all(temp), arr[i]);
            *it = arr[i];
        }
    }

    return cnt; 
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> arr(n+3);
    for (int i = 1; i <= n; i++) cin>> arr[i];

    cout << LIS(arr,n)<<nl;
}