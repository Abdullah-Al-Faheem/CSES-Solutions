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
    int n,m,k;
    cin>> n>> m>> k;

    vector<int> arr(n), vec(m);

    input(arr); sort(all(arr));
    input(vec); sort(all(vec));

    int l = -1, cnt  = 0;

    for(auto it: arr)
    {
        int at = lower_bound(vec.begin()+l+1, vec.end(), it-k)- vec.begin();

        if(at==m) continue;

        if(abs(vec[at]- it) <= k) 
        {
            cnt++;
            l = at;
        }
    }  
    
    cout<< cnt<<nl;
    
}