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
    vector<int> arr(n); input(arr);
    sort(rall(arr));

    int sum = accumulate(all(arr),0LL);

    sum-= arr.front();

    if(sum< arr.front()) cout<< 2*arr.front()<<nl;
    else cout<< sum+arr.front()<<nl;

}