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

void hanoi(int A, int B, int C, int cnt)
{
    if(cnt==0) return; 

    hanoi(A,C,B, cnt-1);
    cout<<A<<" "<<C<<nl;
    hanoi(B,A,C,cnt-1);
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    cout<<(1LL<<n) -1<<nl;
    hanoi(1,2,3,n);
}