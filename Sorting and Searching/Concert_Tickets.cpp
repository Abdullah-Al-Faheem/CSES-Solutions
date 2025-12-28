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
    int n, m, x; cin >> n>>m;

    multiset<int> st;

    for (int i = 1; i <= n; i++)
    {
        cin>>x;
        st.insert(x);
    }


    while(m--)
    {
        cin>> x;

        if(st.empty()) 
        {
            cout<<-1<<nl;
            continue;
        }
        
        auto it = st.upper_bound(x);
        if(it==st.begin()) 
        {
            cout<<-1<<nl;
            continue;
        }
        --it;
        cout<< *it<<nl;

        st.erase(it);
    }
}