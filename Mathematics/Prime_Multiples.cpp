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

int n, k, x;
vector<int> total[22];
vector<int> num;    

void knap(int p,int cnt, int at)
{
    if(at==num.size())
    {
        total[cnt].push_back(p);
        return;
    }

    // nebo 
    knap(p/num[at], cnt+1, at+1);

    // nebo na
    knap(p, cnt, at+1);
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>n>>k;

    for (int i = 1; i <= k; i++)
    {
        cin>> x; num.push_back(x);
    }

    knap(n,0,0);

    bool flag = true;

    int sum =0;
    for (int i = 1; i <= k; i++)
    {
        for (auto it: total[i])
        {
            if(flag) sum+= it;
            else sum-= it;
        }
        flag^=true;
    }

    cout << sum<<nl;
}