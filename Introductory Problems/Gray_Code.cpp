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

int tot; // for leading zeros 

int lastSetBit(int n)
{
    if(n == 0) return 0;
    int k = __builtin_clzll(n);
    return (64-k);
}
void toGray(int n)
{
    if(n==0) 
    {
        for (int i = 1; i <tot; i++)cout<<0;
        cout<<0<<nl;
        return;
    }
    
    int sz = lastSetBit(n);

    for (int i = 0; i <tot-sz; i++)cout<<0;

    int prev= 1;

    cout<<prev;
    for (int i =sz-2; i>=0; i--)
    {
        if((1LL<<i)&n) //str.push_back('1');
        {
            cout<< (prev^1);
            prev = 1;
        } 
        else 
        {
            cout<< prev;
            prev = 0;
        }
    }
    cout<<nl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;

    n = 1<<n;

    tot = lastSetBit(n)-1;

    for (int i = 0; i < n; i++)
    {
        toGray(i);
    }
}