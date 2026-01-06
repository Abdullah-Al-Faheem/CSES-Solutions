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

int n, k; 
const int M = 2e5+9;
int arr[M];

bool ok(int mx)  
{
    int part = 1;
    
    int sum =0;
    for (int i = 1; i <= n; i++)
    {
        if(arr[i]> mx) return false;

        if(sum+arr[i] > mx)
        {
            sum= arr[i];
            part++;
        }
        else sum+= arr[i];


        if(part>k) return false;
    }

    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>> n>>k;
    for (int i = 1; i <= n; i++) cin>> arr[i];

    ok(7);

    int lft = 0, rgt = n*1e9 + 9, mid, ans = 0;

    while(lft<=rgt)
    {
        mid = lft + (rgt-lft)/2;

        if(ok(mid))
        {
            ans = mid;
            rgt = mid-1;
        }
        else
        {
            lft = mid+1;
        }
    }

    cout<< ans<<nl;
}