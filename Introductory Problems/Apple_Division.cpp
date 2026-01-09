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

vector<int> arr;
int n, total, ans = LLONG_MAX;

void knapsack(int at, int sum)
{
    if(at==n) 
    {

        int b = total-sum;
        int diff = abs(b-sum);

        ans= min(ans, diff);
        return;
    }

    knapsack(at+1, sum+arr[at]);
    knapsack(at+1, sum);
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>> n;
    int x; 
    for (int i = 1; i <= n; i++) {cin>> x; arr.push_back(x);}
    total = accumulate(all(arr), 0LL);

    knapsack(0,0);

    cout<< ans<<nl;

}