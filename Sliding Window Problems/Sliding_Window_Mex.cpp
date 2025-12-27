#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define output(arr) for(auto &it: arr) cerr<<it<<" "; cerr<<nl;
#define cerr if(false)cerr

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, k, x; cin >> n>>k;

    vector<int> arr(n+3); for (int i = 1; i <= n; i++) cin>> arr[i];

    set<int>st;
    map<int,int> mp;
    for (int i = 0; i <= k; i++) st.insert(i);

    for (int i = 1; i <k; i++)
    {
        x= arr[i];
        mp[x]++;

        auto f = st.find(x);
        if(f!= st.end()) st.erase(f);
    }
    
    for (int i = k; i <= n; i++)
    {
        x= arr[i];

        //> in
        mp[x]++;
        auto f = st.find(x);
        if(f!= st.end()) st.erase(f);
    
        cout<<*st.begin()<<" ";

        //> out
        x= arr[i-k+1];
        mp[x]--;
        if(mp[x]==0) st.insert(x);
    }
}