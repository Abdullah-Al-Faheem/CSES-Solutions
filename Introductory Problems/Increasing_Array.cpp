#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define vec2d(name,n,m,val) vector<vector<int>>(name)((n),vector<int>((m),(val)))
// #define cerr if(false)cerr

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> arr(n+3);
    for (int i = 1; i <= n; i++) cin>> arr[i];

    int ans = 0;

    for (int i = 2; i <= n; i++)
    {
        ans+= max(0LL, arr[i-1]-arr[i]);
        arr[i]= max(arr[i], arr[i-1]);
    }

    cout << ans<< nl;
}