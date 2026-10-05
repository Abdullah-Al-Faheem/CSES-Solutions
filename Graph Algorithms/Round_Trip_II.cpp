#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define vec2d(name,n,m,val) vector<vector<int>>(name)((n),vector<int>((m),(val)))
#define cerr if(false)cerr

const int M = 2e5+9;
vector<int> adj[M];

int n, edge, a, b;
bool status[M];
bool onPath[M];
int par[M];
int be =0,en=0;
bool flag=false;

void dfs(int src)
{
    status[src] = onPath[src]= true;
    
    for (int child : adj[src])
    {
        if (!status[child]) 
        {
            par[child]=src;
            
            dfs(child);
        }
        else if(onPath[child])
        {
            en=child;
            be = src;
            flag=true;
        }
    }

    onPath[src]=false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>> n>> edge;

    while(edge--)
    {
        cin>> a>>b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) if(!status[i]) dfs(i);

    if(be+en ==0) cout <<"IMPOSSIBLE\n";
    else 
    {
        vector<int> ans;

        int curr=be;
        ans.push_back(en);
        while(curr!=en)
        {
            ans.push_back(curr);
            curr=par[curr];
        }
        
        ans.push_back(en);
        cout<<ans.size()<<nl;
        while(!ans.empty()){cout << ans.back()<<" ";ans.pop_back();}cout <<nl;
    }
    
}