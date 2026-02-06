#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define cerr if(false)cerr

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, k, b, e; cin>>n>>k;

    vector<pair<int,int>>task;

    for (int i = 1; i <= n; i++)
    {
        cin>> b>> e;
        task.push_back({e,b});
    }

    sort(all(task)); 
    int ans = 0;
    multiset<int> st;

    for (auto ii : task)
    {
        b = ii.second, e = ii.first;
        
        if(!st.empty())
        {
            auto it = st.upper_bound(b);

            if(it==st.begin())
            {
                if(st.size()<k) 
                {
                    st.insert(e);
                    ans++;
                }
            }
            else
            {
                --it;
                st.erase(it);
                st.insert(e);
                ans++;
            }
        }
        else 
        {
            st.insert(e);
            ans++;
        }
    }

    cout<<ans<<nl;
}