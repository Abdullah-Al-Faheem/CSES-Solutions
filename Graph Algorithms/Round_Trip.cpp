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

const int M = 1e5+9;
int pre[M];
bool status[M];
vector<int>adj[M];
bool f;

vector<int>ans;

void print(int a, int b)
{
    if(f)return;
    f=true;

    ans.push_back(b);
    while(a!=b)
    {
        ans.push_back(a);
        a=pre[a];
    }
    ans.push_back(b);
}

void dfs(int src, int par)
{
    dbug(src)   

    if(f)return;

    pre[src]=par;

    status[src] = 1; 

    for (int child : adj[src])
    {
        if(child==par)continue;

        if(status[child]==1)
        {
            print(src,child);
        }
        if(f)return;
        if (status[child] == 0) dfs(child, src);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin>>n>>m;

    int a,b;
    for (int i = 1; i <= m; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if(status[i]==false)
        {
            dfs(i,0);
        }
    }

    if(ans.empty()){cout<<"IMPOSSIBLE"<<nl; return 0;}
    cout<<ans.size()<<nl;
    for (auto it: ans) cout<<it<<" ";
    cout<<nl;

}