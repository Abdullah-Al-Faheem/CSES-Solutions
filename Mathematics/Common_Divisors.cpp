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

const int N = 1e6+3;
vector<int> arr(N,0);

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;

    int tmp;
    for (int i = 1; i <= n; i++) {cin>> tmp; arr[tmp]++;}

    // think from gcd
    // take gcd, find it's multiples

    int ans = 1;

    for (int i = 1; i < N; i++) // taking gcd
    {
        int cnt = 0;
        for (int j = i; j < N; j+= i) // finding it's multiples
        {
            cnt+= arr[j];
        }
        
        if(cnt>=2) ans = max(ans, i);
    }

    cout << ans<<nl;

    
}