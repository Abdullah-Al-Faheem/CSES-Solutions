#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define nl "\n"
#define int long long
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define input(arr) for(auto &it:arr) cin>>it
#define dbug(x) cerr << (#x) << " is " << (x) << nl;
#define output(arr) for(auto &it: arr) cerr<<it<<" "; cerr<<nl;
// #define cerr if(false)cerr

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, 
tree_order_statistics_node_update>;
//order_of_key (find index from val)
//find_by_order (find val from index)
//less // greater_equal // less_equal
// similar to set/ multiset

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, k;
    cin >> n>> k;
 
    vector<int> arr(n+3,0); 
    for (int i = 1; i <= n; i++) cin>> arr[i];
 
    pbds<pair<int,int>> pb;
 
    for (int i =1; i<k; i++) pb.insert({arr[i],i});
 
    
    int mid;
    if(k&1) mid = k/2;
    else mid = k/2-1;
    // dbug(mid)

    
    int lft = 1;
    for (int i =k; i<=n; i++)
    {
        pb.insert({arr[i],i});

        // for (auto it: pb) cerr<<it.first<<" "<<it.second<<nl; 
        // cerr<<nl<<nl;
        
        auto it =  pb.find_by_order( mid );
        cout << it->first <<" ";

        pb.erase({arr[lft], lft}); ++lft;
    }
    cout <<nl;
}