#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define endl "\n"
#define ll long long
#define pb push_back
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define all(x) (x).begin(), (x).end()
#define rall(x) x.rbegin(), x.rend()
#define fix(n) fixed<<setprecision(n) 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1e5+5;
vector<int> adj[N];
int status[N];
int par[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    status[src] = 1;
    par[src] = -1;

    // level[src] = 1; // can vary

    while(!q.empty())
    {
        int parent = q.front(); // ber kore ana
        q.pop();

        // processing
        for (int child : adj[parent])
        {
            if (!status[child]) // set e na thakle
            {
                q.push(child);
                status[child] = 1;
                par[child] = parent;
                // level[child] = level[parent]+1; 
            }
        }

        // after work
        // cout << parent<<endl;
    }
}


int main()
{
    fast_io;
    int nodes, edge;
    cin >> nodes>> edge;


    int a, b;
    while(edge--)
    {
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }  

    memset(par, -1, sizeof(par));

    bfs(1); 

    int child = nodes;
    int parent = par[nodes];
    stack<int> ans;
    if (parent != -1) ans.push(child);

    while(parent != -1)
    {
        ans.push(parent);
        child = parent;
        parent = par[child];
    }

    if (ans.empty()) cout << "IMPOSSIBLE"<< endl;
    else cout << ans.size()<< endl;
    while (!ans.empty())
    {
        cout << ans.top()<<" ";
        ans.pop();
    }
    
    cout << endl;
}