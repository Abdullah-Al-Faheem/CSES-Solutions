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

const int M = 1e3+9;
char arr[M][M];
char path[M][M];
bool status[M][M];
int n,m, a1,b1, a2, b2;
vector<pair<int,int>> op = {{1, 0}, {0,1}, {-1,0}, {0,-1}};


pair<int,int> bfs(void)
{
    queue<pair<int,int>> q;
    q.push({a1,b1});
    status[a1][b1] = true;

    while(!q.empty())
    {
        auto parent = q.front(); // ber kore ana
        q.pop();

        for (auto it: op)
        {
            int a,b;
            char ch;
            a=it.first, b=it.second;

            if(a==1) ch='D';
            else if(a==-1)ch='U';
            else if(b==1)ch='R';
            else ch='L';
            
            a = it.first+parent.first, b=it.second+parent.second;

            if(a>n or a<1 or b>m or b<1 or arr[a][b]=='#' or status[a][b])continue;
            
            if(arr[a][b]=='B')
            {
                path[a][b]=ch;
                dbug(ch)
                return {a,b};
            }
            else if (!status[a][b]) // set e na thakle
            {
                q.push({a,b});
                status[a][b] = 1;
                path[a][b]=ch;

                // dbug(ch)
            }
        }

    }

    return {0,0};
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>> n>> m;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
        {
            cin>> arr[i][j];
            if(arr[i][j]=='A') a1=i,b1=j;
            else if(arr[i][j]=='B')a2 = i, b2=j;
        }
    
    auto it = bfs();

    int a, b; a=it.first, b= it.second;

    if(a+b==0){cout<<"NO\n"; return 0;}
        

    cout<<"YES\n";
    vector<char> ans;

    while(arr[a][b]!='A')
    {
        cerr<<a<<" "<<b <<"-> " << path[a][b]<<nl;
        ans.push_back(path[a][b]);
        char ch = path[a][b];

        if(ch=='U') a++;
        else if(ch=='D') a--;
        else if(ch=='L')b++;
        else if(ch=='R') b--;
    }
    
    
    cout << ans.size()<<nl;
    while(!ans.empty()) {cout << ans.back(); ans.pop_back();} cout <<nl;
}