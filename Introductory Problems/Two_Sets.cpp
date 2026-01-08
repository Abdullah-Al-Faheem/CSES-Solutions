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

    int sum = n*(n+1)/2;

    if(sum&1) {cout<<"NO\n"; return 0;}

    vector<bool>status(n+1, false);

    int half = sum/2,at = n, cnt = 0;

    while(half>0)
    {
        if(half-at<0) break;;

        half-= at;
        status[at]= true;

        at--;
        cnt++;
    }

    if(half)
    {
        cnt++;
        status[half]= true;
    }

    cout<<"YES\n";
    cout<< n-cnt<<nl;
    for (int i = 1; i <= n; i++)
    {
        if(!status[i]) cout<<i<<" ";
    }
    cout<<nl;
    cout<< cnt<<nl;
    for (int i = 1; i <= n; i++)
    {
        if(status[i]) cout<<i<<" ";
    }
    cout<<nl;

    
}