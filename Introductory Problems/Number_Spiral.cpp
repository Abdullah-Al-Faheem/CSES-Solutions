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
    int tc, test = 0; cin >> tc;
    while(tc--)
    {
        int a, b; cin>> a>> b;

        int t = max(a, b);

        int cnt;

        int at =0;
        if(a<=b) at= a;
        else at = a+ a-b;

        if(t&1) cnt = t*t - at+1;
        else cnt = (t-1)*(t-1) + at; // lft to rgt

        cout << cnt<<nl;

    }
}