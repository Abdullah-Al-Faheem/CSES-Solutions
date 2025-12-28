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
    vector<int> arr(n+3);
    for (int i = 1; i <= n; i++) cin>> arr[i];

    int ans, sum; ans = sum = arr[1];

    for (int i = 2; i <= n; i++)
    {
        if(arr[i]> sum+arr[i]) sum = arr[i];
        else sum+= arr[i];

        ans = max(ans, sum);
    }

    cout<<ans<<nl;
}