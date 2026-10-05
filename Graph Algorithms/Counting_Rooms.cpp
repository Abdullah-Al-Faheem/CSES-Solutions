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

vector<pair<int,int>>op={{1,0}, {0,1}, {-1,0}, {0,-1}};
const int M = 1e3+3;
char arr[M][M];

void dfs(int r, int c)
{
    cerr<< r<<", "<< c<<nl;
    arr[r][c]= '#'; 

    for (auto it: op)
    {
        if (arr[it.first+r][it.second+c]=='.') dfs(r+it.first, c+it.second);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a,b; cin>> a>> b;

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            cin>> arr[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if(arr[i][j]=='.')
            {
                ans++;
                cerr<<i<<" "<< j<<nl;
                dbug(ans);
                
                dfs(i,j);
                cerr<<nl;
            }
        }
    }

    cout << ans<<nl;
}