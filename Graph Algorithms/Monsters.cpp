#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define output(arr) for(auto &it: arr) cerr<<it<<" "; cerr<<nl;
#define vec2d(name,n,m,val) vector<vector<int>>(name)((n),vector<int>((m),(val)))
#define cerr if(false)cerr

vector<pair<int,int>>monsters;
pair<int,int> src;

const int M = 1e3+3, inf = 1e6+3;
char arr[M][M];
int n,m;

vector<pair<int,int>> op = {{0,1}, {0, -1}, {-1, 0}, {1,0}};

vec2d(dp, M, M, inf);

bool ok =false;
char path[M][M];
pair<int,int> last;

void func(char ch, int r, int c, int tm)
{
    
    cerr<< r<<" "<<c<<" -> "<<tm<<nl;

    if(r<1 or r>n or c<1 or c>m) return;
    if(arr[r][c] == '#') return;
    if(dp[r][c]<=tm) return;
    
    cerr<< r<<" "<<c<<" -> "<<tm<<nl;
    cerr<<nl;

    path[r][c] = ch;
    dp[r][c] = tm;

    if(r==1 or r==n or c==1 or c==m) 
    {
        ok = true;
        last = {r,c};
        return;
    }
    
    func('R', r, c+1 , tm+1);
    func('L', r, c-1 , tm+1);
    func('D', r+1, c , tm+1);
    func('U', r-1, c , tm+1);
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>> n>> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>> arr[i][j];
            if(arr[i][j] == 'M') monsters.push_back({i,j});
            else if(arr[i][j] == 'A') src = {i,j};
        }
    }

    queue<pair<int,int>> pq;

    for (auto it: monsters)
    {
        dp[it.first][it.second] =0;
        pq.push({it.first, it.second});
    }

    while(!pq.empty())
    {
        int l = pq.front().first, r = pq.front().second; pq.pop();
        cerr<<l<<" "<<r<<" "<< dp[l][r]<<nl;

        for(auto it: op)
        {
            int ll = l+it.first, rr=  r+it.second ;

            if(ll<1 or ll>n or rr<1 or rr>m or arr[ll][rr]== '#')continue;

            if(dp[ll][rr]> dp[l][r]+1)
            {
                dp[ll][rr] = dp[l][r]+1;
                pq.push({ll,rr});
            }
        }
    }

    func('@', src.first, src.second,0);

    if(!ok) {cout <<"NO"<<nl; return 0;}

    int r = last.first, c = last.second;
    string str;
    while(path[r][c]!='@')
    {
        char ch = path[r][c];
        str.push_back(ch);

        if(ch == 'R') c--;
        else if(ch=='L')c++;
        else if(ch=='U')r++;
        else if(ch=='D')r--;
    }

    reverse(all(str));
    cout<<"YES\n";
    cout << str.size()<<nl;
    cout << str<<nl;
}