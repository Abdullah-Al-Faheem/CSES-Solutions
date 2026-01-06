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
    string str; cin>> str;

    int mx = 0, n = str.size();

    for (int i = 0; i < n; )
    {
        int cnt =0, j= i;
        while(j<n and str[j]==str[i])cnt++, j++;
        i=j;
        mx=max(mx, cnt);
    }

    cout << mx<<nl;
}