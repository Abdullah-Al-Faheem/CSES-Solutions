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
    int n, k, x; cin >> n>>k;

    multiset<int> st;

    for (int i = 1; i <= n; i++)
    {
        cin>>x;
        st.insert(x);
    }

    int cnt = 0;

    while(!st.empty())
    {
        cnt++;
        
        int val = *st.begin();
        st.erase(st.begin());

        int gap = k-val;

        if(st.empty()) continue;
        
        auto it = st.upper_bound(gap);

        if(it==st.begin()) continue;
        --it;

        st.erase(it);
    }

    cout<<cnt<<nl;
}