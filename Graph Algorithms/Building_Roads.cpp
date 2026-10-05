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

struct DSU 
{
    vector<int> parent, Size;

    // create with DSU dsu(n)
    DSU(int n)
    {
        parent.resize(n + 1); // 1 based auto
        Size.resize(n + 1, 1);

        for (int i = 1; i <= n; i++) parent[i]=i;
    }

    int find_par(int node)
    {
        if(parent[node] == node) return node;

        return parent[node] = find_par(parent[node]);
    }

    void union_size(int u, int v)
    {
        int pu = find_par(u);
        int pv = find_par(v);

        if(pu == pv) return;

        if(Size[pu] < Size[pv]) swap(pu, pv);

        parent[pv] = pu;
        Size[pu] += Size[pv];
    }

    int size(int node)
    {
        return Size[find_par(node)];
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, k; cin>>n>>k;

    DSU dsu(n);

    int a,b;
    for (int i = 1; i <= k; i++)
    {
        cin>>a>>b;
        dsu.union_size(a,b);
    }

    vector<int>st;

    for (int i = 1; i <= n; i++)
    {
        st.push_back(dsu.find_par(i));
    }
    
    sort(all(st));
    st.erase(unique(all(st)), st.end());

    cout<<st.size()-1<<nl;

    for (int i = 0; i+1 < st.size(); i++)
    {
        cout<<st[i]<<" "<<st[i+1]<<nl;
    }
}