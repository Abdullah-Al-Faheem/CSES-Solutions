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

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string str; cin>> str;

    sort(all(str));

    vector<string> arr;

    do
    {
        arr.push_back(str);
    } while(next_permutation(all(str)));

    cout<< arr.size()<<nl;
    for (auto it: arr)cout<<it<<nl;
}