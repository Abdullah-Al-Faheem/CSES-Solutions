#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long
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

    set<pair<int,int>>st;
    map<int,int> mp;

    for (int i = 1; i <k; i++)
    {
        x= arr[i];

        auto f = st.find({-mp[x],x});
        if(f!= st.end()) st.erase(f);

        mp[x]++;
        st.insert({-mp[x], x});
    }
    
    for (int i = k; i <= n; i++)
    {
        x= arr[i];

        //> in
        auto f = st.find({-mp[x],x});
        if(f!= st.end()) st.erase(f);
    
        mp[x]++;
        st.insert({-mp[x], x});


        cout<<st.begin()->second<<" ";

        for (auto it: st) cerr<<it.second<<" -> "<< -it.first<<nl;
        cerr<<nl<<nl;
        
        //> out
        x= arr[i-k+1];
        st.erase({-mp[x],x});
        mp[x]--;
        if(mp[x]) st.insert({-mp[x],x});
    }
}