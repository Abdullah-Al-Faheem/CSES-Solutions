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
    int n, x; cin >> n;
    priority_queue<pair<int,int>>pq;

    for (int i = 1; i <= n; i++) 
    {
        cin>> x; pq.push({x,i});
    }

    vector<pair<int,int>> tmp, ans;
    
    bool flag = true;

    while(!pq.empty())
    {
        auto it = pq.top(); pq.pop();

        int me = it.second, cnt = it.first;

        while(!pq.empty())
        {
            if(cnt==0) break; cnt--;
            
            tmp.push_back({pq.top().first-1, pq.top().second});
            ans.push_back({me, pq.top().second});
            pq.pop();
        }

        if(cnt) {flag = false; break;}

        while(!tmp.empty()){pq.push(tmp.back()); tmp.pop_back();}
    }

    if(flag) 
    {
        cout<<(int)ans.size()<<nl;
        for (auto it: ans) cout<<it.first<<" "<<it.second<<nl;
    }
    else cout<<"IMPOSSIBLE"<<nl;


}